/*
 * @Description: 引用传递 总结：通过引用参数产生的效果同按地址传递是一样的。引用的语法更清楚简单
 * @Author: HCQ
 * @Company(School): UCAS
 * @Date: 2020-09-16 17:31:48
 * @LastEditors: Please set LastEditors
 * @LastEditTime: 2022-06-21 12:22:46
 */
#include <iostream>
using namespace std;

//1. 值传递
void mySwap01(int a, int b)
{
    int temp = a;
    a = b;
    b = temp;
}
//2. 地址传递
void mySwap02(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}
//3. 引用传递===============================================================
void mySwap03(int &a, int &b)
{
    int temp = a;
    a = b;
    b = temp;
}
int main()
{
    int a = 10;
    int b = 20;
    mySwap01(a, b);
    cout << "a:" << a << " b:" << b << endl;
    mySwap02(&a, &b);
    cout << "a:" << a << " b:" << b << endl;
    mySwap03(a, b); // 总结：通过引用参数产生的效果同按地址传递是一样的。引用的语法更清楚简单
    cout << "a:" << a << " b:" << b << endl;
    system("pause");
    return 0;
}
/* 
a:10 b:20
a:20 b:10
a:10 b:20
 */