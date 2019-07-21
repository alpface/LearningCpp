//
//  linkedlist_reverse.c
//  LearningAlgorithm
//
//  Created by swae on 2019/7/21.
//  Copyright © 2019 xiaoyuan. All rights reserved.
//  链表反转

#include "linkedlist_reverse.h"


// 构造一个链表
struct Node * construcLinkedtList(void) {
    
    // 定义一个头结点
    struct Node *headP = NULL;
    // 记录当前尾结点
    struct Node *currentP = NULL;
    
    for (int i = 0; i < 5; i++) {
        // 创建当前结点
        struct Node *node = malloc(sizeof(struct Node));
        node->data = i;
        node->next = NULL;
        // 如果头结点为空，新节点就是头结点
        if (headP == NULL) {
            headP = node;
        }
        else {
            currentP->next = node;
        }
        
        // 记录当前节点
        currentP = node;
        
    }
    return headP;
}
// 对一个链表进行反转
struct Node * reverseLinkedList(struct Node *head) {
    // 定义临时指针p，初始化为头结点
    struct Node *p = head;
    // 定义一个新的链表头结点，作为反转后的链表头结点
    struct Node *newHead = NULL;
    
    while (p != NULL) {
        
        // 记录下一个结点
        struct Node *temp = p->next;
        // 当前结点的next指针指向链表头部
        p->next = newHead;
        // 更改新链表头部为当前结点
        newHead = p;
        // 移动p指针
        p = temp;
    }
    // 返回反转后的链表头结点
    return newHead;
}
//// 打印链表中的所有数据
void printinkedtList(struct Node *head) {
    struct Node *temp = head;
    while (temp != NULL) {
        printf("node is %d \n", temp->data);
        temp = temp->next;
    }
}
