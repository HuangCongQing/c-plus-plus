/*
 * @Description: 类型转换
 * @Author: HCQ
 * @Company(School): UCAS
 * @Email: 1756260160@qq.com
 * @Date: 2021-04-16 12:36:55
 * @LastEditTime: 2021-04-16 12:42:24
 * @FilePath: /c-plus-plus/data-process/类型转换.cpp
 */

#include <iostream>
using namespace std;

int main()
{
    // 字符串转浮点型   https://blog.csdn.net/matthew_fan/article/details/8443561
    char szString[] = "-3.1415926535898";
    double db1;
    db1 = atof(szString);
    printf("atof result:\n");
    printf("%f  %.12f  %.2f  %e  %E\n", db1, db1, db1, db1, db1);
    printf("%.1e  %.1E  %.18e  %.18E\n", db1, db1, db1, db1);

    return 0;
}
