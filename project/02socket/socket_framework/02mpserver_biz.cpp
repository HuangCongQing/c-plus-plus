/*
 *  程序名：mpserver_biz.cpp，此程序演示采用freecplus框架的CTcpServer类实现socket通信多进程的服务端。
 *  增加了业务示例。
 *  作者：C语言技术网(www.freecplus.net) 日期：20190525
*/
#include "_freecplus.h"
using namespace std;
 
// CLogFile logfile;
CTcpServer TcpServer;   // 创建服务端对象。

// 程序退出时调用的函数
void FathEXIT(int sig);   // 父进程退出函数。
void ChldEXIT(int sig);   // 子进程退出函数。

// 处理业务的主函数。
bool _main(const char *strrecvbuffer,char *strsendbuffer);  

// 心跳报文。
bool biz000(const char *strrecvbuffer,char *strsendbuffer);  

// 身份验证业务处理函数。
bool biz001(const char *strrecvbuffer,char *strsendbuffer);  

// 查询余客业务处理函数。
bool biz002(const char *strrecvbuffer,char *strsendbuffer);  

int main(int argc,char *argv[])
{
  // if (argc!=3)
  // {
  //   printf("Using:./mpserver_biz port logfile\nExample:./mpserver_biz 5005 /tmp/mpserver_biz.log\n\n"); return -1;
  // }

  // 关闭全部的信号
  for (int ii=0;ii<100;ii++) signal(ii,SIG_IGN);

  // 打开日志文件。
  // if (logfile.Open(argv[2],"a+")==false) { printf("logfile.Open(%s) failed.\n",argv[2]); return -1;}

  // 设置信号,在shell状态下可用 "kill + 进程号" 正常终止些进程
  // 但请不要用 "kill -9 +进程号" 强行终止
  signal(SIGINT,FathEXIT); signal(SIGTERM,FathEXIT);
 
  if (TcpServer.InitServer(5005)==false) // 初始化TcpServer的通信端口。
  {
    printf("TcpServer.InitServer 5005 failed.\n"); FathEXIT(-1);
  }
 
  while (true)
  {
    if (TcpServer.Accept()==false)   // 等待客户端连接。
    {
      printf("TcpServer.Accept() failed.\n"); continue;
    }

    if (fork()>0) { TcpServer.CloseClient(); continue; } // 父进程返回到循环首部。

    // 子进程重新设置退出信号。
    signal(SIGINT,ChldEXIT); signal(SIGTERM,ChldEXIT);

    TcpServer.CloseListen();
 
    // 以下是子进程，负责与客户端通信。
    printf("客户端(%s)已连接。\n",TcpServer.GetIP());
 
    char strrecvbuffer[1024],strsendbuffer[1024];  // 存放数据的缓冲区。
 
    while (true)
    {
      memset(strrecvbuffer,0,sizeof(strrecvbuffer));
      memset(strsendbuffer,0,sizeof(strsendbuffer));

      if (TcpServer.Read(strrecvbuffer,30)==false) break; // 接收客户端发过来的请求报文。
      printf("接收：%s\n",strrecvbuffer);

      // 处理业务的主函数。
      if (_main(strrecvbuffer,strsendbuffer)==false) ChldEXIT(-1); 
 
      printf("发送：%s\n",strsendbuffer);
      if (TcpServer.Write(strsendbuffer)==false) break;     // 向客户端回应报文。
    }
 
    printf("客户端已断开。\n");    // 程序直接退出，析构函数会释放资源。

    ChldEXIT(-1);  // 通信完成后，子进程退出。
  }
}

// 父进程退出时调用的函数
void FathEXIT(int sig)
{
  if (sig > 0)
  {
    signal(sig,SIG_IGN); signal(SIGINT,SIG_IGN); signal(SIGTERM,SIG_IGN);
    printf("catching the signal(%d).\n",sig);
  }

  kill(0,15);  // 通知其它的子进程退出。

  printf("父进程退出。\n");

  // 编写善后代码（释放资源、提交或回滚事务）
  TcpServer.CloseClient();

  exit(0);
}

// 子进程退出时调用的函数
void ChldEXIT(int sig)
{
  if (sig > 0)
  {
    signal(sig,SIG_IGN); signal(SIGINT,SIG_IGN); signal(SIGTERM,SIG_IGN);
  }

  printf("子进程退出。\n");

  // 编写善后代码（释放资源、提交或回滚事务）
  TcpServer.CloseClient();

  exit(0);
}

bool _main(const char *strrecvbuffer,char *strsendbuffer)  // 处理业务的主函数。
{
  int ibizcode=-1;
  GetXMLBuffer(strrecvbuffer,"bizcode",&ibizcode);
  printf("-----code:%d\n", ibizcode);

  switch (ibizcode)
  {
    case 0:  // 心跳
      biz000(strrecvbuffer,strsendbuffer); break;
    case 1:  // 身份验证。
      biz001(strrecvbuffer,strsendbuffer); break;
    case 2:  // 查询余额。
      biz002(strrecvbuffer,strsendbuffer); break;

    default:
      printf("非法报文：%s\n",strrecvbuffer); return false;
  }

  return true;
}

// 身份验证业务处理函数。
bool biz001(const char *strrecvbuffer,char *strsendbuffer)
{
  char username[51],password[51];
  memset(username,0,sizeof(username));
  memset(password,0,sizeof(password));

  GetXMLBuffer(strrecvbuffer,"username",username,50);
  GetXMLBuffer(strrecvbuffer,"password",password,50);

  if ( (strcmp(username,"wucz")==0) && (strcmp(password,"p@ssw0rd")==0) )
    sprintf(strsendbuffer,"<retcode>0</retcode><message>成功。</message>");
  else
    sprintf(strsendbuffer,"<retcode>-1</retcode><message>用户名或密码不正确。</message>");

  return true;
}

// 查询余额业务处理函数。
bool biz002(const char *strrecvbuffer,char *strsendbuffer)
{
  char cardid[51];
  memset(cardid,0,sizeof(cardid));

  GetXMLBuffer(strrecvbuffer,"cardid",cardid,50);

  if (strcmp(cardid,"62620000000001")==0) 
    sprintf(strsendbuffer,"<retcode>0</retcode><message>成功。</message><ye>100.50</ye>");
  else
    sprintf(strsendbuffer,"<retcode>-1</retcode><message>卡号不存在。</message>");

  return true;
}

// 心跳报文
bool biz000(const char *strrecvbuffer,char *strsendbuffer)
{
  sprintf(strsendbuffer,"<retcode>0</retcode><message>成功。</message>");

  return true;
}
