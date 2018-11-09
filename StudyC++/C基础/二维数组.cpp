//
//  二维数组.cpp
//  StudyC++
//
//  Created by xiaoyuan on 2018/11/9.
//  Copyright © 2018 xiaoyuan. All rights reserved.
//

#include <iostream>

void printArray(int (*pArr)[3], int len1, int len2)
{
    for (int i = 0; i < len1; ++i) {
        for (int j = 0; j < len2; ++j) {
            printf("%d ", *(*(pArr + i) + j));
        }
    }
}

void test()
{
    // 二维数组
    int array[3][3] = {
        {1, 9, 10},
        {20, 60, 100},
        {56, 98, 23},
    };
    
    // 对于多维数组和一维数组相同， 除了&array取地址和sizeof以外，数组名就是取数组首元素的地址
    
    // 打印array的类型
    printf("%s\n", typeid(array).name());
    
    int (*pArray)[3] = array;
    int n = pArray[1][2];
    printArray(pArray, 3, 3);
    return;
}

int main(int argc, const char *argv[])
{
    test();
    return EXIT_SUCCESS;
}
