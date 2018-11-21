//
//  03左移运算符重载.cpp
//  05
//
//  Created by swae on 2018/11/22.
//  Copyright © 2018 xiaoyuan. All rights reserved.
//

#include <iostream>

using namespace std;
// 默认情况下 cout是无法输出自定义类型的
// 本示例实现cout 输出 自定义数据类型

class Person {
    friend ostream & operator<<(ostream &cout, Person &p);
public:
    Person(int a, int b):m_a(a), m_b(b){}
    Person();
    
private:
    int m_a;
    int m_b;
};

// 重载左移运算符，注意重载左移运算符不能作为类的成员函数
ostream & operator<<(ostream &cout, Person &p)
{
    cout << "m_a = " << p.m_a << " m_b = " << p.m_b;
    return cout;
}

void test()
{
    Person p(10, 20);
    cout << p << endl;
}

int main(int argc, const char *argv[])
{
    test();
    return EXIT_SUCCESS;
}
