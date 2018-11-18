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

// 根据位置移除链表中的数据
void RemoveByPosition_LinkList(LinkList list, int position)
{
    if (NULL == list) {
        return;
    }
    struct LList *myList = (struct LList *)list;
    if (position < 0 || position > myList->size) {
        return;
    }
    
    // 找到position的上一个节点
    // 定义赋值指针变量
    struct LinkNode *pCurrent = &(myList->header);
    for (int i = 0; i < position; ++i) {
        pCurrent = pCurrent->next;
    }
    
    // 缓存待删除的节点
    struct LinkNode *pDel = pCurrent->next;
    
    // 重新建立待删除节点左右的链表关系
    pCurrent->next = pDel->next;
    
    // 注意: 由于节点不是堆上创建的，所以不需要释放节点
//    free(pDel);
//    pDel = NULL;
    
    myList->size--;
}

struct Person {
    LinkNode node;
    char name[64];
    int age;
};

void myPrint(int index, void *data)
{
    struct Person *p = (struct Person *)data;
    printf("Name:%s  -- age:%d\n", p->name, p->age);
}

void test()
{
    // 初始化链表
    LinkList list = Init_LinkList();
    struct Person p1 = {NULL, "aaaa", 20};
    struct Person p2 = {NULL, "bbbb", 30};
    struct Person p3 = {NULL, "cccc", 40};
    struct Person p4 = {NULL, "dddd", 50};
    struct Person p5 = {NULL, "eeee", 60};
    struct Person p6 = {NULL, "ffff", 70};
    
    // 插入数据
    Insert_LinkList(list, 0, &p1);
    Insert_LinkList(list, 1, &p2);
    Insert_LinkList(list, 2, &p3);
    Insert_LinkList(list, 3, &p4);
    Insert_LinkList(list, 4, &p5);
    Insert_LinkList(list, 5, &p6);
    
    // 遍历链表
    Foreach_LinkList(list, myPrint);
    printf("_____________\n");
    // 删除第二个节点
    RemoveByPosition_LinkList(list, 1);
    
    Foreach_LinkList(list, myPrint);
}

int main(int argc, const char *argv[])
{
    test();
    return EXIT_SUCCESS;
}

