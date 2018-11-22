//
//  05继承方式.cpp
//  06
//
//  Created by swae on 2018/11/22.
//  Copyright © 2018 xiaoyuan. All rights reserved.
//

#include <iostream>

using namespace std;

class Base1 {
    
public:
    int m_a;
protected:
    int m_b;
private:
    int m_c;
    
};

/*****************公有继承***************/
class Son1: public Base1 {
    
public:
    void func()
    {
        cout << m_a << endl; // 基类中公有属性可以访问
        cout << m_b << endl; // 基类中受保护的属性可以访问，类外不能被访问
//        cout << m_c << endl; // 基类中私有属性不能被访问
    }
};

void test1()
{
    Son1 s1;
    cout <<  s1.m_a << endl;
    s1.func();
}

/*****************保护继承***************/
class Son2: protected Base1 {
    
public:
    void func()
    {
        cout << m_a << endl; // 基类中公有属性可以继承，但是是protected的, 类外不可以被访问
        cout << m_b << endl; // 基类中受保护的属性可以访问，但是是protected的, 类外不可以被访问
        //        cout << m_c << endl; // 基类中私有属性不能被访问，不被继承
    }
};

void test02()
{
    Son2 s1;
//    s1.m_a;
    s1.func();
    
}

/*****************私有继承***************/
class Son3: private Base1 {
    
public:
    void func()
    {
        cout << m_a << endl; // 基类中公有属性可以继承，但是是private的, 类外不可以被访问
        cout << m_b << endl; // 基类中受保护的属性可以访问，但是是private的, 类外不可以被访问
        //        cout << m_c << endl; // 基类中私有属性不能被访问，不被继承
    }
};

void test03()
{
    Son3 s1;
//        s1.m_a;
    s1.func();
    
}

int main(int argc, const char *argv[])
{
    return EXIT_SUCCESS;
}
