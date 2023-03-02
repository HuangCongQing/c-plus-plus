/*
 * @Description: https://www.bilibili.com/video/BV18V41167wz?p=3
 * @Author: HCQ
 * @Company(School): UCAS
 * @Email: 1756260160@qq.com
 * @Date: 2020-12-27 16:49:04
 * @LastEditTime: 2020-12-27 18:02:36
 * @FilePath: /c-plus-plus/Eigen/bili3基本运算.cpp
 */


#include <iostream>
#include <Eigen/Dense>
using namespace Eigen;
using namespace std;

int main(){
    
    Matrix2d mat1;
    Matrix2d mat2;
    mat1<<1,2,3,4;
    mat2<<5,6,7,8;
    cout<<"matrix1:"<<endl<<mat1<<endl;
    cout<<"matrix2:"<<endl<<mat2<<endl;
    // 获取行数列数，大小
    cout<< " 获取行数列数，大小==================="<<endl;  //  获取行数
    cout<< "mat1.rows()"<<endl;  //  获取行数
    cout<< mat1.rows()<<endl;  //  获取行数
    cout<< "mat1.cols()"<<endl;  //  获取列数
    cout<< mat1.cols()<<endl;  //  获取列数
    cout<<  "mat1.size()"<<endl;  //  获取大小
    cout<<  mat1.size()<<endl;  //  获取大小
    // 加减乘除
    cout<<"加减乘除=============="<<endl<<mat1+mat2<<endl;
    cout<<"mat1+mat2: "<<endl<<mat1+mat2<<endl;
    cout<<"mat1-mat2: "<<endl<<mat1-mat2<<endl;
    cout<<"mat1*mat2: "<<endl<<mat1*mat2<<endl;
    cout<<"mat1/2: "<<endl<<mat1/2<<endl;
    // 特殊矩阵
    cout<< " 特殊矩阵==================="<<endl;  //  
    cout<< "mat1.transpose()"<<endl;  //
    cout<< mat1.transpose()<<endl;  // 转置矩阵
    cout<< "mat1.conjugate()"<<endl;  //
    cout<< mat1.conjugate()<<endl;  // 共轭矩阵
    cout<< "mat1.adjoint()"<<endl;  //
    cout<< mat1.adjoint()<<endl;  // 伴随矩阵
    cout<< "mat1.diagonal() 对角矩阵"<<endl;  //
    cout<< mat1.diagonal()<<endl;  // 对角矩阵


    return 0;
}
