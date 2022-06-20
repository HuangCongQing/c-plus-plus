/*
 * @Description: 空指针
 * @Author: HCQ
 * @Company(School): UCAS
 * @Email: 1756260160@qq.com
 * @Date: 2021-04-17 11:24:57
 * @LastEditTime: 2022-06-20 16:05:09
 * @FilePath: /c-plus-plus/part1基础/指针/03空指针.cpp
 */
#include<iostream>  
using namespace std;



int main(int argc, char *argv[]) {

    // 空指针
    // 初始化
    int * p = NULL;
    
    // 空指针不可以访问
    //内存编号0 ~255为系统占用内存，不允许用户访问
    *p = 10; // 报错
    
    return 0;
}