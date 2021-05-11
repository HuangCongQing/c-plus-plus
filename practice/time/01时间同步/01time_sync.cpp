/*
 * @Description: 双线程时间同步  https://www.shuangyi-tech.com/news_188.html
 运行命令:cd "/home/hcq/github/c-plus-plus/practice/01时间同步/" && g++ 01time_sync.cpp -o 01time_sync -pthread && "/home/hcq/github/c-plus-plus/practice/01时间同步/"01time_sync
 * @Author: HCQ
 * @Company(School): UCAS
 * @Email: 1756260160@qq.com
 * @Date: 2021-04-15 10:56:25
 * @LastEditTime: 2021-04-15 11:05:22
 * @FilePath: /c-plus-plus/practice/01时间同步/01time_sync.cpp
 */

#include <iostream>
#include <thread>
#include <mutex>
#include <vector>
#include <condition_variable>

using namespace std;

  
std::mutex mtx;
std::condition_variable cv;
std::vector<int> vec;
int productNum = 5;

void Producer()
{
    for (int i = 1; i <= productNum; ++i) {
        std::unique_lock<std::mutex> lock(mtx);
        while (!vec.empty()) {
            cv.wait(lock); // vec 不为空时阻塞当前线程
        }
        vec.push_back(i);
        std::cout << "Producer生产产品: " << i << std::endl;
        cv.notify_all(); // 释放线程锁
    }
}

void Consumer()
{
    while (true) {
        std::unique_lock<std::mutex> lock(mtx);
        while (vec.empty()) {
            cv.wait(lock); // vec 为空时等待线程锁。其他线程锁释放时，当前线程继续执行
        }
        int data = vec.back();
        vec.pop_back();
        std::cout << "Consumer消费产品: " << data << std::endl;
        cv.notify_all();
    }
}

int main()
{
    std::thread t1(Producer);
    std::thread t2(Consumer);
    t2.join();
    t1.join();
    std::cin.get();
}