/*
 * @Description: 读取txt文件 参考：https://blog.csdn.net/weixin_42915431/article/details/107893794
 * @Author: HCQ
 * @Company(School): UCAS
 * @Email: 1756260160@qq.com
 * @Date: 2021-04-14 15:47:24
 * @LastEditTime: 2021-04-14 16:08:41
 * @FilePath: /c-plus-plus/data-process/txt/01c++读取txt文件按空格分割字符串.cpp
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
	infile.open("/home/hcq/github/c-plus-plus/data-process/txt/labelme_test.txt"); // txt文件
    int lineCnt=0;
    while(	infile.getline(line, sizeof(line))){ // 遍历每行
        stringstream word(line);  //采用字符流格式将读取的str进行空格分隔，并放入str word中
        word >> x >> y >> z;
    	lineCnt++;
        cout << x << " " << y << " " << z << endl;   // 小数点4位  -12.8349 -2.35511 -1.0137
        // cout << fixed << setprecision(9) << x << " " << y << " " << z << endl;   // 小数点9位 -2.295508150 -0.421606420 2.291652680
    }
    cout << "行数"<<lineCnt+1<<endl;
 

   return 0;
}
