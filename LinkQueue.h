//
// Created by 51676 on 2024/6/29.
//

#ifndef LANGUAGE_CPP_LINKQUEUE_H
#define LANGUAGE_CPP_LINKQUEUE_H

typedef int ElementType;

typedef struct LinkNode {
    ElementType data; // 数据与
    struct LinkNode *next;
} LinkNodeAlias;

typedef struct LinkQueue {
    LinkNode *front;
    LinkNode *rear;
} LinkQueueAlias;

void initLinkQueue(LinkQueue *&listQueue) {

    LinkNode *head = (LinkNode *)malloc(sizeof (LinkNode));
    head->data = 0;
    head->next = NULL;
    listQueue = (LinkQueue *) malloc(sizeof (LinkQueue));
    listQueue->front = listQueue->rear = head;
}

bool pushIntoListQueue(LinkQueue *listQueue, ElementType e) {
    LinkNode *tmpNode = (LinkNode *)malloc(sizeof (LinkNode));
    tmpNode->data = e;
    tmpNode->next = NULL;
    listQueue->rear->next = tmpNode;
    listQueue->rear = tmpNode;
    return true;
}

bool peekListQueue(LinkQueue *listQueue, ElementType &e) {

    return true;
}

#endif //LANGUAGE_CPP_LINKQUEUE_H
