/*
 * @Description: 
 * @Author: HCQ
 * @Company(School): UCAS
 * @Email: 1756260160@qq.com
 * @Date: 2021-05-11 15:02:08
 * @LastEditTime: 2021-05-11 15:43:03
 * @FilePath: /c-plus-plus/Part3C++提高编程_泛化编程_STL/03STL-常用容器/3.1string/06string容器_字符存取.cpp
 */
#include<iostream>
using namespace std;
#include <string>
//string 字符存取
void test01()
{
	string str = "hello";

	//cout << "str = " << str << endl;

	//1、通过 []访问单个字符
	for (int i = 0; i < str.size(); i++)
	{
		cout << str[i] << " ";
	}
	cout << endl;

	//2、通过at方式访问单个字符
	for (int i = 0; i < str.size(); i++)
	{
		cout << str.at(i) << " ";
	}
	cout << endl;

// c++11
for(char ch:str){
        cout << ch<< " ";
    }
    
	cout << endl;

	cout << endl;


	//修改单个字符
	str[0] = 'x';
	// xello
	cout << "str = " << str << endl;

	str.at(1) = 'x';
	// xxllo
	cout << "str = " << str << endl;
}

int main() {

	test01();
	
	system("pause");

	return 0;
}