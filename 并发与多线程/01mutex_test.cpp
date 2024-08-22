/*
 * @Description: https://www.yuque.com/huangzhongqing/lang/ysbaam504ow210ni
 g++ -o mutex_test mutex_test.cpp -std=c++11 -lpthread
 * @Author: HCQ
 * @Company(School): UCAS
 * @Email: 1756260160@qq.com
 * @Date: 2024-07-31 19:10:15
 * @LastEditTime: 2024-07-31 19:15:30
 * @FilePath: /c-plus-plus/并发与多线程/mutex_test.cpp
 */
#include <iostream>
#include <mutex>
#include <thread>

#define TRY_MUTEX 0
#define MY_MUTEX 1

volatile int counter(0);  // non-atomic counter

std::mutex mtx;

void increases10k() {
  for (int i = 0; i < 10000; i++) {
#if TRY_MUTEX
    if (mtx.try_lock()) {
      ++counter;
      mtx.unlock();
    }
#elif MY_MUTEX
    mtx.lock();
    ++counter;
    mtx.unlock();
#endif
  }
}

int main(int argc, char** argv) {
  std::thread threads[10];
  for (int i = 0; i < 10; i++) {
    threads[i] = std::thread(increases10k);
    std::cout << "-----" << i << std::endl;
  }
  for (auto& th : threads) {
    std::cout << "111111111111" << std::endl;
    th.join();
  }
  std::cout << " successful increases of the counter " << counter << std::endl;
  return 0;
}
/*  
-----0
-----1
-----2
-----3
-----4
-----5
-----6
-----7
-----8
-----9
111111111111
111111111111
111111111111
111111111111
111111111111
111111111111
111111111111
111111111111
111111111111
111111111111
*/