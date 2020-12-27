/*
 * @Description: 常用自带函数
 * @Author: HCQ
 * @Company(School): UCAS
 * @Email: 1756260160@qq.com
 * @Date: 2020-12-27 16:27:04
 * @LastEditTime: 2020-12-27 16:30:50
 * @FilePath: /c-plus-plus/Eigen/bili1常用自带函数.cpp
 */

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
    MatrixXd mat1=MatrixXd::Zero(2,2);
    MatrixXd mat2=MatrixXd::Ones(2,2);
    MatrixXd mat3=MatrixXd::Identity(2,2); // 单位阵
    MatrixXd mat4=MatrixXd::Random(2,2); // 随机阵
    
    std::cout<<mat1<<endl;
    std::cout<<mat2<<endl;
    std::cout<<mat3<<endl;
    std::cout<<mat4<<endl;
    return 0;
}