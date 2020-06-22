#ifndef MY_HARRIS_H
#define MY_HARRIS_H
#include "iostream"
#include "opencv2/core.hpp"
#include "opencv2/highgui.hpp"

using namespace cv;
using namespace std;
class my_Harris
{
public:
    my_Harris();
    void RGB2GRAY(Mat rgb_img, Mat &gray_img);
    void IMG_GRAD(Mat img, Mat &x_grad, Mat &y_grad);
    void GRAD_MULTI(Mat x_grad, Mat y_grad, Mat &p_x, Mat &p_y, Mat &p_xy);
    void GAUSS_WEI(Mat p_x, Mat p_y, Mat p_xy, Mat &A, Mat &B, Mat &C);
    Mat GAUSS_PRO(Mat g);
    void GET_RESPONSE(Mat A_, Mat B_, Mat C_, Mat &R);
    void FILTER_THRESH(Mat R, Mat img, Mat &F_R);
};

#endif // MY_HARRIS_H