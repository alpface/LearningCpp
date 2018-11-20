//
//  06C++构造函数的调用规则.cpp
//  03
//
//  Created by xiaoyuan on 2018/11/20.
//  Copyright © 2018 xiaoyuan. All rights reserved.
//

#include <iostream>

/*
     C++构造函数调用规则
 
     1）当类中没有定义任何一个构造函数时，C++编译器会提供默认无参构造函数和默认拷贝构造函数
 
     2）当类中定义了拷贝构造函数时，C++编译器不会提供无参数构造函数
 
     3）当类中定义了任意的非拷贝构造函数时，当类中提供了有参构造函数或无参构造函数，c++编译器不会提供无参构造函数
 
     总结：只要你写了构造函数，那么必须要用
 */

/**
 构造析构阶段总结
 
 1）构造函数是C++中用于初始化对象状态的特殊函数
 
 2）构造函数在创建对象时，自动被调用
 
 3）构造函数和普通成员函数都遵循重载原则
 
 4）拷贝构造函数是对象正确初始化的重要保证
 
 5）必要时候必须手动编写拷贝构造函数
 */

using namespace std;

class MyClass {
    
public:
    MyClass()
    {
        cout << "默认构造函数被调用" << endl;
    }
    MyClass(int a)
    {
        cout << "带参数的构造函数被调用" << endl;
        m_a = a;
    }
    MyClass(const MyClass &c)
    {
        cout << "拷贝构造函数被调用" << endl;
        m_a = c.m_a;
    }
    
    void setA(int a) {
        m_a = a;
    }
    
private:
    int m_a;
};

// 系统默认给一个提供三个函数：默认构造函数、拷贝构造函数、析构函数
// 当我们重置带参数的构造函数后，系统就不会再提供默认的构造函数，所以如果要使用默认的构造函数，还需要进行重新默认的构造函数
// 但是系统还会提供默认的拷贝函数，进行简单的值拷贝

void test01()
{
    MyClass c(10);
    MyClass c1;
    MyClass c2(c);
    printf("<#const char *, ...#>");
}

int main(int argc, const char *argv[])
{
    test01();
    return EXIT_SUCCESS;
}
