//
//  指针数组排序_选择排序.cpp
//  StudyC++
//
//  Created by xiaoyuan on 2018/11/9.
//  Copyright © 2018 xiaoyuan. All rights reserved.
//

#include <iostream>

// 打印数组
void printArray(const char **array, int len)
{
    for (int i = 0; i < len; ++i) {
        printf("%s\n", array[i]);
    }
}

// 选择排序
void selectSort(const char **array, int len)
{
    for (int i = 0; i < len; ++i) {
        int min = i;
        for (int j = i + 1; j < len; ++j) {
            // 比较两个字符串
            if (strcmp(array[j], array[min]) < 0) {
                // 如果j所在的字符串比min所在的字符串小,
                min = j;
            }
        }
        
        // 交互元素
        if (i != min) {
            const char* temp = array[i];
            array[i] = array[min];
            array[min] = temp;
        }
    }
}

void test()
{
    // pArray 是 char **类型
    const char *pArray[] = {"hahah", "nanan", "dada", "aaaaa", "ooooo", "xxxxx"};
    int len = sizeof(pArray) / sizeof(char *);
    printArray(pArray, len);
    printf("-----------------\n");
    selectSort(pArray, len);
    printArray(pArray, len);
}

int main(int argc, const char *argv[])
{
    test();
    return EXIT_SUCCESS;
}
