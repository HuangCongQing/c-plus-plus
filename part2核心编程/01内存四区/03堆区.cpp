/*
 * @Description: 
 * @Author: HCQ
 * @Company(School): UCAS
 * @Date: 2020-06-10 11:28:16
 * @LastEditors: HCQ
 * @LastEditTime: 2020-06-10 11:28:38
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

    system("pause");
    return 0;
}