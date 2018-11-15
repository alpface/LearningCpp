//
//  04单向链表（版本二）.cpp
//  StudyC++
//
//  Created by swae on 2018/11/15.
//  Copyright © 2018 xiaoyuan. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// 链表节点结构
struct LinkNode {
    struct LinkNode *next;
};

// 链表结构体
struct LList {
    // 头节点
    struct LinkNode header;
    int size;
};

typedef LList * LinkList;

// 初始化链表
LinkList Init_LinkList(void) {
    
    struct LList *list  = (struct LList *)malloc(sizeof(struct LList));
    if (NULL == list) {
        return NULL;
    }
    
    list->header.next = NULL;
    list->size = 0;
    return list;
}

// 插入数据
void Insert_LinkList(LinkList list, int position, void *data) {
    if (NULL == list) {
        return;
    }
    if (NULL == data) {
        return;
    }
    struct LList *llist = (struct LList *)list;
    if (position < 0 || position > llist->size) {
        position = list->size;
    }
    
    // 找位置，找到position前一个的位置
    struct LinkNode *pCurrent = &(llist->header);
    for (int i = 0; i < position; ++i) {
        
        pCurrent = pCurrent->next;
    }
    
    // 插入链表
    struct LinkNode *newNode = (struct LinkNode *)data;
    newNode->next = pCurrent->next;
    pCurrent->next = newNode;
    llist->size++;
}

// 遍历
void Foreach_LinkList(LinkList list, void (*myForeach)(int index, void *data))
{
    if (NULL == list) {
        return;
    }
    if (NULL == myForeach) {
        return;
    }
    struct LList *llist = (struct LList *)list;
    struct LinkNode *pCurrent = list->header.next;
    for (int i = 0; i < llist->size; ++i) {
        struct LinkNode *pNext = pCurrent->next;
        myForeach(i, pCurrent);
        pCurrent = pNext;
    }
}

int main(int argc, const char *argv[])
{
    
    return EXIT_SUCCESS;
}

