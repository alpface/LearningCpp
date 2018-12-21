//
//  链表逆序.cpp
//  04
//
//  Created by xiaoyuan on 2018/12/21.
//  Copyright © 2018 xiaoyuan. All rights reserved.
//

#include <iostream>

using namespace std;

struct Node
{
    int value;
    Node *next;
};

// 生成链表
Node *make_linkList(void)
{
    Node *head = new Node();
    Node *cur = head;
    for (int i = 0; i < 10; ++i) {
        cur->value = rand() % 10;
        cur->next = new Node();
        cur = cur->next;
    }
    return head;
}

// 逆序链表
Node *reverse(Node *head)
{
    Node *pre, *post, *cur;
    if (!head && !head->next) {
        return head;
    }
    pre = head;
    cur = pre->next;
    while (cur) {
        post = cur->next;
        cur->next = pre;
        pre = cur;
        cur = post;
    }
    head->next = NULL;
    return pre;
}

void printLink(Node *head)
{
    Node *cur = head;
    while (cur) {
        cout << cur->value << " ";
        cur = cur->next;
    }
    cout << endl;
}


void test()
{
    Node *head = make_linkList();
    cout << "生成有10的元素的随机数链表:" << endl;
    printLink(head);
    head = reverse(head);
    cout << "对链表逆序后:" << endl;
    printLink(head);
}

int main(int argc, const char *argv[])
{
    test();
    return EXIT_SUCCESS;
}
