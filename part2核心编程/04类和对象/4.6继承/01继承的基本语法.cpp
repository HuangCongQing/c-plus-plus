/*
 * @Description: 用继承的技术，减少重复代码  https://www.yuque.com/huangzhongqing/lang/wixs4k#KLGvK
 * @Author: HCQ
 * @Company(School): UCAS
 * @Date: 2020-09-19 18:54:04
 * @LastEditors: Please set LastEditors
 * @LastEditTime: 2022-06-17 23:10:53
 */
#include <iostream>
#include <string>

// class A : public B;
// A 类称为子类 或 派生类
// B 类称为父类 或 基类

using namespace std;

//公共页面
class BasePage
{
public:
    void header()
    {
        cout << "首页、公开课、登录、注册...（公共头部）" << endl;
    }
    void footer()
    {
        cout << "帮助中心、交流合作、站内地图...(公共底部)" << endl;
    }
    void left()
    {
        cout << "Java,Python,C++...(公共分类列表)" << endl;
    }
};
//Java页面 冒号表示继承
class Java : public BasePage
{
public:
    void content()
    {
        cout << "JAVA学科视频" << endl;
    }
};
//Python页面
class Python : public BasePage
{
public:
    void content()
    {
        cout << "Python学科视频" << endl;
    }
};
//C++页面
class CPP : public BasePage
{
public:
    void content()
    {
        cout << "C++学科视频" << endl;
    }
};
void test01()
{
    //Java页面
    cout << "Java下载视频页面如下： " << endl;
    Java ja;
    ja.header();
    ja.footer();
    ja.left();
    ja.content();
    cout << "--------------------" << endl;
    //Python页面
    cout << "Python下载视频页面如下： " << endl;
    Python py;
    py.header();
    py.footer();
    py.left();
    py.content();
    cout << "--------------------" << endl;
    //C++页面
    cout << "C++下载视频页面如下： " << endl;
    CPP cp;
    cp.header();
    cp.footer();
    cp.left();
    cp.content();
}
int main()
{
    test01();
    system("pause");
    return 0;
}