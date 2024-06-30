//
// Created by 51676 on 2024/6/29.
//

#ifndef LANGUAGE_CPP_LINKEDQUEUE_H
#define LANGUAGE_CPP_LINKEDQUEUE_H

typedef int ElementType;

typedef struct LinkedNode {
    ElementType data; // 数据与
    struct LinkedNode *next;
} LinkedNodeAlias;

typedef struct LinkedQueue {
    LinkedNode *front;
    LinkedNode *rear;
} LinkedQueueAlias;

void initLinkedQueue(LinkedQueueAlias *&listQueue) {

    LinkedNodeAlias *head = (LinkedNodeAlias *)malloc(sizeof (LinkedNodeAlias));
    head->data = 0;
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

//TODO
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
    linkedQueue->front->next = firstNode->next;
    if (firstNode == linkedQueue->rear) {
        linkedQueue->rear = linkedQueue->front;
    }
    free(firstNode);
    return true;
}

#endif //LANGUAGE_CPP_LINKEDQUEUE_H
