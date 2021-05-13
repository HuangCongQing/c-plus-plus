/*
 * @Description: 
 * @Author: HCQ
 * @Company(School): UCAS
 * @Email: 1756260160@qq.com
 * @Date: 2021-05-11 16:05:00
 * @LastEditTime: 2021-05-13 13:02:47
 * @FilePath: /c-plus-plus/Part3实战-基于STL泛式编程-演讲比赛流程管理/speechManager.h
 */
#pragma once // 防止头文件重复编译
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

	//构造函数---------
	SpeechManager();

	//析构函数---------
	~SpeechManager();

	//菜单功能
	void show_Menu();

	//退出系统
	void exitSystem();

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
	map<int, Speaker>m_Speaker;   // class Speaker选手类   #include "speaker.h"

	//存放比赛轮数 
	int m_Index;

};