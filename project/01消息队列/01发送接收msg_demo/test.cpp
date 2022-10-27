/*
 * @Description: 
 * @Author: HCQ
 * @Company(School): UCAS
 * @Email: 1756260160@qq.com
 * @Date: 2022-10-27 23:08:22
 * @LastEditTime: 2022-10-27 23:08:38
 * @FilePath: /c-plus-plus/project/01消息队列/01demo/test.cpp
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>
struct my_msg_st
{
    long int my_msg_type;
    char some_text[BUFSIZ];
};
int main()
{
    int running = 1;
    int msgid;
    struct my_msg_st some_data;
    long int msg_to_receive = 0;  //如果为0，表示消息队列中的所有消息都会被读取
 
    //创建消息队列：
    msgid = msgget((key_t)1234,0666|IPC_CREAT);
    if(msgid == -1)
    {
        fprintf(stderr,"msgget failed with error: %d\n", errno);
        exit(EXIT_FAILURE);
    }
  
    //接收消息队列中的消息直到遇到一个end消息。最后，消息队列被删除。
    while(running)
    {
        //第5个参数为0表示阻塞方式，当消息队列为空，一直等待
        if(msgrcv(msgid, (void *)&some_data, BUFSIZ, msg_to_receive, 0) == -1)
        {
            fprintf(stderr, "msgrcv failed with errno: %d\n", errno);
            exit(EXIT_FAILURE);
        }
 
        printf("You wrote: %s", some_data.some_text);
        if(strncmp(some_data.some_text, "end", 3)==0)
        {
            running = 0;
        }
    }
    if(msgctl(msgid, IPC_RMID, 0)==-1) // 删除消息队列
    {
        fprintf(stderr, "msgctl(IPC_RMID) failed\n");
        exit(EXIT_FAILURE);
    }
    exit(EXIT_SUCCESS);
}