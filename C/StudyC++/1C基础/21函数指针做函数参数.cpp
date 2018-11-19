//
//  21函数指针做函数参数.cpp
//  StudyC++
//
//  Created by xiaoyuan on 2018/11/12.
//  Copyright © 2018 xiaoyuan. All rights reserved.
//

#include <iostream>

/**
 可能我们无法确定函数的处理逻辑，程序需要动态的改变，这时我们可以通过定义函数指针来实现。
比如，我们有加法，乘法两个函数，如果还要一个除法我们怎么做，可能我们会想到，这好办，创建一个除法的函数，分分钟搞定。如果客户还要变怎么办？数据还是那些数据，只是函数的功能改变了。那有点太麻烦了。我们定义一个中间函数，其他函数作为指针参数传递进来，这样就可进行动态的处理了。
 */

// 函数指针就是一个变量，保存函数的地址
// 函数指针作为函数参数，就是回调函数

int sum(int a, int b)
{
    printf("执行的加法运算\n");
    return a + b;
}

int sub(int a, int b)
{
    printf("执行的减法运算\n");
    return a - b;
}

/// 计算 a 和 b的运算
/// @param a 参与计算的数字
/// @param b 参与计算的数字2
/// @param result 将计算的结果放在result所指向的内存空间
/// @param funcPointer 计算的方式 是一个函数指针类型的参数
void calculation(int a, int b, int *result, int (*funcPointer)(int, int))
{
    if (NULL == funcPointer) {
        return;
    }
    int res = funcPointer(a, b);
    if (NULL != result) {
        *result = res;
    }
}

void test()
{
    // 函数指针作为函数参数
    int result;
    calculation(10, 20, &result, sum);
    printf("%d\n", result);
}

extern void func1();
extern void func2();
extern void func3();

void test1()
{
    // 定义一个函数指针数组：保存的每个元素是一个函数指针，类型: 返回值为void类型，无参数
    void (*funcArray[3])();
    funcArray[0] = func1;
    funcArray[1] = func2;
    funcArray[2] = func3;
    
    for (int i = 0; i < 3; ++i) {
        funcArray[i]();
    }
}

void func1()
{
    printf("func1()\n");
}

void func2()
{
    printf("func2()\n");
}

void func3()
{
    printf("func3()\n");
}

extern void printAllArray(void *array, int elementSize, int len, void (*print)(void *));
extern void printChar(void *data);
void printPerson(void *data);

struct Person {
    char name[64];
    int age;
};

void test2()
{
    char array[3] = {'s', 'r', 'f'};
    printAllArray(array, sizeof(char), 3, printChar);
    
    Person personArray[3] = {
        {"xiaoyuan", 20},
        {"ketao", 18},
        {"meili", 26}
    };
    printAllArray(personArray, sizeof(Person), 3, printPerson);
}

// 打印所有类型的数组
void printAllArray(void *array, int elementSize, int len, void (*print)(void *))
{
    // 获取数组的首元素的地址指针
    char *startPos =(char *)array;
    
    for (int i = 0; i < len; ++i) {
//        printf("%d\n", startPos+i*elementSize);
        // 获取元素的内存首地址: 首地址 +（元素的长度 * 元素的index）= 下一个元素的首地址
        char *elementData = startPos + i * elementSize;
        print(elementData);
    }
    
}

void printChar(void *data)
{
    char *p = (char *)data;
    printf("%c\n", *p);
}

void printPerson(void *data)
{
    Person *p = (Person *)data;
    printf("name:%s --- age:%d\n", p->name, p->age);
}

int main(int argc, const char *argv[])
{
//    test();
//    test1();
    test2();
    return EXIT_SUCCESS;
}
