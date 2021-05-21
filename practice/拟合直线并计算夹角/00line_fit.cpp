/*
 * @Description: 拟合直线
 * @Author: HCQ
 * @Company(School): UCAS
 * @Email: 1756260160@qq.com
 * @Date: 2021-05-21 9:06:53
 * @LastEditTime: 2021-05-21 19:59:21
 * @FilePath: /c-plus-plus/practice/拟合直线并计算夹角/00line_fit.cpp
 */
#include <opencv2/opencv.hpp>
#include <iostream>
#include <vector>

// using namespace std;
// using namespace cv;

//生成[0,1]之间符合均匀分布的数
double uniformRandom(void)
{
    return (double)rand() / (double)RAND_MAX;
}

//生成[0,1]之间符合高斯分布的数
double gaussianRandom(void)
{
    /* This Gaussian routine is stolen from Numerical Recipes and is their
    copyright. */
    static int next_gaussian = 0;
    static double saved_gaussian_value;

    double fac, rsq, v1, v2;

    if (next_gaussian == 0)
    {
        do
        {
            v1 = 2 * uniformRandom() - 1;
            v2 = 2 * uniformRandom() - 1;
            rsq = v1 * v1 + v2 * v2;
        } while (rsq >= 1.0 || rsq == 0.0);
        fac = sqrt(-2 * log(rsq) / rsq);
        saved_gaussian_value = v1 * fac;
        next_gaussian = 1;
        return v2 * fac;
    }
    else
    {
        next_gaussian = 0;
        return saved_gaussian_value;
    }
}

//RANSAC 拟合2D 直线
//输入参数：points--输入点集
//        iterations--迭代次数
//        sigma--数据和模型之间可接受的差值,车道线像素宽带一般为10左右
//              （Parameter use to compute the fitting score）
//        k_min/k_max--拟合的直线斜率的取值范围.
//                     考虑到左右车道线在图像中的斜率位于一定范围内，
//                      添加此参数，同时可以避免检测垂线和水平线
//输出参数:line--拟合的直线参数,It is a vector of 4 floats
//              (vx, vy, x0, y0) where (vx, vy) is a normalized
//              vector collinear to the line and (x0, y0) is some
//              point on the line.
//返回值：无
void fitLineRansac(const std::vector<cv::Point2f> &points,
                   cv::Vec4f &line,
                   int iterations = 1000,
                   double sigma = 1.)
{
    unsigned int n = points.size();
    
    if (n < 2)
    {
        return;
    }

    cv::RNG rng;  // RNG产生随机数
    double bestScore = -1.;
    for (int k = 0; k < iterations; k++)
    {
        int i1 = 0, i2 = 0;
        while (i1 == i2)
        {
            i1 = rng(n);
            i2 = rng(n);
        }
        const cv::Point2f &p1 = points[i1];
        const cv::Point2f &p2 = points[i2];

        cv::Point2f dp = p2 - p1; //直线的方向向量
        dp *= 1. / norm(dp);
        double score = 0;

        // if (dp.y / dp.x <= k_max && dp.y / dp.x >= k_min)
        // {
            for (int i = 0; i < n; i++)
            {
                cv::Point2f v = points[i] - p1;
                double d = v.y * dp.x - v.x * dp.y; //向量a与b叉乘/向量b的摸.||b||=1./norm(dp)
                //score += exp(-0.5*d*d/(sigma*sigma));//误差定义方式的一种
                if (fabs(d) < sigma)
                    score += 1;
            }
        // }
        // std::cout << "score: " << score << std::endl;
        if (score > bestScore)
        {
            line = cv::Vec4f(dp.x, dp.y, p1.x, p1.y);
            bestScore = score;
        }
    }
}
// num：生成点数量
void CreatePoints(double a, double b, double c, std::vector<cv::Point2f> &ptSet, int num = 20)
{

    //demo 10m*10m
    int width = 100;
    int height = 100;
    //随机获取直线上20个点
    int ninliers = 0;
    // std::vector<cv::Point2f> ptSet;
    srand((unsigned int)time(NULL)); //设置随机数种子
    while (true)
    {
        double x = uniformRandom() * (width - 1);
        double y = (a * x + c) / b;
        //加0.1高斯噪声
        x += gaussianRandom() * 0.1;
        y += gaussianRandom() * 0.1;
        if (x >= 10 && y >= 10) // //demo 10m*10m
            continue;
        cv::Point2f pt(x, y);
        ptSet.push_back(pt);
        ninliers++;
        if (ninliers == num)
            break;
    }
    // std::cout << "生成点size: " << ptSet.size() << std::endl;
}


/* 

*函数功能 ： 输入两条直线（每条直线以斜率和截距确定），返回两直线夹角，0为弧度，1为角度
*输入参数 ： line_1_k为一条直线斜率，line_2_k为另一条直线斜率，aaa为0则为弧度，反之则为角度
 */
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



int main(int argc, char *argv[])
{

    //直线参数     y = (a*x + c) / b;
    double a = 1, b = 2, c = 1; //斜率a/b
    std::vector<cv::Point2f> points1;
    double d = 1, e = 3, f = 1;
    std::cout<<"真实值k1: "<<a/b<<"    "<<"k2: "<<d/e<<std::endl;
    std::vector<cv::Point2f> points2;
    CreatePoints(a, b, c, points1);
    CreatePoints(d, e, f, points2);

    cv::Vec4f lineParam1;
    cv::Vec4f lineParam2;
    // 获得直线参数
    fitLineRansac(points1, lineParam1, 1000, 1);
    fitLineRansac(points2, lineParam2, 1000, 1);
    // std::cout<<"lineParam1: "<< lineParam1[1]<<" lineParam1[0]: "<< lineParam1[0]<<std::endl;
    double k1 = lineParam1[1] / lineParam1[0];
    double k2 = lineParam2[1] / lineParam2[0];
    std::cout<<"RANSAC计算k1: "<<k1<<"    "<<"k2: "<<k2<<std::endl;
    

    float groundTruth;
    float result;
    // (0为弧度，1为角度)
    groundTruth = get_lines_arctan(a/b, d/e, 0);
    result = get_lines_arctan(k1, k2, 0);
    std::cout<<"groundTruth弧度: "<< groundTruth<<std::endl;
    std::cout<<"result计算弧度: "<<result<<std::endl;
    std::cout<<"弧度Diff: "<<groundTruth- result<<std::endl;
    return 0;
}