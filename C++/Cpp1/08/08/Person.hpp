//
//  Person.hpp
//  08
//
//  Created by swae on 2018/11/25.
//  Copyright © 2018 xiaoyuan. All rights reserved.
//

#pragma once

#ifndef Person_hpp
#define Person_hpp

#include <iostream>

using namespace std;

template <class T1, class T2>
class Person {
    
public:
    Person(T1 name, T2 age);
    void showPerson();
    T1 m_name;
    T2 m_age;
};

template <class T1, class T2>
Person<T1, T2>::Person(T1 name, T2 age)
{
    this->m_name = name;
    this->m_age = age;
}

template <class T1, class T2>
void Person<T1, T2>::showPerson()
{
    cout << typeid(T1).name() << endl;
    cout << typeid(T2).name() << endl;
    
    cout << "姓名:" << this->m_name << " 年龄:" << this->m_age << endl;
}

#include <stdio.h>

#endif /* Person_hpp */
