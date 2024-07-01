//
// Created by 51676 on 2024/6/30.
//

#ifndef LANGUAGE_CPP_LINKEDCIRCULARQUEUE_H
#define LANGUAGE_CPP_LINKEDCIRCULARQUEUE_H

//基于 链表的循环队列

typedef int ElementType;

typedef struct LinkedCircularNode {
    ElementType data;
//    LinkedCircularNodeAlias *next; // 此种写法编译报错
    struct LinkedCircularNode *next;
} LinkedCircularNodeAlias;

typedef struct LinkedCircularQueue {
    LinkedCircularNodeAlias * front; // 两种声明方式均可
    struct LinkedCircularNode *rear; // 两种声明方式均可
} LinkedCircularQueueAlias;

// 如下所有方法是基于 2019.42题解答案的数据结构实现的
// 不同的数据结构, 具体实现方法会有差异, 但是只要方法功能实现没有问题 接口
bool initLinkedCircularQueue(LinkedCircularQueueAlias &linkedCircularQueue) {
    linkedCircularQueue.front = linkedCircularQueue.rear = (LinkedCircularNodeAlias *)malloc(sizeof (LinkedCircularNodeAlias));
    linkedCircularQueue.rear->next = linkedCircularQueue.front;
    return true;
}

bool isLinkedCircularQueueEmpty(LinkedCircularQueueAlias linkedCircularQueue) {
    return linkedCircularQueue.rear == linkedCircularQueue.front;
}

bool isLinkedCircularQueueFull(LinkedCircularQueueAlias linkedCircularQueue) {
    return linkedCircularQueue.rear->next == linkedCircularQueue.front;
}

bool enLinkedCircularQueue(LinkedCircularQueueAlias &linkedCircularQueue, ElementType e) {
    if (linkedCircularQueue.rear->next == linkedCircularQueue.front) {
        LinkedCircularNodeAlias *tmpPinkedCircularNode = (LinkedCircularNodeAlias *) malloc(sizeof (LinkedCircularNodeAlias));
//        tmpPinkedCircularNode->data = 0;
        tmpPinkedCircularNode->next = NULL;
        tmpPinkedCircularNode->next = linkedCircularQueue.front;
        linkedCircularQueue.rear->data = e;
        linkedCircularQueue.rear->next = tmpPinkedCircularNode;
        linkedCircularQueue.rear = linkedCircularQueue.rear->next;
        printf("malloc new space for: %d\n", e);
    } else {
        linkedCircularQueue.rear->data = e;
        linkedCircularQueue.rear = linkedCircularQueue.rear->next;
        printf("reuse space for: %d\n", e);
    }
    return true;
}

// 方法二
bool enLinkedCircularQueue2(LinkedCircularQueueAlias &linkedCircularQueue, ElementType e) {
    if (linkedCircularQueue.rear->next == linkedCircularQueue.front) {
        LinkedCircularNodeAlias *tmpPinkedCircularNode = (LinkedCircularNodeAlias *) malloc(sizeof (LinkedCircularNodeAlias));
        tmpPinkedCircularNode->data = e;
        tmpPinkedCircularNode->next = NULL;
        linkedCircularQueue.rear->next = tmpPinkedCircularNode;
        tmpPinkedCircularNode->next = linkedCircularQueue.front;
        linkedCircularQueue.rear = linkedCircularQueue.rear->next;
        printf("malloc new space for: %d\n", e);
    } else {
        linkedCircularQueue.rear->data = e;
        linkedCircularQueue.rear = linkedCircularQueue.rear->next;
        printf("reuse space for: %d\n", e);
    }
    return true;
}

bool deLinkedCircularQueue(LinkedCircularQueueAlias &linkedCircularQueue, ElementType &e) {
    if (linkedCircularQueue.front == linkedCircularQueue.rear) {
        return false;
    }
    e = linkedCircularQueue.front->data;
    linkedCircularQueue.front = linkedCircularQueue.front->next;
    return true;
}

#endif //LANGUAGE_CPP_LINKEDCIRCULARQUEUE_H
