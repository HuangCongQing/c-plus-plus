/*
 *  程序名：mpserver.cpp，此程序演示采用freecplus框架的CTcpServer类实现socket通信多进程的服务端。
 *  作者：C语言技术网(www.freecplus.net) 日期：20190525
*/
#include "_freecplus.h"
 
CLogFile logfile;       // 服务程序的运行日志。
CTcpServer TcpServer;   // 创建服务端对象。

// 程序退出时调用的函数
void FathEXIT(int sig);   // 父进程退出函数。
void ChldEXIT(int sig);   // 子进程退出函数。

int main(int argc,char *argv[])
{
  if (argc!=3)
  {
    printf("Using:./mpserver port logfile\nExample:./mpserver 5005 /tmp/mpserver.log\n\n"); return -1;
  }

  // 关闭全部的信号
  for (int ii=0;ii<100;ii++) signal(ii,SIG_IGN);

  // 打开日志文件。
  if (logfile.Open(argv[2],"a+")==false) { printf("logfile.Open(%s) failed.\n",argv[2]); return -1;}

  // 设置信号,在shell状态下可用 "kill + 进程号" 正常终止些进程
  // 但请不要用 "kill -9 +进程号" 强行终止
  signal(SIGINT,FathEXIT); signal(SIGTERM,FathEXIT);
 
  if (TcpServer.InitServer(atoi(argv[1]))==false) // 初始化TcpServer的通信端口。
  {
    logfile.Write("TcpServer.InitServer(%s) failed.\n",argv[1]); FathEXIT(-1);
  }
 
  while (true)
  {
    if (TcpServer.Accept()==false)   // 等待客户端连接。
    {
      logfile.Write("TcpServer.Accept() failed.\n"); continue;
    }

    if (fork()>0) { TcpServer.CloseClient(); continue; } // 父进程返回到循环首部。

    // 子进程重新设置退出信号。
    signal(SIGINT,ChldEXIT); signal(SIGTERM,ChldEXIT);

    TcpServer.CloseListen();
 
    // 以下是子进程，负责与客户端通信。
    logfile.Write("客户端(%s)已连接。\n",TcpServer.GetIP());
 
    char strbuffer[1024];  // 存放数据的缓冲区。
 
    while (true)
    {
      memset(strbuffer,0,sizeof(strbuffer));
      if (TcpServer.Read(strbuffer,50)==false) break; // 接收客户端发过来的请求报文。
      logfile.Write("接收：%s\n",strbuffer);
 
      strcat(strbuffer,"ok");      // 在客户端的报文后加上"ok"。
      logfile.Write("发送：%s\n",strbuffer);
      if (TcpServer.Write(strbuffer)==false) break;     // 向客户端回应报文。
    }
 
    logfile.Write("客户端已断开。\n");    // 程序直接退出，析构函数会释放资源。

    ChldEXIT(-1);  // 通信完成后，子进程退出。
  }
}

// 父进程退出时调用的函数
void FathEXIT(int sig)
{
  if (sig > 0)
  {
    signal(sig,SIG_IGN); signal(SIGINT,SIG_IGN); signal(SIGTERM,SIG_IGN);
    logfile.Write("catching the signal(%d).\n",sig);
  }

  kill(0,15);  // 通知其它的子进程退出。

  logfile.Write("父进程退出。\n");

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

  logfile.Write("子进程退出。\n");

  // 编写善后代码（释放资源、提交或回滚事务）
  TcpServer.CloseClient();

  exit(0);
}
