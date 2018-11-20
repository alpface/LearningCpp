//
//  11new运算符的使用.cpp
//  03
//
//  Created by xiaoyuan on 2018/11/20.
//  Copyright © 2018 xiaoyuan. All rights reserved.
//

#include <iostream>

/*
 “new”是C++的一个关键字，同时也是操作符。关于new的话题非常多，因为它确实比较复杂，也非常神秘，下面我将把我了解到的与new有关的内容做一个总结。
 
 new的过程
 当我们使用关键字new在堆上动态创建一个对象时，它实际上做了三件事：获得一块内存空间、调用构造函数、返回正确的指针。当然，如果我们创建的是简单类型的变量，那么第二步会被省略。假如我们定义了如下一个类Person：
 */

using namespace std;

class Person {
    
public:
    Person(int age, const char *name)
    {
        m_age = age;
        m_name = (char *)malloc(strlen(name)+1);
        strcpy(m_name, name);
        cout << "有参的构造函数" << endl;
    }
    Person()
    {
        cout << "默认的构造函数" << endl;
    }
    ~Person()
    {
        cout << "析构函数" << endl;
    }
    void say()
    {
        cout << "name = " << m_name << "age = " << m_age << endl;
    }
private:
    int m_age;
    char *m_name;
};

void test()
{
    // 栈区开辟控件
    Person p1(10, "hello");
    // 堆区开辟
    Person *p  = new Person;
    
    // 所有new出来的对象都会返回该类型的指针
    // malloc() 返回的是类型是void * 还需要进行强转
    // new 出来的对象会调用其构造函数，而malloc()的则不会调用其构造函数
    // new是运算符 malloc()是函数
    // new出来的需要使用delete释放内存空间，malloc需要使用free释放内存
    // delete 是运算符 配合new使用
    delete p;
    
}

void test02()
{
    void *p = new Person;
    // 当使用void *接收new出来的对象，会存在无法释放的问题 (析构函数不会被调用)
    delete (Person *)p;
}

void test03()
{
    // 通过new开辟数组，一定会调用默认的构造函数，所以一定要有默认构造函数
    Person *pList = new Person[10];
    
    // 在栈上开辟数组，一定要指定有参构造
    Person pList1[] = {Person(), Person(20, "xiaoyuan")};
    
    // 释放数组 delete []
    delete [] pList;
    
}

int main(int argc, const char *argv[])
{
//    test();
//    test02();
    test03();
    return EXIT_SUCCESS;
}
