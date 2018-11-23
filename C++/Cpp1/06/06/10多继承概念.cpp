//
//  10多继承概念.cpp
//  06
//
//  Created by xiaoyuan on 2018/11/23.
//  Copyright © 2018 xiaoyuan. All rights reserved.
//

#include <iostream>

using namespace std;

class Base1 {
    
public:
    
    Base1()
    {
        this->m_a = 100;
    }
    
    int m_a;
};

class Base2 {
    
public:
    Base2()
    {
        this->m_b = 200;
        this->m_a = 300;
    }
    int m_b;
    int m_a;
};

class Son: public Base1, public Base2 {
    
public:
    
    Son()
    {
        m_c = 300;
        m_d = 99;
    }
    
    int m_c;
    int m_d;
};

void test()
{
    Son s;
    // 多继承中很容易引发二义性：两个父类Base1和Base2中都有m_a属性，子类直接调用m_a时，编译器不知道该调用哪个，所以报错
//    s.m_a; // Member 'm_a' found in multiple base classes of different types
    // 可以这样调用:
    cout << s.Base1::m_a << endl;
    cout << s.Base2::m_a << endl;
}

/*
 多继承引发的问题:
 符号二义性问题
 使用多重继承， 一个不小心就可能因为符号二义性问题而导致编译通不过。最简单的例子，在上面的基类B1和B2中若存在相同的符号，那么在派生类C中或使用C的对象时，若使用这个符号时，就会使编译器搞不清写代码的人是想调用B1中的那个符号还是B2中的那个符号。当然我们可以通过显示指出要调用的是那个类中的符号来解决这个问题，而有时也可以通过在派生类C中重新定义这个符号以覆盖基类中的符号版本，从而使编译器能够正常工作。至于到底使用哪种解决办法，就得具体情况具体分析了。
 */

int main(int argc, const char *argv[])
{
    return EXIT_SUCCESS;
}
