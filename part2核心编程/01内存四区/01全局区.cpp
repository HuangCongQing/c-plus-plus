/*
 * @Description: 
 ● 全局区:存放全局变量、静态变量、常量
 ● 堆区：存放局部变量
 * @Author: HCQ
 * @Company(School): UCAS
 * @Date: 2020-06-10 10:22:47
 * @LastEditors: Please set LastEditors
 * @LastEditTime: 2022-06-21 10:35:58
 */ 
#include <iostream>
#include <stdio.h> // ‘size_t’ does not name a type
using namespace std;
//全局变量（全局区）
int g_a = 10;
int g_b = 10;

//全局常量（全局区）
const int c_g_a = 10;
const int c_g_b = 10;

int main()
{
    //局部变量（堆区）（在函数体内的（比如main函数）============================================
    int a = 10;
    int b = 10;
    //打印地址
    cout << "局部变量a地址为： " << (int)(size_t)(&a) << endl;
    cout << "局部变量b地址为： " << (int)(size_t)(&b) << endl;
    cout << "全局变量g_a地址为： " << (int)(size_t)(&g_a) << endl;
    cout << "全局变量g_b地址为： " << (int)(size_t)(&g_b)<< endl;
    //静态变量（全局区）
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

/* 
局部变量a地址为： -235866392
局部变量b地址为： -235866388
下面全是全局区==================================================================
全局变量g_a地址为： 293720080
全局变量g_b地址为： 293720084
静态变量s_a地址为： 293720088
静态变量s_b地址为： 293720092
字符串常量地址为： 293712091
字符串常量地址为： 293712103
全局常量c_g_a地址为： 293711884
全局常量c_g_b地址为： 293711888
局部常量c_l_a地址为： -235866384
局部常量c_l_b地址为： -235866380
 */