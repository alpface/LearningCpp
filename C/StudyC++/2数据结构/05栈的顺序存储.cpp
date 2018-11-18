//
//  05栈的顺序存储.cpp
//  StudyC++
//
//  Created by xiaoyuan on 2018/11/16.
//  Copyright © 2018 xiaoyuan. All rights reserved.
//

#include "SeqStack.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/*
 栈(Stack)是操作限定在表的尾端进行的线性表。表尾由于要进行插入、删除等操作，所以，它具有特殊的含义，把表尾称为栈顶（Top），另一端是固定的，叫栈底（Bottom）。当栈中没有数据元素时叫空栈(Empty Stack)。
 
 栈的操作是按照后进先出(Last In First Out，简称LIFO)或先进后出(First In Last Out，简称FILO)的原则进行的，因此，栈又称为LIFO表或FILO表。
 
 顺序栈
 用一片连续的存储空间来存储栈中的数据元素，这样的栈称为顺序栈(Sequence Stack)。类似于顺序表，用一维数组来存放顺序栈中的数据元素。栈顶指示器top设在数组下标为0的端，top随着插入和删除而变化，当栈为空时，top=-1。
 */

struct Person {
    char name[64];
    int age;
};

void test()
{
    // 初始化栈
    SeqStack stack = Init_SeqStack();
    
    struct Person p1 = {"aaaa", 10};
    struct Person p2 = {"aaaa", 20};
    struct Person p3 = {"aaaa", 30};
    struct Person p4 = {"aaaa", 40};
    struct Person p5 = {"aaaa", 50};
    struct Person p6 = {"aaaa", 60};
    
    // 数据入栈
    Push_SeqStack(stack, &p1);
    Push_SeqStack(stack, &p2);
    Push_SeqStack(stack, &p3);
    Push_SeqStack(stack, &p4);
    Push_SeqStack(stack, &p5);
    Push_SeqStack(stack, &p6);
    
    // 查找栈中的元素
    while (Size_SeqStack(stack) != 0) {
        
        // 获取栈顶的元素
        void *top = Top_SeqStack(stack);
        struct Person *p = (struct Person *)top;
        printf("Name:%s -- age:%d\n", p->name, p->age);
        // 出栈
        Pop_SeqStack(stack);
    }
    
    // 释放栈
    Destory_SeqStack(stack);
    stack = NULL;
}

int main(int argc, const char *argv[])
{
    test();
    return EXIT_SUCCESS;
}
