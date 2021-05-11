/*
 * @Description: 
 * @Author: HCQ
 * @Company(School): UCAS
 * @Email: 1756260160@qq.com
 * @Date: 2021-05-11 15:02:08
 * @LastEditTime: 2021-05-11 15:38:25
 * @FilePath: /c-plus-plus/Part3C++提高编程_泛化编程_STL/03STL-常用容器/3.1string/07string容器_插入和删除.cpp
 */
#include<iostream>
using namespace std;
#include <string>

//字符串 插入和删除
void test01()
{
	string str = "hello";

	//插入
	str.insert(1, "111");
	//h111ello
	cout << "str = " << str << endl;

	//删除
	str.erase(1, 3); // 包括3
	cout << "str = " << str << endl;
}

int main() {

	test01();

	system("pause");

	return 0;
}