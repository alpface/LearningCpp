//
//  01静态成员变量和静态成员函数.cpp
//  04
//
//  Created by xiaoyuan on 2018/11/20.
//  Copyright © 2018 xiaoyuan. All rights reserved.
//

#include <iostream>

using namespace std;

class Person {
public:
    // 成员变量
    int m_a;
    // 静态成员变量，共享数据，在类内定义，在类外初始化
    static int count;
    
    // 静态成员函数
    // 不可以访问普通成员变量
    // 可以访问静态成员变量
    static void func()
    {
        count++;
        cout << "count = " << count << endl;
    }
    
    // 普通成员函数可以访问普通成员变量，也可以访问静态成员变量
    void myFunc()
    {
        m_a = 10;
        count++;
    }
    
private:
    static int b; // 私有静态变量, 类外不可以访问
};

// 在类外初始化类的静态成员变量
int Person::count = 100;
int Person::b = 0;

void test()
{
    Person p1;
    
    Person p2;
    p1.count = 200;
    
    cout << "p1 = " << p1.count << endl;
    cout << "p2 = " << p2.count << endl;
    
    cout << "通过类名访问静态成员 count = " << Person::count << endl;
    
    p1.func();
    p2.func();
    Person::func();
    
}

int main(int argc, const char *argv[])
{
    test();
    return EXIT_SUCCESS;
}

