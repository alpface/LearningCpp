//
//  03函数模板与普通函数的区别以及调用规则.cpp
//  08
//
//  Created by swae on 2018/11/24.
//  Copyright © 2018 xiaoyuan. All rights reserved.
//

#include <iostream>

using namespace std;

// 1.普通函数与函数模板的区别
// 函数模板
template <class T>
T myPlus(T a, T b)
{
    return a + b;
}
// 普通函数
int myPlus1(int a, int b)
{
    return a +b;
}

void test01()
{
    int a = 10;
    int b = 100;
    myPlus(a, b);
    char c = 'a';
//    myPlus(a, c); // 函数模板 此处a和c不是同一种类型，编译器不知道该使用哪种类型，存在二义性
    myPlus1(a, c); // 普通函数，可以进行参数的隐式类型转换
    
}

// 2.普通函数和函数模板的调用规则
template <class T>
void myPrint(T a, T b)
{
    cout << a << " " << b << endl;
    cout << "函数模板调用void myPrint(T a, T b, T c)" << endl;
}
// 函数模板函数重载
template <class T>
void myPrint(T a, T b, T c)
{
    cout << a << " " << b << " " << b << endl;
    cout << "函数模板重载调用void myPrint(T a, T b, T c)" << endl;
}

// 普通函数
void myPrint(int a, int b)
{
    cout << "普通函数被调用void myPrint(int a, int b)" << endl;
}

void test02()
{
    int a = 10;
    int b = 20;
    // 1.如果函数模板与普通函数相同，而调用时参数类型与普通函数也相同，则调用这个普通函数
    myPrint(a, b);
    
    // 2.如果类型与普通函数不同，则调用模板函数
    double a1 = 20.0;
    double a2 = 30.0;
    myPrint(a1, a2); // 调用的是模板函数
    
    // 3.函数模板可以重载
    double a3 = 300;
    myPrint(a1, a2, a3);
    
    char a5 = 'a';
    char a6 = 'b';
    myPrint(a5, a6);
}

int main(int argc, const char*crgv[])
{
    test02();
    return EXIT_SUCCESS;
}
