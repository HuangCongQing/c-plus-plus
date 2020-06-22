/*
 * @Description: 
 * @Author: HCQ
 * @Company(School): UCAS
 * @Date: 2020-06-21 22:10:52
 * @LastEditors: HCQ
 * @LastEditTime: 2020-06-21 22:13:56
 */
#include "iostream"
#include "my_harris.h"
#include "opencv2/core.hpp"
#include "opencv2/highgui.hpp"
using namespace cv;
using namespace std;

int main()
{
    my_Harris Harris;
    Mat img = imread("1.jpg");
    //imshow("img",img);
    //waitKey(0);
    /*0.图像预处理之灰度化RGB2GRAY*/
    int cols = img.cols;
    int rows = img.rows;
    Mat img_gray = Mat(rows, cols, CV_8UC1, Scalar(0));
    Harris.RGB2GRAY(img, img_gray);
    /*1.计算图像在x,y方向的梯度*/
    Mat gx_img = Mat(rows, cols, CV_8UC1, Scalar(0));
    Mat gy_img = Mat(rows, cols, CV_8UC1, Scalar(0));
    Harris.IMG_GRAD(img_gray, gx_img, gy_img);

    /*2.计算图像在两个方向梯度的乘积*/
    Mat gx_p = Mat(rows, cols, CV_8UC1, Scalar(0));
    Mat gy_p = Mat(rows, cols, CV_8UC1, Scalar(0));
    Mat gxy = Mat(rows, cols, CV_8UC1, Scalar(0));
    Harris.GRAD_MULTI(gx_img, gy_img, gx_p, gy_p, gxy);

    /*3.使用高斯函数加权*/
    Mat A = Mat(rows, cols, CV_8UC1, Scalar(0));
    Mat B = Mat(rows, cols, CV_8UC1, Scalar(0));
    Mat C = Mat(rows, cols, CV_8UC1, Scalar(0));
    Harris.GAUSS_WEI(gx_p, gy_p, gxy, A, B, C);
    /*4.计算每个像素点的harris响应值*/
    Mat R = Mat(rows, cols, CV_8UC1, Scalar(0));
    Harris.GET_RESPONSE(A, B, C, R);
    /*5.过滤大于某一阈值t的R值*/
    Mat CORNER = Mat(rows, cols, CV_8UC1, Scalar(0));
    Harris.FILTER_THRESH(R, img, CORNER);
    return 0;
}