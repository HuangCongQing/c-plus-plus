#include <cstdio>
#include <iostream>
#include "Spline.h"

using namespace std;
using namespace SplineSpace;

int main(void)
{
	//异常抛出测试
		
	//double x0[2]={1,2};		//已知的数据点
	//double y0[2]={3,4};
	//try
	//{
	//	SplineInterface* sp = new Spline(x0,y0,2);
	//}
	//catch(SplineFailure sf)
	//{
	//	cout<<sf.GetMessage()<<endl;
	//}
	//getchar();		//程序暂停

	//单点插值测试

	//double x0[5]={1,2,4,5,6};		//已知的数据点
	//double y0[5]={1,3,4,2,5};
	//try
	//{
	//	//Spline sp(x0,y0,5,GivenSecondOrder,0,0);
	//	SplineInterface* sp = new Spline(x0,y0,5);	//使用接口，且使用默认边界条件
	//	double x=4.5;
	//	double y;
	//	sp->SinglePointInterp(x,y);	//求x的插值结果y
	//	cout<<"x="<<x<<"时的插值结果为:"<<y<<endl;
	//}
	//catch(SplineFailure sf)
	//{
	//	cout<<sf.GetMessage()<<endl;
	//}
	//getchar();	//程序暂停

	//多点插值测试

	double x0[5]={1,2,4,5,6};		//已知的数据点
	double y0[5]={1,3,4,2,5};

	double x[4] = {1.5,2.5,3.5,4.5};	//插值点
	double y[4];
	double leftBound=0,RightBound=0;	//边界导数

	try
	{
		Spline sp(x0,y0,5,GivenSecondOrder,leftBound,RightBound);
		sp.MultiPointInterp(x,4,y);			//求x的插值结果y
		for(int i = 0;i < 4;i++)
		{
			cout<<"x="<<x[i]<<"时的插值结果为:"<<y[i]<<endl;
		}
	}
	catch(SplineFailure sf)
	{
		cout<<sf.GetMessage()<<endl;
	}
	getchar();	//程序暂停

	// 自动插值测试

	// double x0[5]={1,2,4,5,6};		//已知的数据点
	// double y0[5]={1,3,4,2,5};

	// double x[10];	//插值点
	// double y[10];

	// try
	// {
		// SplineInterface* sp = new Spline(x0,y0,5);	//使用接口，且使用默认边界条件
		// sp->AutoInterp(10,x,y);			//求x的插值结果y

		// for(int i = 0;i < 10;i++)
			// cout<<x[i]<<",";
		// cout<<endl;
		// for(int i = 0;i < 10;i++)
			// cout<<y[i]<<",";
	// }
	// catch(SplineFailure sf)
	// {
		// cout<<sf.GetMessage()<<endl;
	// }
	// getchar();	//程序暂停
}