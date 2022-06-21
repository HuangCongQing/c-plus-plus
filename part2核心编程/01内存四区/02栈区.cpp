/*
 * @Description: 注意事项：不要返回局部变量的地址，栈区开辟的数据由编译器自动释放
 * @Author: HCQ
 * @Company(School): UCAS
 * @Date: 2020-06-10 10:22:47
 * @LastEditors: Please set LastEditors
 * @LastEditTime: 2022-06-21 10:59:49
 */ 
#include <iostream>
using namespace std;

// 注意事项：不要返回局部变量的地址，栈区开辟的数据由编译器自动释放
int* func()
{
    int a = 10; // 局部变量存放在栈区（栈区的数据在函数执行完释放）
    return &a; // 返回地址
}
int main()
{   
    // 接收func的返回值
    int * p = func();
    cout << *p << endl; // 第一次可以打印10，因为编译器作了保留
    cout << *p << endl; // 第二次不再保留
    system("pause");
    return 0;
}