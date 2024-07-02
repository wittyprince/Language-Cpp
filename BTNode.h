//
// Created by 51676 on 2024/7/1.
//

#ifndef LANGUAGE_CPP_BTNODE_H
#define LANGUAGE_CPP_BTNODE_H

#include <stdlib.h>

// 二叉树
typedef char TreeElementType;

// 二叉树节点
typedef struct btNode {
    TreeElementType data;
    struct btNode *left;
    struct btNode *right;
} BTNode;

// 辅助队列? 辅助链表?
// 用于临时存放 二叉树节点
typedef struct btListNode {
//    struct btNode *data; // struct btNode *data 与 BTNode *btNodePointer两种方式均可
    BTNode *data; // 用于存放某一节点的地址值
    struct btListNode *next;
} BTListNode;

void preOrder(BTNode *btNode) {
    if (btNode != NULL) {
        putchar(btNode->data); // 等价于 printf("%c", btNode->data);
        preOrder(btNode->left);
        preOrder(btNode->right);
    }
}

void inOrder(BTNode *btNode) {
    if (btNode != NULL) {
        inOrder(btNode->left);
        putchar(btNode->data);
        inOrder(btNode->right);
    }
}

void postOrder(BTNode *btNode) {
    if (btNode != NULL) {
        postOrder(btNode->left);
        postOrder(btNode->right);
        putchar(btNode->data);
    }
}

#endif //LANGUAGE_CPP_BTNODE_H
