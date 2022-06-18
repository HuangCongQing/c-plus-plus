/*
 * @Description: 函数前面加上virtual关键字，变成虚函数，那么编译器在编译的时候就不能确定函数调用了。
//我们希望传入什么对象，那么就调用什么对象的函数
//如果函数地址在编译阶段就能确定，那么静态联编
//如果函数地址在运行阶段才能确定，就是动态联编
 * @Author: HCQ
 * @Company(School): UCAS
 * @Date: 2020-09-19 20:06:51
 * @LastEditors: Please set LastEditors
 * @LastEditTime: 2022-06-18 12:51:28
 */
#include <iostream>
#include <string>

using namespace std;

class Animal
{
public:
    //Speak函数就是虚函数
    //函数前面加上virtual关键字，变成虚函数，那么编译器在编译的时候就不能确定函数调用了。
    virtual void speak()
    {
        cout << "动物在说话" << endl;
    }
};
class Cat : public Animal
{
public:
    void speak()
    {
        cout << "小猫在说话" << endl;
    }
};
class Dog : public Animal
{
public:
    void speak()
    {
        cout << "小狗在说话" << endl;
    }
};
//我们希望传入什么对象，那么就调用什么对象的函数
//如果函数地址在编译阶段就能确定，那么静态联编
//如果函数地址在运行阶段才能确定，就是动态联编
void DoSpeak(Animal &animal)
{
    animal.speak();
}
//
//多态满足条件：
//1、有继承关系
//2、子类重写父类中的虚函数
//多态使用：
//父类指针或引用指向子类对象
void test01()
{
    Cat cat;
    DoSpeak(cat);
    Dog dog;
    DoSpeak(dog);
}
int main()
{
    test01();
    system("pause");
    return 0;
}
