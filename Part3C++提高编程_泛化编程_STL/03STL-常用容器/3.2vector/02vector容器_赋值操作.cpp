/*
 * @Description:   赋值：assign()
 * @Author: HCQ
 * @Company(School): UCAS
 * @Email: 1756260160@qq.com
 * @Date: 2021-04-21 10:00:48
 * @LastEditTime: 2021-04-21 15:18:58
 * @FilePath: /c-plus-plus/Part3C++提高编程_泛化编程_STL/03STL-常用容器/3.2vector/02vector容器_赋值操作.cpp
 */
#include<iostream>
using namespace std;
#include <vector>

void printVector(vector<int>& v)
{
	for(vector<int>::iterator it =v.begin(); it!=v.end();it++){
		cout << *it << " ";
	}
	cout << endl;
}

//vector赋值
void test01()
{
	vector<int>v1;
	for (int i = 0; i < 10; i++)
	{
		v1.push_back(i);
	}
	printVector(v1);

	//赋值   operator=
	vector <int>v2;
	v2 = v1;
	printVector(v2);

	// assign
	vector<int>v3;
	v3.assign(v1.begin(), v1.end());
	printVector(v3);

	//n个elem 方式赋值
	vector<int>v4;
	v4.assign(10, 100);
	printVector(v4);
}

int main() {

	test01();

	// system("pause");

	return 0;
}