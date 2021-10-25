/*
 * @Description: https://www.jianshu.com/p/c1328f95edf7
 * @Author: HCQ
 * @Company(School): UCAS
 * @Email: 1756260160@qq.com
 * @Date: 2021-10-25 20:31:27
 * @LastEditTime: 2021-10-25 20:34:47
 * @FilePath: /c-plus-plus/important/02thread.cpp
 */
#include <iostream>
#include<thread>
#include<unistd.h>

using namespace std;

void sayHello() {
    while (1) {
        sleep(1);
        cout << endl << "hello" << endl;
    }
}

void sayWorld() {
    while (1) {
        sleep(1);
        cout << endl << "world" << endl;
    }
}

int main() {
    thread threadHello(&sayHello);
    thread threadWorld(&sayWorld);
    threadHello.join();
    threadWorld.join();
    return 0;
}