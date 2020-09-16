/*
 * @Description: 
 * @Author: HCQ
 * @Company(School): UCAS
 * @Date: 2020-09-16 19:55:07
 * @LastEditors: HCQ
 * @LastEditTime: 2020-09-16 19:56:06
 */
#include<iostream>
using namespace std;

//函数重载需要函数都在同一个作用域下
void func()
{
    cout << "func 的调用！" << endl;
}
void func(int a)
{
    cout << "func (int a) 的调用！" << endl;
}
void func(double a)
{
    cout << "func (double a)的调用！" << endl;
}
void func(int a, double b)
{
    cout << "func (int a ,double b) 的调用！" << endl;
}
void func(double a, int b)
{
    cout << "func (double a ,int b)的调用！" << endl;
}
//函数返回值不可以作为函数重载条件
//int func(double a, int b)
//{
//	cout << "func (double a ,int b)的调用！" << endl;
//}
int main()
{
    func();
    func(10);
    func(3.14);
    func(10, 3.14);
    func(3.14, 10);

    system("pause");
    return 0;
}