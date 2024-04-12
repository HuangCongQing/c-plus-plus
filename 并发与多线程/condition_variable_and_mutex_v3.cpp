/*
 * @Description:
 * 有三个事件，每个事件都是一个函数(每个事件耗时分别sleep0.3，0.2，0.1)，当第一个事件执行外之后才能执行第二个，第二个执行完才能执行完第三个
 * @Author: HCQ
 * @Company(School): UCAS
 * @Email: 1756260160@qq.com
 * @Date: 2024-04-12 16:16:56
 * @LastEditTime: 2024-04-12 17:14:36
 * @FilePath: /c-plus-plus/并发与多线程/condition_variable_and_mutex_v3.cpp
 */
//   -std=c++11  -pthread
#include <array>
#include <chrono>
#include <condition_variable>
#include <iostream>
#include <mutex>
#include <thread>
#include <vector>

// 定义事件数量
static constexpr int kNumberOfEvents = 3;

class EventSequencer {
 public:
  EventSequencer() {}

  // 开始事件序列
  void startEvents() {
    std::vector<std::thread> threads;

    // 启动所有事件线程，但每个线程会等待前一个事件完成
    for (int i = 0; i < kNumberOfEvents; ++i) {
      threads.emplace_back([this, i]() {
        // 执行三个线程
        handleEvent(i);
      });
    }

    // 等待所有线程完成
    for (auto& t : threads) {
      t.join();
    }
  }

 private:
  // 控制变量数组
  std::array<std::condition_variable, kNumberOfEvents> cv_controllers_;
  // 这个数组用于管理多个互斥锁，以实现对多个事件的并发控制和同步操作。
  std::array<std::mutex, kNumberOfEvents> mtxs_;
  // 用于避免在wait之前调用notify的情况
  std::array<bool, kNumberOfEvents> ready_to_proceed_ = {false};

  // 处理单个事件
  void handleEvent(int eventIndex) {
    // 锁
    std::unique_lock<std::mutex> lock(mtxs_[eventIndex]);

    // 等待前一个事件完成（如果有的话） 第一个时间不等待
    // 如果事件索引大于0，就会调用条件变量cv_controllers_中索引为eventIndex -
    // 1的控制器的wait函数， 等待一个条件为ready_to_proceed_[eventIndex -
    // 1]的条件变量。在条件满足之前，当前线程会一直被阻塞。
    if (eventIndex > 0) {
      // 当 std::condition_variable 对象的某个 wait 函数被调用的时候，它使用
      // std::unique_lock(通过 std::mutex) 来锁住当前线程
      // 当前线程会一直被阻塞，直到另外一个线程在相同的 std::condition_variable
      // 对象上调用了 notify 函数来唤醒当前线程。
      cv_controllers_[eventIndex - 1].wait(lock, [this, eventIndex]() {
        // 上一个线程（eventIndex - 1）状态为True，才执行当前线程（eventIndex）
        // std::cout << "ready_to_proceed_ ： " << ready_to_proceed_[eventIndex
        // - 1]<<std::endl;
        return ready_to_proceed_[eventIndex - 1];
      });
    }

    // 执行事件
    switch (eventIndex) {
      case 0:
        std::cout << "Starting event 1 (sleep for 2s)\n";
        std::this_thread::sleep_for(std::chrono::milliseconds(2000));
        break;
      case 1:
        std::cout << "Starting event 2 (sleep for 2s)\n";
        std::this_thread::sleep_for(std::chrono::milliseconds(2000));
        break;
      case 2:
        std::cout << "Starting event 3 (sleep for 0.1s)\n";
        std::this_thread::sleep_for(std::chrono::milliseconds(100));
        break;
    }
    std::cout << "Event " << eventIndex + 1 << " finished\n";

    // 标记当前事件完成，并通知下一个事件可以开始
    ready_to_proceed_[eventIndex] = true;

    // notify_one();不调用会一直在wait位置等待
    // cv_controllers_[eventIndex].notify_one();
  }
};

int main() {
  EventSequencer sequencer;
  sequencer.startEvents();
  return 0;
}