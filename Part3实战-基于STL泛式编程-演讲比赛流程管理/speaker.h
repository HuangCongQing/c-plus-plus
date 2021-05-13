/*
 * @Description: 
 * @Author: HCQ
 * @Company(School): UCAS
 * @Email: 1756260160@qq.com
 * @Date: 2021-05-11 16:11:19
 * @LastEditTime: 2021-05-13 12:57:05
 * @FilePath: /c-plus-plus/Part3实战-基于STL泛式编程-演讲比赛流程管理/speaker.h
 */
#pragma once  // 防止头文件重复包含
#include <iostream>
using namespace std;

//选手类
class Speaker
{
public:

	string m_Name;    //姓名
	double m_Score[2]; //分数  最多有两轮得分
};