//
//  25排序算法.cpp
//  StudyC++
//
//  Created by xiaoyuan on 2018/11/13.
//  Copyright © 2018 xiaoyuan. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/// 选择排序
/// @param ptr 需要排序的指针
/// @param elementSize 元素的大小
/// @param elementCount 元素的数量
/// @param compare 比较元素规则的函数指针
void selectSort(void *ptr, int elementSize, int elementCount, int (*compare)(void *, void *))
{
    // 开辟赋值内存空间，在交换数据时，用于临时存储的
    char *temp = (char *)malloc(elementSize);
    
    for (int i = 0; i < elementCount; ++i) {
        
        int minOrMax = i;
        
        for (int j = i+1; j < elementCount; ++j) {
            
            char *pJ = (char *)ptr + j * elementSize;
            char *pMinOrMax = (char *)ptr + minOrMax * elementSize;
            if (compare(pJ, pMinOrMax)) {
                minOrMax = j;
            }
        }
        
        if (minOrMax != i) {
            char *pMinOrMax = (char *)ptr + minOrMax *elementSize;
            char *pI = (char *)ptr + i * elementSize;
            // 交换内存空间
            // 拷贝pI所执行的内存到temp所指向的内存中
            memcpy(temp, pI, elementSize);
            // 拷贝pMinOrMax所执行的内存到pI所指向的内存中
            memcpy(pI, pMinOrMax, elementSize);
            // 拷贝temp所执行的内存到pMinOrMax所指向的内存中
            memcpy(pMinOrMax, temp, elementSize);
        }
    }
    
    // 释放临时的内存空间
    if (temp != NULL) {
        free(temp);
        temp = NULL;
    }
    
}

int compareInt(void *p1, void *p2)
{
    int *d1 = (int *)p1;
    int *d2 = (int *)p2;
    return *d1 < *d2;
}

void test()
{
    int array[5] = {1, 90, 23, 22, 67};
    selectSort(array, sizeof(int), 5, compareInt);
    
    for (int i = 0; i < 5; ++i) {
        printf("%d\n", array[i]);
    }
    
}

int main(int argc, const char *argv[])
{
    test();
    return EXIT_SUCCESS;
}
