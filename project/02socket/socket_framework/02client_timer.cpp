/*
 *  程序名：demo47_timer.cpp，此程序演示采用freecplus框架的CTcpClient类实现socket通信的客户端。
 *  增加了业务示例。
 *  增加了计时功能。
 *  作者：C语言技术网(www.freecplus.net) 日期：20190525
*/
#include "_freecplus.h"
 
CTcpClient TcpClient;   // 创建客户端的对象。

bool biz000();  // 发送心跳报文。
bool biz001();  // 身份验证
bool biz002();  // 余额查询

int main(int argc,char *argv[])
{
  if (argc!=3)
  {
    printf("Using:./demo47_biz ip port\nExample:./demo47_biz 172.21.0.3 5005\n\n"); return -1;
  }

  CTimer Timer;
  if (TcpClient.ConnectToServer(argv[1],atoi(argv[2]))==false) // 向服务端发起连接请求。
  {
    printf("TcpClient.ConnectToServer(\"%s\",%s) failed.\n",argv[1],argv[2]); return -1;
  }
  printf("TcpClient.ConnectToServer() 耗时%lf\n",Timer.Elapsed());

  // 身份验证
  biz001();
  printf("biz001() 耗时%lf\n",Timer.Elapsed());

  biz002(); // 余额查询
  printf("biz002() 耗时%lf\n",Timer.Elapsed());

  biz000();
  printf("biz000() 耗时%lf\n",Timer.Elapsed());

  // 程序直接退出，析构函数会释放资源。
}

// 身份验证。
bool biz001()
{
  char strbuffer[1024];    // 存放数据的缓冲区。
 
  memset(strbuffer,0,sizeof(strbuffer));
  snprintf(strbuffer,1000,"<bizcode>1</bizcode><username>wucz</username><password>p@ssw0rd</password>");
  printf("发送：%s\n",strbuffer);
  if (TcpClient.Write(strbuffer)==false) return false;    // 向服务端发送请求报文。
 
  memset(strbuffer,0,sizeof(strbuffer));
  if (TcpClient.Read(strbuffer,20)==false) return false;  // 接收服务端的回应报文。
  printf("接收：%s\n",strbuffer);

  int iretcode=-1;
  GetXMLBuffer(strbuffer,"retcode",&iretcode);

  if (iretcode==0) 
  { 
    printf("身份验证成功。\n"); 
    return true; 
  }
 
  // printf("身份验证失败。\n"); 

  return false;
}
 
// 余额查询
bool biz002()
{
  char strbuffer[1024];    // 存放数据的缓冲区。
 
  memset(strbuffer,0,sizeof(strbuffer));
  snprintf(strbuffer,1000,"<bizcode>2</bizcode><cardid>62620000000001</cardid>");
  printf("发送：%s\n",strbuffer);
  if (TcpClient.Write(strbuffer)==false) return false;    // 向服务端发送请求报文。
 
  memset(strbuffer,0,sizeof(strbuffer));
  if (TcpClient.Read(strbuffer,20)==false) return false;  // 接收服务端的回应报文。
  printf("接收：%s\n",strbuffer);

  int iretcode=-1;
  GetXMLBuffer(strbuffer,"retcode",&iretcode);

  if (iretcode==0) 
  { 
    printf("查询余额成功。\n"); 
    return true; 
  }
 
  // printf("查询余额失败。\n"); 

  return false;
}
 
bool biz000()  // 发送心跳报文。
{
  char strbuffer[1024];    // 存放数据的缓冲区。
 
  memset(strbuffer,0,sizeof(strbuffer));
  snprintf(strbuffer,1000,"<bizcode>0</bizcode>");
  printf("发送：%s\n",strbuffer);
  if (TcpClient.Write(strbuffer)==false) return false;    // 向服务端发送请求报文。
 
  memset(strbuffer,0,sizeof(strbuffer));
  if (TcpClient.Read(strbuffer,20)==false) return false;  // 接收服务端的回应报文。
  printf("接收：%s\n",strbuffer);

  return true;
}
 
