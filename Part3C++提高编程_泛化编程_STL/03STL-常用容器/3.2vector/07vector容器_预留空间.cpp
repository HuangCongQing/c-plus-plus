/*
 * @Description: 
 * @Author: HCQ
 * @Company(School): UCAS
 * @Email: 1756260160@qq.com
 * @Date: 2021-04-21 10:00:48
 * @LastEditTime: 2021-04-21 10:01:29
 * @FilePath: /c-plus-plus/Part3C++提高编程_泛化编程_STL/03STL-常用容器/3.2vector/07 vector容器_预留空间.cpp
 */
#include<iostream>
using namespace std;
#include <vector>

//vector容器 预留空间
void test01()
{
	vector<int>v;

	//利用reserve预留空间
	v.reserve(100000);

	int num = 0; //统计开辟次数
	int * p = NULL;
	for (int i = 0; i < 100000; i++)
	{
		v.push_back(i);

		if (p != &v[0])
		{
			p = &v[0];
			num++;
		}
	}

	cout << "num = " << num << endl;
}

int main() {

	test01();

	system("pause");

	return 0;
}