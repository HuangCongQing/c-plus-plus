/*
 * @Description: 数组的话。 *p = p[0]
 * @Author: HCQ
 * @Company(School): UCAS
 * @Email: 1756260160@qq.com
 * @Date: 2022-06-21 11:49:45
 * @LastEditTime: 2022-06-21 11:50:54
 * @FilePath: /c-plus-plus/part2核心编程/01内存四区/05堆区开辟数组.cpp
 */

#include <iostream>
using namespace std;

//堆区开辟数组
int main() {

int* arr = new int[10];

for (int i = 0; i < 10; i++)
 {
 	arr[i] = i + 100;  //  *p = p[0]
 }

for (int i = 0; i < 10; i++)
 {
 	cout << arr[i] << endl;
 }
//释放数组 delete 后加 []
delete[] arr;

system("pause");

return 0;
}