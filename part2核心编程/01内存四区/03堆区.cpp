/*
 * @Description: 堆区不会因为函数的结束而释放
 * @Author: HCQ
 * @Company(School): UCAS
 * @Date: 2020-06-10 11:28:16
 * @LastEditors: Please set LastEditors
 * @LastEditTime: 2022-06-21 11:32:37
 */
#include <iostream>
using namespace std;

// 堆区不会因为函数的结束而释放==================================================
int *func()
{   
    // 利用new关键字，可以将数据开辟到堆区
    int *a = new int(10);  // new返回的是地址
    cout<<"a地址："<< (int)(size_t)a<< endl; 
    return a; // 地址

}
int main()
{
    int *p = func();
    // size_t 类型表示C中任何对象所能达到的最大长度，它是无符号整数。
    cout<<"p地址："<< (int)(size_t)p<< endl; // 地址：1641807536 地址：0x5599e9855eb0  
    cout << *p << endl; // 10
    cout << *p << endl; // 10

    system("pause");
    return 0;
}