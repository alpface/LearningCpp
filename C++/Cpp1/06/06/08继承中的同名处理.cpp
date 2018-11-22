//
//  08继承中的同名处理.cpp
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
    }
    void fun()
    {
        cout << "Base func()被调用" << endl;
    }
    void fun(int a)
    {
        cout << "Base func(int)被调用" << endl;
    }
    
    int m_a;
};

class Son: public Base {
    
public:
    Son()
    {
        m_a = 200;
    }
    void fun()
    {
        cout << "Son func()被调用" << endl;
    }
    int m_a;
};

void test01()
{
    Son s;
    // 由于Son和Base各有m_a属性，未使用虚继承，所以这两个属性是共存的
    // 调用Son的m_a属性
    cout << "s.m_a = " << s.m_a << endl;
    
    // 调用Son父类的m_a属性
    cout << "s.Base::m_a = " << s.Base::m_a << endl;
    
    // 调用Son的fun()
    s.fun();
    
    // 调用父类fun()
    s.Base::fun();
    
    s.Base::fun(10);
    
    /*
     总结:
     子类并不会覆盖父类同名的函数和属性
     */
}

int main(int argc, const char*argv[])
{
    test01();
    return EXIT_SUCCESS;
}
