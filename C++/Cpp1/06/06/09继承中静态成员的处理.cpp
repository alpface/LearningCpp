//
//  09继承中静态成员的处理.cpp
//  06
//
//  Created by swae on 2018/11/22.
//  Copyright © 2018 xiaoyuan. All rights reserved.
//

#include <iostream>

using namespace std;

class Base {
    
public:
    static void func()
    {
        cout << "Base func()被调用" << endl;
    }
    static void func(int a)
    {
       cout << "Base func(int)被调用" << endl;
    }
    static int m_a;
};

int Base::m_a = 20;

class Son: public Base {
    
public:
    static void func()
    {
        cout << "Son func()被调用" << endl;
    }
    static int m_a;
};

int Son::m_a = 200;

// 静态成员属性，子类可以继承下来
void test01()
{
    // 访问Son的m_a
    cout << Son::m_a << endl;
    // 访问Base的m_a
    cout << Base::m_a << endl;
    
    // 访问Son的func()
    Son::func();
    // 访问Base的func()
    Base::func();
}

int main(int argc, const char*argv[])
{
    test01();
    return EXIT_SUCCESS;
}
