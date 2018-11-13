//
//  LinkList.c
//  StudyC++
//
//  Created by xiaoyuan on 2018/11/13.
//  Copyright © 2018 xiaoyuan. All rights reserved.
//  24动态链表

#include "LinkList.h"

// 初始化链表
struct LinkData *Init_LinkList(void) {
    
    // 为链表的头部分配内存空间，让header的next指向NULL
    // header本身不存储数据，只记录第一条节点的内存地址
    struct LinkData *header = malloc(sizeof(struct LinkData));
    header->data = -1;
    header->next = NULL;
    
    // 尾部指针
    struct LinkData *bear = header;
    
    int val = -1;
    while (true) {
        // 提示用户从键盘输入插入的数据
        printf("请输入需要插入的数据（输入-1结束）：");
        scanf("%d", &val);
        
        if (val == -1) { // 输入-1结束输入
            break;
        }
        
        // 创建新节点
        struct LinkData *newNode = malloc(sizeof(struct LinkData));
        newNode->data = val;
        newNode->next = NULL;
        
        // 将新节点插入到链表中
        bear->next = newNode;
        
        // 更新尾部指针
        bear = newNode;
    }

    return header;
}

// 在链表中值为oldValue的第一个节点位置插入一个新的数据newValue，如果oldValue不存在链表中，则将newValue插入到链表的尾部
void InsertByValue_LinkList(struct LinkData *header, int oldValue, int newValue) {
    if (NULL == header) {
        return;
    }
    
    // 定义两个辅助指针变量
    struct LinkData *pPrevious = header;
    struct LinkData *pCurrent = header->next;
    while (pCurrent != NULL) {
       
        // 如果找到了就插入
        if (pCurrent->data == oldValue) {
            
            break;
        }
        
        // 如果未找到，两个指针变量都向后移动
        pPrevious = pCurrent;
        pCurrent = pCurrent->next;
    }
#if 0
    // 此种情况只有在链表中存在oldValue的情况时才会插入newValue，否则不会插入
    // 如果pCurrent == NULL，说明没有找到那个节点，链表中不存在值为oldValue的节点
    if (pCurrent == NULL) {
        return;
    }
#endif
    
    
    // 创建新节点
    struct LinkData *newNode = malloc(sizeof(struct LinkData));
    newNode->data = newValue;
    if (pCurrent != NULL) {
        // 将newNode插入到oldValue所属的节点后面
        // pCurrent != NULL 说明pCurrent 指向oldValue所属的节点内存
        // 让新节点指向oldValue的next节点
        newNode->next = pCurrent->next;
        // 让oldValue所在节点指向新节点
        pCurrent->next = newNode;
    }
    else {
        // 将newNode插入到链表的末尾
        // 如果 pCurrent == NULL 说明当前链表中没有找到oldValue，pCurrent为最后一个元素的next
        // 此时pPrevious为链表的最后一个元素，我们需要更新newNode为最后一个元素，让pPrevious的next指向 newNode即可
        pPrevious->next = newNode;
        newNode->next = NULL;
    }
}

// 删除值为value的节点
void RemoveValue_LinkList(struct LinkData *header, int value) {
    if (header == NULL) {
        return;
    }
    
    struct LinkData *pPrevious = header;
    struct LinkData *pCurrent = pPrevious->next;
    
    while (pCurrent != NULL) {
        if (pCurrent->data == value) {
            // 找到value所在的节点
            break;
        }
        
        // 没找到value所在的节点，指针向下移动
        pPrevious = pCurrent;
        pCurrent = pPrevious->next;
    }
    
    if (pCurrent != NULL) {
        // 找到value所在的节点，让pPrevious的next指向pCurrent的next内存地址
        pPrevious->next = pCurrent->next;
        // 是否pCurrent
        free(pCurrent);
        pCurrent = NULL;
    }
    
}

// 遍历节点
void ForEach_LinkList(struct LinkData *header) {
    
    if (NULL == header) {
        return;
    }
    
    // 创建辅助指针变量， 让其指向链表头部的第一个结点，[header本身只用来记录链表的第一个节点(不存储数据)]
    struct LinkData *pCurrent = header->next;
    while (pCurrent != NULL) {
        printf("%d\n", pCurrent->data);
        pCurrent = pCurrent->next;
    }
}

// 销毁
void Distory_LinkList(struct LinkData **header) {
    if (NULL == header) {
        return;
    }
    
    // 定义赋值指针变量
    struct LinkData *pCurrent = *header;
    while (pCurrent != NULL) {
        
        // 定义临时指针变量，记录当前节点的下一个节点
        struct LinkData *pNext = pCurrent->next;
        // 释放当前节点
        free(pCurrent);
        // 记录pNext
        pCurrent = pNext;
    }
    *header = NULL;
}

// 清空链表中所有数据
void Clean_LinkList(struct LinkData *header) {
    if (header == NULL) {
        return;
    }
    
    // 定义赋值指针变量
    struct LinkData *pCurrent = header->next;
    while (pCurrent != NULL) {
        
        // 先保存下当前节点的下一个节点内存地址，防止释放当前节点后找不到下一个节点
        struct LinkData *pNext = pCurrent->next;
        // 释放当前节点
        free(pCurrent);
        // 让当前节点pCurrent指向下一个节点
        pCurrent = pNext;
    }
    
    // 清空header
    header->next = NULL;
}
