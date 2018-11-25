//
//  08类模板类外实现成员函数.cpp
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
    Person(NameType name, AgeType age);
    void showPerson();
    NameType m_name;
    AgeType m_age;
};

// 类外实现模板函数，也必须要在在函数前面加入template
template <class T1, class T2>
Person<T1, T2>::Person(T1 name, T2 age)
{
    this->m_name = name;
    this->m_age = age;
}
// 类外实现模板函数，也必须要在在函数前面加入template
template <class T1, class T2>
void Person<T1, T2>::showPerson()
{
    cout << typeid(T1).name() << endl;
    cout << typeid(T2).name() << endl;
    
    cout << "姓名:" << this->m_name << " 年龄:" << this->m_age << endl;
}

void test()
{
    Person<string , int> p("xiaoyuan", 18);
    p.showPerson();
}

int main(int argc, const char *argv[])
{
    test();
    return EXIT_SUCCESS;
}
