/*
 * @Description: 外加参数
 * 测试：  ./01参数 /2020-08-21-09-57-41.bag  /src/pcd_all
 * @Author: HCQ
 * @Company(School): UCAS
 * @Email: 1756260160@qq.com
 * @Date: 2021-03-03 18:36:31
 * @LastEditTime: 2021-03-03 18:49:55
 * @FilePath: /c-plus-plus/practice/01参数.cpp
 */
#include<iostream>  
#include <boost/filesystem.hpp>
#include <boost/foreach.hpp>
using namespace std;



int main(int argc, char *argv[]) {
  if (argc < 3) {
    std::cerr << "Too little params !" << std::endl;
    return -1;
  } else if (argc > 3) {
    std::cerr << "Too many params !" << std::endl;
    return -2;
  }

    //CCLib::DgmOctree* theOctree;
  std::string bag_path = argv[1];   // .. /2020-08-21-09-57-41.bag
  cout<<bag_path<<endl;
  std::string source_folder = argv[2];  // ../src/pcd_all
  cout<<source_folder<<endl;
  // // 判断文件类型
  // bag_path = "asgd.bag";
  // boost::filesystem::path f(bag_path);
  // std::string extensionname = f.extension().string();
  // if (extensionname != ".bag") {   // 判断是不是bag文件
  //   std::cerr << "Not a bag  !" << std::endl;
  //   }else{
  //       std::cerr << "is  a bag  !" << std::endl;
  //   }

}