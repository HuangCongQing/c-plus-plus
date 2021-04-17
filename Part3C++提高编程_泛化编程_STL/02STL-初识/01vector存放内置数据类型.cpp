/*
 * @Description: vector存放内置数据类型 参考video:https://www.bilibili.com/video/BV1Hb411Y7E5?p=186&spm_id_from=pageDriver
 * @Author: HCQ
 * @Company(School): UCAS
 * @Email: 1756260160@qq.com
 * @Date: 2021-04-17 12:02:45
 * @LastEditTime: 2021-04-17 12:35:10
 * @FilePath: /c-plus-plus/Part3C++提高编程_泛化编程_STL/02STL-初识/01vector存放内置数据类型.cpp
 */

#include<iostream>  
using namespace std;
#include<vector> // vector容器头文件
#include<algorithm> // 标准算法头文件  for_each

//  vector存放内置数据类型 
void myPrint(int val){
    cout<< val << endl;
}


void test01(){
    vector<int> v;
    v.push_back(10);
    v.push_back(20);
    v.push_back(30);
    // // 通过迭代器访问容器中的数据
    // vector<int>::iterator itBegin = v.begin(); //起始迭代器
    // vector<int>::iterator itEnd = v.end(); //结束迭代器，指向容器中最后一个元素的下一个位置

    // // 第一种遍历方式
    // while(itBegin!=itEnd){
    //     cout << *itBegin << endl;
    //     itBegin++;
    // }

    // 第二种方法
    // for(vector<int>::iterator it = v.begin(); it!=v.end(); it++){
    //     cout << *it << endl;
    // }

    // 第三种方法 利用STL提供遍历算法 需要#include<algorithm> 
    for_each(v.begin(), v.end(), myPrint);
    
}

int main(int argc, char *argv[]) {
    test01();
    return 0;
}