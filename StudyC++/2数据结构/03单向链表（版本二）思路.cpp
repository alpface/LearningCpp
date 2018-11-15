//
//  03单向链表（版本二）思路.cpp
//  StudyC++
//
//  Created by xiaoyuan on 2018/11/15.
//  Copyright © 2018 xiaoyuan. All rights reserved.
//

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct LinkNode{
    // 指针域
    struct LinkNode *next;
};

struct Person {
    struct LinkNode node;
    char name[64];
    int age;
};

void test()
{
    struct Person p1 = {NULL, "aaaa", 18};
    struct Person p2 = {NULL, "bbbb", 19};
    struct Person p3 = {NULL, "cccc", 20};
    struct Person p4 = {NULL, "dddd", 21};
    struct Person p5 = {NULL, "eeee", 22};
    struct Person p6 = {NULL, "ffff", 23};
    
    struct LinkNode *n1 =(struct LinkNode *)&p1;
    struct LinkNode *n2 =(struct LinkNode *)&p2;
    struct LinkNode *n3 =(struct LinkNode *)&p3;
    struct LinkNode *n4 =(struct LinkNode *)&p4;
    struct LinkNode *n5 =(struct LinkNode *)&p5;
    struct LinkNode *n6 =(struct LinkNode *)&p6;
    
    n1->next = n2;
    n2->next = n3;
    n3->next = n4;
    n4->next = n5;
    n5->next = n6;
    n6->next = NULL;
    
    struct LinkNode *pCurrent = n1;
    while (pCurrent != NULL) {
        struct Person *p = (struct Person *)pCurrent;
        printf("Name:%s  -- age:%d\n", p->name, p->age);
        pCurrent = pCurrent->next;
    }
    
}

int main(int argc, const char *argv[])
{
    test();
    return EXIT_SUCCESS;
}
