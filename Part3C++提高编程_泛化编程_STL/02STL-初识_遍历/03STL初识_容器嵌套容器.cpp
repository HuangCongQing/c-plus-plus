/*
 * @Description: 03 STL初识_容器嵌套容器.cpp
 https://www.bilibili.com/video/BV1Hb411Y7E5?p=188
 * @Author: HCQ
 * @Company(School): UCAS
 * @Email: 1756260160@qq.com
 * @Date: 2021-04-17 19:04:50
 * @LastEditTime: 2021-04-17 19:15:35
 * @FilePath: /c-plus-plus/Part3C++提高编程_泛化编程_STL/02STL-初识/03STL初识_容器嵌套容器.cpp
 */

#include<iostream>  
using namespace std;
# include <vector>


void test01()
{
    // 创建容器
    vector<vector<int>> v;

	//创建小容器
	vector<int>v1;
	vector<int>v2;
	vector<int>v3;
	vector<int>v4;

	//向小容器中添加数据
	for(int i = 0 ; i < 4;i++)
	{
		v1.push_back(i + 1);
		v2.push_back(i + 2);
		v3.push_back(i + 3);
		v4.push_back(i + 4);
	}


	//将小容器插入到大容器中
	v.push_back(v1);
	v.push_back(v2);
	v.push_back(v3);
	v.push_back(v4);

	//通过大容器，把所有数据遍历一遍
    for (vector<vector<int>>::iterator it = v.begin(); it!=v.end(); it++)
    {
		// (*it) ---- 容器 vector<int>
		for (vector<int>::iterator vit = (*it).begin(); vit != (*it).end(); vit++)
		{
			cout << *vit << " ";
		}
		cout << endl;
    }
    
    
}


int main(int argc, char *argv[]) {
    test01();
    return 0;
}