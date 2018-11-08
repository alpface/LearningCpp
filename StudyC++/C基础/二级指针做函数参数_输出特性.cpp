//
//  二级指针做函数参数_输出特性.cpp
//  StudyC++
//
//  Created by xiaoyuan on 2018/11/8.
//  Copyright © 2018 xiaoyuan. All rights reserved.
//

#include <iostream>

void allocSpace(int **temp)
{
    int *p = (int *)malloc(sizeof(int) * 10);
    memset(p, 0, 10);
    for (int i = 0; i < 10; ++i) {
        p[i] = i + 1;
    }
    if (temp) {
        // 指针的间接赋值
        *temp = p;
    }
}

void printArray(int *arr, int len)
{
    for (int i = 0; i < len; ++i) {
        printf("%d ", arr[i]);
        if (i == len - 1) {
            printf("\n");
        }
    }
}

#if 0
void freeArray(void *arr)
{
    if (arr == NULL) {
        return;
    }
    free(arr);
    arr = NULL;
}

#else
// 修改指针的指向
void freeArray(int **arr)
{
    if (arr == NULL) {
        return;
    }
    if (*arr != NULL) {
        free(*arr);
        *arr = NULL;
        arr = NULL;
    }
}
#endif

void test()
{
    int *pArray = NULL;
    allocSpace(&pArray);
    printArray(pArray, 10);
#if 0
    // 此种释放内存，需要将指针 变量z重置为NULL
    free(pArray);
    pArray = NULL;
#else
    // 使用指针传递，不需要重置为NULL
    freeArray(&pArray);
    if (pArray == NULL) {
        printf("pArray = NULL\n");
    }
#endif
}

int main(int argc, const char *argv[])
{
    test();
    
    return EXIT_SUCCESS;
}
