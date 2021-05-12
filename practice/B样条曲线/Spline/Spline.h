//----------------------------------------------------------------------------
// �ļ�����Spline.h
//----------------------------------------------------------------------------
// ����:	ʹ�������������߽��в�ֵ
//----------------------------------------------------------------------------
// ˵����	1.�ṩ�����ֱ߽��������趨��ʽ��
//				1)�����˵��һ�׵�
//				2)�����˵�Ķ��׵�
//			2.�ṩ�����ֲ�ֵ���㷽ʽ��
//				1)����һ��������Ӧ��ֵ,�����׳����ֵ�쳣
//				2)�������������Ӧ��ֵ�������׳����ֵ�쳣
//				3)�趨��ֵ���������(����Ϊ2),�Զ���Max(x)��Min(x)֮��ȼ��������ֵ.
//				xΪ��֪�����Ա�������,�����׳����������쳣
//----------------------------------------------------------------------------
// ���ߣ� ���Ǳ�
// ��������: 2017��2��20��
// �޸����ڣ�
//-----------------------------------------------------------------------------

#ifndef _SPLINE_H
#define _SPLINE_H
#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#pragma warning (disable:4290)		//vs2010��c++����������Ժ����׳��쳣���м�⣬ֱ�Ӻ����������

//��Ϊ������������Ƚ϶�,Ϊ�˷�ֹ����������һ�������ռ���а���
namespace SplineSpace		
{
	class SplineFailure		//�쳣��
	{
	private:
		const char* Message;
	public:
		SplineFailure(const char* msg);
		const char* GetMessage();
	};

	class SplineInterface		//�ӿ���
	{
	public:
		//�����ֵ:
		//x->�����Ա���(����)
		//y->���ز�ֵ���(���)
		//���x�����ڲ�ֵ�����ֵʧ��
		virtual bool SinglePointInterp(const double& x,double& y)=0;
		//����ֵ:
		//x->�����Ա���������ָ��,num->�Ա�������������(����)
		//y->���ز�ֵ�������ָ��(�������)
		virtual bool MultiPointInterp(const double* x,const int& num,double* y)=0;		
		//�Զ���ֵ:
		//num->��Ҫ���ɵĲ�ֵ����������(����)
		//x->����Ա����������ָ��(�������)
		//y->��Ӧ��Ͻ������ָ��(�������)
		virtual bool AutoInterp(const int& num,double* x,double* y)=0;					

		virtual ~SplineInterface(){};			
	};

	enum BoundaryCondition		//�߽�����ö��
	{
		GivenFirstOrder=1		//����һ�׵���
		,GivenSecondOrder		//�������׵���
	};

	class Spline:public SplineInterface				//ʵ����
	{
	public:
		//���캯��:
		//x0->��֪���Ա���������ָ��,y0->��֪�������������ָ��,num->��֪���ݵĸ���
		//bc->�߽�����,Ĭ�ϸ������׵���
		//leftBoundary,rightBoundary���ұ߽絼��ֵ������,Ĭ�϶���0
		Spline(const double* x0,const double* y0,const int& num,
			BoundaryCondition bc=GivenSecondOrder,const double& leftBoundary=0,const double& rightBoundary=0);

		bool SinglePointInterp(const double& x,double& y)throw(SplineFailure);		//�麯��ʵ��
		bool MultiPointInterp(const double* x,const int& num,double* y)throw(SplineFailure);
		bool AutoInterp(const int& num,double* x,double* y)throw(SplineFailure);

		~Spline();
		
	private:
		//����
		void PartialDerivative1(void);		//��һ�׵�
		void PartialDerivative2(void);		//����׵�
		//����
		const double* GivenX;	//��֪���ݵ��Ա���
		const double* GivenY;	//��֪���ݵ������
		const int GivenNum;		//��������֪���ݵ���
		const BoundaryCondition Bc;	//�߽�����
		const double LeftB;
		const double RightB;

		double* PartialDerivative;	//�����Ӧ�Ķ��׻���һ��ƫ����
		double MaxX;				//�Ա��������ֵ
		double MinX;				//�Ա�������Сֵ

		const double* SplineX;	//��ֵ�Ա���
		double* SplineY;		//��ֵ�����
		const int* SplineNum;	//��ֵ����
	};
}
#endif