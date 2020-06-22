// Harris.cpp : 定义控制台应用程序的入口点。
//
//#include "stdafx.h"
#include "opencv2/core.hpp"
#include "opencv2/imgproc.hpp"
#include "opencv2/highgui.hpp"
#include <iostream>
#include <sys/types.h>
#include <vector>
#include <string.h>
#include <math.h>

using namespace cv;
using namespace std;

void compareMat(Mat& s1, Mat& s2, Mat& d)
{
	if (d.empty())
	{
		d.create(s1.rows, s1.cols, s1.type());
	}

	for (int y = 0; y < s1.rows; y++)
	{
		for (int x = 0; x < s1.cols; x++)
		{
			if (s1.at<float>(y, x) == s2.at<float>(y, x))
			{
				d.at<float>(y, x) = s1.at<float>(y, x);
			}
			else
			{
				d.at<float>(y, x) = 0.0f;
			}
		}
	}
}

int main() {
	Mat Srcimg = imread("lena.png");
	//Mat Srcimg = imread("2.jpg");
	if (!Srcimg.data) {
		return -1;
	}
	vector<Point2i> corners;
	double GaussKernel[5][5] = {
		0.00390625, 0.015625, 0.0234375, 0.015625, 0.00390625,
		0.015625, 0.0625, 0.09375, 0.0625, 0.015625,
		0.0234375, 0.09375, 0.140625, 0.09375, 0.0234375,
		0.015625, 0.0625, 0.09375, 0.0625, 0.015625,
		0.00390625, 0.015625, 0.0234375, 0.015625, 0.00390625,
	};
	Mat gray;
	cvtColor(Srcimg, gray, CV_BGR2GRAY);

	Mat IxIx(gray.rows, gray.cols, CV_8UC1);
	Mat IyIy(gray.rows, gray.cols, CV_8UC1);
	Mat IxIy(gray.rows, gray.cols, CV_8UC1);
	for (int y = 1; y <= Srcimg.rows - 2; y++)
	{
		for (int x = 1; x <= Srcimg.cols - 2; x++)
		{
			//计算当前像素在两个方向的梯度
			uchar ix = gray.at<uchar>(y + 1, x) - gray.at<uchar>(y - 1, x);
			uchar iy = gray.at<uchar>(y, x + 1) - gray.at<uchar>(y, x - 1);

			IxIx.at<uchar>(y, x) = ix * ix;
			IyIy.at<uchar>(y, x) = iy * iy;

			IxIy.at<uchar>(y, x) = ix * iy;
		}
	}

	//Harris响应矩阵
	Mat R(gray.rows, gray.cols, CV_32FC1);

	//最大响应值
	float maxResponse = 0.0f;

	for (int y = 0; y <= Srcimg.rows - 5; y++)
	{
		for (int x = 0; x <= Srcimg.cols - 5; x++)
		{
			uchar a = 0;  /*  自相似矩阵 M：                       */
			uchar b = 0;  /*  [ ∑g*a  ∑g*c ]   即  [ ∑g*IxIx ∑g*IxIy ]        */
			uchar c = 0;  /*  [ ∑g*c  ∑g*b ]       [ ∑g*IxIy ∑g*IyIy ]        */
			for (int m = 0; m < 5; m++)
			{
				for (int n = 0; n < 5; n++)
				{
					//分别对IxIx，IyIy，IxIy的5*5邻域计算高斯均值以求得自相似矩阵 M
					a += IxIx.at<uchar>(y + m, x + n) * GaussKernel[m][n];
					b += IyIy.at<uchar>(y + m, x + n) * GaussKernel[m][n];
					c += IxIy.at<uchar>(y + m, x + n) * GaussKernel[m][n];
				}
			}

			//计算当前像素的Harris响应值
			float t = (a * c - b * b) - 0.05f * (a + c) * (a + c);

			R.at<float>(y, x) = t;

			if (t > maxResponse)
			{
				maxResponse = t;
			}
		}
	}

	Mat dilated;
	dilate(R, dilated, Mat());
	Mat localMax;
	compareMat(R, dilated, localMax);
	//剔除部分局部极大值
	Mat threshold2;
	threshold(localMax, threshold2, 0.5 * maxResponse, 255, THRESH_BINARY);

	for (int y = 0; y < threshold2.rows - 1; y++)
	{
		const float* row = threshold2.ptr<float>(y);
		for (int x = 0; x < threshold2.cols - 1; x++)
		{
			if (row[x])
			{
				corners.push_back(Point2i(x, y));
			}
		}
	}
	for (vector<Point2i>::iterator it = corners.begin(); it != corners.end(); it++)
	{
		circle(Srcimg, *it, 2, Scalar(255, 0, 0));
	}
	 imwrite("Harris.png", Srcimg);
	 imshow("Harris", Srcimg);
	 waitKey(0);
	 return 0;
	
}
