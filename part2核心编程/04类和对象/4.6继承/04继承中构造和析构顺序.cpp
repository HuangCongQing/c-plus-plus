/*
 * @Description: 继承中 先调用父类构造函数，再调用子类构造函数，析构顺序与构造相反
 * @Author: HCQ
 * @Company(School): UCAS
 * @Email: 1756260160@qq.com
 * @Date: 2022-06-18 12:27:47
 * @LastEditTime: 2022-06-18 12:35:46
 * @FilePath: \c-plus-plus\part2核心编程\04类和对象\4.6继承\04继承中构造和析构顺序.cpp
 */
// 继承中 先调用父类构造函数，再调用子类构造函数，析构顺序与构造相反


#include<iostream>
using namespace std;
// 继承中的构造和析构顺序
class Base
{
public:
    Base(){
        cout<<"Base 构造函数"<<endl;
    }
    ~Base(){
        cout<<"Base 析构函数"<<endl;
    }

};
// 子类
class Son:public Base
{
public:
    Son(){
        cout<<"Son 构造函数"<<endl;
    }
    ~Son(){
        cout<<"Son 析构函数"<<endl;
    }

};

void test01()
{
//继承中 先调用父类构造函数，再调用子类构造函数，析构顺序与构造相反
 Son s;
}

int main() {

test01();

system("pause");

return 0;
}

