/*
 * @Description: 
 * @Author: HCQ
 * @Company(School): UCAS
 * @Date: 2020-09-16 17:08:12
 * @LastEditors: HCQ
 * @LastEditTime: 2020-09-16 17:15:48
 */
#include <iostream>
using namespace std;

int main(){
    // 引用基本类型
    // 数据类型 &别名 = 原名
    int a = 10;
    // 创建引用
    int &b = a;
    cout << "a=" << a << endl;
    cout << "b=" << b << endl;

    b = 100;
    cout << "a=" << a << endl;
    cout << "b=" << b << endl;

    system("pause"); // 请按任意键继续. . .

    return 0;
}
