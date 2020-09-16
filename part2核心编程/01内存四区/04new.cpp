/*
 * @Description: 
 * @Author: HCQ
 * @Company(School): UCAS
 * @Date: 2020-06-10 11:40:00
 * @LastEditors: HCQ
 * @LastEditTime: 2020-06-10 11:41:03
 */ 
#include <iostream>
using namespace std;

int *func()
{
    int *a = new int(10);
    return a;
}
int main()
{
    int *p = func();
    cout << *p << endl;
    cout << *p << endl;
    //利用delete释放堆区数据
    delete p;
    //cout << *p << endl; //报错，释放的空间不可访问
    system("pause");
    return 0;
}