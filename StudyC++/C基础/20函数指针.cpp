//
//  20函数指针.cpp
//  StudyC++
//
//  Created by xiaoyuan on 2018/11/12.
//  Copyright © 2018 xiaoyuan. All rights reserved.
//

#include <iostream>

void func()
{
    printf("hello world\n");
}

void test()
{
    // 函数名就是函数的入口地址
    // 打印func()这个函数的内存地址
    printf("func的函数地址:%p\n", func);
    
    // 0x100000df0 是func的内存地址 16进制
    // 拿到函数的入口地址，使用func指向函数入口地址
    int *funcPointer = (int *)0x100000df0;
    funcPointer = (int *)func;
    // 将指针转换为函数入口地址指针
    // void (*myFunc)() void 是函数的返回值 myFunc是函数名  后面的括号是函数的参数列表
    void (*myFunc)() = (void (*)())funcPointer;
    // 指向函数指针
    myFunc();
}


int testMyFunc(int a, char b)
{
    printf("int testMyFunc(%d, %c)\n", a, b);
    return 0;
}

// 定义一个指向函数的指针
// 决定函数的类型：函数的返回值和函数的参数列表
void test1()
{
    // 1.定义一个函数类型: 返回值为int类型，有两个参数
    typedef int (FUNC_TYPE)(int a, char b);
    FUNC_TYPE *func = testMyFunc;
    func(2, 'c');
    
    // 2. 定义一个函数指针类型
    typedef int (*FUNC_POINTER)(int a, char b);
    FUNC_POINTER funcP = testMyFunc;
    funcP(3, 'u');
    
    // 3. 直接定义函数指针变量
    int (*funcPointer)(int a, char b) = testMyFunc;
    funcPointer(10, 'g');
    
    printf("函数指针的size:%lu\n", sizeof(funcPointer));
    
    // 3.把指针转换为函数指针类型的写法:
    int (*func2)(int a, char b) = (int (*)(int a, char b))NULL;
    func2 = funcPointer;
    func2(99, 'p');
}

int main(int argc, const char *arhv[])
{
//    test();
    test1();
    
    return EXIT_SUCCESS;
}
