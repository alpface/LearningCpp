//
//  07const分配内存情况.cpp
//  day01
//
//  Created by swae on 2018/11/18.
//  Copyright © 2018 xiaoyuan. All rights reserved.
//

#include <iostream>

using namespace std;

// 1.const分配内存 取地址会分配临时内存
// 2.extern 编译器也会给const分配内存
void test1()
{
    const int a = 100;
    int *p = (int *)&a; // 编译器会分配临时内存
    
}

// 3.用普通变量初始化const
void test2()
{
    int a = 10;
    const int b = a; // 会分配内存
    int *p = (int *)&a;
    *p = 100;
    
    cout << a << endl;
}

// 3.自定义类型加const修饰也会分配内存
struct Person {
    string name;
    int age;
};

void test3()
{
    const Person p{};
//    p.age = 100;
    Person *pp = (Person *)&p;
    pp->age = 100;
    pp->name = "aaa";
}

int main(int argc, const char *argv[])
{
    
    return 0;
}
