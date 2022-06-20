/*
 * @Description: 32位 4个字节，64位操作系统8个字节
 * @Author: HCQ
 * @Company(School): UCAS
 * @Email: 1756260160@qq.com
 * @Date: 2021-04-17 11:24:57
 * @LastEditTime: 2022-06-20 15:58:45
 * @FilePath: /c-plus-plus/part1基础/指针/02指针所占内存空间.cpp
 */
#include<iostream>  
using namespace std;


int main() {

	int a = 10;

	int * p;
	p = &a; //指针指向数据a的地址

	cout << *p << endl; //* 解引用  10
	cout << sizeof(p) << endl; // 8
	cout << sizeof(char *) << endl;// 8
	cout << sizeof(float *) << endl;// 8
	cout << sizeof(double *) << endl;// 8

	system("pause");

	return 0;
}