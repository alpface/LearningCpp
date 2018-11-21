//
//  02加号运算符重载.cpp
//  05
//
//  Created by swae on 2018/11/21.
//  Copyright © 2018 xiaoyuan. All rights reserved.
//

#include <iostream>

using namespace std;

class Person {
    
public:
    Person()
    {
        
    }
    Person(int a, int b): m_a(a), m_b(b){}
    int m_a;
    int m_b;
    // 通过成员函数的方法对 加号运算符重载 二元
    Person operator+(Person&p)
    {
        Person temp;
        temp.m_a = this->m_a + p.m_a;
        temp.m_b = this->m_b + p.m_b;
        return temp;
    }
};

// 通过全局函数的方式 对 加号运算的进行重载
// 注意全局函数和成员函数不能同时定义的，编译不通过，Use of overloaded operator '+' is ambiguous (with operand types 'Perso
//Person operator+(Person &p1, Person &p2) // 二元 p1+p2
//{
//    Person temp;
//    temp.m_a = p1.m_a + p2.m_a;
//    temp.m_b = p1.m_b + p2.m_b;
//    return temp;
//}



Person operator+(Person &p, int a)
{
    Person temp;
    temp.m_a = p.m_a + a;
    temp.m_b = p.m_b + a;
    return temp;
}

void test()
{
    Person p1(10, 20);
    Person p2(20, 30);
    Person p3 = p1 + p2;
    Person p4 = p3 + 20;
    cout << p1.m_b << " " << p1.m_b << endl;
    cout << p2.m_b << " " << p2.m_b << endl;
    cout << p3.m_b << " " << p3.m_b << endl;
    cout << p4.m_b << " " << p4.m_b << endl;
    
}

int main(int argc, const char *argv[])
{
    test();
    return EXIT_SUCCESS;
}
