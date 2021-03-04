/*
 * @Description: c++读取txt文件，按空格分割字符串
 * @Author: HCQ
 * @Company(School): UCAS
 * @Email: 1756260160@qq.com
 * @Date: 2021-03-03 18:06:38
 * @LastEditTime: 2021-03-04 14:17:50
 * @FilePath: /c-plus-plus/practice/02c++读取txt文件按空格分割字符串.cpp
 */

#include<iostream>  
#include<sstream>  
#include<fstream>
#include<iomanip>
using namespace std;

 
// main() 是程序开始执行的地方
 
int main()
{
   double x, y, z;
	char line[1024] = { 0 };
	ifstream infile;
	infile.open("/home/hcq/data/pcd/RS-LiDAR-16-pcd/process/1134off-ground points.txt"); // txt文件
    while(	infile.getline(line, sizeof(line))){ // 遍历每行
        stringstream word(line);  //采用字符流格式将读取的str进行空格分隔，并放入str word中
        word >> x >> y >> z;
    
        cout << x << " " << y << " " << z << endl;   // 小数点4位  -12.8349 -2.35511 -1.0137
        // cout << fixed << setprecision(9) << x << " " << y << " " << z << endl;   // 小数点9位 -2.295508150 -0.421606420 2.291652680
    }
 

   return 0;
}
