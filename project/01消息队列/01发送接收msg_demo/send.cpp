/*
 * @Description: 发送
 * @Author: HCQ
 * @Company(School): UCAS
 * @Email: 1756260160@qq.com
 * @Date: 2022-10-27 23:08:06
 * @LastEditTime: 2022-10-27 23:52:45
 * @FilePath: /c-plus-plus/project/01消息队列/01发送接收msg_demo/send.cpp
 */
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#define MAX_TEXT 512
struct my_msg_st
{
    long int my_msg_type;
    char some_text[MAX_TEXT];
};

typedef struct {
    int TartgetID; //告警物体的ID号，每个告警物体应该具有唯一ID号
    int alarmtype; //告警类型，0-无告警，1-过近距离，2-过高物体
    int alarmlevel; //告警级别，数字越高，级别越高，风险或危险越大
    int Height; //物体的高度，单位cm。
    int Distance; //物体距离电线的最近距离；单位cm
    int colorR; //输出点云中，距离线和高度线的颜色R
    int colorG; //输出点云中，距离线和高度线的颜色G
    int colorB; //输出点云中，距离线和高度线的颜色B
} AlarmTargets;


int main()
{
    int running = 1;
    struct my_msg_st some_data; // 结构体实例化
    int msgid;
    char buffer[BUFSIZ]; // buffer[512]
 
 
    msgid = msgget((key_t)1234, 0666|IPC_CREAT); //用一个整数作为一个键值
    if(msgid==-1)
    {
        fprintf(stderr,"msgget failed with errno: %d\n", errno);
        exit(EXIT_FAILURE);
    }
     while(running)
    {
        printf("Enter some text: ");
        fgets(buffer, BUFSIZ, stdin); // buffer输入信息
        some_data.my_msg_type = 1; // 赋值
        strcpy(some_data.some_text, buffer); // 赋值
        if(msgsnd(msgid, (void *)&some_data, MAX_TEXT, 0)==-1)
        {
            fprintf(stderr, "msgsnd failed\n");
            exit(EXIT_FAILURE);
        }
        if(strncmp(buffer, "end", 3) == 0) // 输入end退出
        {
            running = 0;
        }
    }
     exit(EXIT_SUCCESS);
}