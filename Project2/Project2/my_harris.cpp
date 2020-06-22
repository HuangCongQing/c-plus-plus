#include "my_harris.h"
#define pi 3.14
my_Harris::my_Harris()
{
}
void my_Harris::RGB2GRAY(Mat rgb_img, Mat &gray_img)
{
    Mat img_src = rgb_img.clone();
    int rows = img_src.rows;
    int cols = img_src.cols;
    Mat img_gray = Mat(rows, cols, CV_8UC1, Scalar(0));
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            img_gray.at<uchar>(i, j) = (0.1 * img_src.at<Vec3b>(i, j)[0]) + (0.6 * img_src.at<Vec3b>(i, j)[1]) + (0.3 * img_src.at<Vec3b>(i, j)[2]); //粗略参数
        }
    }
    gray_img = img_gray;
}

void my_Harris::IMG_GRAD(Mat img, Mat &x_grad, Mat &y_grad)
{
    Mat img_src = img.clone();
    int rows = img_src.rows;
    int cols = img_src.cols;
    Mat x_g = Mat(rows, cols, CV_8UC1, Scalar(0));
    Mat y_g = Mat(rows, cols, CV_8UC1, Scalar(0));
    for (int i = 1; i < rows - 1; i++)
    {
        for (int j = 1; j < cols - 1; j++)
        {
            　　　　　　　 //使用sobel算子求梯度
                x_g.at<uchar>(i, j) = abs((img_src.at<uchar>(i + 1, j - 1) - img_src.at<uchar>(i - 1, j - 1)) + 2 * (img_src.at<uchar>(i + 1, j) - img_src.at<uchar>(i - 1, j)) + (img_src.at<uchar>(i + 1, j + 1) - img_src.at<uchar>(i - 1, j + 1))) / 3;
            y_g.at<uchar>(i, j) = abs((img_src.at<uchar>(i - 1, j + 1) - img_src.at<uchar>(i - 1, j - 1)) + 2 * (img_src.at<uchar>(i, j + 1) - img_src.at<uchar>(i, j - 1)) + (img_src.at<uchar>(i + 1, j + 1) - img_src.at<uchar>(i + 1, j - 1))) / 3;
        }
    }
    x_grad = x_g;
    y_grad = y_g;
}

void my_Harris::GRAD_MULTI(Mat x_grad, Mat y_grad, Mat &p_x, Mat &p_y, Mat &p_xy)
{
    Mat x_g = x_grad.clone();
    Mat y_g = y_grad.clone();
    int rows = x_g.rows;
    int cols = x_g.cols;
    Mat px = Mat(rows, cols, CV_8UC1, Scalar(0));
    Mat py = Mat(rows, cols, CV_8UC1, Scalar(0));
    Mat pxy = Mat(rows, cols, CV_8UC1, Scalar(0));
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            px.at<uchar>(i, j) = x_g.at<uchar>(i, j) * x_g.at<uchar>(i, j);
            py.at<uchar>(i, j) = y_g.at<uchar>(i, j) * y_g.at<uchar>(i, j);
            pxy.at<uchar>(i, j) = x_g.at<uchar>(i, j) * y_g.at<uchar>(i, j);
        }
    }
    p_x = px;
    p_y = py;
    p_xy = pxy;
}

void my_Harris::GAUSS_WEI(Mat p_x, Mat p_y, Mat p_xy, Mat &A, Mat &B, Mat &C)
{
    Mat Ix = p_x.clone();
    Mat Iy = p_y.clone();
    Mat Ixy = p_xy.clone();
    int rows = Ix.rows;
    int cols = Ix.cols;
    Mat g_Ix = Mat(rows, cols, CV_8UC1, Scalar(0));
    Mat g_Iy = Mat(rows, cols, CV_8UC1, Scalar(0));
    Mat g_Ixy = Mat(rows, cols, CV_8UC1, Scalar(0));
    int k = 3;
    Mat gauss_plate = Mat(k, k, CV_8UC1, Scalar(0));
    //GET_GAUSS(3,0.5, gauss_plate);
    g_Ix = GAUSS_PRO(Ix);
    g_Iy = GAUSS_PRO(Iy);
    g_Ixy = GAUSS_PRO(Ixy);
    A = g_Ix;
    B = g_Iy;
    C = g_Ixy;
}

Mat my_Harris::GAUSS_PRO(Mat g)
{
    Mat Ix = g.clone();
    float gauss_plate[3][3] = {0.0113437, 0.0838195, 0.0113437, 0.0838195, 0.619347, 0.0838195, 0.0113437, 0.0838195, 0.0113437};
    int rows = Ix.rows;
    int cols = Ix.cols;
    Mat g_f = Mat(rows, cols, CV_8UC1, Scalar(0));
    for (int i = 1; i < rows - 1; i++)
    {
        for (int j = 1; j < cols - 1; j++)
        {
            g_f.at<uchar>(i, j) = Ix.at<uchar>(i - 1, j - 1) * gauss_plate[0][0] + Ix.at<uchar>(i, j - 1) * gauss_plate[1][0] + Ix.at<uchar>(i + 1, j - 1) * gauss_plate[2][0] + Ix.at<uchar>(i - 1, j) * gauss_plate[0][1] + Ix.at<uchar>(i, j - 1) * gauss_plate[1][1] + Ix.at<uchar>(i + 1, j - 1) * gauss_plate[2][1] + Ix.at<uchar>(i - 1, j + 1) * gauss_plate[0][2] + Ix.at<uchar>(i, j + 1) * gauss_plate[1][2] + Ix.at<uchar>(i + 1, j + 1) * gauss_plate[2][2];
        }
    }
    return g_f;
}
void my_Harris::GET_RESPONSE(Mat A_, Mat B_, Mat C_, Mat &R)
{
    Mat A = A_.clone();
    Mat B = B_.clone();
    Mat C = C_.clone();
    int rows = A.rows;
    int cols = B.cols;
    Mat M_R = Mat(rows, cols, CV_8UC1, Scalar(0));
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            float k = 0.15;
            float a = A.at<uchar>(i, j);
            float b = B.at<uchar>(i, j);
            float c = C.at<uchar>(i, j);
            float r = (a * b - c * c - k * ((a + b) * (a + b)));
            M_R.at<uchar>(i, j) = int(r);
            if (abs(int(r)) > 48000)
            {
                M_R.at<uchar>(i, j) = 255;
            }
            else
            {
                M_R.at<uchar>(i, j) = 0;
            }
        }
    }
    R = M_R;
}

void my_Harris::FILTER_THRESH(Mat R, Mat img, Mat &F_R)
{
    Mat img_src = R.clone();
    int rows = img_src.rows;
    int cols = img_src.cols;
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            if (abs(img_src.at<uchar>(i, j)) > 254)
            {
                img.at<Vec3b>(i, j)[0] = 0;
                img.at<Vec3b>(i, j)[1] = 0;
                img.at<Vec3b>(i, j)[2] = 255;
            }
        }
    }
    imshow("img_src", img);
    waitKey(0);
}