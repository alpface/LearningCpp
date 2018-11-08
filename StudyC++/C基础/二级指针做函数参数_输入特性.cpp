//
//  二级指针做函数参数_输入特性.cpp
//  StudyC++
//
//  Created by xiaoyuan on 2018/11/8.
//  Copyright © 2018 xiaoyuan. All rights reserved.
//

#include <iostream>

void printArray(int **array, int len)
{
    for (int i = 0; i < len; ++i) {
        printf("%d ", *(array[i]));
    }
}

// 在堆上分配的指针数组，数组中每个元素是在堆中分配的内存指针，每个元素需要释放，数组也需要释放
void test()
{
    int **array = (int **)malloc(sizeof(int *) * 5);
    for (int i = 0; i < 5; ++i) {
        // 分配内存
        array[i] = (int *)malloc(sizeof(int));
        // 给内存赋值
        *(array[i]) = 100 + i;
    }
    printArray(array, 5);
    
    if (array == NULL) {
        return;
    }
    
    for (int i = 0; i < 5; ++i) {
        if (array[i] != NULL) {
            free(array[i]);
            array[i] = NULL;
        }
    }
    
    free(*array);
    
}

// 在栈上分配的指针数组，数组中每个元素是在堆中分配的内存指针，每个元素需要释放，数组不需要释放
void test1()
{
    int *array[5];
    for (int i = 0; i < 5; ++i) {
        // 分配内存
        array[i] = (int *)malloc(sizeof(int));
        // 给内存赋值
        *(array[i]) = 100 + i;
    }
    printArray(array, 5);
    
    
    for (int i = 0; i < 5; ++i) {
        if (array[i] != NULL) {
            free(array[i]);
            array[i] = NULL;
        }
    }
    
}

int main(int argc, const char *argv[])
{
    test1();
    return 0;
}
