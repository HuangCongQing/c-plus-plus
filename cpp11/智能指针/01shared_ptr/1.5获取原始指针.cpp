/*
 * @Description: 
 * @Author: HCQ
 * @Company(School): UCAS
 * @Email: 1756260160@qq.com
 * @Date: 2022-06-21 21:07:54
 * @LastEditTime: 2022-06-21 21:07:56
 * @FilePath: /c-plus-plus/cpp11/智能指针/1.5获取原始指针.cpp
 */

#include <iostream>
#include <string>
#include <memory>
using namespace std;

int main()
{
    int len = 128;
    shared_ptr<char> ptr(new char[len]);
    // 得到指针的原始地址
    char* add = ptr.get();
    memset(add, 0, len);
    strcpy(add, "我是要成为海贼王的男人!!!");
    cout << "string: " << add << endl;
    
    shared_ptr<int> p(new int);
    *p = 100;
    cout << *p.get() << "  " << *p << endl;
    
    return 0;
}
