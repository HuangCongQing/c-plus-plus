/*
 * @Description: make_shared<Test>(520);
 * @Author: HCQ
 * @Company(School): UCAS
 * @Email: 1756260160@qq.com
 * @Date: 2022-06-21 21:02:47
 * @LastEditTime: 2022-06-21 21:22:46
 * @FilePath: /c-plus-plus/cpp11/智能指针/01shared_ptr/1.3通过std::make_shared初始化.cpp
 */

#include <iostream>
#include <string>
#include <memory> 
using namespace std;

class Test
{
public:
    Test() 
    {
        cout << "construct Test..." << endl;
    }
    Test(int x) 
    {
        cout << "construct Test, x = " << x << endl;
    }
    Test(string str) 
    {
        cout << "construct Test, str = " << str << endl;
    }
    ~Test()
    {
        cout << "destruct Test ..." << endl;
    }
};

int main()
{
    // 使用智能指针管理一块 int 型的堆内存, 内部引用计数为 1
    shared_ptr<int> ptr1 = make_shared<int>(520);
    cout << "ptr1管理的内存引用计数: " << ptr1.use_count() << endl;

    shared_ptr<Test> ptr2 = make_shared<Test>();
    cout << "ptr2管理的内存引用计数: " << ptr2.use_count() << endl;

    shared_ptr<Test> ptr3 = make_shared<Test>(520);
    cout << "ptr3管理的内存引用计数: " << ptr3.use_count() << endl;

    shared_ptr<Test> ptr4 = make_shared<Test>("我是要成为海贼王的男人!!!");
    cout << "ptr4管理的内存引用计数: " << ptr4.use_count() << endl;
    return 0;
}

/* 
ptr1管理的内存引用计数: 1
construct Test...
ptr2管理的内存引用计数: 1
construct Test, x = 520
ptr3管理的内存引用计数: 1
construct Test, str = 我是要成为海贼王的男人!!!
ptr4管理的内存引用计数: 1
destruct Test ...
destruct Test ...
destruct Test ...

 */