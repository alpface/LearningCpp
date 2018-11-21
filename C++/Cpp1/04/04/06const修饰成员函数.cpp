//
//  06const修饰成员函数.cpp
//  04
//
//  Created by xiaoyuan on 2018/11/21.
//  Copyright © 2018 xiaoyuan. All rights reserved.
//

#include <iostream>

class Person {
public:
    Person()
    {
        this->m_a = 10;
        this->m_b = 20;
    }
    
    // const 修饰的函数就叫做常函数，不允许修改指针指向的值
    // 如果非要在常函数中修改指针指向的值，需要在成员属性前面加上mutable关键字
    void showInfo() const
    {
//        this->m_a = 10; 常函数内不允许修改成员变量的值
        this->m_c = 20; // 加入mutable关键字后就可以在常函数内或者常对象修改成员属性的值
    }
    void showInfo1()
    {
        
    }
    int m_a;
    int m_b;
    mutable int m_c; // 就算是常函数也可以修改
};

void test01()
{
    Person p1;
    p1.showInfo();
    // 定义常对象
    const Person p2;
    // 常对象不可以修改非mutable声明的成员
//    p2.m_a = 200;
    p2.m_c = 100;
    // 常对象不可以调用非常函数
//    p2.showInfo1(); // 'this' argument to member function 'showInfo1' has type 'const Person', but function is not marked const
    p2.showInfo();
}

int main(int argc, const char *argv[])
{
    test01();
    return EXIT_SUCCESS;
}
