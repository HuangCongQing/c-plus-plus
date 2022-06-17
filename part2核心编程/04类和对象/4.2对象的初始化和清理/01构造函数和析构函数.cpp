/*
 * @Description: 构造函数(初始化）和析构函数（清理）https://www.yuque.com/huangzhongqing/lang/wixs4k#olpLc
 * @Author: HCQ
 * @Company(School): UCAS
 * @Date: 2020-09-18 10:39:27
 * @LastEditors: Please set LastEditors
 * @LastEditTime: 2022-06-17 22:43:10
 */
#include <iostream>
#include <string>

using namespace std;

class Person
{
public:
    //构造函数 初始化的时候使用
    Person()
    {
        cout << "Person的构造函数调用" << endl;
    }
    //析构函数 销毁的时候调用
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