/*
 * @Description: 
 * @Author: HCQ
 * @Company(School): UCAS
 * @Date: 2020-06-10 10:22:47
 * @LastEditors: HCQ
 * @LastEditTime: 2020-06-10 11:00:35
 */ 
#include <iostream>
using namespace std;
//全局变量
int g_a = 10;
int g_b = 10;

//全局常量
const int c_g_a = 10;
const int c_g_b = 10;

int main()
{
    //局部变量
    int a = 10;
    int b = 10;
    //打印地址
    cout << "局部变量a地址为： " << (int)(size_t)(&a) << endl;
    cout << "局部变量b地址为： " << (int)(size_t)(&b) << endl;
    cout << "全局变量g_a地址为： " << (int)(size_t)(&g_a) << endl;
    cout << "全局变量g_b地址为： " << (int)(size_t)(&g_b)<< endl;
    //静态变量
    static int s_a = 10;
    static int s_b = 10;
    cout << "静态变量s_a地址为： " << (int)(size_t)(&s_a) << endl;
    cout << "静态变量s_b地址为： " << (int)(size_t)(&s_b) << endl;
    cout << "字符串常量地址为： " << (int)(size_t)(&"hello world") << endl;
    cout << "字符串常量地址为： " << (int)(size_t)(&"hello world1") << endl;
    cout << "全局常量c_g_a地址为： " << (int)(size_t)(&c_g_a) << endl;
    cout << "全局常量c_g_b地址为： " << (int)(size_t)(&c_g_b) << endl;
    const int c_l_a = 10;
    const int c_l_b = 10;
    cout << "局部常量c_l_a地址为： " << (int)(size_t)(&c_l_a) << endl;
    cout << "局部常量c_l_b地址为： " << (int)(size_t)(&c_l_b) << endl;

    system("pause");

    return 0;
}