/*
 * @Description: 
 * @Author: HCQ
 * @Company(School): UCAS
 * @Email: 1756260160@qq.com
 * @Date: 2021-04-17 14:38:13
 * @LastEditTime: 2021-04-21 10:18:49
 * @FilePath: /c-plus-plus/Part3C++提高编程_泛化编程_STL/03STL-常用容器/3.2vector/01vector容器_构造函数.cpp
 */
#include<iostream>
using namespace std;
#include<vector>

void printVector(vector<int>&v)
{
	for (vector<int>::iterator it = v.begin(); it != v.end(); it++)
	{
		cout << *it << " ";
	}
	cout << endl;
}

//vector容器构造
void test01()
{
	vector<int>v1; //1 默认构造 无参构造

	for (int i = 0; i < 10; i++)
	{
		v1.push_back(i);
	}

	printVector(v1);

	//2 通过区间方式进行构造
	vector<int>v2(v1.begin(), v1.end());
	printVector(v2);

	//3. n个elem方式构造
	vector<int>v3(10, 100);
	printVector(v3);

	//4 拷贝构造
	vector<int>v4(v3);
	printVector(v4);
}

int main() {

	test01();

	// system("pause");

	return 0;
}