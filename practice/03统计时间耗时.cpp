/*
 * @Description: 统计时间耗时   https://blog.csdn.net/qfturauyls/article/details/107051902
 * @Author: HCQ
 * @Company(School): UCAS
 * @Email: 1756260160@qq.com
 * @Date: 2021-03-04 14:18:29
 * @LastEditTime: 2021-03-04 14:47:10
 * @FilePath: /c-plus-plus/practice/03统计时间耗时.cpp
 */

#include<iostream>  
#include <chrono>     // must
using namespace std;
using namespace chrono;// must
// main() 是程序开始执行的地方
 
int main()
{
   auto t1 = std::chrono::steady_clock::now();
   for (size_t i = 0; i < 1000; i++)
   {
       /* code */
   }
   
   auto t2 = std::chrono::steady_clock::now();
//  static double to_dr_ms = 0.0;
  double dr_ms=std::chrono::duration<double,std::milli>(t2-t1).count();   //这一帧处理时间  毫秒ms
//   to_dr_ms += dr_ms;   // 总时间
//   std::cout<<"## Extract ground time: "<<dr_ms<<" ms"<<std::endl;

  //double clustering_time = (ros::Time::now() - begin_time).toSec();
  cout<<dr_ms<<endl;


// auto start = system_clock::now();
// // do something...
// auto end   = system_clock::now();
// auto duration = duration_cast<microseconds>(end - start);
// cout <<  "花费了" 
//      << double(duration.count()) * microseconds::period::num / microseconds::period::den 
//      << "秒" << endl;
   return 0;
}
