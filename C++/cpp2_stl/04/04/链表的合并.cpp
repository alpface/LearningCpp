//
//  链表的合并.cpp
//  04
//
//  Created by xiaoyuan on 2018/12/21.
//  Copyright © 2018 xiaoyuan. All rights reserved.
//  链表合并，将两个有序的链表合并为一个

#include <iostream>

using namespace std;

struct Node {
    int value;
    Node *next;
};

// 生成元素有10个随机数的链表
Node *make_linkList(void)
{
    Node *head = new Node();
    Node *cur = head;
    for (int i = 0; i < 10; ++i) {
        cur->value = rand()%10;
        cur->next = new Node();
        cur = cur->next;
    }
    return head;
}
void printLink(Node *head)
{
    Node *pCur = head;
    while (pCur) {
        cout << pCur->value << " ";
        pCur = pCur->next;
    }
    cout << endl;
}

void  sort(Node *head)
{
    Node *cur = head;
    while (cur) {
        Node *min = cur;
        Node *cur2 = cur->next;
        while (cur2) {
            if (cur2->value < min->value) {
                min = cur2;
            }
            cur2 = cur2->next;
        }
        int temp = cur->value;
        cur->value = min->value;
        min->value = temp;
        cur = cur->next;
    }
}

Node *merge(Node *h1, Node *h2)
{
    Node *mcur = new Node();
    Node *cur1 = h1;
    Node *cur2 = h2;
    while (cur1 && cur2) {
        if (cur1->value < cur2->value) {
            mcur->next = cur1;
            mcur = mcur->next;
            cur1 = cur1->next;
        }
        else
        {
            mcur->next = cur2;
            mcur = mcur->next;
            cur2 = cur2->next;
        }
    }
    
    if (cur1) {
        mcur->next = cur1;
    }
    else
    {
        mcur->next = cur2;
        
    }
    return h1->value < h2->value ? h1 : h2;
}

void test()
{
    Node *node1 = make_linkList();
    cout << "随机生成有10个元素的随机数链表1：" << endl;
    printLink(node1);
    cout << "对链表1排序：" << endl;
    sort(node1);
    printLink(node1);
    
    Node *node2 = make_linkList();
    cout << "随机生成有10个元素的随机数链表2：" << endl;
    printLink(node2);
    sort(node2);
    cout << "对链表2排序：" << endl;
    printLink(node2);
    
    Node *newNode = merge(node1, node2);
    cout << "合并后的链表：" << endl;
    printLink(newNode);
    
}



int main(int argc, const char *argv[])
{
    test();
    return 0;
}
