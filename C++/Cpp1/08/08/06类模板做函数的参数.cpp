//
//  06类模板做函数的参数.cpp
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
    
public:
    Person(NameType name, AgeType age)
    {
        this->m_name = name;
        this->m_age = age;
    }
    void showPerson()
    {
        cout << "姓名:" << this->m_name << " 年龄:" << this->m_age << endl;
    }
    NameType m_name;
    AgeType m_age;
};

// 函数模板做参数1：指定参数类型，不然编译失败: Use of class template 'Person' requires template arguments
void doWork(Person<string, int> &p)
{
    p.showPerson();
}

void test01()
{
    Person<string, int> p("xiaoyuan", 18);
    doWork(p);
}

// 2.参数模板化
template <class T1, class T2>
void doWork2(Person<T1, T2> &p)
{
    p.showPerson();
}

void test02()
{
    Person<string, int> p("xiaoyuan", 18);
    doWork2(p);
}

// 3.整体模板化
template <class T>
void doWork3(T &p)
{
    p.showPerson();
    cout << "p的类型:" <<  typeid(p).name() << endl;
}

void test03()
{
    Person<string, int> p("xiaoyuan", 18);
    doWork3(p);
}

int main(int argc, const char*argv[])
{
//    test01();
//    test02();
    test03();
    return EXIT_SUCCESS;
}
 
