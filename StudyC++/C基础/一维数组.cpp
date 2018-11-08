//
//  一维数组.cpp
//  StudyC++
//
//  Created by swae on 2018/11/8.
//  Copyright © 2018 xiaoyuan. All rights reserved.
//

#include <iostream>

void printArray(int *array, int len)
{
    for (int i = 0; i < len; ++i) {
        // array[i] 和 *(array+i) 是等价的
        printf("%d\n", array[i]);
        printf("%d\n", *(array+i));
    }
}

void test()
{
    int arr[] = {1, 2, 3, 4};
    // 1.sizeof 2.对数组取地址&arr
    // 以上两种情况下，数组名不是指向首元素的指针
    // 以上两种情况下，数组名是数组类型
    // @note: 除了以上两种情况外，数组名在其他情况下都是指向首元素的指针
    printf("sizeof arr:%lu\n", sizeof arr);
    
    printf("&arr addr : %d\n", &arr);
    
    printf("&arr + 1 addr : %d\n", &arr + 1);
    
    int *p = arr;
    
    // 数组名是一个厂里指针，不可以修改数组名的指向
//    arr = NULL;
    
    // 数组下标是否能为负数
    // 答案: 可以的
    p += 3;
    printf("p[-1] = %d\n", p[-1]);
    // p[-1]等价于*(p-1)
    printf("p[-1] =  %d\n", *(p-1));
    
}

int main(int argc, const char *argv[])
{
    test();
    return EXIT_SUCCESS;
}
