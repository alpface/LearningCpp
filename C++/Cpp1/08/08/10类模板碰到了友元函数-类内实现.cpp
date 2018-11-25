//
//  10类模板碰到了友元函数-类内实现.cpp
//  08
//
//  Created by swae on 2018/11/25.
//  Copyright © 2018 xiaoyuan. All rights reserved.
//

#include <iostream>
#include <string>

using namespace std;

template <class NameType, class AgeType>
class Person {
    friend void printPerson(Person &p)
    {
        cout << "姓名:" << p.m_name << " 年龄:" << p.m_age << endl;
    }
public:
    Person(NameType name, AgeType age)
    {
        this->m_name = name;
        this->m_age = age;
    }
    
    NameType m_name;
    AgeType m_age;
};

void test()
{
    Person<string, int> p("Tom", 18);
    printPerson(p);
}

int main(int argc, const char *argv[])
{
    test();
    return EXIT_SUCCESS;
}
