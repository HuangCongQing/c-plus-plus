/*
 * @Description: 
 * @Author: HCQ
 * @Company(School): UCAS
 * @Email: 1756260160@qq.com
 * @Date: 2022-10-28 00:41:25
 * @LastEditTime: 2022-10-28 03:15:11
 * @FilePath: /electrical-wire-around-obstacle-detection/test/interface.cpp
 */

#include<stdio.h>
#include<sys/types.h>
#include<stdlib.h>
#include<string>
#include<sys/socket.h>
#include<netinet/in.h>
#include<arpa/inet.h>
#include<unistd.h>
#include<iostream>

// #include "cv.h"
// #include "highgui.h"

#include "interface.h"

using namespace std;


Interface::Interface(){
}

//析构函数===================
Interface::~Interface(){}



void Interface::SetMonitoringArea(float LeftWidth, float RightWidth, float MaxDistance)
{
    std::cout<<"设置区域"<<LeftWidth<<" "<<RightWidth<<"  "<<MaxDistance<<std::endl;
}