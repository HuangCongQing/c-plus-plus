/*
 * @Description: 欧氏距离  https://blog.csdn.net/weixin_43916755/article/details/100089833
 * @Author: HCQ
 * @Company(School): UCAS
 * @Email: 1756260160@qq.com
 * @Date: 2021-04-19 13:09:38
 * @LastEditTime: 2021-04-19 13:10:35
 * @FilePath: /c-plus-plus/practice/math数学计算/欧氏距离.cpp
 */


#include <iostream>
#include <math.h>
using namespace std;
float twoPointDistance(float x1, float y1, float x2, float y2);
int main()
{
	float x1=829, y1=339, x2=829, y2=341;
	cout << twoPointDistance(829, 339, 829, 342) << endl;
	// system("pause");
	return 1;
}
float twoPointDistance(float x1 ,float y1 , float x2 , float y2 )
{
	return  pow(pow(x1 - x2, 2) + pow(y1 - y2, 2), 0.5);
}
