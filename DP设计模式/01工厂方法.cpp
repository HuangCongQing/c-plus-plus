/*
 * @Description: 工厂方法：https://www.yuque.com/huangzhongqing/lang/mkigui/
 * @Author: HCQ
 * @Company(School): UCAS
 * @Email: 1756260160@qq.com
 * @Date: 2022-06-20 11:01:03
 * @LastEditTime: 2022-06-20 11:36:52
 * @FilePath: \c-plus-plus\DP设计模式\01工厂方法.cpp
 */

// 1.1 定义:工厂方法：每种产品对应一个具体工厂，每个具体工厂负责生产对应的具体产品；
// 工厂方法模式（Factory Method Pattern）又叫虚拟构造函数（Virtual Constructor）模式或者多态性工厂（PolymorphicFactory）模式。
// 工厂方法模式的用意是定义一个创建产品对象的工厂接口，将实际创建性工作推迟到子类中，即定义一个用于创建对象的接口，让子类决定实例化哪个类。工厂方法使一个类的实例化延迟到其子类。
// 1.2 缺点
// 当产品种类过多，由于每一种产品都需要实现一个工厂类，增加了代码量
#include<iostream>
using namespace std;

//定义产品类型
typedef enum{
    Product_Type_01,
    Product_Type_02
}Product_Type;

//定义抽象产品类
class Product{
public:
    virtual string getType() = 0;
};

//具体产品类01
class Product01:public Product{
public:
    Product01():Product(),m_type("Product01"){

    }
    string getType(){
        cout << m_type << endl;
        return m_type;
    }
private:
    string m_type;
};

//具体产品类02
class Product02:public Product{
public:
    Product02():Product(),m_type("Product02"){

    }
    string getType(){
        cout << m_type << endl;
        return m_type;
    }
private:
    string m_type;
};

//抽象工厂类
class ProductFactory
 {
 public:
     virtual  Product* createProduct() = 0;
 };

 //具体创建工厂类
 class Product01Factory
 {
 public:
     virtual  Product* createProduct(){
         return new Product01();
     }
 };

  //具体创建工厂类
 class Product02Factory
 {
 public:
     virtual  Product* createProduct(){
         return new Product02();
     }
 };
int main(){
    Product01Factory* factory01 = new Product01Factory();
    Product* product01 =  factory01->createProduct();
    product01->getType();

    Product02Factory* factory02 = new Product02Factory();
    Product* product02 =  factory02->createProduct();
    product02->getType();

    delete product01;
    product01 = NULL;
    delete factory01;
    factory01 = NULL;
    delete product02;
    product02 = NULL;
    delete factory02;
    factory02 = NULL;
}