/*
 * @Description: 
 * @Author: HCQ
 * @Company(School): UCAS
 * @Email: 1756260160@qq.com
 * @Date: 2021-05-11 16:05:00
 * @LastEditTime: 2021-05-11 16:06:41
 * @FilePath: /c-plus-plus/Cpp-0-1-Resource/第6阶段实战-基于STL泛化编程的演讲比赛资料/资料/代码/基于STL的演讲比赛流程管理系统/╗∙╙┌STL╡─╤▌╜▓▒╚╚ⁿ┴≈│╠╣▄└φ╧╡═│/╗∙╙┌STL╡─╤▌╜▓▒╚╚ⁿ┴≈│╠╣▄└φ╧╡═│/speechManager.h
 */
#pragma once 
#include <iostream>
using namespace std;
#include <vector>
#include <map>
#include "speaker.h"
#include <algorithm>
#include <deque>
#include <functional>
#include <numeric>
#include <string>
#include <fstream>


//设计演讲管理类
class SpeechManager
{
public:

	//构造函数
	SpeechManager();

	//菜单功能
	void show_Menu();

	//退出系统
	void exitSystem();

	//析构函数
	~SpeechManager();

	//初始化容器和属性
	void initSpeech();

	//创建12名选手
	void createSpeaker();

	//开始比赛  比赛整个流程控制函数
	void startSpeech();

	//抽签
	void speechDraw();

	//比赛
	void speechContest();

	//显示得分
	void showScore();

	//保存记录
	void saveRecord();

	//读取记录
	void loadRecord();

	//显示往届记录
	void showRecord();

	//清空文件
	void clearRecord();


	//判断文件是否为空
	bool fileIsEmpty;

	//存放往届记录的容器
	map<int, vector<string>>m_Record;

	//成员属性
	//保存第一轮比赛选手编号容器
	vector<int>v1;

	//第一轮晋级选手编号容器
	vector<int>v2;

	//胜出前三名选手编号容器
	vector<int>vVictory;

	//存放编号以及对应具体选手容器
	map<int, Speaker>m_Speaker;

	//存放比赛轮数 
	int m_Index;

};