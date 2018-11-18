//
//  08队列的链式存储.cpp
//  StudyC++
//
//  Created by swae on 2018/11/17.
//  Copyright © 2018 xiaoyuan. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkQueue.h"

struct Person {
    QueueNode node;
    char name[64];
    int age;
};


void test()
{
    // 初始化队列
    LinkQueue queue = Init_LinkQueue();
    
    struct Person p1 = {NULL, "aaaa", 10};
    struct Person p2 = {NULL, "aaaa", 20};
    struct Person p3 = {NULL, "aaaa", 30};
    struct Person p4 = {NULL, "aaaa", 40};
    struct Person p5 = {NULL, "aaaa", 50};
    struct Person p6 = {NULL, "aaaa", 60};
    struct Person p7 = {NULL, "aaaa", 70};
    
    // 入队
    Push_LinkQueue(queue, &p1);
    Push_LinkQueue(queue, &p2);
    Push_LinkQueue(queue, &p3);
    Push_LinkQueue(queue, &p4);
    Push_LinkQueue(queue, &p5);
    Push_LinkQueue(queue, &p6);
    Push_LinkQueue(queue, &p7);
    
    // 查看队列
    // 查看队列的末尾
    Person *real = (Person *)Back_LinkQueue(queue);
    printf("real [Name:%s -- Age%d]\n", real->name, real->age);
    while (Size_LinkQueue(queue) != 0) {
        
        // 打印队列的头部
        Person *p = (Person *)Front_LinkQueue(queue);
        printf("Name:%s -- Age%d\n", p->name, p->age);
        // 出队
        Pop_LinkQueue(queue);
    }
    
    // 销毁队列
    Destory_LinkQueue(queue);
}

int main(int argc, const char *argv[])
{
    test();
    return EXIT_SUCCESS;
}
