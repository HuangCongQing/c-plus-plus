/*
 * @Description: 
 * @Author: HCQ
 * @Company(School): UCAS
 * @Email: 1756260160@qq.com
 * @Date: 2021-05-11 15:02:08
 * @LastEditTime: 2021-05-11 15:33:16
 * @FilePath: /c-plus-plus/Part3C++提高编程_泛化编程_STL/03STL-常用容器/3.1string/05string容器_字符串比较.cpp
 */
#include<iostream>
using namespace std;

//字符串比较

void test01()
{
	string str1 = "hello";
	string str2 = "xello";

	if (str1.compare(str2) == 0)
	{
		cout << "str1 等于 str2" << endl;
	}
	else if (str1.compare(str2) > 0)
	{
		cout << "str1 大于 str2" << endl;
	}
	else
	{
		cout << "str1 小于 str2" << endl;
	}

}

int main() {

	test01();

	system("pause");

	return 0;
}