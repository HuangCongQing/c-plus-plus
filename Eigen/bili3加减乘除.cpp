/*
 * @Description: https://www.bilibili.com/video/BV18V41167wz?p=3
 * @Author: HCQ
 * @Company(School): UCAS
 * @Email: 1756260160@qq.com
 * @Date: 2020-12-27 16:49:04
 * @LastEditTime: 2020-12-27 17:11:38
 * @FilePath: /c-plus-plus/Eigen/bili3加减乘除.cpp
 */


#include <iostream>
#include <Eigen/Dense>
using namespace Eigen;
using namespace std;

int main(){
    // 加减乘除
    Matrix2d mat1;
    Matrix2d mat2;
    mat1<<1,2,3,4;
    mat2<<5,6,7,8;
    cout<<"matrix1:"<<endl<<mat1<<endl;
    cout<<"matrix2:"<<endl<<mat2<<endl;

    cout<<"mat1+mat2: "<<endl<<mat1+mat2<<endl;
    cout<<"mat1-mat2: "<<endl<<mat1-mat2<<endl;
    cout<<"mat1*mat2: "<<endl<<mat1*mat2<<endl;
    cout<<"mat1/2: "<<endl<<mat1/2<<endl;



    return 0;
}
