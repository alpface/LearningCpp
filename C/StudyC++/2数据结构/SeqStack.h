//
//  SeqStack.h
//  StudyC++
//
//  Created by xiaoyuan on 2018/11/16.
//  Copyright © 2018 xiaoyuan. All rights reserved.
//  栈的顺序存储：本demo栈中的数据是使用数组模拟存储的

/**
 栈分为两种,一种是顺序栈,一种是链栈。两种都是线性表的结构。
 
栈是比较特殊的一种线性表,只能在一端插入或是删除数据。只能插入和删除数据的一端为栈顶，而固定不变的是栈底。
 
 栈完全符合先进后出（后进先出）的规则。
 
 向栈中插入数据，叫做入栈（push）。
 
 从栈中取出数据，叫做出栈（pop）。
 
 两种情况下均是移动栈顶指针。
 */

#pragma once

#ifdef __cplusplus
extern "C"{
#endif

#define MAX 1024
 
    // 顺序栈的数据结构
    struct SStack {
        // 存放数据的数组
        int *data[MAX];
        // 栈中元素的个数
        int size;
    };
    
    typedef void* SeqStack;
    
    // 初始化
    SeqStack Init_SeqStack(void);
    
    // 入栈
    void Push_SeqStack(SeqStack stack, void *data);
    
    // 出栈
    void Pop_SeqStack(SeqStack stack);
    
    // 获取栈顶的元素
    void *Top_SeqStack(SeqStack stack);
    
    // 获取栈的大小
    int Size_SeqStack(SeqStack stack);
    
    // 销毁栈
    void Destory_SeqStack(SeqStack stack);
    
#ifdef __cplusplus
}
#endif
