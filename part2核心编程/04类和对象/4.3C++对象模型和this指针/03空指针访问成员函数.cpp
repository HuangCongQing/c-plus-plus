/*
 * @Description: 
 * @Author: HCQ
 * @Company(School): UCAS
 * @Date: 2020-09-18 19:19:23
 * @LastEditors: HCQ
 * @LastEditTime: 2020-09-18 19:27:24
 */


#include <iostream>
#include <string>

using namespace std;

//空指针访问成员函数
class Person
{
public:
    void ShowClassName()
    {
        cout << "我是Person类!" << endl;
    }
    void ShowPerson()
    { 
        // 防止传空指针
        if (this == NULL)
        {
            return;
        }
        cout << mAge << endl;
    }

public:
    int mAge;
};
void test01()
{
    // 创建个空指针
    Person *p = NULL;
    p->ShowClassName(); //空指针，可以调用成员函数
    p->ShowPerson();    //但是如果成员函数中用到了this指针，就不可以了
}
int main()
{
    test01();
    system("pause");
    return 0;
}