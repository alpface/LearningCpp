//
//  10指针的引用.cpp
//  day01
//
//  Created by swae on 2018/11/18.
//  Copyright © 2018 xiaoyuan. All rights reserved.
//

#include <iostream>

using namespace std;

struct Person {
    int age;
};

void allocMemory(Person **p)
{
    Person *pp = (Person *)malloc(sizeof(Person *));
    *p = pp;
    (*p)->age = 100;
}

void test1()
{
    Person *p = NULL;
    allocMemory(&p);
    cout << "年龄= " << p->age << endl;
}

// 利用指针引用开辟空间
void allocMemoryByRef(Person* &p)
{
    p = (Person *)malloc(sizeof(Person *));
    p->age = 20;
}

void test2()
{
    Person *p = NULL;
    allocMemoryByRef(p);
    cout << "年龄 = " << p->age << endl;
}

int main(int argc, const char *argv[])
{
    test1();
    return EXIT_SUCCESS;
}
