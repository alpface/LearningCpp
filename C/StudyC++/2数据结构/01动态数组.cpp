//
//  01动态数组.cpp
//  StudyC++
//
//  Created by xiaoyuan on 2018/11/14.
//  Copyright © 2018 xiaoyuan. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "DynamicArray.h"

struct Person{
    char name[64];
    int age;
};

void myPrint(void *data, int index)
{
    struct Person *p = (struct Person *)data;
    printf("第%d位 -- name: %s -- age: %d\n", index, p->name, p->age);
}

int myCompare(void *v1, void *v2)
{
    struct Person *p1 = (struct Person *)v1;
    struct Person *p2 = (struct Person *)v2;
    return strcmp(p1->name, p2->name) == 0 && p1->age == p2->age;
}

void test()
{
    // 创建动态数组
    void *array = Init_DynamicArray(20);
    // 为动态数组添加元素
    struct Person p = {"xiaoyuan", 18};
    struct Person p1 = {"xiaoyuan1", 19};
    struct Person p2 = {"xiaoyuan2", 20};
    struct Person p3 = {"xiaoyuan3", 21};
    struct Person p4 = {"xiaoyuan4", 22};
    Insert_DynamicArray(array, 0, &p);
    Insert_DynamicArray(array, 0, &p1);
    Insert_DynamicArray(array, 1, &p2);
    Insert_DynamicArray(array, 2, &p3);
    Insert_DynamicArray(array, 3, &p4);
    Foreach_DynamicArray(array, myPrint);
    
    printf("__________________\n");
    struct Person p5 = {"xiaoyuan5", 23};
    Insert_DynamicArray(array, 1, &p5);
    Foreach_DynamicArray(array, myPrint);
    printf("capacity: %d\n", GetCapacity_DynamicArray(array));
    printf("size: %d\n", GetCount_DynamicArray(array));
    
    // 移除第二个元素
    RemoveByPos_DynamicArray(array, 2);
    Foreach_DynamicArray(array, myPrint);
    printf("capacity: %d\n", GetCapacity_DynamicArray(array));
    printf("size: %d\n", GetCount_DynamicArray(array));
    
    // 移除元素
    struct Person remove = {"xiaoyuan", 18};
    // 移除名字为xiaoyuan，年龄18岁的人
    RemoveByValue_DynamicArray(array, &remove, myCompare);
    Foreach_DynamicArray(array, myPrint);
    printf("capacity: %d\n", GetCapacity_DynamicArray(array));
    printf("size: %d\n", GetCount_DynamicArray(array));
    
    // 销毁
    Destroy_DynamicArray(array);
    
}

int main(int argc, const char *argv[])
{
    test();
    return EXIT_SUCCESS;
}
