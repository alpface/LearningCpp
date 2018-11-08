//
//  main.cpp
//  StudyC++
//
//  Created by xiaoyuan on 2018/11/1.
//  Copyright © 2018 xiaoyuan. All rights reserved.
//

#include <iostream>

struct Person {
    char name[64];
    int age;
};

typedef struct Person NSPerson;

static void test1()
{
    __unused NSPerson *p;
}

static void test2()
{
    char *p1, *p2;
    std::cout << typeid(p1).name() << std::endl;
    std::cout << typeid(p2).name() << std::endl;
}

static void test3()
{
    // 直接赋值
    int a = 10;
    a = 100;
    // 间接赋值
    int *p = &a;
    *p = 300;
    printf("%d\n", *p);
    return;
}

struct Person1 {
    char a;
    int b;
    char c;
    int d;
};

static void test4()
{
    Person1 p = {'a', 100, 'x', 200};
    printf("p.d=%d\n", p.d);
    
    // 直接修改p.d的值
    p.d = 200001;
    
    // p的地址 &p
    // p 是Person1类型的，取地址就是Person1 *类型的
//    &p

    // 通过指针间接取p.d的值
    printf("%d\n", *(int *)((char *)&p + 12));
    
//    int *pp = NULL;
//    printf("pp:%d\n", pp); // 0
//    printf("pp+1:%d\n", pp+1); // 4
    
    //////////////////
    // 声明一个int指针
    int *ptr;
    // 声明一个int值
    int val = 1;
    // 为指针分配一个int值的引用
    ptr = &val;
    // 对指针进行取值，打印存储在指针地址中的内容
    int deref = *ptr;
    printf("%d\n", deref);
    //////////////////
    
    const char *p3 = "hello world";
}

// 栈区
// 栈区的内存自动分配自动释放。不需要程序管理
int * myFunc()
{
    int a = 10;
    return &a;
    // 我们并不关心a的值是多少，而是return后，a的内存已经超出作用域，被释放了
    // 所以不要返回局部变量的值
    
}

char * getString()
{
    char a[] = "get String";
    return a;
}

static void test5()
{
    
    int *a = myFunc();
    printf("%d\n", *a);
}

/// 堆区分配地址
int * getMySpace() {
    
    int size = 5;
    // p这个变量在栈上，p保存的地址在堆上
    int *p = (int *)malloc((sizeof(int) * size));
    
    // 只要是连续的内存空间都能使用下标的形式的访问
//    p[0] = 100;
    
    for (int i = 0; i< size; ++i) {
        p[i] = 100+i;
    }
    return p;
}

static void test6()
{
    int *p = getMySpace();
    for (int i = 0; i<5; ++i) {
        // 打印*p连续的内存地址
        printf("%d ", p[i]);
    }
    printf("\n");
    // 释放堆内存
    free(p);
    p = NULL;
}

//////////错误的///////////////

// 定义变量的时候一定要初始化
static void allocSpace(char *p)
{
    p = (char *)malloc(100);
    /*
     static void *memset(static void *s, int ch, size_t n);
     函数解释：将s中当前位置后面的n个字节 （typedef unsigned int size_t ）用 ch 替换并返回 s 。
     */
    memset(p, 0, 100);
    strcpy(p, "hello world");
//    std::cout << p << std::endl;
}

static void test7()
{
    char *p = NULL;
    allocSpace(p);
    printf("%s\n", p);
}
/////////////////////////

//////////正确的///////////////
static void allocSpace1(char **p)
{
    char *temp = (char *)malloc(100);
    memset(temp, 0, 100);
    strcpy(temp, "hello world");
    *p = temp;
}

static void test8()
{
    char *p = NULL;
    allocSpace1(&p);
    printf("%s\n", p);
    free(p);
}

static void test9()
{
    const char *p = "hello world!";
    printf("%p\n", &p);
    printf("%p\n", &"hello world!");
}

static void test10()
{
//    int a = 0xaabbccdd;
//    unsigned char *p = &a;
    
}

/////////////////////////////

//int main(int argc, const char * argv[]) {
//    // insert code here...
//    std::cout << "Hello, World!\n";
//    
//    test2();
//    test3();
//    test4();
//    test5();
//    test6();
//    test7();
//    test8();
//    test9();
//    return 0;
//}
