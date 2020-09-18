/*
 * @Description: 
 * @Author: HCQ
 * @Company(School): UCAS
 * @Date: 2020-09-17 10:55:15
 * @LastEditors: HCQ
 * @LastEditTime: 2020-09-17 12:06:01
 */
#include <iostream>
using namespace std;

// 设计立方体类(Cube)
// 求出立方体的面积和体积
// 分别用全局函数和成员函数判断两个立方体是否相等。

class Cube
{
public:
    // 设置长
    void setL(int l)
    {
        m_L = l;
    }
    // 获取长
    int getL()
    {
        return m_L;
    }
    // 设置宽

    void setW(int w)
    {
        m_W = w;
    }
    // 获取宽

    int getW()
    {
        return m_W;
    }
    // 设置高

    void setH(int h)
    {
        m_H = h;
    }
    // 获取高

    int getH()
    {
        return m_H;
    }
    // 获取面积
    int calculateS()
    {
        return 2 * (m_H * m_L + m_H * m_W + m_W * m_L);
    }
    // 获取体积
    int calculateV()
    {
        return m_H * m_L * m_W;
    }
    // 成员函数判断两个立方体是否相等
    bool isSameByClass(Cube &c){
        if (m_H == c.getH() && m_W == c.getW() && m_L== c.getL())
        {
            return true;
        }
        return false;
    }

private:
    int m_L;
    int m_W;
    int m_H;
};

// 利用全局函数判断两个立方体是否相等
bool isSame(Cube &c1, Cube &c2)
{
    if (c1.getH() == c2.getH() && c1.getW() == c2.getW() && c1.getL() == c2.getL())
    {
        return true;
    }
    return false;
};

int main()
{
    // 创建立方体
    Cube c1;
    c1.setH(10);
    c1.setW(10);
    c1.setL(10);
    cout << "面积：" << c1.calculateS() << endl;
    cout << "体积：" << c1.calculateV() << endl;
    // 创建第二个立方体
    Cube c2;
    c2.setH(10);
    c2.setW(10);
    c2.setL(10);

    bool ret = isSame(c1, c2);
    if (ret)
    {
        cout << "全局函数判断：c1 c2 are equal" << endl;
    }
    else
    {
        cout << "全局函数判断：not equal" << endl;
    }
    // 利用全局函数判断
    ret = c1.isSameByClass(c2);
    if (ret)
    {
        cout << "成员函数判断：c1 c2 are equal" << endl;
    }
    else
    {
        cout << "成员函数判断：not equal" << endl;
    }
    system("pause");
    return 0;
}