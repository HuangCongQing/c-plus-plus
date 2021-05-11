/*
 * @Description: 
 * @Author: HCQ
 * @Company(School): UCAS
 * @Email: 1756260160@qq.com
 * @Date: 2021-05-11 16:05:00
 * @LastEditTime: 2021-05-11 16:06:33
 * @FilePath: /c-plus-plus/Cpp-0-1-Resource/第6阶段实战-基于STL泛化编程的演讲比赛资料/资料/代码/基于STL的演讲比赛流程管理系统/╗∙╙┌STL╡─╤▌╜▓▒╚╚ⁿ┴≈│╠╣▄└φ╧╡═│/╗∙╙┌STL╡─╤▌╜▓▒╚╚ⁿ┴≈│╠╣▄└φ╧╡═│/╤▌╜▓▒╚╚ⁿ┴≈│╠╣▄└φ╧╡═│.cpp
 */
#include <iostream>
using namespace std;
#include "speechManager.h"
#include<string>
#include <ctime>
int main()
{
	//随机数种子
	srand((unsigned int)time(NULL));
	//创建管理类对象
	SpeechManager sm;

	//测试12名选手创建
	//for (map<int, Speaker>::iterator it = sm.m_Speaker.begin(); it != sm.m_Speaker.end(); it++)
	//{
	//	cout << "选手编号： " << it->first << " 姓名： " << it->second.m_Name << " 分数： " << it->second.m_Score[0] << endl;
	//}

	int choice = 0; //用于存储用户输入

	while (true)
	{
		sm.show_Menu();

		cout << "请输入您的选择： " << endl;
		cin >> choice;

		switch (choice)
		{
		case 1: // 开始比赛
			sm.startSpeech();
			break;
		case 2: //查看往届比赛记录
			sm.showRecord();
			break;
		case 3:  //清空比赛记录
			sm.clearRecord();
			break;
		case 0:  //退出系统
			sm.exitSystem();
			break;
		default:
			system("cls"); // 清屏
			break;
		}
	}
	

	system("pause");
	return 0;
}