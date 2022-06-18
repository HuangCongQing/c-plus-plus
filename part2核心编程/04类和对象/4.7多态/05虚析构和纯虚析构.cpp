/*
 * @Description: 虚析构和纯虚析构 virtual ~Animal() = 0; 虚析构函数就是用来解决通过父类指针释放子类对象
 * @Author: HCQ
 * @Company(School): UCAS
 * @Email: 1756260160@qq.com
 * @Date: 2021-04-17 11:24:57
 * @LastEditTime: 2022-06-18 20:34:26
 * @FilePath: \c-plus-plus\part2核心编程\04类和对象\4.7多态\05虚析构和纯虚析构.cpp
 */
#include <iostream>
using namespace std;

// 虚析构和纯虚析构
class Animal
{
public:
    Animal()
    {
        cout << "Animal 构造函数调用！" << endl;
    }
    virtual void Speak() = 0;

    //析构函数加上virtual关键字，变成虚析构函数
    // virtual ~Animal()
    //{
    //	cout << "Animal虚析构函数调用！" << endl;
    //}

    virtual ~Animal() = 0; // ==============================================
};

Animal::~Animal()
{
    cout << "Animal 纯虚析构函数调用！" << endl;
}

//和包含普通纯虚函数的类一样，包含了纯虚析构函数的类也是一个抽象类。不能够被实例化。

class Cat : public Animal
{
public:
    Cat(string name)
    {
        cout << "Cat构造函数调用！" << endl;
        m_Name = new string(name);
    }
    virtual void Speak()
    {
        cout << *m_Name << "小猫在说话!" << endl;
    }
    ~Cat()
    {
        cout << "Cat析构函数调用!" << endl; // 结束清除堆区=================================================================
        if (this->m_Name != NULL)
        {
            delete m_Name;
            m_Name = NULL;
        }
    }

public:
    string *m_Name;
};

void test01()
{
    Animal *animal = new Cat("Tom");
    animal->Speak();

    //通过父类指针去释放，会导致子类对象可能清理不干净，造成内存泄漏
    //怎么解决？给基类增加一个虚析构函数
    //虚析构函数就是用来解决通过父类指针释放子类对象
    delete animal;
}

int main()
{

    test01();

    system("pause");

    return 0;
}