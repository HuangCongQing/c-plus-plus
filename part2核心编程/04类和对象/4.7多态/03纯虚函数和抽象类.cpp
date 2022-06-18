/*
 * @Description: 纯虚函数
 * @Author: HCQ
 * @Company(School): UCAS
 * @Email: 1756260160@qq.com
 * @Date: 2021-04-17 11:24:57
 * @LastEditTime: 2022-06-18 20:01:33
 * @FilePath: \c-plus-plus\part2核心编程\04类和对象\4.7多态\03纯虚函数和抽象类.cpp
 */
#include<iostream>  
using namespace std;

class Base
{
public:
//纯虚函数
//类中只要有一个纯虚函数就称为抽象类
//抽象类无法实例化对象
//子类必须重写父类中的纯虚函数，否则也属于抽象类
virtual void func() = 0; //=======================================
};

class Son :public Base
{
public:
virtual void func() 
 {
 	cout << "func调用" << endl;
 };
};

void test01()
{
 Base * base = NULL;
//base = new Base; // 错误，抽象类无法实例化对象
 base = new Son;
 base->func();
delete base;//记得销毁
}

int main() {

test01();

system("pause");

return 0;
}