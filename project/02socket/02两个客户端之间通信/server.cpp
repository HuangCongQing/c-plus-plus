#include <stdio.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <stdlib.h>
#include <string.h>
#include<pthread.h>
#include <unistd.h> // fix: error: ‘close’ was not declared in this scope; 

#define PORT   8888

struct info
{
    char buf[100];
    int Tofd;
};

void *MyReceive(void *arg)
{
    struct info Recvbuf = {0};
    int ret;

    pthread_detach(pthread_self());

    while(1)
    {
        ret = recv(*(int *)arg,&Recvbuf,sizeof(Recvbuf),0);
        if(-1 == ret)
        {
            perror("recv");
            exit(1);
        }
        if(!strcmp(Recvbuf.buf,"bye"))
        {
            close(*(int *)arg);
            break;
        }

        ret = send(Recvbuf.Tofd,&Recvbuf,sizeof(Recvbuf),0);
        if(-1==ret)
        {
            perror("send");
            exit(1);
        }
        memset(&Recvbuf, 0, sizeof(Recvbuf));
    }
}

int main()
{
    int sockfd, ret,fd[100]={0}, i=0,length;
    pthread_t tid[100]={0};
    char buf[100] = {0};
    struct sockaddr_in server_addr;                
    struct sockaddr_in client_addr;                

    printf("Start Server!\n");
    sockfd = socket(PF_INET, SOCK_STREAM, 0);      
    if (-1 == sockfd)
    {
        perror("socket");
        exit(1);
    }

    int opt = 1;
    setsockopt(sockfd, SOL_SOCKET, SO_REUSEADDR, &opt, sizeof(opt));

    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = PF_INET;                               
    server_addr.sin_port = PORT;                                    
    server_addr.sin_addr.s_addr = inet_addr("127.0.0.1");       

    ret = bind(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr));   
    if (-1 == ret)
    {
        perror("bind");
        exit(1);
    }

    printf("Listening...\n");
    ret = listen(sockfd, 5);                              
    if(-1 == ret)
    {
        perror("listen");
        exit(1);
    }

    while(1)
    {
        length = sizeof(client_addr);
        fd[i] = accept(sockfd, (struct sockaddr *)&client_addr, (socklen_t*)&length); // fix: https://bbs.csdn.net/topics/380235557
        if (-1 == fd[i])
        {
            perror("accept");
            exit(1);
        }

        printf("Accept %d , Port %d\n", fd[i], client_addr.sin_port);

        ret =pthread_create(&tid[i],NULL,MyReceive,(void *)&fd[i]);
        if(0 != ret)
        {
            perror("pthread_create");
            exit(1);
        }
        i++;
    }

    close(sockfd);

    return 0;
}