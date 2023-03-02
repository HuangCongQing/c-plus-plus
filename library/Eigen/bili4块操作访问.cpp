/*
 * @Description: https://www.bilibili.com/video/BV18V41167wz?p=4
 * @Author: HCQ
 * @Company(School): UCAS
 * @Email: 1756260160@qq.com
 * @Date: 2020-12-27 18:12:28
 * @LastEditTime: 2020-12-27 18:37:19
 * @FilePath: /c-plus-plus/Eigen/bili4块操作访问.cpp
 */

#include <iostream>
#include <Eigen/Dense>
using namespace Eigen;
using namespace std;

int main(){
    
    // 向量块操作访问
    ArrayXd vec(9);
    vec<<1,2,3,4,5,6,7,8,9;
    cout<<vec<<endl;
    cout<<"vec.head(3)"<<endl; // 前三个
    cout<<vec.head(3)<<endl; // 前三个
    cout<<"vec.tail(3)"<<endl;  // 后三个
    cout<<vec.tail(3)<<endl;  // 后三个
    cout<<"vec.segment(3,2)"<<endl;
    cout<<vec.segment(3,2)<<endl;// 从index=3，抽取2个  segment(Eigen::Index start, Eigen::Index n)
    
    // 矩阵块操作
    MatrixXd mat(4,4);
    mat<<1,2,3,4,
                5,6,7,8,
                9,10,11,12,
                13,14,15,16;
    cout<<"mat"<<mat<<endl;
    cout<<"第3列mat.col(3)"<<endl;
    cout<<mat.col(3)<<endl;
    cout<<"第3行mat.row(3)"<<endl;
    cout<<mat.row(3)<<endl;
    // block操作 四个参数
    cout<<"mat.block(1,1,2,2)"<<endl;
    cout<<mat.block(1,1,2,2)<<endl;
    cout<<"<几行几列>(参考点坐标)"<<endl;//
    cout<<mat.block<2,2>(1,1)<<endl;//<几行几列>(参考点坐标)
/* 参数:
startRow – the first row in the block
startCol – the first column in the block
blockRows – the number of rows in the block
blockCols – the number of columns in the block Example:
 */
    return 0;
}
