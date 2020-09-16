/*
 * @Description: 
 * @Author: HCQ
 * @Company(School): UCAS
 * @Date: 2020-09-16 20:42:10
 * @LastEditors: HCQ
 * @LastEditTime: 2020-09-16 20:42:38
 */
#include <iostream>
#include <string>

using namespace std;

//三种权限
//公共权限  public     类内可以访问  类外可以访问
//保护权限  protected  类内可以访问  类外不可以访问
//私有权限  private    类内可以访问  类外不可以访问
class Person
{
    //姓名  公共权限
public:
    string m_Name;
    //汽车  保护权限
protected:
    string m_Car;
    //银行卡密码  私有权限
private:
    int m_Password;

public:
    void func()
    {
        m_Name = "张三";
        m_Car = "拖拉机";
        m_Password = 123456;
    }
};
int main()
{
    Person p;
    p.m_Name = "李四";
    //p.m_Car = "奔驰";  //保护权限类外访问不到
    //p.m_Password = 123; //私有权限类外访问不到
    system("pause");
    return 0;
}