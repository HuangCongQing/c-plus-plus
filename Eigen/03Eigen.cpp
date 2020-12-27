/*
 * @Description:  https://blog.csdn.net/guotianqing/article/details/111487795
 * @Author: HCQ
 * @Company(School): UCAS
 * @Email: 1756260160@qq.com
 * @Date: 2020-12-27 13:05:20
 * @LastEditTime: 2020-12-27 13:06:15
 * @FilePath: /c-plus-plus/Eigen/03Eigen.cpp
 */
#include "Eigen/Core"
#include <iostream>

using std::cout;
using std::endl;


int main()
{
    Eigen::Matrix<double, 2, 2> m; // 创建double类型的2X2维矩阵
    m << 1, 2, 3, 4; // 为每个元素赋值

    Eigen::MatrixXf m1(2, 3); // 创建动态矩阵，并初始化为2X3矩阵，类型为float
    m1 << 1, 2, 3, 4, 5, 6;

    Eigen::Matrix3d m2 = Eigen::Matrix3d::Identity(); // 3维double类型的单位矩阵
    Eigen::Matrix3d m3 = Eigen::Matrix3d::Random(); // 3维double类型的随机矩阵

    Eigen::Vector3f v1 = Eigen::Vector3f::Zero(); // 3维float类型的零向量（默认为列向量，除非显式指定）
    Eigen::Vector3d v2(1.0, 2.0, 3.0); // 3维double类型的向量，并赋值

    Eigen::VectorXf v3(3); // 动态列向量，指定为3维
    v3 << 1.0, 2.0, 3.0;

    Eigen::RowVector2d rv1(1, 2); // 2维行向量，并赋值
    Eigen::RowVectorXd rv2(5); // 动态行向量，初始化为5维
    rv2 << 1, 2, 3, 4, 5;

    cout << m1(1, 1) << endl; // 输出指定位置的值
    cout << v1(1) << endl;

    return 0;
}
