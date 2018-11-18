//
//  LinkStack.c
//  StudyC++
//
//  Created by xiaoyuan on 2018/11/16.
//  Copyright © 2018 xiaoyuan. All rights reserved.
//

#include "LinkStack.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// 用户入栈的数据，前四个字节是预留给我们使用的，所以我们把用户数据强制转为StackNode类型，就可以取到我们的节点数据了

// 初始化
LinkStack Init_LinkStack(void)
{
    struct LStack *stack = malloc(sizeof(struct LStack));
    if (NULL == stack) {
        return NULL;
    }
    stack->header.next = NULL;
    stack->size = 0;
    return stack;
}

// 入栈
void Push_LinkStack(LinkStack stack, void *data)
{
    if (NULL == stack) {
        return;
    }
    if (NULL == data) {
        return;
    }
    
    struct LStack *myStack = (struct LStack *)stack;
    // 将用户传入的data强转为StackNode
    // 因为用户入栈的数据，前四个字节是预留给我们使用的，所以我们把用户数据强制转为StackNode类型，就可以取到我们的节点数据了
    struct StackNode *newNode = (struct StackNode *)data;
    
    // 将新数据放到链表的头结点的下一个节点(放到最前面)
    newNode->next = myStack->header.next;
    myStack->header.next = newNode;
    myStack->size++;
}

// 出栈
void Pop_LinkStack(LinkStack stack)
{
    if (NULL == stack) {
        return;
    }
    
    // 移除链表头结点的下一个节点，然后更新后一个节点与头结点的关系即可
    struct LStack *myStack = (struct LStack *)stack;
    if (myStack->size == 0) {
        return;
    }
    // 缓存第一个节点
    struct StackNode *pFirst = myStack->header.next;
    // 让头结点指向第一个节点的下一个节点即可
    myStack->header.next = pFirst->next;
    myStack->size--;
}

// 获取栈顶元素
void *Top_LinkStack(LinkStack stack)
{
    if (NULL == stack) {
        return NULL;
    }
    struct LStack *myStack = (struct LStack *)stack;
    if (myStack->size == 0) {
        return NULL;
    }
    // 链表中的第一个节点就是栈顶元素，也就是头结点的next节点
    return myStack->header.next;
}

// 获取链表的元素个数
int Size_LinkStack(LinkStack stack)
{
    if (NULL == stack) {
        return -1;
    }
    struct LStack *myStack = (struct LStack *)stack;
    return myStack->size;
}

// 销毁链表
void Destory_LinkStack(LinkStack stack)
{
    if (NULL == stack) {
        return;
    }
    free(stack);
}
