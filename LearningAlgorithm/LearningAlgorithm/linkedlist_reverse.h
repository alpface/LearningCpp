//
//  linkedlist_reverse.h
//  LearningAlgorithm
//
//  Created by swae on 2019/7/21.
//  Copyright © 2019 xiaoyuan. All rights reserved.
//  链表反转

#ifndef linkedlist_reverse_h
#define linkedlist_reverse_h

#include <stdio.h>

// 定义链表节点的结构体
struct Node {
    int data; // 数据域
    struct Node *next; // 指针域
};

// 构造一个链表
struct Node * construcLinkedtList(void);
// 对一个链表进行反转
struct Node * reverseLinkedList(struct Node *head);
// 打印链表中的所有数据
void printinkedtList(struct Node *head);

#endif /* linkedlist_reverse_h */
