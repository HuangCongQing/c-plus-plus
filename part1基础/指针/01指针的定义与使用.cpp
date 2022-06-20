/*
 * @Description: 
 * @Author: HCQ
 * @Company(School): UCAS
 * @Date: 2020-06-02 23:58:42
 * @LastEditors: Please set LastEditors
 * @LastEditTime: 2022-06-20 15:49:15
 */

#include <iostream>
#include <string.h>
using namespace std;

int main()
{

    //1、指针的定义
    int a = 10; //定义整型变量a

    //指针定义语法： 数据类型 * 变量名 ;
    int *p;

    //指针变量赋值
    p = &a;             //指针指向变量a的地址
    cout << &a << endl; //打印数据a的地址  0x7ffed5b416ac
    cout << p << endl;  //打印指针变量p  0x7ffed5b416ac

    //2、指针的使用
    //通过*操作指针变量指向的内存
    cout << "*p = " << *p << endl; // *p = 10

    system("pause");

    return 0;
}