/*
 * @Description: 
 * @Author: HCQ
 * @Company(School): UCAS
 * @Date: 2020-06-02 19:40:32
 * @LastEditors: HCQ
 * @LastEditTime: 2020-06-02 19:47:35
 */
// https://blog.csdn.net/msdnwolaile/article/details/52708144

#include <string.h>
#include <vector>
#include <iostream>
using namespace std;

int main(){
    vector<int> obj;
    for(int i = 0; i < 10;i++){
        obj.push_back(i);
        cout << obj[i] << ",";
    }
    for (int i = 0; i < 5; i++) //去掉数组最后一个数据
    {
        obj.pop_back();
    }

    cout << "\n"
         << endl;

    for (int i = 0; i < obj.size(); i++) //size()容器中实际数据个数
    {
        cout << obj[i] << ",";
    }

    return 0;
}