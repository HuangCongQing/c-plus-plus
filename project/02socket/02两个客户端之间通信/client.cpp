#include <stdio.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <stdlib.h>
#include <string.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include<pthread.h>
#include <unistd.h>


#define PORT    8888

struct info
{
    char buf[100];
    int Tofd;
};

pthread_t tid[2]={0};

void *Send(void *arg)
{
    struct info Sendbuf = {0};
    int ret;

    while (1)
    {
        scanf("%s%d", Sendbuf.buf,&Sendbuf.Tofd);

        ret = send(*(int *)arg,&Sendbuf, sizeof(Sendbuf), 0);     
        if (-1 == ret)
        {
            perror("send");
            exit(1);
        }

        if (!strcmp(Sendbuf.buf, "bye"))
        {
            close(*(int *)arg);
            pthread_cancel(tid[1]);
            break;
        }

        memset(&Sendbuf, 0, sizeof(Sendbuf));
    }
}

void *Recv(void *arg)
{
    struct info Recvbuf = {0};
    int ret,oldtype;
    pthread_setcanceltype(PTHREAD_CANCEL_ASYNCHRONOUS,&oldtype);

    while (1)
    {
        ret = recv(*(int *)arg,&Recvbuf, sizeof(Recvbuf), 0);      
        if (-1 == ret)
        {
            perror("recv");
            exit(1);
        }

        printf("\t\t\t%s\n",Recvbuf.buf);

        memset(&Recvbuf, 0, sizeof(Recvbuf));
    }
}

int main()
{
    int sockfd, ret;
    struct sockaddr_in server_addr;              

    sockfd = socket(PF_INET, SOCK_STREAM, 0);    
    if (-1 == sockfd)
    {
        perror("socket");
        exit(1);
    }

    memset(&server_addr, 0, sizeof(server_addr));     
    server_addr.sin_family = PF_INET;
    server_addr.sin_port = PORT;
    server_addr.sin_addr.s_addr = inet_addr("127.0.0.1");   

    printf("Start Connecting...\n");
    ret = connect(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr));
    if (-1 == ret)
    {
        perror("connect");
        exit(1);
    }

    ret = pthread_create(&tid[0],NULL,Send,(void *)&sockfd);
    if(0 != ret)
    {
        perror("pthread_create1");
        exit(1);
    }

    ret = pthread_create(&tid[1],NULL,Recv,(void *)&sockfd);
    if(0 != ret)
    {
        perror("pthread_create1");
        exit(1);
    }

    pthread_join(tid[0],NULL);
    pthread_join(tid[1],NULL);
    close(sockfd);

    return 0;
}
