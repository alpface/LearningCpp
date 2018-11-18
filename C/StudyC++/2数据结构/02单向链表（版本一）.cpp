//
//  02单向链表（版本一）.cpp
//  StudyC++
//
//  Created by xiaoyuan on 2018/11/15.
//  Copyright © 2018 xiaoyuan. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "./LinkList.h"

struct Person {
    char name[64];
    int age;
};

void myPrint(int index, void *data)
{
    struct Person *p = (struct Person *)data;
    printf("name:%s  -- age:%d\n", p->name, p->age);
}

int myCompare(void *value1, void *value2)
{
    struct Person *p1 = (struct Person *)value1;
    struct Person *p2 = (struct Person *)value2;
    return strcmp(p1->name, p2->name) == 0 && p1->age == p2->age;
}

void test()
{
    // 初始化链表
    LinkList list = Init_CLinkList();
    
    // 给链表添加数据
    struct Person p1 = { "aaa", 18 };
    struct Person p2 = { "bbb", 43 };
    struct Person p3 = { "ccc", 23 };
    struct Person p4 = { "ddd", 34 };
    struct Person p5 = { "eee", 12 };
    
    Insert_CLinkList(list, 0, &p1);
    Insert_CLinkList(list, 1, &p2);
    Insert_CLinkList(list, 2, &p3);
    Insert_CLinkList(list, 3, &p4);
    Insert_CLinkList(list, 4, &p5);
    
    // 遍历链表
    Foreach_CLinkList(list, myPrint);
    
    // 获取index为1的数据
    struct Person *value = (struct Person *)GetValueByPos_CLinkList(list, 1);
    printf("GetValueByPos [name:%s  -- age:%d]\n", value->name, value->age);
    
    printf("__________________\n");
    // 移除元素
    RemoveValue_ClinkList(list, &p3, myCompare);
    Foreach_CLinkList(list, myPrint);
    printf("__________________\n");
    struct Person del = { "eee", 12 };
    RemoveValue_ClinkList(list, &del, myCompare);
    Foreach_CLinkList(list, myPrint);
    printf("__________________\n");
    RemoveByPos_ClinkList(list, 0);
    Foreach_CLinkList(list, myPrint);
    printf("__________________\n");
    // 清空
    Clear_ClinkList(list);
    Foreach_CLinkList(list, myPrint);
    printf("__________________\n");
    // 释放
    Destory_ClinkList(list);
    list = NULL;
}

int main(int argc, const char *argv[])
{
    test();
    return EXIT_SUCCESS;
}
