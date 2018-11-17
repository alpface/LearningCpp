//
//  LinkQueue.h
//  StudyC++
//
//  Created by swae on 2018/11/17.
//  Copyright © 2018 xiaoyuan. All rights reserved.
//  通过链表实现队列的链式存储

#pragma once

#ifdef __cplusplus
extern "C"{
#endif
    
    // 链表节点的数据结构类型
    struct QueueNode {
        // 指针域
        struct QueueNode *next;
    };
    
    // 链表的数据结构类型 先进先出
    // 插入数据时插入到尾部 弹出数据时从头部弹出
    struct LQueue {
        // 链表的头结点
        struct QueueNode header;
        // 链表的元素个数
        int size;
        // 尾指针，此指针始终指向链表的最后一个节点
        struct QueueNode *rear;
    };
    
    typedef void * LinkQueue;
    
    // 初始化
    LinkQueue Init_LinkQueue(void);
    
    // 添加数据 插入到队列尾部
    void Push_LinkQueue(LinkQueue queue, void *data);
    
    // 弹出数据 弹出队列的首节点
    void Pop_LinkQueue(LinkQueue queue);
    
    // 获取头结点
    struct QueueNode *Front_LinkQueue(LinkQueue queue);
    
    // 获取尾节点
    struct QueueNode *Back_LinkQueue(LinkQueue queue);
    
    // 获取队列的元素个数
    int Size_LinkQueue(LinkQueue queue);
    
    // 释放队列
    void Destory_LinkQueue(LinkQueue queue);
#ifdef __cplusplus
}
#endif
