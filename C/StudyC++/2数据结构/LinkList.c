//
//  LinkList.c
//  StudyC++
//
//  Created by xiaoyuan on 2018/11/15.
//  Copyright © 2018 xiaoyuan. All rights reserved.
//

#include "LinkList.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>


// 链表节点数据类型
struct LNode {
    // 数据域
    void *data;
    // 指针域
    struct LNode *next;
};

// 链表数据类型
struct LList {
    // 头结点
    struct LNode header;
    int size;
};


//// 初始化链表
LinkList Init_CLinkList(void) {
    // 初始化链表
    struct LList *list = malloc(sizeof(struct LList));
    if (NULL == list)
    {
        return NULL;
    }

    // 设置头结点
    list->header.data = NULL;
    list->header.next = NULL;
    list->size = 0;

    return list;
}

// 根据位置查找元素
void *GetValueByPos_CLinkList(LinkList list, int pos) {
    if (NULL == list) {
        return NULL;
    }

    struct LList *llist = (struct LList *)list;
    if (pos < 0 || pos >= llist->size) {
        return NULL;
    }
    struct LNode *pCurrent = llist->header.next;
    if (NULL == pCurrent) {
        return NULL;
    }
    for (int i = 0; i < pos; ++i) {
        pCurrent = pCurrent->next;
    }
    return pCurrent->data;
}

// 按pos位置插入某个节点
void Insert_CLinkList(LinkList list, int pos, void *data) {
    if (NULL == list) {
        return;
    }
    if (NULL == data) {
        return;
    }
    struct LList *llist = (struct LList *)list;
    if (pos < 0 || pos > llist->size) {
        pos = llist->size;
    }

    // 查找插入的位置
    struct LNode *pCurrent = &(llist->header);
    for (int i = 0; i < pos; ++i) {
        pCurrent = pCurrent->next;
    }

    // 创建新节点
    struct LNode *newNode = malloc(sizeof(struct LNode));
    newNode->data = data;
    newNode->next = NULL;

    // 将新节点插入到链表中
    newNode->next = pCurrent->next;
    pCurrent->next = newNode;

    // 更新size
    llist->size++;
}


//// 遍历链表
void Foreach_CLinkList(LinkList list, Foreach foreach) {
    if (NULL == list) {
        return;
    }
    if (NULL == foreach) {
        return;
    }

    struct LList *llist = (struct LList *)list;
    struct LNode *pCurrent = llist->header.next;

    int index = 0;
    while (pCurrent != NULL) {
        foreach(index, pCurrent->data);
        pCurrent = pCurrent->next;
        index++;
    }
}


// 按位置删除节点
void RemoveByPos_ClinkList(LinkList list, int pos) {
    if (NULL == list) {
        return;
    }
    struct LList *llist = (struct LList *)list;
    if (pos < 0 || pos >= llist->size) {
        return;
    }
    
    struct LNode *pCurrent = &(llist->header);
    for (int i = 0; i < pos; ++i) {
        pCurrent = pCurrent->next;
    }
    
    // 保存需要删除的节点
    struct LNode *pDel = pCurrent->next;
    // 重新建立要删除的节点的前驱和后继节点关系
    pCurrent->next = pDel->next;
    
    // 释放删除的内存
    if (NULL != pDel) {
        free(pDel);
        pDel = NULL;
    }
    llist->size--;
}

// 按值删除某个节点
void RemoveValue_ClinkList(LinkList list, void *data, Compare compare) {
    if (NULL == list) {
        return;
    }
    if (NULL == data) {
        return;
    }
    if (NULL == compare) {
        return;
    }
    
    struct LList *llist = (struct LList *)list;
    
    // 定义赋值指针变量
    struct LNode *pPrevious = &(llist->header);
    struct LNode *pCurrent = llist->header.next;
    while (pCurrent != NULL) {
        
        if (compare(pCurrent->data, data)) {
            // 找到了要删除的节点
            pPrevious->next = pCurrent->next;
            // 释放删除节点
            free(pCurrent);
            pCurrent = NULL;
            llist->size--;
            break;
        }
        
        // 没有找到
        pPrevious = pCurrent;
        pCurrent = pCurrent->next;
    }
    
}

// 清空节点
void Clear_ClinkList(LinkList list) {
    if (NULL == list) {
        return;
    }
    
    struct LList *llist = (struct LList *)list;
    // 定义辅助指针变量
    struct LNode *pCurrent = llist->header.next;
    
    while (pCurrent != NULL) {
        
        // 保存下一个节点的内存地址，防止找不到
        struct LNode *pNext = pCurrent->next;
        // 释放当前节点
        free(pCurrent);
        pCurrent = pNext;
    }
    llist->header.next = NULL;
    llist->size = 0;
}

// 销毁链表
void Destory_ClinkList(LinkList list) {
    if (NULL == list) {
        return;
    }
    
    // 先清空链表
    Clear_ClinkList(list);
    // 释放链表
    free(list);
    list = NULL;
}
