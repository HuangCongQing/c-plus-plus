/*
 * @Description: 
 * @Author: HCQ
 * @Company(School): UCAS
 * @Date: 2020-09-16 21:35:48
 * @LastEditors: HCQ
 * @LastEditTime: 2020-09-16 21:44:04
 */
#include <iostream>
#include <string>

using namespace std;

// 优点1：将所有成员属性设置为私有，可以自己控制读写权限
// 优点2：对于写权限，我们可以检测数据的有效性

class Person
{
public:
    //姓名设置可读可写
    void setName(string name)
    {
        m_Name = name;
    }
    string getName()
    {
        return m_Name;
    }
    //获取年龄
    int getAge()
    {
        return m_Age;
    }
    //设置年龄
    void setAge(int age)
    {
        if (age < 0 || age > 150) // 设年龄范围
        {
            cout << "你个老妖精!" << endl;
            return;
        }
        m_Age = age;
    }
    //情人设置为只写
    void setLover(string lover)
    {
        m_Lover = lover;
    }

private:
    string m_Name; //可读可写  姓名

    int m_Age;      //只读  年龄
    string m_Lover; //只写  情人
};
int main()
{
    Person p;
    //姓名设置
    p.setName("张三");
    cout << "姓名： " << p.getName() << endl;
    //年龄设置
    p.setAge(50);
    cout << "年龄： " << p.getAge() << endl;
    //情人设置
    p.setLover("苍井");
    //cout << "情人： " << p.m_Lover << endl;  //只写属性，不可以读取
    system("pause");
    return 0;
}