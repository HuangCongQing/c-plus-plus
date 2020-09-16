/*
 * @Description: 
 * @Author: HCQ
 * @Company(School): UCAS
 * @Date: 2020-09-16 19:54:10
 * @LastEditors: HCQ
 * @LastEditTime: 2020-09-16 19:54:30
 */
#include <iostream>
using namespace std;

//函数占位参数 ，占位参数也可以有默认参数
void func(int a, int)
{
    cout << "this is func" << endl;
}
int main()
{
    func(10, 10); //占位参数必须填补
    system("pause");
    return 0;
}