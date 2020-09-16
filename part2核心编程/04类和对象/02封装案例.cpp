/*
 * @Description: 
 * @Author: HCQ
 * @Company(School): UCAS
 * @Date: 2020-09-16 20:26:40
 * @LastEditors: HCQ
 * @LastEditTime: 2020-09-16 20:40:58
 */

#include <iostream>
#include <string>

using namespace std;

// 示例2：设计一个学生类，属性有姓名和学号，可以给姓名和学号赋值，可以显示学生的姓名和学号
//学生类
class Student
{
public:
    void setName(string name)
    {
        m_name = name;
    }
    void setID(int id)
    {
        m_id = id;
    }
    void showStudent()
    {
        cout << "name:" << m_name << " ID:" << m_id << endl;
    }

public:
    string m_name;
    int m_id;
};
int main()
{
    Student stu;
    stu.setName("德玛西亚");
    stu.setID(250);
    stu.showStudent();
    system("pause");
    return 0;
}