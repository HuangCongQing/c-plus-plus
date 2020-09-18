/*
 * @Description: 
 * @Author: HCQ
 * @Company(School): UCAS
 * @Date: 2020-09-18 10:54:43
 * @LastEditors: HCQ
 * @LastEditTime: 2020-09-18 10:55:12
 */
#include <iostream>
#include <string>

using namespace std;

class Person
{
public:
    Person()
    {
        cout << "无参构造函数!" << endl;
        mAge = 0;
    }
    Person(int age)
    {
        cout << "有参构造函数!" << endl;
        mAge = age;
    }
    Person(const Person &p)
    {
        cout << "拷贝构造函数!" << endl;
        mAge = p.mAge;
    }
    //析构函数在释放内存之前调用
    ~Person()
    {
        cout << "析构函数!" << endl;
    }

public:
    int mAge;
};
//1. 使用一个已经创建完毕的对象来初始化一个新对象
void test01()
{
    Person man(100);      //p对象已经创建完毕
    Person newman(man);   //调用拷贝构造函数
    Person newman2 = man; //拷贝构造
    //Person newman3;
    //newman3 = man; //不是调用拷贝构造函数，赋值操作
}
//2. 值传递的方式给函数参数传值
//相当于Person p1 = p;
void doWork(Person p1) {}
void test02()
{
    Person p; //无参构造函数
    doWork(p);
}
//3. 以值方式返回局部对象
Person doWork2()
{
    Person p1;
    cout << (int *)&p1 << endl;
    return p1;
}
void test03()
{
    Person p = doWork2();
    cout << (int *)&p << endl;
}
int main()
{
    //test01();
    //test02();
    test03();
    system("pause");
    return 0;
}