/*
 * @Description:  	L1.swap(L2);  // L1 L2互换
 * @Author: HCQ
 * @Company(School): UCAS
 * @Email: 1756260160@qq.com
 * @Date: 2021-04-18 12:39:33
 * @LastEditTime: 2021-04-20 18:20:10
 * @FilePath: /c-plus-plus/Part3C++提高编程_泛化编程_STL/03STL-常用容器/3.1string/02list容器_赋值和交换.cpp
 */
#include<iostream>
using namespace std;
#include <list>

//list容器赋值和交换
void printList(const list<int>&L)
{
	for (list<int>::const_iterator it = L.begin(); it != L.end(); it++)
	{
		cout << *it << " ";
	}
	cout << endl;
}

//赋值
void test01()
{
	list<int>L1;

	L1.push_back(10);
	L1.push_back(20);
	L1.push_back(30);
	L1.push_back(40);

	printList(L1);

	list<int>L2;
	L2 = L1; // operator= 赋值
	printList(L2);


	list<int>L3;
	L3.assign(L2.begin(), L2.end());
	printList(L3);

	list<int>L4;
	L4.assign(10, 100);
	printList(L4);

}

//交换
void test02()
{
	list<int>L1;

	L1.push_back(10);
	L1.push_back(20);
	L1.push_back(30);
	L1.push_back(40);

	list<int>L2;
	L2.assign(10, 100);

	cout << "交换前： " << endl;
	printList(L1);
	printList(L2);

	L1.swap(L2);  // L1 L2互换
	cout << "交换后： " << endl;
	printList(L1);
	printList(L2);
}

int main() {

	//test01();
	test02();

	// system("pause");

	return 0;
}