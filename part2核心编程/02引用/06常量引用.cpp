/*
 * @Description: 加入const，引用使用的场景，通常用来修饰形参
 * @Author: HCQ
 * @Company(School): UCAS
 * @Date: 2020-09-16 18:25:13
 * @LastEditors: Please set LastEditors
 * @LastEditTime: 2022-06-21 12:49:14
 */
#include <iostream>
using namespace std;

//加入const，引用使用的场景，通常用来修饰形参，防止误操作============================================
void showValue(const int& v)
{
    //v += 10;
    cout << v << endl;
}
int main()
{
    //int& ref = 10;  引用本身需要一个合法的内存空间，因此这行错误
    //加入const就可以了，编译器优化代码，int temp = 10; const int& ref = temp;==================================
    const int& ref = 10;
    //ref = 100;  //加入const后只读，不可以修改变量
    cout << ref << endl;
    //函数中利用常量引用防止误操作修改实参
    int a = 10;
    showValue(a);
    system("pause");
    return 0;
}
