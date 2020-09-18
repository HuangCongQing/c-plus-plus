/*
 * @Description: 
 * @Author: HCQ
 * @Company(School): UCAS
 * @Date: 2020-09-18 18:20:28
 * @LastEditors: HCQ
 * @LastEditTime: 2020-09-18 19:00:24
 */
#include <iostream>
#include <string>

using namespace std;
// 空对象占用内存为1 
// C++ 编译器占一个内存，为了区分对象占内存的位置
class Person
{
public:
    Person()
    {
        mA = 0;
    }
    //非静态成员变量占对象空间
    int mA;
    //静态成员变量不占对象空间
    static int mB;
    //函数也不占对象空间，所有函数共享一个函数实例
    void func()
    {
        cout << "mA:" << this->mA << endl;
    }
    //静态成员函数也不占对象空间
    static void sfunc()
    {
    }
};
int main()
{
    cout << sizeof(Person) << endl;
    system("pause");
    return 0;
}