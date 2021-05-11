/*
 * @Description: 
 * @Author: HCQ
 * @Company(School): UCAS
 * @Email: 1756260160@qq.com
 * @Date: 2021-04-17 14:38:12
 * @LastEditTime: 2021-05-11 15:06:22
 * @FilePath: /c-plus-plus/Part3C++提高编程_泛化编程_STL/03STL-常用容器/3.1string/01 string容器_构造函数.cpp
 */
#include<iostream>
using namespace std;
#include <string>
//string的构造函数

/*
- string();          				//创建一个空的字符串 例如: string str;
 string(const char* s);	        //使用字符串s初始化
- string(const string& str);       //使用一个string对象初始化另一个string对象
- string(int n, char c);           //使用n个字符c初始化
*/

void test01()
{
	string s1; //默认构造

	const char * str = "hello world";
	string s2(str);

	cout << "s2 = " << s2 << endl;

	string s3(s2);
	cout << "s3 = " << s3 << endl;

	string s4(10, 'a');
	cout << "s4 = " << s4 << endl;
}

int main() {

	test01();

	return 0;
}