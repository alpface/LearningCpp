//
//  calloc&realloc.cpp
//  StudyC++
//
//  Created by xiaoyuan on 2018/11/7.
//  Copyright © 2018 xiaoyuan. All rights reserved.
//

#include <iostream>

// calloc
void test1()
{
    int *p = (int *)calloc(10, sizeof(int));
    for (int i = 0; i < 10; ++i) {
        p[i] = i + 1;
    }
    for (int i = 0; i < 10; ++i) {
        printf("%d\n", p[i]);
    }
    
    if (NULL != p) {
        free(p);
        p = NULL;
    }
}

// realloc
void test2()
{
    // 申请一块连续的内存空间，可以容纳10个int类型的
    int *p = (int *)malloc(sizeof(int) * 10);
    for (int i = 0; i < 10; ++i) {
        p[i] = i+1;
    }
    for (int i = 0; i < 10; ++i) {
        printf("%d\n", p[i]);
    }
    printf("%d\n", p);
    p = (int *)realloc(p, sizeof(int) * 20);
    printf("%d\n", p);
    for (int i = 0; i < 10; ++i) {
        printf("%d\n", p[i]);
    }
}

int main(int argc, const char * arvc[] )
{
//    test1();
    test2();
}
