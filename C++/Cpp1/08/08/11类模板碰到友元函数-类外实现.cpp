//
//  11类模板碰到友元函数-类外实现.cpp
//  08
//
//  Created by swae on 2018/11/25.
//  Copyright © 2018 xiaoyuan. All rights reserved.
//

#include <iostream>
#include <string>

using namespace std;

// 需要让编译器提前看到 printPerson()函数，不然类外的友元函数实现链接不到
template <class T1, class T2> class Person;     
template <class T1, class T2> void printPerson(Person<T1, T2> &p);

template <class T1, class T2>
class Person {
    // 友元函数
    friend void printPerson<>(Person<T1, T2> &p);
public:
    Person(T1 name, T2 age)
    {
        this->m_name = name;
        this->m_age = age;
    }
    T1 m_name;
    T2 m_age;
};

// 友元函数在外的实现
template <class T1, class T2>
void printPerson(Person<T1, T2> &p)
{
    cout << "姓名:" << p.m_name << " 年龄:" << p.m_age << endl;
}

void test()
{
    Person<string, int> p("xiaoyuan", 18);
    printPerson(p);
}

int main(int argc, const char*argv[])
{
    test();
    return EXIT_SUCCESS;
}
