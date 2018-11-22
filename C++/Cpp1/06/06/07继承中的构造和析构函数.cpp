//
//  07继承中的构造和析构函数.cpp
//  06
//
//  Created by swae on 2018/11/22.
//  Copyright © 2018 xiaoyuan. All rights reserved.
//

#include <iostream>

using namespace std;

class Base {
public:
    Base()
    {
        m_a = 100;
        cout << "Base的构造函数被调用" << endl;
    }
    ~Base()
    {
        cout << "Base的析构函数被调用" << endl;
    }
    Base&operator=(Base &b)
    {
        cout << "Base的=赋值运算符被调用" << endl;
        this->m_a = b.m_a;
        return *this;
    }
    int m_a;
};

// 子类会继承父类的成员属性和成员函数
// 但是子类不会继承父类的构造函数、析构函数、=赋值运算符
class Son: public Base {
    
public:
    Son()
    {
        m_a = 200;
        cout << "Son的构造函数被调用" << endl;
    }
    ~Son()
    {
        cout << "Son的析构函数被调用" << endl;
    }
    Son&operator=(int age)
    {
        cout << "Son的=赋值运算符被调用" << endl;
        this->m_a = age;
        return *this;
    }
};

void test()
{
    Son s;
}

int main(int argc, const char *argv[])
{
    test();
    /*
     Base的构造函数被调用
     Son的构造函数被调用
     Son的析构函数被调用
     Base的析构函数被调用
     */
    return EXIT_SUCCESS;
}
