/*
 * @Description: 
 * @Author: HCQ
 * @Company(School): UCAS
 * @Email: 1756260160@qq.com
 * @Date: 2023-04-27 18:12:32
 * @LastEditTime: 2023-04-28 14:53:26
 * @FilePath: /c-plus-plus/part1基础/指针/数组和指针/01demo.cpp
 */
#include <iostream>
using namespace std;
int main()
{
   double arr[5] = {1000.0, 2.0, 3.4, 17.0, 50.0};    
   double* p;     
   p = arr;   // arr的首地址给p  
   for(int i = 0; i < 5; i++ )
   {
      cout << "*(p + " << i << ") : ";        
      cout << *(p + i) << endl;    
    }
    return 0;
}
/*  
*(p + 0) : 1000
*(p + 1) : 2
*(p + 2) : 3.4
*(p + 3) : 17
*(p + 4) : 50

*/


// for void* https://blog.csdn.net/weixin_55420595/article/details/121087721

// #include<stdio.h>
// int main()
// {	
// 	int arr[] = {1,2,3,4,5,6};
// 	void * p;
// 	int  i ,n;
// 	p = arr;
// 	n = sizeof(arr)/sizeof(int);
// 	for(i = 0;i < n;i++)
// 	{
// 		printf("%d",*((int *)p + i));
// 	 }
// 	puts("");
// 	return 0;
// }
