/*
 * @Description: 
 * @Author: HCQ
 * @Company(School): UCAS
 * @Date: 2020-09-16 17:31:48
 * @LastEditors: HCQ
 * @LastEditTime: 2020-09-16 18:03:03
 */
#include <iostream>
using namespace std;

//返回局部变量引用
int &test01()
{
    int a = 10; //局部变量
    return a;
}
//返回静态变量引用
int &test02()
{
    static int a = 20; // 静态变量存放在全局区，最后、程序结束后才释放掉
    return a;
}
int main()
{
    //不能返回局部变量的引用
    int &ref = test01();
    cout << "ref = " << ref << endl;// 第一次结果正确，是因为编译器做了保留
    cout << "ref = " << ref << endl; // 第二次结果错误，是因为a的内存已经释放
    //如果函数做左值，那么必须返回引用
    int &ref2 = test02();
    cout << "ref2 = " << ref2 << endl;
    cout << "ref2 = " << ref2 << endl;
    test02() = 1000; //  如果函数的返回值是引用，这个函数调用可以作为左值
    cout << "ref2 = " << ref2 << endl;
    cout << "ref2 = " << ref2 << endl;
    system("pause");
    return 0;
}
