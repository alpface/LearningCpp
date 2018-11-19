//
//  04函数的默认参数以及占位参数.cpp
//  02
//
//  Created by xiaoyuan on 2018/11/19.
//  Copyright © 2018 xiaoyuan. All rights reserved.
//

#include <iostream>

using namespace std;

// 1.函数的默认参数
// 函数声明时，给参数设置默认值，如果在该调用函数，未传入参数，则参数就为默认值
void myFunc(int a = 10, int b = 20);
void myFunc(int a, int b)
{
    int ret = a + b;
    cout << "ret = " << ret << endl;
}
// 默认参数注意事项:
/*
 1.如果参数列表中有一个设置了默认值，那么其他的参数也必须有默认值，不然编译器编译不通过，比如
 void myFunc(int a = 10, int b); 错误
 2.函数的声明和实现，只能其中一个给参数们设置默认值，也就是说如果声明中设置了默认值，实现就不要设置了，如果实现设置了，声明就不需要设置了，不然编译器无法编译通过
*/
void test01()
{
    myFunc();
    myFunc(100);
    myFunc(20, 30);
}

// 2.函数的占位参数
/*
 占位参数只有参数类型声明，而没有参数名声明
 一般情况下，在函数体内部无法使用占位参数
*/
// 第三个参数为int类型的占位参数
int placeholderFunc(int a, int b, int)
{
    return a + b;
}

void test02()
{
    
    //    placeholderFunc(10, 20); // ERROR:No matching function for call to 'placeholderFunc'
    int ret = placeholderFunc(10, 20, 30);
    cout << "placeholderFunc = " << ret << endl;
}

// 3.和默认参数一起使用

int placeholderFunc1(int a,int b,int)
{
    return a+b;
}

int placeholderFunc2(int a,int b = 0,int = 0)
{
    return a+b;
}

void test03()
{
    int ret1 = placeholderFunc1(10, 20, 30);
    int ret2 = placeholderFunc2(10, 20, 30);
    cout << "placeholderFunc1 = " << ret1 << endl;
    cout << "placeholderFunc2 = " << ret2 << endl;
}

int main(int argc, const char *argv[])
{
//    test01();
//    test02();
    test03();
    return EXIT_SUCCESS;
}
