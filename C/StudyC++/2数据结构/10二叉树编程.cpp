//
//  10二叉树编程.cpp
//  StudyC++
//
//  Created by swae on 2018/11/18.
//  Copyright © 2018 xiaoyuan. All rights reserved.
//

#include <iostream>

struct BiNode {
    char ch;  // 数据域
    struct BiNode *leftChild; // 左子树
    struct BiNode *rightChild; // 右子树
};

// 计算二叉树的叶子节点数
void calculationLeafNum(struct BiNode *root, int *num)
{
    if (NULL == num) {
        return;
    }
    if (NULL == root) {
        return;
    }
    if (root->leftChild == NULL && root->rightChild == NULL) {
        (*num)++;
    }
    
    calculationLeafNum(root->leftChild, num);
    calculationLeafNum(root->rightChild, num);
}

// 计算二叉树的高度
int getTreeHeight(struct BiNode *root)
{
    if (NULL == root) {
        return 0;
    }
    
    // 左子树的高度
    int lHeight = getTreeHeight(root->leftChild);
    // 右子树的高度
    int rHeight = getTreeHeight(root->rightChild);
    int height = lHeight > rHeight ? lHeight + 1 : rHeight + 1;
    return height;
}

void showBiTree(struct BiNode *root)
{
    if (NULL == root) {
        return;
    }
    printf("%c", root->ch);
    showBiTree(root->leftChild);
    showBiTree(root->rightChild);
}

// 拷贝二叉树
struct BiNode *copyBiTree(struct BiNode *root)
{
    if (NULL == root) {
        return NULL;
    }
    
    // 先拷贝左子树
    struct BiNode *lNode = copyBiTree(root->leftChild);
    // 再拷贝右子树
    struct BiNode *rNode = copyBiTree(root->rightChild);
    
    struct BiNode *newNode = (struct BiNode *)malloc(sizeof(struct BiNode));
    newNode->leftChild = lNode;
    newNode->rightChild = rNode;
    newNode->ch = root->ch;
    return newNode;
}

void freeSpace(struct BiNode *root)
{
    if (NULL == root) {
        return;
    }
    // 先释放左子树内存
    freeSpace(root->leftChild);
    // 再释放右子树内存
    freeSpace(root->rightChild);
    printf("%c 被释放啦\n", root->ch);
    free(root);
}

void test()
{
    // 创建树的节点数据
    struct BiNode a = {'A', NULL, NULL};
    struct BiNode b = {'B', NULL, NULL};
    struct BiNode c = {'C', NULL, NULL};
    struct BiNode d = {'D', NULL, NULL};
    struct BiNode e = {'E', NULL, NULL};
    struct BiNode f = {'F', NULL, NULL};
    struct BiNode g = {'G', NULL, NULL};
    struct BiNode h = {'H', NULL, NULL};
    
    a.leftChild = &b;
    a.rightChild = &f;
    
    b.rightChild = &c;
    
    c.leftChild = &d;
    c.rightChild = &e;
    
    f.rightChild = &g;
    
    g.leftChild = &h;
    
    // 计算二叉树的叶子节点数
    int leafNum = 0;
    calculationLeafNum(&a, &leafNum);
    printf("二叉树的叶子节点数：%d\n", leafNum);
    
    // 计算二叉树的高度
    int treeHeight = getTreeHeight(&a);
    printf("二叉树的高度：%d\n", treeHeight);
    
    // 拷贝二叉树
    BiNode *newRoot = copyBiTree(&a);
    showBiTree(newRoot);
    printf("\n");
    showBiTree(&a);
    printf("\n");
}

int main(int argc, const char *argv[])
{
    test();
    return EXIT_SUCCESS;
}
