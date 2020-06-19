/*
 * @Description: 
 * @Author: HCQ
 * @Company(School): UCAS
 * @Date: 2020-06-18 18:36:19
 * @LastEditors: HCQ
 * @LastEditTime: 2020-06-20 02:47:31
 */
#include <opencv2\highgui.hpp>
#include <opencv2\opencv.hpp>
using namespace cv;
int main()
{
    Mat img = imread("1.jpg");
    cv::imshow("image", img);
    cv::waitKey();
    return 0;
}
// ———————————————— 版权声明：本文为CSDN博主「未完城」的原创文章，遵循CC 4.0 BY - SA版权协议，转载请附上原文出处链接及本声明。 原文链接：https://blog.csdn.net/u012435142/article/details/82952302