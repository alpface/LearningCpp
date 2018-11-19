//
//  05c++对c语言的增强.c
//  day01
//
//  Created by swae on 2018/11/18.
//  Copyright © 2018 xiaoyuan. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>

// 1.c语言中全局变量可以先声明再赋值 c++中不行
// c++编译不通过：Redefinition of 'a'  (重复定义)
int a;
int a = 20;

// 2.函数检测增强 c++中必须明确函数参数类型和返回值类型
int func(w, d)
{
    return w;
}

void test1()
{
    // c++中函数实参个数必须和形参一致
    func(10, 20, 30);
}

// 3.类型转换检测增强
void test2()
{
    // c++中必须类型一致才能赋值，可以将malloc强转为char *
    char *p = malloc(sizeof(char));
}

// 4.struct结构体增强
// c语言的结构体中不可以有函数
struct Person {
    char name[64];
    int age;
//    void getAge();
};

void test3()
{
    struct Person *p;
    // c语言在使用结构体时必须在前面加上struct关键字
}


// 5.bool类型增强
// c语言中没有bool类型
//bool flag;

// 6.三目运算符
void test4()
{
    // c语言中三木运算符返回的是值，c++中返回的是变量
    int a = 10;
    int b = 20;
//    (a > b ? a : b) = 10;
    *(a>b ? &a : &b) = 10;
}


// 7.const增强
const int m_a = 10; // m_a全局变量，const修饰受到保护，一旦定义不可以修改，也不可以通过指针间接修改
void test5()
{
    const int m_b = 20; // c语言中局部变量const修饰的是伪常量，可以通过指针间接修改
    int *p = (int *)&m_b;
    *p = 100;
    printf("%d\n", *p);
    // 不可以使用m_b初始化数组
//    int m_array[m_b];
}
