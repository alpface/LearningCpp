//
//  LinkStack.h
//  StudyC++
//
//  Created by xiaoyuan on 2018/11/16.
//  Copyright © 2018 xiaoyuan. All rights reserved.
//  栈的链式存储

/*
 栈的链式存储结构及实现
 链式存储结构最大的好处就是没有空间的限制，通过指针指向将结点像一个链子一样把结点链接，那么栈的同样可以用于链式存储结构。
 
 栈的链式存储结构，简称为链栈。想想看，栈只是栈顶来做插入和删除操作，栈顶放在链表的头部还是尾部呢？由于单链表有头指针，而栈顶指针也是必须的，那么干嘛不让他们合二为一呢，所以比较好的办法是把栈顶放到单链表的头部。另外栈顶在头部了，那么单链表的头结点也就失去了意义，通常对于链栈来说，是不需要头结点的。
 
 同样对于链栈来说，基本不存在栈满的情况，除非内存已经没有可用的空间了。
 */

#pragma once

#ifdef __cplusplus
extern "C"{
#endif
    
    // 定义栈的节点结构体
    struct StackNode {
        // 指针域
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
    // 操作很简单，指针域指向原来栈顶元素。
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
