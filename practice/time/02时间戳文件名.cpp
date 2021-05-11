/*
 * @Description: 
 * @Author: HCQ
 * @Company(School): UCAS
 * @Email: 1756260160@qq.com
 * @Date: 2021-04-20 10:38:04
 * @LastEditTime: 2021-04-20 10:40:16
 * @FilePath: /c-plus-plus/practice/time/02时间戳文件名.cpp
 */
// https://blog.csdn.net/qq_38418182/article/details/104556444?utm_medium=distribute.pc_relevant.none-task-blog-baidujs_title-0&spm=1001.2101.3001.4242



#include <fstream>
#include<iostream>
#include<time.h>
#include<string>
int main()
{
	using namespace std;

    time_t currentTime=time(NULL);
	char chCurrentTime[256];
	strftime(chCurrentTime,sizeof(chCurrentTime),"%Y%m%d %H%M%S",localtime(&currentTime));
    string stCurrentTime=chCurrentTime;
    string filename="data"+stCurrentTime+".txt";////////////////////////////////////////////////////////
    cout<< filename<< endl;
	// ofstream fout;
	// fout.open(filename.c_str());
	// int v_set,v_act,a_set,a_act;
	// int i=0;
	// while(i<5)
	// {
	// 	cin>>v_set>>v_act>>a_set>>a_act;
    // 	fout<<v_set<<", "<<v_act<<", "<<a_set<<", "<<a_act<<", "<<endl;
    // 	i++;
    // }
	// fout<<flush;
	// fout.close();
}

