/*
 * @Description: Wire object detection interface(v0.2)
 * @Author: Chongiqng,Huang
 * @Date: 2022-10-14 00:52:08
 * @LastEditTime: 2022-10-28 03:13:42
 * @FilePath: /electrical-wire-around-obstacle-detection/test/interface.h
 */

#ifndef MY_INTERFACE_H
#define MY_INTERFACE_H


#pragma once // 防止头文件重复编译



#include <pcl/io/io.h>
#include <pcl/io/pcd_io.h>

/* 模块1---点云空间计算模块 */
// 报警输出数据
// 报警物体，一次可以有很多个，例如在区域内出现多个过高或者过近的目标。数量不等。
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

// typedef struct {
//    alarms *p_alarms; // 告警物体，指向一段缓存，具体由算法人员设计???
//    long alarmtime; //报警发生的时间
//    pcl::PointXYZI *pcdfile; // 输出点云文件，类型格式？
//    cv::Mat *imgfile; // 图像文件，调用外部接口获取图像并输出
// } AlarmInfo; 

/* 模块2---电线重建模块 */


class Interface{
// private:
//     float smoothed;

public:
	//构造函数---------
	Interface();
	//析构函数---------
	~Interface();

    /* 模块1---点云空间计算模块 */
    // 点云数据实时采集
   //  void getOriginPointCloud(pcl::PointCloud<pcl::PointXYZI>::Ptr OriginCloud);
    
    // 设置监控区域SetMonitoringArea
    void SetMonitoringArea(float LeftWidth, float RightWidth, float MaxDistance);
    // 设置高度预警级别参数
   //  void SetHeightWarnPara(float *pWarnHeights, int WarnNumbers); 
   //  // 设置高度预警级别参数
   //  void SetHeightWarnPara(float *pWarnHeights, int WarnNumbers);
   //  // 设置距离报警级别参数
   //  void SetDistanceAlarmPara(float *pAlarmDistances, int AlarmNumbers);
   //  // 监控计算
   // //  bool  ABSMonitor(pcl::PointXYZI InputCloud, cv::Mat InputImg, AlarmInfo* p_alarm);
   //  // 屏蔽报警物体
   //  int ShieldAlarm(int TartgetID);
   //  // 读取监控区域
   //  void ReadMonitoringArea(float *LeftWidth, float *RightWidth, float *MaxDistance);
   //  // 读取高度预警级别参数
   //  void ReadHeightWarnPara(float *pWarnHeights, int *WarnNumbers);
   //  // 读取距离报警级别参数
   //  void ReadDistanceAlarmPara(float *pAlarmDistances, int *AlarmNumbers);

   /* 模块2---电线重建模块 */ 
    
};


// // 原始点云发出来, 首先经过电线重建, 得到重建后的点云输出
// void ReconstructionPC(pcl::PointCloud<pcl::PointXYZI>::Ptr OriginCloud, 
//                       pcl::PointCloud<pcl::PointXYZI>::Ptr RebuildCloud);


#endif //MY_INTERFACE_H
