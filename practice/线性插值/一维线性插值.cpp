/*
 * @Description: https://blog.csdn.net/shenliu0558/article/details/105729629
 * @Author: HCQ
 * @Company(School): UCAS
 * @Email: 1756260160@qq.com
 * @Date: 2021-05-13 09:57:15
 * @LastEditTime: 2021-05-13 10:04:05
 * @FilePath: /c-plus-plus/practice/线性插值/一维线性插值.cpp
 */

/* 
section: 1 2
1
1.1
1.2
1.3
1.4
1.5
1.6
1.7
1.8
1.9


 */

#include <iostream>

using namespace std;

void test(double a, double b){
    cout << "section: " << a << " " << b << endl;
    const int INSERTPOINTNUMBER = 10;
    double c[INSERTPOINTNUMBER] = {0.0};
    for(int i = 0; i < INSERTPOINTNUMBER; ++i){
        c[i] = (a * (INSERTPOINTNUMBER - i) + b * i) / float(INSERTPOINTNUMBER);
        cout << c[i] << endl;
    }
}


int main()
{
    double a,b;
    a=1.0;
    b=2.0;
    test(a, b);
    return 0;
}

// https://blog.csdn.net/shenliu0558/article/details/105729629