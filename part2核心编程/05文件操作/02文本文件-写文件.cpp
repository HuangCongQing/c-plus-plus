#include <iostream>
#include <string>

using namespace std;

#include <fstream>
void test01()
{
    ofstream ofs;
    ofs.open("test.txt", ios::out);
    ofs << "姓名：张三" << endl;
    ofs << "性别：男" << endl;
    ofs << "年龄：18" << endl;
    ofs << "20200921" << endl;
    ofs.close();
}
int main()
{
    test01();
    system("pause");
    return 0;
}