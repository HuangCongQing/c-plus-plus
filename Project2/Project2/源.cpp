#include "cv.h"
#include "highgui.h"
int main(int argc, char** argv)
{
    IplImage* pImg; //声明IplImage指针 
    if ((pImg = cvLoadImage("1.jpg", 1)) != 0)
    {
        cvNamedWindow("Image", 1); //创建窗口 
        cvShowImage("Image", pImg); //显示图像 
        cvWaitKey(0); //等待按键 
        cvDestroyWindow("Image"); //销毁窗口 
        cvReleaseImage(&pImg); //释放图像，注意pImg前面一定要加& 
        return 0;
    }
    return -1;
}