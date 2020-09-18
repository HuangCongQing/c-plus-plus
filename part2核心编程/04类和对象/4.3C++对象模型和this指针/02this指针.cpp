/*
 * @Description: 
 * @Author: HCQ
 * @Company(School): UCAS
 * @Date: 2020-09-18 19:10:36
 * @LastEditors: HCQ
 * @LastEditTime: 2020-09-18 19:16:32
 */
#include <iostream>
#include <string>

using namespace std;

class Person
{
public:
    Person(int age)
    {
        //1、当形参和成员变量同名时，可用this指针来区分
        this->age = age;
    }
    Person& PersonAddPerson(Person p)
    {
        this->age += p.age;
        //返回对象本身
        // this指向p2的指针，而*this指向的就是p2这个对象本体
        return *this;
    }
    int age;
};
void test01()
{
    Person p1(10);
    cout << "p1.age = " << p1.age << endl;
    Person p2(10);
    // 链式编程思想
    p2.PersonAddPerson(p1).PersonAddPerson(p1).PersonAddPerson(p1);
    cout << "p2.age = " << p2.age << endl;
}
int main()
{
    test01();
    system("pause");
    return 0;
}