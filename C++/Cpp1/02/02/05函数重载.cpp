//
//  05函数重载.cpp
//  02
//
//  Created by xiaoyuan on 2018/11/19.
//  Copyright © 2018 xiaoyuan. All rights reserved.
//

/*
 在实际开发中，有时候我们需要实现几个功能类似的函数，只是有些细节不同。例如希望交换两个变量的值，这两个变量有多种类型，可以是 int、float、char、bool 等，我们需要通过参数把变量的地址传入函数内部。在C语言中，程序员往往需要分别设计出三个不同名的函数，其函数原型与下面类似：
 void swap1(int *a, int *b); //交换 int 变量的值
 void swap2(float *a, float *b); //交换 float 变量的值
 void swap3(char *a, char *b); //交换 char 变量的值
 void swap4(bool *a, bool *b); //交换 bool 变量的值
 但在C++中，这完全没有必要。C++ 允许多个函数拥有相同的名字，只要它们的参数列表不同就可以，这就是函数的重载（Function Overloading）。借助重载，一个函数名可以有多种用途。

 */

/// @note  参数列表又叫参数签名，包括参数的类型、参数的个数和参数的顺序，只要有一个不同就叫做参数列表不同。
/// 函数的返回值不同不可以作为函数重载的条件

#include <iostream>

///【示例】借助函数重载交换不同类型的变量的值：

using namespace std;

void Swap(int *p1, int *p2)
{
    int temp = *p1;
    *p1 = *p2;
    *p2 = temp;
}

void Swap(double *p1, double *p2)
{
    double temp = *p1;
    *p1 = *p2;
    *p2 = temp;
}

void Swap(float *p1, float *p2)
{
    float temp = *p1;
    *p1 = *p2;
    *p2 = temp;
}

void Swap(char *p1, char *p2)
{
    char temp = *p1;
    *p1 = *p2;
    *p2 = temp;
}

void test()
{
    int a_int = 10, b_int = 20;
    double a_double = 10.0, b_double = 20.0;
    float a_float = 10.0, b_float = 20.0;
    char a_char = 'a', b_char = 'b';
    Swap(&a_int, &b_int);
    Swap(&a_double, &b_double);
    Swap(&a_float, &b_float);
    Swap(&a_char, &b_char);
    
    cout << "a_int = " << a_int << " b_int = " << b_int << endl;
    cout << "a_double = " << a_double << " b_double = " << b_double << endl;
    cout << "a_float = " << a_float << " b_float = " << b_float << endl;
    cout << "a_char = " << a_char << " b_char = " << b_char << endl;
    
}

/*
 @note 通过本例可以发现，重载就是在一个作用范围内（同一个类、同一个命名空间等）有多个名称相同但参数不同的函数。重载的结果是让一个函数名拥有了多种用途，使得命名更加方便（在中大型项目中，给变量、函数、类起名字是一件让人苦恼的问题），调用更加灵活。
 
 在使用重载函数时，同名函数的功能应当相同或相近，不要用同一函数名去实现完全不相干的功能，虽然程序也能运行，但可读性不好，使人觉得莫名其妙。
 
 @note 参数列表不同包括参数的个数不同、类型不同或顺序不同，仅仅参数名称不同是不可以的。函数返回值也不能作为重载的依据。
 */

/**
 函数的重载的规则：
 函数名称必须相同。
 参数列表必须不同（个数不同、类型不同、参数排列顺序不同等）。
 函数的返回类型可以相同也可以不相同。
 仅仅返回类型不同不足以成为函数的重载。
 C++ 是如何做到函数重载的
 
 C++代码在编译时会根据参数列表对函数进行重命名，例如void Swap(int a, int b)会被重命名为_Swap_int_int，void Swap(float x, float y)会被重命名为_Swap_float_float。当发生函数调用时，编译器会根据传入的实参去逐个匹配，以选择对应的函数，如果匹配失败，编译器就会报错，这叫做重载决议（Overload Resolution）。
 不同的编译器有不同的重命名方式，这里仅仅举例说明，实际情况可能并非如此。
 从这个角度讲，函数重载仅仅是语法层面的，本质上它们还是不同的函数，占用不同的内存，入口地址也不一样
 */

int main(int argc, const char *argv[])
{
    test();
    return EXIT_SUCCESS;
}

