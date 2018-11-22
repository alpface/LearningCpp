//
//  01关系运算符重载.cpp
//  06
//
//  Created by xiaoyuan on 2018/11/22.
//  Copyright © 2018 xiaoyuan. All rights reserved.
//

#include <iostream>
#include <string>

using namespace std;

/*
 运算符重载形式
 
 重载是c++的一大特性，不仅可以用于一般函数重载，还可以用于运算符重载，对于一些基本数据类型来说运算符可以直接拿来使用，所以运算符重载一般是应用于对象之间，而对象之间的运算符重载主要分为成员运算符重载和友元运算符重载两种形式。
 成员运算符重载：表示在类内定义的这个与运算符相关的函数是属于类的成员函数。所以他可以直接由对象调用对于双目运算符他只需要一个参数（另外一个参数其实就是调用它的对象）
 友元运算符重载：以友元函数的形式对对象进行运算符重载，所以对于双目运算符来说，它需要两个参数都写出来。

 */

class Person {
    
public:
    
    Person(string name, int age):m_name(name), m_age(age){}
    
    // 重载==运算符
    bool operator==(Person &p)
    {
        if (this->m_age == p.m_age && this->m_name == p.m_name) {
            return true;
        }
        return false;
    }
    // 重载!=运算符
    bool operator!=(Person &p)
    {
        if (this->m_age != p.m_age || this->m_name != p.m_name) {
            return true;
        }
        return false;
    }
    string m_name;
    int m_age;
};

void test()
{
    Person p1("xiaoyuan", 20);
    Person p2("ketao", 30);
    if (p1 == p2) {
        cout << "p1 和 p2 相等" << endl;
    }
    else {
        cout << "p1 和 p2 不同相等" << endl;
    }
    Person p3("xiaoyuan", 20);
    if (p1 != p3) {
        cout << "p1 和 p3 不相等" << endl;
    }
    else {
        cout << "p1 和 p3 相等" << endl;
    }
}

int main(int argc, const char *argv[])
{
    test();
    return EXIT_SUCCESS;
}
