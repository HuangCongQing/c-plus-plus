/*
 * @Description: 读取txt文件   https://zhuanlan.zhihu.com/p/133882142
 * @Author: HCQ
 * @Company(School): UCAS
 * @Email: 1756260160@qq.com
 * @Date: 2021-04-20 10:00:47
 * @LastEditTime: 2021-04-20 10:34:27
 * @FilePath: /c-plus-plus/data-process/txt/03保存txt文件.cpp
 */
#include <iostream>
#include <fstream> // c++文件操作
#include <iomanip> // 设置输出格式
#include<time.h>
#include<string>


using namespace std;

int main(int argc, char const *argv[])
{

    time_t currentTime=time(NULL);
	char chCurrentTime[256];
	strftime(chCurrentTime,sizeof(chCurrentTime),"%Y%m%d %H%M%S",localtime(&currentTime));
    string stCurrentTime=chCurrentTime;
    string filename="data"+stCurrentTime+".txt";
    // 定义/打开输出的txt文件
    ofstream out_txt_file;
    out_txt_file.open(filename,  ios::out | ios::trunc);
    out_txt_file << fixed;

    // 保存数据到文件中
    for(int i = 0; i < 10; i++)
    {
        out_txt_file << setprecision(4) << i << ","<< i +2 << endl;
    }
    // 关闭文件
    out_txt_file.close();

    return 0;
}