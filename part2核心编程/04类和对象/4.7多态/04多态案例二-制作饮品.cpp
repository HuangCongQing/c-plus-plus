/*
 * @Description: 纯虚函数使用
 * @Author: HCQ
 * @Company(School): UCAS
 * @Email: 1756260160@qq.com
 * @Date: 2022-06-18 20:08:38
 * @LastEditTime: 2022-06-18 20:13:15
 * @FilePath: \c-plus-plus\part2核心编程\04类和对象\4.7多态\04多态案例二-制作饮品.cpp
 */


#include<iostream>  
using namespace std;

//抽象制作饮品
class AbstractDrinking {
public:
//烧水
virtual void Boil() = 0;
//冲泡
virtual void Brew() = 0;
//倒入杯中
virtual void PourInCup() = 0;
//加入辅料
virtual void PutSomething() = 0;
//规定流程
void MakeDrink() {
 	Boil();
 	Brew();
 	PourInCup();
 	PutSomething();
 }
};

//制作咖啡
class Coffee : public AbstractDrinking {
public:
//烧水
virtual void Boil() {
 	cout << "煮农夫山泉!" << endl;
 }
//冲泡
virtual void Brew() {
 	cout << "冲泡咖啡!" << endl;
 }
//倒入杯中
virtual void PourInCup() {
 	cout << "将咖啡倒入杯中!" << endl;
 }
//加入辅料
virtual void PutSomething() {
 	cout << "加入牛奶!" << endl;
 }
};

//制作茶水
class Tea : public AbstractDrinking {
public:
//烧水
virtual void Boil() {
 	cout << "煮自来水!" << endl;
 }
//冲泡
virtual void Brew() {
 	cout << "冲泡茶叶!" << endl;
 }
//倒入杯中
virtual void PourInCup() {
 	cout << "将茶水倒入杯中!" << endl;
 }
//加入辅料
virtual void PutSomething() {
 	cout << "加入枸杞!" << endl;
 }
};

//业务函数=============================================
void DoWork(AbstractDrinking* drink) {  //  AbstractDrinking* drink  =Coffee
 drink->MakeDrink();
delete drink;
}

void test01() {
DoWork(new Coffee);
 cout << "--------------" << endl;
DoWork(new Tea);
}


int main() {

test01();

system("pause");

return 0;
}