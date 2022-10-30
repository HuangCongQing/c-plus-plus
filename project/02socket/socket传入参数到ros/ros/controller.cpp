/*
 * @Description: Socket向ROS传递参数  https://www.yuque.com/huangzhongqing/lang/hze9zs
 * @Author: HCQ
 * @Company(School): UCAS
 * @Email: 1756260160@qq.com
 * @Date: 2022-10-28 01:14:19
 * @LastEditTime: 2022-10-28 01:17:11
 * @FilePath: /c-plus-plus/project/01消息队列/02socket传入参数到ros/ros/controller.cpp
 */

#include "ros/ros.h"
#include <visualization_msgs/Marker.h>
#include "std_msgs/String.h"
#include <sstream>
#include<stdio.h>
#include<sys/types.h>
#include<stdlib.h>
#include<string>
#include<sys/socket.h>
#include<netinet/in.h>
#include<arpa/inet.h>
#include<unistd.h>
#include<iostream>
#include "ROS_Socket_adaptor/data.h"

using namespace std;

int main(int argc, char **argv)
{

  ros::init(argc, argv, "controller");

  ros::NodeHandle n;


  ros::Publisher controller = n.advertise<visualization_msgs::Marker>("visualization_marker", 10);

  ros::Rate loop_rate(1);


    //1.创建一个socket

    int socket_fd = socket(AF_INET, SOCK_STREAM, 0);
    if (socket_fd == -1)
    {
        cout << "socket 创建失败： "<< endl;
        exit(1);
    }
    //2.准备通讯地址（必须是服务器的）
    struct sockaddr_in addr;
    addr.sin_family = AF_INET;
    addr.sin_port = htons(8888);//将一个无符号短整型的主机数值转换为网络字节顺序，即大尾顺序(big-endian)
    addr.sin_addr.s_addr = inet_addr("127.0.0.1");//net_addr方法可以转化字符串，主要用来将一个十进制的数转化为二进制的数，用途多于ipv4的IP转化。
    //3.bind()绑定

    int res = bind(socket_fd,(struct sockaddr*)&addr,sizeof(addr));

  while (ros::ok())
  {

    ROS_Socket_adaptor::data msg;

   if (res == -1)
    {
        //cout << "bind创建失败： " << endl;
        //exit(-1);
    }
    cout << "bind ok 等待客户端的连接" << endl;
    //4.监听客户端listen()函数
    listen(socket_fd,30);
    //5.等待客户端的连接accept()，返回用于交互的socket描述符
    struct sockaddr_in client;
    socklen_t len = sizeof(client);
    int fd = accept(socket_fd,(struct sockaddr*)&client,&len);
    if (fd == -1)
    {
        cout << "accept错误\n" << endl;
        exit(-1);
    }
    //6.使用第5步返回socket描述符，进行读写通信。
    char *ip = inet_ntoa(client.sin_addr);
    cout << "客户： 【" << ip << "】连接成功" << endl;
  
    float buffer[4]={0};
    recv(fd,(char*)buffer,sizeof(buffer),0);
    //int size = read(fd, buffer, sizeof(buffer));//通过fd与客户端联系在一起,返回接收到的字节数

    //cout << "接收到字节数为： " << size << endl;
    //cout << "内容： " << buffer[1] << endl;

    msg.c0 = buffer[0];
    msg.c1 = buffer[1];
    msg.c2 = buffer[2];
    msg.c3 = buffer[3];
    ROS_INFO("%f %f %f %f", msg.c0, msg.c1, msg.c2, msg.c3);

    float c0 = buffer[0];
    float c1 = buffer[1];
    float c2 = buffer[2];
    float c3 = buffer[3];

    visualization_msgs::Marker points, line_strip, line_list;
    points.header.frame_id = line_strip.header.frame_id = line_list.header.frame_id = "map";
    points.header.stamp = line_strip.header.stamp = line_list.header.stamp = ros::Time::now();
    points.ns = line_strip.ns = line_list.ns = "points_and_lines";
    points.action = line_strip.action = line_list.action = visualization_msgs::Marker::ADD;
    points.pose.orientation.w = line_strip.pose.orientation.w = line_list.pose.orientation.w = 1.0;



    points.id = 0;
    line_strip.id = 1;
    line_list.id = 2;



    points.type = visualization_msgs::Marker::POINTS;
    line_strip.type = visualization_msgs::Marker::LINE_STRIP;
    line_list.type = visualization_msgs::Marker::LINE_LIST;



    // POINTS markers use x and y scale for width/height respectively
    points.scale.x = 0.2;
    points.scale.y = 0.2;

    // LINE_STRIP/LINE_LIST markers use only the x component of scale, for the line width
    line_strip.scale.x = 0.1;
    line_list.scale.x = 0.1;



    // Points are green
    points.color.g = 1.0f;
    points.color.a = 0.0;

    // Line strip is blue
    line_strip.color.b = 1.0;
    line_strip.color.a = 1.0;

    // Line list is red
    line_list.color.r = 1.0;
    line_list.color.a = 0.0;



    // Create the vertices for the points and lines
    for (uint32_t i = 0; i < 100; ++i)
    {
      float y = c3*i*i*i + c2*i*i + c1*i + c0;
      float z = 0;

      geometry_msgs::Point p;
      p.x = (int32_t)i;
      p.y = y;
      p.z = z;

      points.points.push_back(p);
      line_strip.points.push_back(p);

      // The line list needs two points for each line
      line_list.points.push_back(p);
      p.z += 1.0;
      line_list.points.push_back(p);
    }


    controller.publish(points);
    controller.publish(line_strip);
    controller.publish(line_list);

    //controller.publish(msg);
     
    ros::spinOnce();

    loop_rate.sleep();
  }


  return 0;
}
