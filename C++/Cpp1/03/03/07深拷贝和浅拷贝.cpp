//
//  07深拷贝和浅拷贝.cpp
//  03
//
//  Created by xiaoyuan on 2018/11/20.
//  Copyright © 2018 xiaoyuan. All rights reserved.
//

#include <iostream>

using namespace std;

class Person {
    
public:
    Person()
    {
        
    }
    
    Person(int age, const char *name)
    {
        m_name = (char *)malloc(sizeof(strlen(name)) + 1);
        strcpy(m_name, name);
        m_age = age;
    }
    
    // 拷贝构造函数：系统给我们提供的默认拷贝构造函数，仅仅是对成员的浅拷贝
    // 重载拷贝构造函数：简单的浅拷贝会释放堆空间两次，导致crash
    Person(const Person &p)
    {
        m_name = (char *)malloc(sizeof(strlen(p.m_name)) + 1);
        strcpy(m_name, p.m_name);
        m_age = p.m_age;
    }
    
    // 析构函数
    ~Person()
    {
        // 释放堆空间
        if (m_name != NULL) {
            free(m_name);
            m_name = NULL;
        }
    }
    
    char *getName() const
    {
        return m_name;
    }
    
private:
    int m_age;
    char *m_name;
};

void test()
{
    Person p1(20, "xiaoyuan");
    Person p2(p1); // 调用拷贝构造函数
    cout << "p2.name = " << p2.getName() << endl;
}

int main(int argc, const char *argv[])
{
    test();
    return EXIT_SUCCESS;
}
