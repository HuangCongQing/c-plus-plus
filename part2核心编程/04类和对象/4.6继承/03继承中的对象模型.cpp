/*
 * @Description: 继承中的对象模型
 * @Author: HCQ
 * @Company(School): UCAS
 * @Date: 2020-09-19 19:57:43
 * @LastEditors: Please set LastEditors
 * @LastEditTime: 2022-06-17 23:13:18
 */
#include <iostream>
#include <string>

using namespace std;

class Base
{
public:
    int m_A;

protected:
    int m_B;

private:
    int m_C; //私有成员只是被隐藏了，但是还是会继承下去
};
//公共继承
class Son : public Base
{
public:
    int m_D;
};
void test01()
{
    cout << "sizeof Son = " << sizeof(Son) << endl; // sizeof Son = 16
}
int main()
{
    test01();
    system("pause");
    return 0;
}
