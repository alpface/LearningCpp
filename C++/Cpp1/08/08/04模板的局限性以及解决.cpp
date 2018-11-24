//
//  04模板的局限性以及解决.cpp
//  08
//
//  Created by swae on 2018/11/24.
//  Copyright © 2018 xiaoyuan. All rights reserved.
//

#include <iostream>
#include <string>

using namespace std;

class Person {
    
public:
    Person(string name, int age)
    {
        this->m_name = name;
        this->m_age = age;
    }
    string m_name;
    int m_age;
};

// 比较基本数据类型
template <class T>
bool myCompare(T &a, T &b)
{
    if (a == b) {
        return true;
    }
    return false;
}

// 比较自定义数据类
template<> bool myCompare<Person>(Person &p1, Person &p2)
{
    if (p1.m_age == p2.m_age && p1.m_name == p2.m_name) {
        return true;
    }
    return false;
}

void test()
{
    int a = 10;
    int b = 20;
    myCompare(a, b);
    
    Person p1("xiaoyuan", 19);
    Person p2("xiaoyuan", 10);
    myCompare(p1, p2);
}

int main(int argc, const char *argv[])
{
    test();
    return EXIT_SUCCESS;
}
