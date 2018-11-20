//
//  08初始化列表的基本使用.cpp
//  03
//
//  Created by xiaoyuan on 2018/11/20.
//  Copyright © 2018 xiaoyuan. All rights reserved.
//

#include <iostream>

using namespace std;

class Person {
public:
    // 有参构造函数
//    Person(int a, int b, int c)
//    {
//
//    }
    // 初始化列表
    // 构造函数后面 + 属性(参数) ...
    Person(int a, int b, int c): m_a(a), m_b(b), m_c(c) {
        cout << "初始化列表被调用" << endl;
    }
    
    Person(): m_a(10), m_b(20), m_c(30) {
        cout << "无参数的初始化列表被调用" << endl;
    }
private:
    int m_a;
    int m_b;
    int m_c;
};

void test()
{
    Person p1(10, 20, 50);
    Person p2;
}

int main(int argc, const char *argv[])
{
    test();
    return EXIT_SUCCESS;
}

