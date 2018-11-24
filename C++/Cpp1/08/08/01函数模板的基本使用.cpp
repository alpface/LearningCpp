//
//  01函数模板的基本使用.cpp
//  08
//
//  Created by swae on 2018/11/24.
//  Copyright © 2018 xiaoyuan. All rights reserved.
//

#include <iostream>

using namespace std;

void mySwapInt(int &a, int &b)
{
    int temp = a;
    a = b;
    b = temp;
}

void mySwapDouble(double &a, double &b)
{
    double temp = a;
    a = b;
    b = temp;
}

// 模板技术 -- 类型参数化，泛型编程
// template<class T> // 告诉编译器，下面如果出现T不要报错，T是一个通用类型
// 注意：多个参数如果都为T时，传入的参数类型必须相同，不然会存在二义性（编译器不知道该使用哪个类型）
template<class T>
void mySwap(T &a, T &b)
{
    T temp = a;
    a = b;
    b = temp;
}

// template<class T> 和 template<typename T>等价
template<typename T>
void mySwap1(T &a, T &b)
{
    T temp = a;
    a = b;
    b = temp;
}

void test01()
{
    int a = 10;
    int b = 300;
    // 1.编译器自动推导参数的类型，但是这两个参数类型必须一致，不然存在二义性
    mySwap(a, b);
    cout << "a == " << a << " b == " << b << endl;
    
    // 2.显示指定类型
    mySwap<int>(a, b);
}

int main(int argc, const char *argv[])
{
    test01();
    return EXIT_SUCCESS;
}
