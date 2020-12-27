/*
 * @Description: https://www.bilibili.com/video/BV18V41167wz?p=2
 * @Author: HCQ
 * @Company(School): UCAS
 * @Email: 1756260160@qq.com
 * @Date: 2020-12-27 13:13:27
 * @LastEditTime: 2020-12-27 16:26:05
 * @FilePath: /c-plus-plus/Eigen/bili1.cpp
 */

#include <iostream>
#include <Eigen/Dense>
using namespace Eigen;
using namespace std;


template <typename T> using Mat2 = Matrix<T, 2, 2> ;  //  Matrix<T, 2, 2>类型用Mat2表示

int main(int argc, char *argv[]){
    // 方法一：自定义
    Mat2<int> mat1;
    mat1<<1, 1,
                    1,1;
    cout<<mat1<<endl;

    // 方法二
    Vector2d vec1;
    vec1<<1,2;
    cout<<vec1<<endl;

    // 方法三最常用
    MatrixXd mat(2,2);
    for(int i=0; i<2;i++)
    for(int j=0;j<2;j++)
    mat(i,j) = 1;
    cout<<mat<<endl;
    
    return 0;
}