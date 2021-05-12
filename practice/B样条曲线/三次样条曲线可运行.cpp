/*
 * @Description: https://blog.csdn.net/twicave/article/details/2808038?utm_medium=distribute.pc_relevant.none-task-blog-baidujs_title-5&spm=1001.2101.3001.4242
 * @Author: HCQ
 * @Company(School): UCAS
 * @Email: 1756260160@qq.com
 * @Date: 2021-05-12 16:11:17
 * @LastEditTime: 2021-05-12 16:28:57
 * @FilePath: /c-plus-plus/practice/B样条曲线/三次样条曲线可运行.cpp
 */


#include<iostream>  
#include<math.h>
#include<vector>
#include<algorithm>
using namespace std;


// 三次样条曲线https://blog.csdn.net/twicave/article/details/2808038?
double spl2(double x[],                                                                /*x坐标序列*/
                        double y[],                                                                /*y坐标序列*/
                        int n,                                                                        /*输入数据个数*/
                        double ddy1, double ddyn,                                /*第一点和最末点二阶导数*/
                        double t[],                                                                /*插值点的x坐标序列*/
                        int m,                                                                        /*插值点个数*/
                        double z[]                                                                /*插值点的y坐标序列*/
)        
{
        int i,j;
        double h0,h1,alpha,beta,*s,*dy;
        s= new double[n];
        dy = new double[n];
        dy[0]=-0.5;
        h0=x[1]-x[0];
        s[0]=3.0*(y[1]-y[0])/(2.0*h0)-ddy1*h0/4.0;
        for (j=1;j<=n-2;j++)
        {
                h1=x[j+1]-x[j];
                alpha=h0/(h0+h1);
                beta=(1.0-alpha)*(y[j]-y[j-1])/h0;
                beta=3.0*(beta+alpha*(y[j+1]-y[j])/h1);
                dy[j]=-alpha/(2.0+(1.0-alpha)*dy[j-1]);
                s[j]=(beta-(1.0-alpha)*s[j-1]);
                s[j]=s[j]/(2.0+(1.0-alpha)*dy[j-1]);
                h0=h1;
        }
        dy[n-1]=(3.0*(y[n-1]-y[n-2])/h1+ddyn*h1/2.0-s[n-2])/(2.0+dy[n-2]);
        for (j=n-2;j>=0;j--)        dy[j]=dy[j]*dy[j+1]+s[j];
        for (j=0;j<=n-2;j++)        s[j]=x[j+1]-x[j];
        for (j=0;j<=m-1;j++)
        {
                if (t[j]>=x[n-1]) i=n-2;
                else
                {
                        i=0;
                        while (t[j]>x[i+1]) i=i+1;
                }
                h1=(x[i+1]-t[j])/s[i];
                h0=h1*h1;
                z[j]=(3.0*h0-2.0*h0*h1)*y[i];
                z[j]=z[j]+s[i]*(h0-h0*h1)*dy[i];
                h1=(t[j]-x[i])/s[i];
                h0=h1*h1;
                z[j]=z[j]+(3.0*h0-2.0*h0*h1)*y[i+1];
                z[j]=z[j]-s[i]*(h0-h0*h1)*dy[i+1];
        }
        delete[] s;
        delete[] dy;
        return 0.0;
}


int main(int argc, char *argv[]) {
    
    return 0;
}


