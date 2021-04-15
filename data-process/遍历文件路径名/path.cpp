/*
 * @Description: 获取路径名 后缀名等
 运行：添加 -lboost_system -lboost_filesystem  属性进行编译
 命令：
 cd "/home/hcq/github/c-plus-plus/data-process/遍历文件路径名/" && g++ path.cpp -o path -lboost_system -lboost_filesystem && "/home/hcq/github/c-plus-plus/data-process/遍历文件路径名/"path
 * @Author: HCQ
 * @Company(School): UCAS
 * @Email: 1756260160@qq.com
 * @Date: 2021-04-15 15:57:19
 * @LastEditTime: 2021-04-15 16:20:07
 * @FilePath: /c-plus-plus/data-process/遍历文件路径名/path.cpp
 */
// 遍历文件
#include <boost/filesystem/operations.hpp>
#include <boost/filesystem/path.hpp>
#include <boost/filesystem.hpp>
#include <iostream>
using namespace std;
namespace fs = boost::filesystem;

int main()
{
    std::string pcd_all_path = "/home/hcq/data/curb/Test/shenbao_pcd/1one_pcd_test"; // pcd文件
    // std::string  pcd_all_path = "/home/hcq/data/curb/Test/shenbao_pcd/1one_pcd_test";  //json或者txt文件
    for (auto &it : boost::filesystem::directory_iterator(pcd_all_path))
    {
        std::string strPath = it.path().string(); //遍历出来的文件名称
        std::string filename = it.path().filename().string(); //文件名称
        std::string stem = it.path().stem().string(); //不带后缀的文件名
        std::string extension = it.path().extension().string(); //后缀名

        std::cout << "完整路径:" << strPath << std::endl;
        std::cout <<  "文件名:" << filename << std::endl;  // filename:1600050937.416284.pcd
        std::cout <<  "不带后缀的文件名:" << stem << std::endl;  //不带后缀的文件名:1600050937.416284
        std::cout <<  "后缀名:" << extension << std::endl;  //  后缀名:.pcd
    }
    return 0;
}