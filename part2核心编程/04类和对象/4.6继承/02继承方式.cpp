/*
 * @Description: 
 * @Author: HCQ
 * @Company(School): UCAS
 * @Date: 2020-09-19 19:16:35
 * @LastEditors: HCQ
 * @LastEditTime: 2020-09-19 19:55:50
 */
#include <iostream>
#include <string>

using namespace std;
class Base1
{
public:
    int m_A;

protected:
    int m_B;

private:
    int m_C;
};
//公共继承
class Son1 : public Base1
{
public:
    void func()
    {
        m_A; //可访问 public权限
        m_B; //可访问 protected权限
             //m_C; //不可访问
    }
};
void myClass()
{
    Son1 s1;
    s1.m_A; //其他类只能访问到公共权限
}
//保护继承
class Base2
{
public:
    int m_A;

protected:
    int m_B;

private:
    int m_C;
};
class Son2 : protected Base2
{
public:
    void func()
    {
        m_A; //可访问 protected权限
        m_B; //可访问 protected权限
             //m_C; //不可访问(父类中私有成员，子类访问不到)
    }
};
void myClass2()
{
    Son2 s;
    //s.m_A; //不可访问
}
//私有继承
class Base3
{
public:
    int m_A;

protected:
    int m_B;

private:
    int m_C;
};
class Son3 : private Base3
{
public:
    void func()
    {
        m_A; //可访问 private权限
        m_B; //可访问 private权限
             //m_C; //不可访问
    }
};
class GrandSon3 : public Son3
{
public:
    void func()
    {
        //Son3是私有继承，所以继承Son3的属性在GrandSon3中都无法访问到
        //m_A;
        //m_B;
        //m_C;
    }
};