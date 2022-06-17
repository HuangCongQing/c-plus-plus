/*
 * @Description: 
 * @Author: HCQ
 * @Company(School): UCAS
 * @Date: 2020-09-18 20:23:52
 * @LastEditors: Please set LastEditors
 * @LastEditTime: 2022-06-17 23:06:00
 */
#include <iostream>
#include <string>

using namespace std;

class Building;
// 
class goodGay
{
public:
    goodGay();
    void visit(); // 访问building属性

private:
    Building *building;
};

// 
class Building
{
    //告诉编译器 goodGay类是Building类的好朋友，可以访问到Building类中私有内容
    friend class goodGay;

public:
    Building();

public:
    string m_SittingRoom; //客厅
private:
    string m_BedRoom; //卧室
};
// 类外写成员函数
Building::Building()
{
    this->m_SittingRoom = "客厅";
    this->m_BedRoom = "卧室";
}
goodGay::goodGay()
{
    building = new Building;
}
void goodGay::visit()
{
    cout << "好基友正在访问" << building->m_SittingRoom << endl;
    cout << "好基友正在访问" << building->m_BedRoom << endl;
}
void test01()
{
    goodGay gg;
    gg.visit();
}
int main()
{
    test01();
    system("pause");
    return 0;
}