/*
 * @Description: 
 * @Author: HCQ
 * @Company(School): UCAS
 * @Email: 1756260160@qq.com
 * @Date: 2024-08-22 16:09:09
 * @LastEditTime: 2024-08-22 16:31:40
 * @FilePath: /c-plus-plus/并发与多线程/03future_test.cpp
 */
#include <iostream>  
#include <future>  
#include <vector>  
  
// 递增函数 （这个函数执行顺序未知！！！！！！！！！！！）
int increment(int value) {  
    // 假设这里有一些计算，但为了简单起见，我们只是直接返回value + 1  
    std::cout << "递增函数."<<value + 1<<std::endl;  
    return value + 1;  
}  
  
int main() {  
    // 创建一个空的vector来存储std::future对象  
    std::vector<std::future<int>> futures;  
  
    // 假设我们要递增几个数字  
    std::vector<int> numbers = {1, 2, 3, 4, 5};  
  
    // 对每个数字使用std::async启动异步任务  
    for (int num : numbers) {  
        // std::launch::async 表示我们想要异步执行  
        futures.push_back(std::async(std::launch::async, increment, num));  
    }  
  
    // 等待所有异步任务完成  
    // for (auto& fut : futures) {  
        // fut.wait();  
    for (int i=0;i<futures.size();i++) {  
        // 等待特定的future完成  
        futures[i].wait();
  
        // 在这里，我们可以获取结果，但在这个例子中，我们仅演示wait(输出结果是按照顺序的)
        int result = futures[i].get(); // 这将获取结果但也会再次等待（如果尚未完成）  
  
        // 下面这行打印代码是按照顺序打印的
        std::cout << "A future has completed."<<result<<std::endl;  
    }  
  
    return 0;  
}
// Tips:递增函数执行顺序未知，但是输出结果（打印代码）是按照顺序打印的！！！！！！！！！
/* 下面是打印日志
递增函数.递增函数.32

递增函数.4
A future has completed.0
A future has completed.1
递增函数.5递增函数.
6
A future has completed.2
A future has completed.3
A future has completed.4
*/