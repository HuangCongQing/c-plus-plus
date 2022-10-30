/*
 * @Description: demo测试
 * @Author: HCQ
 * @Company(School): UCAS
 * @Email: 1756260160@qq.com
 * @Date: 2022-10-28 00:45:50
 * @LastEditTime: 2022-10-28 03:07:57
 * @FilePath: /electrical-wire-around-obstacle-detection/test/main.cpp
 */




#include <vector>
#include <iostream>
#include <math.h>


#include<stdio.h>
#include<sys/types.h>
#include<stdlib.h>
#include<string>
#include<sys/socket.h>
#include<netinet/in.h>
#include<arpa/inet.h>
#include<unistd.h>
#include<iostream>



#include "interface.h"


using namespace std;


int main (int argc, char** argv){
    std::cout<<"test"<<std::endl;
    Interface interface;
    interface.SetMonitoringArea(20, 20, 20); // 设置监控区域

    return 0;
}