/*
 * @Description: 
 * @Author: HCQ
 * @Company(School): UCAS
 * @Email: 1756260160@qq.com
 * @Date: 2021-04-21 10:00:48
 * @LastEditTime: 2021-04-21 16:05:05
 * @FilePath: /c-plus-plus/Part3C++提高编程_泛化编程_STL/03STL-常用容器/3.2vector/06vector容器_互换容器.cpp
 */
#include<iostream>
using namespace std;
#include <vector>

//vector容器互换

void printVector(vector<int>&v)
{
	for (vector<int>::iterator it = v.begin(); it != v.end(); it++)
	{
		cout << *it << " ";
	}
	cout << endl;
}

//1、基本使用
void test01()
{
	vector<int>v1;
	for (int i = 0; i < 10; i++)
	{
		v1.push_back(i);
	}

	cout << "交换前： " << endl;
	printVector(v1);

	vector<int>v2;
	for (int i = 10; i > 0; i--)
	{
		v2.push_back(i);
	}
	printVector(v2);


	cout << "交换后： " << endl;
	v1.swap(v2);
	printVector(v1);
	printVector(v2);

}

//2、实际用途
//巧用swap可以收缩内存空间
void test02()
{
	vector<int>v;
	for (int i = 0; i < 100000; i++)
	{
		v.push_back(i);
	}

	cout << "v的容量为： " << v.capacity() << endl; // v的容量为： 131072
	cout << "v的大小为： " << v.size() << endl; // v的大小为： 100000


	v.resize(3); //重新指定大小(但容量没有改变)
	cout << "v的容量为： " << v.capacity() << endl;  // v的容量为： 131072
	cout << "v的大小为： " << v.size() << endl;  // v的大小为： 3

	//巧用swap收缩内存
	vector<int>(v).swap(v); 

	cout << "v的容量为： " << v.capacity() << endl;
	cout << "v的大小为： " << v.size() << endl;
}

int main() {

	//test01();

	test02();

	system("pause");

	return 0;
}