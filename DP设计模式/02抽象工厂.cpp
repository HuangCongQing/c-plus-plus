/*
 * @Description: https://www.yuque.com/huangzhongqing/lang/mkigui/
 * @Author: HCQ
 * @Company(School): UCAS
 * @Email: 1756260160@qq.com
 * @Date: 2022-06-20 11:01:03
 * @LastEditTime: 2022-06-20 11:10:52
 * @FilePath: \c-plus-plus\DP设计模式\02抽象工厂.cpp
 */
// 2.1 定义
// 　　为创建一组相关或相互依赖的对象提供一个接口，而且无须指定它们的具体类。抽象工厂模式是工厂方法模式的升级版本。在有多个业务品种、业务分类时，通过抽象工厂模式产生需要的对象是一种非常好的解决方式。

// 2.2 优点
// 　　抽象工厂模式是工厂方法模式的升级版本。在有多个业务品种、业务分类时，通过抽象工厂模式产生需要的对象是一种非常好的解决方式。

// 2.2 缺点
// 　　假如产品族中需要增加一个新的产品，不仅要实现具体的 产品类，而且还要创建相关的工厂接口。


#include<iostream>
using namespace std;

//抽象猫类
class Cat{
public:
    virtual string getType() = 0;
};

//白颜色猫
class WhiteCat:public Cat{
public:
    WhiteCat():Cat(),m_type("WhiteCat"){

    }
    string getType(){
        cout << m_type << endl;
        return m_type;
    }
private:
    string m_type;
};

//黑色猫类
class BlackCat:public Cat{
public:
    BlackCat():Cat(),m_type("BlackCat"){

    }
    string getType(){
        cout << m_type << endl;
        return m_type;
    }
private:
    string m_type;
};

 //抽象狗类
class Dog{
public:
    virtual string getType() = 0;
};

//白色狗类
class WhiteDog:public Dog{
public:
    WhiteDog():Dog(),m_type("WhiteDog"){

    }
    string getType(){
        cout << m_type << endl;
        return m_type;
    }
private:
    string m_type;
};

//黑色狗类
class BlackDog:public Dog{
public:
    BlackDog():Dog(),m_type("BlackDog"){

    }
    string getType(){
        cout << m_type << endl;
        return m_type;
    }
private:
    string m_type;
};

//抽象工厂类
class Pet
 {
 public:
     virtual  Cat* createCat() = 0;
     virtual  Dog* createDog() = 0;
 };

 //白色宠物工厂
class WhitePetFactory
{
public:
     Cat* createCat(){
         return new WhiteCat();
     }
     Dog* creatDog(){
         return new WhiteDog();
     }
};
 //黑色宠物工厂
 class BlackPetFactory
 {
 public:
     Cat* createCat(){
         return new BlackCat();
     }
     Dog* creatDog(){
         return new BlackDog();
     }
 };