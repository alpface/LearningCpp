//
//  09二叉树的递归遍历.cpp
//  StudyC++
//
//  Created by swae on 2018/11/17.
//  Copyright © 2018 xiaoyuan. All rights reserved.
//

#include <iostream>

/*
 二叉树是数据结构中非常重要的内容，在计算机科学中，每个结点最多有两个子树的结构被称作二叉树。
 
 二叉树的基本概念
 n（n≥0）个结点的有限集合，由一个根结点以及两棵互不相交的、分别称为左子树和右子树的二叉树组成。每个根节点只有2个子节点的就叫做二叉树。
 对于二叉树来说，还具备五种基本形态：
 1.空二叉树
 2.只有一个根节点
 3.根节点只有左子树
 4.根节点只有右子树
 5.根节点有左子树和右子树
 
 满二叉树
 在一棵二叉树中，如果所有分支节点都有左孩子节点和右孩子节点，并且叶节点都集中在二叉树的最下一层，这样的二叉树称为满二叉树。
 满二叉树的特点：
   1 . 叶子节点都在最下一层
   2 . 只有度为0和度为2的节点
   3 . 一棵高为h，且有2 h - 1个节点的二叉树称为满二叉树
 完全二叉树
    若二叉树中最多只有最下面两层的节点的度数可以小于2，并且最下面一层的叶节点都依次排列在该层最左边（从左到右）的位置上，则这样的二叉树称为完全二叉树。
 完全二叉树的特点：
   1. 叶子结点只能出现在最下两层
   2. 最下层上的叶子结点都依次排列在该层最左边连续的位置上
   3. 如果有度为1的节点，只能有一个，且该节点只有左孩子，没有右孩子。比如F节点的度就为1，且F节点也只有一个左孩子节点。
   4. 按层编号后，一旦出现某节点（编号为i）为叶子结点或只有左孩子，则编号大于i的节点，均为叶子节点。比如对于编号为6的F节点来说，它的节点只有左孩子，因此凡是大于编号6的节点，即7 - 12都是叶子节点。
 */

/*
 二叉树遍历分为三种：前序、中序、后序，其中序遍历最为重要。为啥叫这个名字？是根据根节点的顺序命名的。
 比如上图正常的一个满节点，A：根节点、B：左节点、C：右节点，前序顺序是ABC（根节点排最先，然后同级先左后右）；中序顺序是BAC(先左后根最后右）；后序顺序是BCA（先左后右最后根）。
 前序遍历：
 
 1.访问根节点
 2.前序遍历左子树
 3.前序遍历右子树
 
 中序遍历：
 
 1.中序遍历左子树
 2.访问根节点
 3.中序遍历右子树
 
 后序遍历：
 1.后序遍历左子树
 2.后序遍历右子树
 3.访问根节点
 */

// 二叉树的节点类型
struct BiNode {
    // 数据域
    char ch;
    // 指针域（包含两个指针，分别指向它的左子树和右子树）
    struct BiNode *leftChild; // 左子树
    struct BiNode *rightChild; // 右子树
};

// 递归遍历的类型：前序遍历、中序遍历、后序遍历
enum RecursionOption {
    RecursionOptionBefore,   // 前序遍历
    RecursionOptionMiddle,   // 中序遍历
    RecursionOptionRear,     // 后序遍历
};

// 二叉树递归遍历
void recursion(struct BiNode *root, RecursionOption option, void (*myForeach)(void *data))
{
    if (NULL == root) {
        return;
    }
    if (NULL == myForeach) {
        return;
    }
    
    switch (option) {
        case RecursionOptionBefore:
            myForeach(&(root->ch));
            // 递归遍历左子树
            recursion(root->leftChild, option, myForeach);
            // 递归遍历右子树
            recursion(root->rightChild, option, myForeach);
            break;
        case RecursionOptionMiddle:
            // 递归遍历左子树
            recursion(root->leftChild, option, myForeach);
            myForeach(&(root->ch));
            // 递归遍历右子树
            recursion(root->rightChild, option, myForeach);
            break;
        case RecursionOptionRear:
            // 递归遍历左子树
            recursion(root->leftChild, option, myForeach);
            // 递归遍历右子树
            recursion(root->rightChild, option, myForeach);
            myForeach(&(root->ch));
            break;
            
        default:
            break;
    }
    
}

void myPrint(void *data)
{
    char *str = (char *)data;
    printf("%s", str);
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
    
    // 前序遍历
    printf("二叉树前序遍历:\n");
    recursion(&a, RecursionOptionBefore, myPrint);
    printf("\n");
    
    // 中序遍历
    printf("二叉树中序遍历:\n");
    recursion(&a, RecursionOptionMiddle, myPrint);
    printf("\n");
    
    // 后序遍历
    printf("二叉树后序遍历:\n");
    recursion(&a, RecursionOptionRear, myPrint);
    printf("\n");
}

int main(int argc, const char *argv[])
{
    test();
    return EXIT_SUCCESS;
}
