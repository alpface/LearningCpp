//
//  06赋值运算符重载.cpp
//  05
//
//  Created by xiaoyuan on 2018/11/22.
//  Copyright © 2018 xiaoyuan. All rights reserved.
//

#include <iostream>

using namespace std;

// 一个类的创建，默认有四个方法: 默认构造函数，析构函数，拷贝构造函数，赋值运算符=的重载

class Person {
    
public:
    Person(int age) {
        this->m_age = age;
    }
    Person(const Person &p){
        this->m_age = p.m_age;
    }
    ~Person(){}
    int m_age;
};

void test01()
{
    Person p1(10);
    Person p2(20);
    p1 = p2;
    cout << "p1.m_age:" << p1.m_age << endl;
    cout << "p2.m_age:" << p2.m_age << endl;
}

class Person2 {
    
public:
    Person2(const char *name)
    {
        this->pName = new char[strlen(name) + 1];
        strcpy(this->pName, name);
    }
    Person2(const Person2 &p)
    {
        if (this->pName != NULL) {
            delete[] this->pName;
            this->pName = NULL;
        }
        this->pName = new char[strlen(p.pName)+1];
        strcpy(this->pName, p.pName);
    }
    // 重载赋值运算符=
    Person2 &operator=(Person2 &p)
    {
        if (this->pName != NULL) {
            delete [] this->pName;
            this->pName = NULL;
        }
        this->pName = new char[strlen(p.pName)+1];
        strcpy(this->pName, p.pName);
        return *this;
    }
    ~Person2()
    {
        if (this->pName != NULL) {
            delete[] this->pName;
            this->pName = NULL;
        }
    }
    char *pName;
};

void test02()
{
    Person2 p1("xiaoyuan");
    Person2 p2("ketao");
    Person2 p3("");
    p3 = p2 = p1;  // p2被赋值为p1, p3被赋值为p2, 所以都是xiaoyuan
    cout << "p1.name:" << p1.pName << endl << "p2.pname:" << p2.pName  << endl << "p3.pname:" << p3.pName << endl;
}

int main(int argc, const char *argv[])
{
//    test01();
    test02();
    return EXIT_SUCCESS;
}
