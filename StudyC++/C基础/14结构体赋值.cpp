//
//  结构体赋值.cpp
//  StudyC++
//
//  Created by xiaoyuan on 2018/11/9.
//  Copyright © 2018 xiaoyuan. All rights reserved.
//

#include <iostream>

struct Teacher {
    char *name;
    int age;
};

void test1()
{
    
    // 栈上分配的结构体赋值
    struct Teacher t1 = {"xiaoyuan", 29};
    struct Teacher t2 = {"gaolei", 39};
    t2 = t1;
    return;
}

void test2()
{
    struct Teacher t1;
    t1.name = (char *)malloc(sizeof(char *) * 64);
    memset(t1.name, 0, 64);
    strcpy(t1.name, "yangxiaoyuan");
    t1.age = 28;
    
    struct Teacher t2;
    t2.name = (char *)malloc(sizeof(char *) * 64);
    memset(t2.name, 0, 64);
    strcpy(t2.name, "hongketao");
    t2.age = 27;
    
    // 错误的赋值方式:
#if 0
     t2 = t1;
#endif
    // 此种赋值, 会导致在释放内存时，重复释放，导致crash
    // 如果结构体内部成员有指针指向堆空间，那么就不能使用编译器默认的赋值行为, 应该手动控制赋值操作
    // 需要先释放掉t2内部的堆空间
    
    // 正确的赋值: 不使用=默认的结构体赋值
    if (NULL != t2.name) {
        free(t2.name);
        t2.name = NULL;
    }
    t2.name = (char *)malloc(strlen(t1.name) + 1);
    memset(t2.name, 0, strlen(t1.name) + 1);
    strcpy(t2.name, t1.name);
    t2.age = t1.age;
    
    printf("-----------------\n");
    
    printf("t1.name:%s -- t1.age:%d\n", t1.name, t1.age);
    printf("t2.name:%s -- t2.age:%d\n", t2.name, t2.age);
    
    if (NULL != t1.name) {
        free(t1.name);
        t1.name = NULL;
    }
    if (NULL != t2.name) {
        free(t2.name);
        t2.name = NULL;
    }
}


int main(int argc, const char *argv[])
{
//    test1();
    test2();
    return EXIT_SUCCESS;
}
