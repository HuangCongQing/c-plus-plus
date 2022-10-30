/*
 *  程序名：mtserver_biz.cpp，此程序演示采用freecplus框架的CTcpServer类实现socket通信多线程的服务端。
 *  作者：C语言技术网(www.freecplus.net) 日期：20190525
*/
#include "_freecplus.h"

void *pthmain(void *arg);  // 线程主函数。

vector<long> vpthid;  // 存放线程id的容器。

void mainexit(int sig);   // 信号2和15的处理函数。

void pthmainexit(void *arg); // 线程清理函数。
 
CLogFile logfile;       // 服务程序的运行日志。
CTcpServer TcpServer;   // 创建服务端对象。

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
  if (argc!=3)
  {
    printf("Using:./mtserver_biz port logfile\nExample:./mtserver_biz 5005 /tmp/mtserver_biz.log\n\n"); return -1;
  }

  // 关闭全部的信号
  for (int ii=0;ii<100;ii++) signal(ii,SIG_IGN);

  // 打开日志文件。
  if (logfile.Open(argv[2],"a+")==false) { printf("logfile.Open(%s) failed.\n",argv[2]); return -1;}

  // 设置信号,在shell状态下可用 "kill + 进程号" 正常终止些进程
  // 但请不要用 "kill -9 +进程号" 强行终止
  signal(SIGINT,mainexit); signal(SIGTERM,mainexit);
 
  if (TcpServer.InitServer(atoi(argv[1]))==false) // 初始化TcpServer的通信端口。
  {
    logfile.Write("TcpServer.InitServer(%s) failed.\n",argv[1]); return -1;
  }
 
  while (true)
  {
    if (TcpServer.Accept()==false)   // 等待客户端连接。
    {
      logfile.Write("TcpServer.Accept() failed.\n"); continue;
    }

    logfile.Write("客户端(%s)已连接。\n",TcpServer.GetIP());

    pthread_t pthid;
    if (pthread_create(&pthid,NULL,pthmain,(void *)(long)TcpServer.m_connfd)!=0)
    { logfile.Write("pthread_create failed.\n"); return -1; }

    vpthid.push_back(pthid); // 把线程id保存到vpthid容器中。
  }

  return 0;
}

void *pthmain(void *arg)
{
  pthread_cleanup_push(pthmainexit,arg);  // 设置线程清理函数。

  pthread_detach(pthread_self());  // 分离线程。

  pthread_setcanceltype(PTHREAD_CANCEL_DISABLE,NULL);  // 设置取消方式为立即取消。

  int sockfd=(int)(long)arg;  // 与客户端的socket连接。

  int  ibuflen=0;
  char strrecvbuffer[1024],strsendbuffer[1024];  // 存放数据的缓冲区。
 
  while (true)
  {
    memset(strrecvbuffer,0,sizeof(strrecvbuffer));
    memset(strsendbuffer,0,sizeof(strsendbuffer));

    if (TcpRead(sockfd,strrecvbuffer,&ibuflen,50)==false) break; // 接收客户端发过来的请求报文。
    logfile.Write("接收：%s\n",strrecvbuffer);
 
    // 处理业务的主函数。
    if (_main(strrecvbuffer,strsendbuffer)==false) break;

    logfile.Write("发送：%s\n",strsendbuffer);

    if (TcpWrite(sockfd,strsendbuffer)==false) break;     // 向客户端回应报文。
  }

  pthread_cleanup_pop(1);

  pthread_exit(0);
}

// 信号2和15的处理函数。
void mainexit(int sig)
{
  logfile.Write("mainexit begin.\n");

  // 关闭监听的socket。
  TcpServer.CloseListen();

  // 取消全部的线程。
  for (int ii=0;ii<vpthid.size();ii++)
  {
    logfile.Write("cancel %ld\n",vpthid[ii]);
    pthread_cancel(vpthid[ii]);
  }

  logfile.Write("mainexit end.\n");

  exit(0);
}

// 线程清理函数。
void pthmainexit(void *arg)
{
  logfile.Write("pthmainexit begin.\n");

  // 关闭与客户端的socket。
  close((int)(long)arg);

  // 从vpthid中删除本线程的id。
  for (int ii=0;ii<vpthid.size();ii++)
  {
    if (vpthid[ii]==pthread_self())
    {
      vpthid.erase(vpthid.begin()+ii);
    }
  }

 logfile.Write("pthmainexit end.\n");
}

bool _main(const char *strrecvbuffer,char *strsendbuffer)  // 处理业务的主函数。
{
  int ibizcode=-1;
  GetXMLBuffer(strrecvbuffer,"bizcode",&ibizcode);

  switch (ibizcode)
  {
    case 0:  // 心跳
      biz000(strrecvbuffer,strsendbuffer); break;
    case 1:  // 身份验证。
      biz001(strrecvbuffer,strsendbuffer); break;
    case 2:  // 查询余额。
      biz002(strrecvbuffer,strsendbuffer); break;

    default:
      logfile.Write("非法报文：%s\n",strrecvbuffer); return false;
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


