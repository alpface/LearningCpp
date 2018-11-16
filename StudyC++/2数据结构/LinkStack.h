//
//  LinkStack.h
//  StudyC++
//
//  Created by xiaoyuan on 2018/11/16.
//  Copyright © 2018 xiaoyuan. All rights reserved.
//  栈的链式存储

#pragma once

#ifdef __cplusplus
extern "C"{
#endif
    
    // 定义栈的节点结构体
    struct StackNode {
        struct StackNode *next;
    };
    
    // 定义栈的链表结构体
    struct LStack {
        // 头节点
        struct StackNode header;
        // 链表的元素个数
        int size;
    };
    
    typedef void * LinkStack;
    
    // 初始化
    LinkStack Init_LinkStack(void);
    
    // 入栈
    void Push_LinkStack(LinkStack stack, void *data);
    
    // 出栈
    void Pop_LinkStack(LinkStack stack);
    
    // 获取栈顶元素
    // 链表中的第一个节点就是栈顶元素，也就是头结点的next节点
    void *Top_LinkStack(LinkStack stack);
    
    // 获取链表的元素个数
    int Size_LinkStack(LinkStack stack);
    
    // 销毁链表
    void Destory_LinkStack(LinkStack stack);
    
#ifdef __cplusplus
}
#endif
