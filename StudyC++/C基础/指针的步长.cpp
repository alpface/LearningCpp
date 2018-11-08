//
//  main.cpp
//  StudyC++
//
//  Created by xiaoyuan on 2018/11/5.
//  Copyright © 2018 xiaoyuan. All rights reserved.
//

#include <iostream>

struct Person {
    int a;
    char b;
    char buffer[64];
    int d;
};

// 通过指针的步长间接取值
static void test2()
{
    struct Person p = {20, 'x', "hello world", 100};
    printf("a offset %d\n", offsetof(struct Person, b));
    
    // 通过指针的步长，间接取d的值
    int d1 = *(int *)((char *)&p + offsetof(struct Person, d));
    printf("%d\n", d1);
}

// 指针的步长: 指针的变量+1，要向后跳多少字节
// 指针的步长是由指针的类型决定的
__unused static void test1()
{
    char *p = NULL;
    printf("%d\n", p);
    printf("%d\n", p+1);
    
    printf("-------------\n");
    
    int *i = NULL;
    printf("%d\n", i);
    printf("%d\n", i+1);
    
    printf("------------\n");
    char buffer[1024] = {0};
    int a = 100;
    // 把a的内存地址拷贝到buffer的偏移1中
    memcpy(buffer+1, &a, sizeof(int));
    // 拿到buffer的内存首地址
    char *b1 = buffer;
    // 拿到100的首地址,
    // note: 需要强转，因为char 是一个字节，需要转为int类型
    int *a1 = (int *)(b1+1);
    printf("%x\n", a1); // a1 存的是 100的内存地址
    printf("%d\n", *a1); // *a1 取100内存地址的值，也就是100
}

// 指针间接赋值: 只要拿到变量的地址，就可以间接的修改内存
static void changeValue(int *p)
{
    *p = 30;
}

static void test3()
{
    int a = 10;
    // &a是把a的地址传过去了，如果直接写a，则是把a的值传过去了
//    printf("%d\n", &a);
    changeValue(&a);
    printf("%d\n", a);
}

// 只要拿到地址就可以修改这块内存空间的值
static void test4()
{
    int a = 10;
    // a的地址不变 0x7ffeefbff57c
    printf("%p\n", &a);
    // 通过地址 间接修改a的值
    *(int *)0x7ffeefbff57c = 100;
    printf("%d\n", a);
}


// 修改指针指向: 指针保存变量的地址，拿到变量的z地址就可以修改内存的值
static void changePointer(int **val)
{
    *val = (int *)0x008;
}

static void test5()
{
    // 定义一级指针
    int *p = NULL;
    changePointer(&p);
    printf("p=%x\n", p);
}

// 打印字符串
static void printString(const char *str)
{
    printf("打印内容:%s\n", str);
}

// 打印数组
static void printArray(double *arr, int len)
{
    
}

static void printStrArray(const char **arr, int len)
{
    // arr[0] 是char * 类型的
    for (int i = 0; i < len; ++i) {
        printf("%s\n", arr[i]);
    }
}

// 指针的输出特性
// 主调函数分配内存，被调函数使用内存，这是指针的输入特性
static void test6()
{
    // 在堆上分配内存
    char *p = (char *)malloc(sizeof(char) * 100);
    memset(p, 0, 100);
    // 给p的内存拷贝字符串
    strcpy(p, "I am Polly!");
    // 让被调用的函数使用它
    printString(p);
    free(p);
    p = NULL;
    
    // 栈上分配内存
    // 指针数组: 每个元素都是char *类型的指针
    const char *statckP[] = {
        "aaaaaa",
        "bbbbbb",
        "cccccc",
        "dddddd",
    };
    // 求数组的长度
    int length = sizeof(statckP) / sizeof(statckP[0]);
    printf("length = %d\n", length);
    printStrArray(statckP, length);
    // 数组名作为函数参数就会退化为指向数组首元素的指针
//    double arr[] = {10.5, 20.6, 30.8, 50.9, 6.8};
}


/// 指针的输出特性
// 分配内存
void mallocSpace(char **temp)
{
    char *r = (char *)malloc(sizeof(char *) * 100);
    memset(r, 0, 100);
    strcpy(r, "hello world");
    // 指针的间接赋值
    *temp = r;
}
static void test7()
{
    char *p = NULL;
    mallocSpace(&p);
    printf("%s\n", p);
    if (p != NULL) {
        free(p);
        p = NULL;
    }
}

static void test8()
{
    // \0
    char str[] = {'h', 'e', 'l', 'l', 'o', '\0'};
    printf("%s\n", str);
    
    char str1[100] = {'h', 'e', 'l', 'l', 'o', '\0'};
    printf("%s\n", str1);
}

// 字符串拷贝
void copyString(char *des, const char *source)
{
    unsigned long len  = strlen(source);
    for (int i = 0; i < len; ++i) {
        des[i] = source[i];
    }
    // 最后一位要加上\0，防止des未初始化d，结尾的字符串未w而被复制的w的问题
    des[len] = '\0';
}

static void test9()
{
    const char *str = "hello world";
    char buffer[1024] = {0};
    copyString(buffer, str);
    printf("%s\n", buffer);
}


// const 修饰的 全局变量，放在常量区， 一旦初始化，不能直接修改，也不能通过指针修改
const int g_c = 10;
__unused static void test10()
{
    // 拿到g_c的内存地址
    int *p = (int *)&g_c;
    // 通过指针修改这块内存的值
    *p = 200;
    // 运行报错: Thread 1: EXC_BAD_ACCESS (code=2, address=0x100000fac)
}

// const 修饰的 布局变量，放在栈上，一旦初始化不能直接修改，但是可以通过指针间接修改
static void test11()
{
    const int a = 10;
    int *p = (int *)&a;
    *p = 200;
    // 修改成功
}

// 两种方式编写 字符串反转
static void reverseString(char *str)
{
    if (NULL == str) {
        return;
    }
    size_t len = strlen(str);
#if 0
    size_t start = 0;
    size_t end = len - 1;
    while (start < end) {
        char temp = str[start];
        str[start] = str[end];
        str[end] = temp;
        ++start;
        --end;
    }
#else
    // 定义str起始和结束的指针，
    char *pStart = str;
    char *pEnd = str + len - 1;
    while (pStart < pEnd) {
        char temp = *pStart;
        *pStart = *pEnd;
        *pEnd = temp;
        ++pStart;
        --pEnd;
    }
    
#endif
}

static void test12()
{
    // 如果要修改一个字符串，定义字符串时 使用数组char str[] ，不要使用char *str
    char str[] = "hello world";
    reverseString(str);
    printf("%s\n", str);
}

int main(int argc, const char *argv[])
{
//    test1();
//    test2();
//    test3();
//    test4();
//    test5();
//    test6();
//    test7();
//    test8();
//    test9();
//    test11();
    test12();
}
