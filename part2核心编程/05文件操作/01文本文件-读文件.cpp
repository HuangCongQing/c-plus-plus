#include <iostream>
#include <string>

using namespace std;

#include <fstream>
#include <string>
void test01()
{
    ifstream ifs;
    ifs.open("test.txt", ios::in);
    if (!ifs.is_open())
    {
        cout << "文件打开失败" << endl;
        return;
    }
    //第一种方式
    // char buf[1024] = { 0 }; // 字符数组
    // while (ifs >> buf) // 一行一行读（会把空格输出转成换行）
    // {
    // 	cout << buf << endl;
    // }
    //第二种
    //char buf[1024] = { 0 };
    //while (ifs.getline(buf,sizeof(buf)))
    //{
    //	cout << buf << endl;
    //}
    //第三种
    string buf;
    while (getline(ifs, buf))
    {
    	cout << buf << endl;
    }
    // 第四种 读取一个字符，不推荐
    // char c;
    // while ((c = ifs.get()) != EOF) // end of file
    // {
    //     cout << c;
    // }

    ifs.close();
}
int main()
{
    test01();
    system("pause");
    return 0;
}