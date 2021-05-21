/*
 * @Description: 计算两直线夹角 https://blog.csdn.net/mao_hui_fei/article/details/81431874
 *函数功能 ： 输入两条直线（每条直线以斜率和截距确定），返回两直线夹角，0为弧度，1为角度
*输入参数 ： line_1_k为一条直线斜率，line_2_k为另一条直线斜率，aaa为0则为弧度，反之则为角度
*返 回 值 ： float型弧度或者角度,有正负，为直线2相对于直线1的角度
 * @Author: HCQ
 * @Company(School): UCAS
 * @Email: 1756260160@qq.com
 * @Date: 2021-05-19 18:13:43
 * @LastEditTime: 2021-05-21 14:14:46
 * @FilePath: /c-plus-plus/practice/拟合直线并计算夹角/02计算两夹角.cpp
 */
/* 

*函数功能 ： 输入两条直线（每条直线以斜率和截距确定），返回两直线夹角，0为弧度，1为角度
*输入参数 ： line_1_k为一条直线斜率，line_2_k为另一条直线斜率，aaa为0则为弧度，反之则为角度
*返 回 值 ： float型弧度或者角度,有正负，为直线2相对于直线1的角度

 */

#include<iostream>  
#include<math.h>
using namespace std;



float get_lines_arctan(float line_1_k, float line_2_k, int aaa)
{
    if (aaa == 0)
    {
        float tan_k = 0; //直线夹角正切值
        float lines_arctan;//直线斜率的反正切值
        tan_k = (line_2_k - line_1_k) / (1 + line_2_k*line_1_k); //求直线夹角的公式
        lines_arctan = atan(tan_k);
        return lines_arctan;
    }
    else
    {
        float tan_k = 0; //直线夹角正切值
        float lines_arctan;//直线斜率的反正切值
        tan_k = (line_2_k - line_1_k) / (1 + line_2_k*line_1_k); //求直线夹角的公式
        lines_arctan = atan(tan_k)* 180.0 / 3.1415926;

        return lines_arctan;
    }
}



int main(int argc, char *argv[]) {
    float result;
    result = get_lines_arctan(0.0, 1.0, 1);
    std::cout<<result<<std::endl;
    return 0;
}
