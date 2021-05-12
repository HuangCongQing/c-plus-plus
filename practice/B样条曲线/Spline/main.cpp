#include <cstdio>
#include <iostream>
#include "Spline.h"

using namespace std;
using namespace SplineSpace;

int main(void)
{
	//�쳣�׳�����
		
	//double x0[2]={1,2};		//��֪�����ݵ�
	//double y0[2]={3,4};
	//try
	//{
	//	SplineInterface* sp = new Spline(x0,y0,2);
	//}
	//catch(SplineFailure sf)
	//{
	//	cout<<sf.GetMessage()<<endl;
	//}
	//getchar();		//������ͣ

	//�����ֵ����

	//double x0[5]={1,2,4,5,6};		//��֪�����ݵ�
	//double y0[5]={1,3,4,2,5};
	//try
	//{
	//	//Spline sp(x0,y0,5,GivenSecondOrder,0,0);
	//	SplineInterface* sp = new Spline(x0,y0,5);	//ʹ�ýӿڣ���ʹ��Ĭ�ϱ߽�����
	//	double x=4.5;
	//	double y;
	//	sp->SinglePointInterp(x,y);	//��x�Ĳ�ֵ���y
	//	cout<<"x="<<x<<"ʱ�Ĳ�ֵ���Ϊ:"<<y<<endl;
	//}
	//catch(SplineFailure sf)
	//{
	//	cout<<sf.GetMessage()<<endl;
	//}
	//getchar();	//������ͣ

	//����ֵ����

	double x0[5]={1,2,4,5,6};		//��֪�����ݵ�
	double y0[5]={1,3,4,2,5};

	double x[4] = {1.5,2.5,3.5,4.5};	//��ֵ��
	double y[4];
	double leftBound=0,RightBound=0;	//�߽絼��

	try
	{
		Spline sp(x0,y0,5,GivenSecondOrder,leftBound,RightBound);
		sp.MultiPointInterp(x,4,y);			//��x�Ĳ�ֵ���y
		for(int i = 0;i < 4;i++)
		{
			cout<<"x="<<x[i]<<"ʱ�Ĳ�ֵ���Ϊ:"<<y[i]<<endl;
		}
	}
	catch(SplineFailure sf)
	{
		cout<<sf.GetMessage()<<endl;
	}
	getchar();	//������ͣ

	// �Զ���ֵ����

	// double x0[5]={1,2,4,5,6};		//��֪�����ݵ�
	// double y0[5]={1,3,4,2,5};

	// double x[10];	//��ֵ��
	// double y[10];

	// try
	// {
		// SplineInterface* sp = new Spline(x0,y0,5);	//ʹ�ýӿڣ���ʹ��Ĭ�ϱ߽�����
		// sp->AutoInterp(10,x,y);			//��x�Ĳ�ֵ���y

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
	// getchar();	//������ͣ
}