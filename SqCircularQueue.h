// 循环队列
// Created by 51676 on 2024/6/28.
//

#ifndef LANGUAGE_CPP_SQCIRCULARQUEUE_H
#define LANGUAGE_CPP_SQCIRCULARQUEUE_H

#define SqQueueMaxSize 5
typedef int ElementType;

// 队列
typedef struct SqCircularQueue {
    // 数组中最多存储SqQueueMaxSize-1 个元素，剩余一个空位用于区别 空对列 与 满队列
    ElementType data[SqQueueMaxSize];
    int front; // 队列头
    int rear; // 队列尾, 注意队尾指向的为最后一个元素的下一个节点
} SqCircularQueueAlias;

bool initSqQueue(SqCircularQueueAlias &sqQueue) {
    sqQueue.front = sqQueue.rear = 0; // 初始化时，需要front=rear且同时为0
    return true;
}

bool isSqQueueEmpty(SqCircularQueueAlias sqQueue) {
    // 判断为空时, 只需要rear = front, 不需要同时为0
    return (sqQueue.rear)/* % SqQueueMaxSize*/ == sqQueue.front/* % SqQueueMaxSize*/;
}

bool isSqQueueFull(SqCircularQueueAlias sqQueue) {
    return (sqQueue.rear + 1) % SqQueueMaxSize == sqQueue.front/* % SqQueueMaxSize*/;
}

// 入队
bool enSqQueue(SqCircularQueueAlias &sqQueue, ElementType e) {
    // 判断队列是否已满
    if ((sqQueue.rear + 1) % SqQueueMaxSize == sqQueue.front) {
        return false;
    }
    sqQueue.data[sqQueue.rear] = e; // 放入元素
    sqQueue.rear = (sqQueue.rear + 1) % SqQueueMaxSize; // 改变队尾标记
    return true;
}

// 出队
bool deSqQueue(SqCircularQueueAlias &sqQueue, ElementType &e) {
    // 判断队列是否为空
    if (sqQueue.rear == sqQueue.front) {
        return false;
    }
    e = sqQueue.data[sqQueue.front];
    sqQueue.front = (sqQueue.front + 1) % SqQueueMaxSize;
    return true;
}


#endif //LANGUAGE_CPP_SQCIRCULARQUEUE_H
