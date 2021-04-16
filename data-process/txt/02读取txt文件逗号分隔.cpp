/*
 * @Description: 逗号分割  使用find和substing   https://blog.csdn.net/q6324266/article/details/52293284
 string::find()能够找到相应分隔符在字符串中的位置(index)，
 而string::substr()能够根据index和length截取字符串。利用这两个函数，我们可以对上面的字符串进行分割。
 * @Author: HCQ
 * @Company(School): UCAS
 * @Email: 1756260160@qq.com
 * @Date: 2021-04-14 15:57:16
 * @LastEditTime: 2021-04-16 12:56:40
 * @FilePath: /c-plus-plus/data-process/txt/02读取txt文件逗号分隔.cpp
 */

#include <iostream>
#include <fstream>
#include <sstream>
#include <iomanip> // Header file needed to use setprecision

using namespace std;

int main()
{
    double pt[2]; //x,y
    // ifstream in_file("/home/hcq/github/c-plus-plus/data-process/txt/labelme_test.txt");
    ifstream in_file("/home/hcq/github/c-plus-plus/data-process/txt/1600050937.416284.txt");
    string str_line;

    int lineCnt = 0;                         // 行数
    while (getline(in_file, str_line, '\n')) // 得到每行数据
    {
        string str_tmp;
        // cout << str_line << endl; //每行数据
        lineCnt++; // 行数
        string str = str_line;
        for (int j = 0; j < 2; j++)
        {
            int pos = str.find(",");          //寻找,的位置
            string point = str.substr(0, pos); //提取数字字符串
            // pt[j] = atoi(point.data());        //将提取出来的字符串转换成数字
            pt[j] = atof(point.data());        //将提取出来的字符串转换成double数字
            str.erase(0, pos + 2);             //消除已经分隔的字符串，方便后续操作的分割
        }
        cout << setprecision(18)<<pt[0] << ", " << pt[1] << endl; // 
    }
    cout << "行数" << lineCnt + 1 << endl;

    in_file.close();

    return 0;
}
