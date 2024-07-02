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

// 借助队列
typedef BTNode* ElementType;
typedef struct LinkedNode {
    ElementType data; // 数据域
    struct LinkedNode *next;
} LinkedNodeAlias;
typedef struct LinkedQueue {
    LinkedNodeAlias *front;
    LinkedNodeAlias *rear;
} LinkedQueueAlias;

// ===================================================================
void initLinkedQueue(LinkedQueueAlias *&listQueue) {
    LinkedNodeAlias *head = (LinkedNodeAlias *)malloc(sizeof (LinkedNodeAlias));
    head->data = {};
    head->next = NULL;
    listQueue = (LinkedQueueAlias *) malloc(sizeof (LinkedQueueAlias));
    listQueue->front = listQueue->rear = head;
}
bool enLinkedQueue(LinkedQueueAlias *&listQueue, ElementType e) {
    LinkedNodeAlias *tmpNode = (LinkedNodeAlias *)malloc(sizeof (LinkedNodeAlias));
    tmpNode->data = e;
    tmpNode->next = NULL;
    listQueue->rear->next = tmpNode;
    listQueue->rear = tmpNode;
    return true;
}
bool deLinkedQueue(LinkedQueueAlias *&linkedQueue, ElementType &e) {
    if (linkedQueue->front == linkedQueue->rear) {
        return false;
    }
    // 由于LinkedQueue是带头结点的, 所以不linkedQueue->front不可能为空
    LinkedNodeAlias *firstNode = linkedQueue->front->next;
    if (firstNode == NULL) {
        return false;
    }
    e = firstNode->data;
    // 头结点不动, 把第一个节点断链
    linkedQueue->front->next = firstNode->next;
    if (firstNode == linkedQueue->rear) {
        linkedQueue->rear = linkedQueue->front;
    }
    // free第一个节点
    free(firstNode);
    return true;
}
// ===================================================================
#endif //LANGUAGE_CPP_BTNODE_H
