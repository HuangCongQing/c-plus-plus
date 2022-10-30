/*
 * @Description: 文档：https://www.yuque.com/huangzhongqing/lang/hze9zs/
 * @Author: HCQ
 * @Company(School): UCAS
 * @Email: 1756260160@qq.com
 * @Date: 2022-10-28 01:13:39
 * @LastEditTime: 2022-10-28 01:13:44
 * @FilePath: /c-plus-plus/project/01消息队列/02socket传入参数到ros/client.cpp
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

using namespace std;

int main()
{
while(true){
    int socket_fd = socket(AF_INET, SOCK_STREAM,0);
    if(socket_fd == -1)
    {
        cout<<"socket 创建失败："<<endl;
        exit(-1);
    }

    struct sockaddr_in addr;
    addr.sin_family = AF_INET;
    addr.sin_port = htons(8888);
    addr.sin_addr.s_addr = inet_addr("127.0.0.1");

    int res = connect(socket_fd,(struct sockaddr*)&addr,sizeof(addr));
    if(res == -1)
    {
        //cout<<"bind 链接失败："<<endl;
        //exit(-1);
    }
    cout<<"bind 链接成功："<<endl;

    float a[4]={1.1,1.2,1.3,1.4};
    send(socket_fd,(char*)a,sizeof(a),0);
    close(socket_fd);
    sleep(1);}

    return 0;
}

