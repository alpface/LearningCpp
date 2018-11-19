//
//  SeqStack.c
//  StudyC++
//
//  Created by xiaoyuan on 2018/11/16.
//  Copyright © 2018 xiaoyuan. All rights reserved.
//

#include "SeqStack.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


// 初始化
SeqStack Init_SeqStack(void)
{
    // 分配内存
    struct SStack *stack = (struct SStack *)malloc(sizeof(struct SStack));
    if (NULL == stack) {
        return NULL;
    }
    
    // 为stack中的数组分配内存
//    memset(stack->data, 0, sizeof(sizeof(struct SStack)));
    for (int i = 0; i < MAX; ++i) {
        stack->data[i] = NULL;
    }
    
    stack->size = 0;
    
    return stack;
}

// 入栈
void Push_SeqStack(SeqStack stack, void *data) {
    if (NULL == data) {
        return;
    }
    if (NULL == stack) {
        return;
    }
    // 入栈，将数据压入栈顶 即放到数组高下标的位置即可
    
    struct SStack *sstack = (struct SStack *)stack;
    
    // 判断当前栈的存储空间是否足够
    if (sstack->size >= MAX) {
        return;
    }
    
    sstack->data[sstack->size] = data;
    sstack->size++;
}

// 出栈
void Pop_SeqStack(SeqStack stack)
{
    if (NULL == stack) {
        return;
    }
    // 出栈，将栈顶的数据移除
    
    struct SStack *sstack = (struct SStack *)stack;
    if (sstack->size == 0) {
        return;
    }
    sstack->data[sstack->size-1] = NULL;
    sstack->size--;
}

// 获取栈顶的元素
void *Top_SeqStack(SeqStack stack)
{
    if (NULL == stack) {
        return NULL;
    }
    struct SStack *sstack = (struct SStack *)stack;
    if (sstack->size == 0) {
        return NULL;
    }
    void *data = sstack->data[sstack->size-1];
    return data;
}

// 获取栈的大小
int Size_SeqStack(SeqStack stack)
{
    if (NULL == stack) {
        return -1;
    }
    struct SStack *sstack = (struct SStack *)stack;
    return sstack->size;
}

// 销毁栈
void Destory_SeqStack(SeqStack stack)
{
    if (NULL == stack) {
        return;
    }
    free(stack);
}
