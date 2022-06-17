/*
 * @Description: 
 * @Author: HCQ
 * @Company(School): UCAS
 * @Date: 2020-09-18 10:46:13
 * @LastEditors: Please set LastEditors
 * @LastEditTime: 2022-06-17 22:49:50
 */
#include <iostream>
#include <string>

using namespace std;

//1、构造函数分类
// 按照参数分类分为 有参和无参构造   无参又称为默认构造函数
// 按照类型分类分为 普通构造和拷贝构造
class Person
{
public:
    //无参（默认）构造函数
    Person()
    {
        cout << "无参构造函数!" << endl;
    }
    //有参构造函数
    Person(int a)
    {
        age = a;
        cout << "有参构造函数!" << endl;
    }
    //拷贝构造函数=======================================
    Person(const Person &p)
    {
        // 可以直接调用p有的属性
        age = p.age;
        cout << "拷贝构造函数!" << endl;
    }
    //析构函数
    ~Person()
    {
        cout << "析构函数!" << endl;
    }

public:
    int age;
};
//2、构造函数的调用
//调用无参构造函数
void test01()
{
    Person p; //调用无参构造函数
}
//调用有参的构造函数
void test02()
{
    //2.1  括号法，常用
    Person p1(10);
    //注意1：调用无参构造函数不能加括号，如果加了编译器认为这是一个函数声明
    //Person p2(); 
    //2.2 显式法
    Person p2 = Person(10);
    Person p3 = Person(p2);// 拷贝构造
    //Person(10)单独写就是匿名对象  当前行结束之后，马上析构
    //2.3 隐式转换法
    Person p4 = 10; // Person p4 = Person(10);
    Person p5 = p4; // Person p5 = Person(p4);
    //注意2：不能利用 拷贝构造函数 初始化匿名对象 编译器认为是对象声明
    //Person p5(p4);
}
int main()
{
    test01();
    //test02();
    system("pause");
    return 0;
}
