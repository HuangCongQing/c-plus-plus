/*
 * @Description: 多态案例一-计算器类
 * @Author: HCQ
 * @Company(School): UCAS
 * @Email: 1756260160@qq.com
 * @Date: 2022-06-18 13:23:42
 * @LastEditTime: 2022-06-18 13:29:49
 * @FilePath: \c-plus-plus\part2核心编程\04类和对象\4.7多态\02多态案例一-计算器类.cpp
 */

#include <iostream>
#include <string>

using namespace std;

//普通实现
class Calculator {
public:
int getResult(string oper)
 {
 	if (oper == "+") {
   return m_Num1 + m_Num2;
 	}
 	else if (oper == "-") {
   return m_Num1 - m_Num2;
 	}
 	else if (oper == "*") {
   return m_Num1 * m_Num2;
 	}
 	//如果要提供新的运算，需要修改源码
 }
public:
int m_Num1;
int m_Num2;
};

void test01()
{
//普通实现测试
 Calculator c;
 c.m_Num1 = 10;
 c.m_Num2 = 10;
 cout << c.m_Num1 << " + " << c.m_Num2 << " = " << c.getResult("+") << endl;

 cout << c.m_Num1 << " - " << c.m_Num2 << " = " << c.getResult("-") << endl;

 cout << c.m_Num1 << " * " << c.m_Num2 << " = " << c.getResult("*") << endl;
}



//多态实现
//抽象计算器类
//多态优点：代码组织结构清晰，可读性强，利于前期和后期的扩展以及维护
class AbstractCalculator
{
public :

virtual int getResult() // 虚函数============================
 {
 	return 0;
 }

int m_Num1;
int m_Num2;
};

//加法计算器
class AddCalculator :public AbstractCalculator
{
public:
int getResult()
 {
 	return m_Num1 + m_Num2;
 }
};

//减法计算器
class SubCalculator :public AbstractCalculator
{
public:
int getResult()
 {
 	return m_Num1 - m_Num2;
 }
};

//乘法计算器
class MulCalculator :public AbstractCalculator
{
public:
int getResult()
 {
 	return m_Num1 * m_Num2;
 }
};


void test02()
{
    // 多态使用条件：父类指针或引用指向子类对象==============================================
//创建加法计算器
 AbstractCalculator *abc = new AddCalculator;
 abc->m_Num1 = 10;
 abc->m_Num2 = 10;
 cout << abc->m_Num1 << " + " << abc->m_Num2 << " = " << abc->getResult() << endl;
delete abc;  //用完了记得销毁

//创建减法计算器
 abc = new SubCalculator;
 abc->m_Num1 = 10;
 abc->m_Num2 = 10;
 cout << abc->m_Num1 << " - " << abc->m_Num2 << " = " << abc->getResult() << endl;
delete abc;  

//创建乘法计算器
 abc = new MulCalculator;
 abc->m_Num1 = 10;
 abc->m_Num2 = 10;
 cout << abc->m_Num1 << " * " << abc->m_Num2 << " = " << abc->getResult() << endl;
delete abc;
}

int main() {

//test01();

test02();

system("pause");

return 0;
}