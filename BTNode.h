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
    struct btNode *lChild;
    struct btNode *rChild;
} BTNode;

// 辅助队列? 辅助链表?
// 用于临时存放 二叉树节点
typedef struct btListNode {
//    struct btNode *btNodePointer; // struct btNode *btNodePointer 与 BTNode *btNodePointer两种方式均可
    BTNode *btNodePointer; // 用于存放某一节点的地址值
    struct btListNode *nextBtListNode;
} BTListNode;

void initBTNode(BTNode *&btNode) {
    btNode = (BTNode *)calloc(1, sizeof (BTNode));
}

#endif //LANGUAGE_CPP_BTNODE_H
