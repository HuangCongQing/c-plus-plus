/*
 * @Description: 
 * @Author: HCQ
 * @Company(School): UCAS
 * @Email: 1756260160@qq.com
 * @Date: 2024-04-12 16:16:56
 * @LastEditTime: 2024-04-12 16:28:05
 * @FilePath: /c-plus-plus/并发与多线程/condition_variable_and_mutex_v2.cpp
 */

#include <iostream>  
#include <thread>  
#include <mutex>  
#include <condition_variable>  
#include <array>  
#include <chrono>  
  
class EventSequencer {  
public:  
    EventSequencer() : next_event_index_(0) {}  
  
    void startEvents() {  
        for (size_t i = 0; i < kNumberOfEvents; ++i) {  
            events_threads_.emplace_back(&EventSequencer::handleEvent, this, i);  
        }  
  
        for (auto& t : events_threads_) {  
            t.join();  
        }  
    }  
  
private:  
    static constexpr int kNumberOfEvents = 3;  
    std::array<std::mutex, kNumberOfEvents> mtxs_;  
    std::array<std::condition_variable, kNumberOfEvents> cv_controllers_;  
    std::atomic<size_t> next_event_index_;  
    std::vector<std::thread> events_threads_;  
  
    // 定义三个事件函数  
    void eventFunction1() {  
        std::cout << "Event 1 is running for 0.3 seconds..." << std::endl;  
        std::this_thread::sleep_for(std::chrono::milliseconds(300));  
    }  
  
    void eventFunction2() {  
        std::cout << "Event 2 is running for 0.2 seconds..." << std::endl;  
        std::this_thread::sleep_for(std::chrono::milliseconds(200));  
    }  
  
    void eventFunction3() {  
        std::cout << "Event 3 is running for 0.1 seconds..." << std::endl;  
        std::this_thread::sleep_for(std::chrono::milliseconds(100));  
    }  
  
    // 根据事件索引调用相应的事件函数  
    void handleEvent(size_t event_index) {  
        std::unique_lock<std::mutex> lock(mtxs_[event_index]);  
  
        // 等待前一个事件完成  
        if (event_index > 0) {  
            cv_controllers_[event_index - 1].wait(lock, [this, &event_index]() {  
                return next_event_index_ == event_index;  
            });  
        }  
  
        // 执行对应的事件函数  
        switch (event_index) {  
            case 0:  
                eventFunction1();  
                break;  
            case 1:  
                eventFunction2();  
                break;  
            case 2:  
                eventFunction3();  
                break;  
            default:  
                // 处理错误情况或不可能发生的情况  
                break;  
        }  
  
        // 通知下一个事件可以开始  
        if (event_index < kNumberOfEvents - 1) {  
            ++next_event_index_;  
            cv_controllers_[event_index].notify_one();  
        }  
    }  
};  
  
int main() {  
    EventSequencer sequencer;  
    sequencer.startEvents();  
    return 0;  
}