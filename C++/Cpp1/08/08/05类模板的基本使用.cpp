//
//  05类模板的基本使用.cpp
//  08
//
//  Created by swae on 2018/11/24.
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
        cout << this->m_name << "[" << this->m_age << "岁]" << endl;
    }
    NameType m_name;
    AgeType m_age;
};

void test01()
{
    // 类模板不支持自动类型推导， error: Use of class template 'Person' requires template arguments
//    Person p1("xiaoyuan", 20);
    
    // 显示指定类型
     Person<string, int> p2("xiaoyuan", 18);
    p2.showPerson();
    
}

class Person2 {
    
public:
    void showPerson2()
    {
        cout << "Person2 的 showPerson2()" << endl;
    }
};

template <class T>
class MyClass {
    
public:
    T obj;
    void func1()
    {
        obj.showPerson();
    }
    void fun2()
    {
        obj.showPerson2();
    }
};

// 类模板中成员函数一开始不会创建，在运行时才会创建
void test02()
{
    MyClass<Person2>m;
    m.fun2();
}

int main(int argc, const char *argv[])
{
//    test01();
    test02();
    return EXIT_SUCCESS;
}
