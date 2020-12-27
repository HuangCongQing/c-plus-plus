/*
 * @Description: Eigen的基本使用
 网址：https://mp.weixin.qq.com/s/hy0sbDRbOwSjOQR0_U80xA
 * @Author: HCQ
 * @Company(School): UCAS
 * @Email: 1756260160@qq.com
 * @Date: 2020-12-27 12:02:00
 * @LastEditTime: 2020-12-27 12:54:33
 * @FilePath: /c-plus-plus/Eigen/02Eigen基本使用.cpp
 */

#include <iostream>


#include <Eigen/Core> //Eigen部分
#include <Eigen/Dense> //稠密矩阵的代数运算（逆，特征值）


using namespace Eigen;
using namespace std;



#define MATRIX_SIZE 50

int main(){
    // Eigen 中所有向量和矩阵都是Eigen::Matrix，它是一个模板类。它的前三个参数为：数据类型，行，列
    // 声明一个2*3的float矩阵
    Eigen::Matrix matrix_23;
    // Eigen::Vector3d v_3d;
    // Eigen::Matrix vd_3d;  // 和Eigen::Vector3d v_3d;等价
    // Eigen::Matrix3d  matrix_33 = Eigen::Matrix3d::Zero(); // 初始化为0
    // Eigen::Matrix matrix_dynamic;
    // Eigen::MatrixXd matrix_x  // 

    // 下面是对Eigen阵的操作
    matrix_23<<1,2,3,4,5,6;
    cout<< matrix_23 <<endl;
    

    

}