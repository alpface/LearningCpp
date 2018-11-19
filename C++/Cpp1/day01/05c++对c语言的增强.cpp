//
//  05c++对c语言的增强.cpp
//  day01
//
//  Created by swae on 2018/11/18.
//  Copyright © 2018 xiaoyuan. All rights reserved.
//

#include <iostream>

using namespace std;

// 1. 全局变量的检查增强
// 编译不通过：Redefinition of 'a'  (重复定义)
//int a;
//int a = 100;

// 2.函数检测增强，参数类型增强，返回值类型检测增强，函数调用参数检测增强
int getRects(int w, int h)
{
    return w * h;
}

void test1()
{
    getRects(10, 20);
}

// 3.类型转换检测增强
void test2()
{
    char *p = (char *)malloc(sizeof(char) * 10);
}

// 4.struct 增强
struct Person {
    int age;
    int getAge()
    {
        return age;
    }
};

void test3()
{
    // c++中使用结构体可以不加struct
    Person p;
    p.age = 10;
    
    cout << p.getAge() << endl;
}

// 5.bool类型增强 c语言中没有bool类型
bool flag = true; // bool类型只有真(1)和假(0)，占1个字节

// 6.三目运算符
void test4()
{
    int a = 10;
    int b = 20;
    // c++中三目运算符返回的是变量
    (a > b ? a : b) = 100;
    cout << b << endl;
}

// 7.const常量增强
const int m_a = 100;
void test5()
{
//    m_a = 100;
    const int m_b = 100;
    int *p = (int *)&m_b;
    *p = 200;
    cout << "m_b = " << m_b << endl;
    
    // 在c++中m_b是真正的常量，即使通过指针还是无法修改m_b的值
    // int *p = (int *)&m_b; 编译器会生成临时变量，让p指针指向这个临时变量，所以无法修改
    
}

int main(int argc, const char *argv[])
{
    test5();
    return EXIT_SUCCESS;
}
