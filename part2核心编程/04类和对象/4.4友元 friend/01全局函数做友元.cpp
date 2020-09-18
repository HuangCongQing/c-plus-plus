/*
 * @Description: 
 * @Author: HCQ
 * @Company(School): UCAS
 * @Date: 2020-09-18 20:23:35
 * @LastEditors: HCQ
 * @LastEditTime: 2020-09-18 20:31:24
 */
#include <iostream>
#include <string>

using namespace std;

class Building
{
    //告诉编译器 goodGay全局函数 是 Building类的好朋友，可以访问Building中的私有内容
    friend void goodGay(Building *building);

public:
    Building()
    {
        this->m_SittingRoom = "客厅";
        this->m_BedRoom = "卧室";
    }

public:
    string m_SittingRoom; //客厅
private:
    string m_BedRoom; //卧室
};
void goodGay(Building *building)
{
    cout << "好基友正在访问： " << building->m_SittingRoom << endl;
    cout << "好基友正在访问： " << building->m_BedRoom << endl;
}
void test01()
{
    Building b;
    goodGay(&b);
}
int main()
{
    test01();
    system("pause");
    return 0;
}