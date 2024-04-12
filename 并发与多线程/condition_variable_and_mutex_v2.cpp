/*
 * @Description: 有三个事件(每个事件耗时分别sleep0.3，0.2，0.1)，当第一个事件执行外之后才能执行第二个，第二个执行完才能执行完第三个
 * @Author: HCQ
 * @Company(School): UCAS
 * @Email: 1756260160@qq.com
 * @Date: 2024-04-12 16:16:56
 * @LastEditTime: 2024-04-12 17:11:57
 * @FilePath: /c-plus-plus/并发与多线程/condition_variable_and_mutex_v2.cpp
 */
//   -std=c++11  -pthread 
#include <iostream>  
#include <thread>  
#include <vector>  
#include <array>  
#include <mutex>  
#include <condition_variable>  
#include <chrono>  
#include <thread>  
  
const int kNumberOfEvents = 3;  
  
class EventSequencer {  
public:  
    EventSequencer() {}  
  
    void startEvents() {  
        std::vector<std::thread> threads;  
  
        for (int i = 0; i < kNumberOfEvents; ++i) {  
            threads.emplace_back([this, i]() {  
                handleEvent(i);  
            });  
        }  
  
        for (auto& t : threads) {  
            t.join();  
        }  
    }  
  
private:  
    std::array<std::condition_variable, kNumberOfEvents> cv_controllers_;  
    std::array<std::mutex, kNumberOfEvents> mtxs_;  
    std::array<bool, kNumberOfEvents> stop_waiting_ = {false};  
  
    void handleEvent(int eventIndex) {  
        std::unique_lock<std::mutex> lock(mtxs_[eventIndex]);  
  
        // Wait until the previous event is finished (if not the first event)  
        if (eventIndex > 0) {  
            cv_controllers_[eventIndex - 1].wait(lock, [this, eventIndex]() {  
                return stop_waiting_[eventIndex - 1];  
            });  
        }  
  
        // Perform the event (simulated with a sleep)  
        std::this_thread::sleep_for(std::chrono::milliseconds(eventIndex * 100 + 200));  
        std::cout << "Event " << eventIndex << " finished\n";  
  
        // Notify the next event to start (if not the last event)  
        if (eventIndex < kNumberOfEvents - 1) {  
            stop_waiting_[eventIndex] = true;  
            cv_controllers_[eventIndex].notify_one();  
        }  
    }  
};  
  
int main() {  
    EventSequencer sequencer;  
    sequencer.startEvents();  
    return 0;  
}