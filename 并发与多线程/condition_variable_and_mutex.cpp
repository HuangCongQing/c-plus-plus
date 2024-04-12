/*
 * @Description: 使用std::condition_variable和std::mutex来实现线程间的同步：
 * @Author: HCQ
 * @Company(School): UCAS
 * @Email: 1756260160@qq.com
 * @Date: 2024-04-12 16:06:54
 * @LastEditTime: 2024-04-12 16:08:01
 * @FilePath: /c-plus-plus/并发与多线程/condition_variable_and_mutex.cpp
 */
//  添加参数： -pthread
// 运行


#include <iostream>                // std::cout
#include <thread>                // std::thread
#include <mutex>                // std::mutex, std::unique_lock
#include <condition_variable>    // std::condition_variable
 
std::mutex mtx; // 全局互斥锁.
std::condition_variable cv; // 全局条件变量.
bool ready = false; // 全局标志位.
 
void do_print_id(int id)
{
	std::unique_lock <std::mutex> lck(mtx);
 
	while (!ready)
	{
		/*
			如果标志位不为 true, 则等待...
			当前线程被阻塞, 当全局标志位变为 true 之后, 线程被唤醒, 继续往下执行打印线程编号id.
		*/
		cv.wait(lck);
	}
	std::cout << "thread " << id << '\n';
}
 
void go()
{
	std::unique_lock <std::mutex> lck(mtx);
	ready = true; // 设置全局标志位为 true.
	cv.notify_all(); // 唤醒所有线程.
}
 
int main()
{
	std::thread threads[10];
	// spawn 10 threads:
	for (int i = 0; i < 10; ++i)
		threads[i] = std::thread(do_print_id, i);
 
	std::cout << "10 threads ready to race...\n";
	go(); // go!
 
	for (auto & th : threads)
		th.join();
 
	return 0;
}