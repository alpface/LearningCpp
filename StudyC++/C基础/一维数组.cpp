//
//  一维数组.cpp
//  StudyC++
//
//  Created by swae on 2018/11/8.
//  Copyright © 2018 xiaoyuan. All rights reserved.
//

#include <iostream>

/** 数组名和指针的区别 **/
/*
 这两种情况下，数组不再当成常量指针来使用。
 总结：
 1.数组名代表了一个指向数组首元素的常量指针，一经定义，不可更改，数组名作为常量指针，其类型与数组元素类型相同。指针是变量指针，定义之后仍可更改，其类型在定义时确定。
 
 2.当出现sizeof,和&操作符时，数组名不再当成指向一个元素的常量指针来使用，而指针仍当成指向一个元素的变量指针来使用。
 
 对于使用指针和数组下标的选择：
 系统在使用数组下标对数组成员变量进行访问时，开销比较大，指针的访问效率是远远大于数组名的访问效率的。
 但是只有在指针正确访问时，才成比下标法更有效率。
 下标法更加容易理解，在可读性方面，也更加的具有优势，具体怎么选择，也没有一定的说法。
 ---------------------
 */

/// 重要: 当数组名作为函数参数传递时，实际传递给函数的是指向数组首元素的指针

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
    
    // 当对数组名使用sizeof时，得到的是数组元素的个数乘元素类型的字节数，对指针sizeof得到的是指针类型的字节数。
    printf("sizeof arr:%lu\n", sizeof arr);
    
    printf("&arr addr : %d\n", &arr);
   // 看到对arr取地址后加1后，增大了16个字节，
    printf("&arr + 1 addr : %d\n", &arr + 1);
    
    int *p = arr;
    printf("&p addr : %d\n", &p);
    // 而对指针p取地址后加一，只增大了8个字节，所以说它们取地址后加一的能力不同。
    printf("&p + 1 addr : %d\n", &p + 1);
    
    // 数组名是一个厂里指针，不可以修改数组名的指向
//    arr = NULL;
    
    // 数组下标是否能为负数
    // 答案: 可以的
    p += 3;
    printf("p[-1] = %d\n", p[-1]);
    // p[-1]等价于*(p-1)
    printf("p[-1] =  %d\n", *(p-1));
    
}

// 定义一个指向数组的指针
void test1()
{
    int arr[5] = {10, 20, 30, 40, 50};
    
    // 1.定义数组类
    // 数组类型为int 类型的数组 有5个元素
    typedef int(ARRAY_TYPE)[5];
    
    ARRAY_TYPE myArray; // 等价于 int myArray[5];
    for (int i = 0; i < 5; ++i) {
        myArray[i] = 100 + i;
    }
    
    for (int i = 0; i < 5; ++i) {
        printf("%d ", myArray[i]);
        if (i == 4) {
            printf("\n");
        }
    }
    
    // 指向整个数组的指针
    ARRAY_TYPE *pArray = &myArray;
    // 修改指针的指向
    pArray = &arr;
    
    /*
     1.*pArray 表示拿到pArray指向的整个数组
     2.*pArray 就是数组名
     */
    
    printf("*(pArray + 1): %d\n *pArray + 1: %d\n", *(pArray + 1), *pArray + 1);
    
    // 2. 定义数组指针类型
    typedef int(*ARRAY_POINTER)[5];
    ARRAY_POINTER arrayP = &myArray;
    arrayP = pArray;
    
    // 3.直接定义数组变量
    int (*pArrayParam)[5] = &myArray;
    return;
}

int main(int argc, const char *argv[])
{
//    test();
    test1();
    return EXIT_SUCCESS;
}
