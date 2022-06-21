/*
 * @Description: 
 * @Author: HCQ
 * @Company(School): UCAS
 * @Email: 1756260160@qq.com
 * @Date: 2022-06-21 21:06:38
 * @LastEditTime: 2022-06-21 21:28:03
 * @FilePath: /c-plus-plus/cpp11/智能指针/01shared_ptr/1.4通过reset方法初始化.cpp
 */


// 对于一个未初始化的共享智能指针，可以通过 reset 方法来初始化，当智能指针中有值的时候，调用 reset 会使引用计数减 1。

#include <iostream>
#include <string>
#include <memory>
using namespace std;

int main()
{
    // 使用智能指针管理一块 int 型的堆内存, 内部引用计数为 1
    shared_ptr<int> ptr1 = make_shared<int>(520);
    shared_ptr<int> ptr2 = ptr1;
    shared_ptr<int> ptr3 = ptr1;
    shared_ptr<int> ptr4 = ptr1;
    cout << "ptr1管理的内存引用计数: " << ptr1.use_count() << endl;
    cout << "ptr2管理的内存引用计数: " << ptr2.use_count() << endl;
    cout << "ptr3管理的内存引用计数: " << ptr3.use_count() << endl;
    cout << "ptr4管理的内存引用计数: " << ptr4.use_count() << endl;

    ptr4.reset(); // ========================================
    cout << "ptr1管理的内存引用计数: " << ptr1.use_count() << endl; // 3
    cout << "ptr2管理的内存引用计数: " << ptr2.use_count() << endl; // 3
    cout << "ptr3管理的内存引用计数: " << ptr3.use_count() << endl; // 3
    cout << "ptr4管理的内存引用计数: " << ptr4.use_count() << endl; // 0

    shared_ptr<int> ptr5;
    ptr5.reset(new int(250)); // 1
    cout << "ptr5管理的内存引用计数: " << ptr5.use_count() << endl; // 1

    return 0;
}


/* 
ptr1管理的内存引用计数: 4
ptr2管理的内存引用计数: 4
ptr3管理的内存引用计数: 4
ptr4管理的内存引用计数: 4

ptr1管理的内存引用计数: 3
ptr2管理的内存引用计数: 3
ptr3管理的内存引用计数: 3
ptr4管理的内存引用计数: 0

ptr5管理的内存引用计数: 1
 */