//
//  LinkQueue.c
//  StudyC++
//
//  Created by swae on 2018/11/17.
//  Copyright © 2018 xiaoyuan. All rights reserved.
//

#include "LinkQueue.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


// 初始化
LinkQueue Init_LinkQueue(void)
{
    // 分配队列的内存空间
    struct LQueue *queue = malloc(sizeof(struct LQueue));
    if (NULL == queue) {
        return queue;
    }
    
    // 初始化队列
    queue->header.next = NULL;
    // 没有元素，让队列的尾指针指向头节点的内存空间
    queue->rear =  &(queue->header);
    queue->size = 0;
    return queue;
}

// 添加数据 插入到队列尾部
void Push_LinkQueue(LinkQueue queue, void *data)
{
    if (NULL == queue) {
        return;
    }
    if (NULL == data) {
        return;
    }
    
    // 添加数据时 遵守FIFO先进先出的原则 将其添加到队列的尾部
    struct LQueue *myQueue = (struct LQueue *)queue;
    struct QueueNode *newNode = (struct QueueNode *)data;
    // 让尾部指针指向新数据的内存空间
    myQueue->rear->next = newNode;
    // 置空新节点的指针域
    newNode->next = NULL;
    myQueue->rear = newNode;
    myQueue->size++;
}

// 弹出数据 弹出队列的首节点
void Pop_LinkQueue(LinkQueue queue)
{
    if (NULL == queue) {
        return;
    }
    // 弹出数据时 遵守FIFO先进先出的原则 将队列头部的数据移除
    struct LQueue *myQueue = (struct LQueue *)queue;
    myQueue->header.next = myQueue->header.next->next;
    myQueue->size--;
}

// 获取头结点
struct QueueNode *Front_LinkQueue(LinkQueue queue)
{
    if (NULL == queue) {
        return NULL;
    }
    struct LQueue *myQueue = (struct LQueue *)queue;
    return myQueue->header.next;
}

// 获取尾节点
struct QueueNode *Back_LinkQueue(LinkQueue queue)
{
    if (NULL == queue) {
        return NULL;
    }
    struct LQueue *myQueue = (struct LQueue *)queue;
    return myQueue->rear;
}

// 获取队列的元素个数
int Size_LinkQueue(LinkQueue queue)
{
    if (NULL == queue) {
        return -1;
    }
    struct LQueue *myQueue = (struct LQueue *)queue;
    return myQueue->size;
}

// 释放队列
void Destory_LinkQueue(LinkQueue queue)
{
    if (NULL == queue) {
        return;
    }
    free(queue);
    queue = NULL;
}
