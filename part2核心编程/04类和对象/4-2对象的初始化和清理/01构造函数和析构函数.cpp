/*
 * @Description: 
 * @Author: HCQ
 * @Company(School): UCAS
 * @Date: 2020-09-18 10:39:27
 * @LastEditors: HCQ
 * @LastEditTime: 2020-09-18 10:44:58
 */
#include <iostream>
#include <string>

using namespace std;

class Person
{
public:
    //构造函数
    Person()
    {
        cout << "Person的构造函数调用" << endl;
    }
    //析构函数
    ~Person()
    {
        cout << "Person的析构函数调用" << endl;
    }
};
void test01()
{
    Person p; // 栈上的数据（局部变量
}
int main()
{

    test01();
    // Person p; // 按了任意键之后 析构才会出现
    system("pause");
    return 0;
}