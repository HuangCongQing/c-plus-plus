/*
 * @Description: 
 * @Author: HCQ
 * @Company(School): UCAS
 * @Date: 2020-09-18 11:57:17
 * @LastEditors: HCQ
 * @LastEditTime: 2020-09-18 11:57:48
 */
#include <iostream>
#include <string>

using namespace std;

class Person
{
public:
    ////传统方式初始化
    //Person(int a, int b, int c) {
    //	m_A = a;
    //	m_B = b;
    //	m_C = c;
    //}
    //初始化列表方式初始化
    Person(int a, int b, int c) : m_A(a), m_B(b), m_C(c) {}
    void PrintPerson()
    {
        cout << "mA:" << m_A << endl;
        cout << "mB:" << m_B << endl;
        cout << "mC:" << m_C << endl;
    }

private:
    int m_A;
    int m_B;
    int m_C;
};
int main()
{
    Person p(1, 2, 3);
    p.PrintPerson();
    system("pause");
    return 0;
}
