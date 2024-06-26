//
// Created by 51676 on 2024/6/26.
//

#ifndef LANGUAGE_CPP_LINKEDLIST2_H
#define LANGUAGE_CPP_LINKEDLIST2_H

#include <stdio.h>
#include <stdlib.h>

typedef int ElementType;

// 定义单链表节点
typedef struct LNode2 {
    ElementType data; // 定义链表的数据域
    struct LNode2 *next; // 定义链表的指针域
} LNode2Alias, *LinkedList2; // 定义LNode2的别名LNode2Alias, 同时定义指针LinkedList2

/**
 * 头插法
 */
LinkedList2 list_head_insert(LinkedList2 &linkedList2) {
    // 以下三种方式 都对 ??? //TODO
//    linkedList2 = (struct LNode2*)malloc(sizeof (struct LNode2));
//    linkedList2 = (LNode2*)malloc(sizeof (LNode2));
    // 使用malloc分配一个头指针
    linkedList2 = (LNode2Alias*)malloc(sizeof (LNode2Alias));
    linkedList2->next = NULL;
    linkedList2->data = 0;
    int value;
    scanf("%d", &value);
    while (value != 9999) {
        // 临时node，用于保存输入的值，并加入到链表中
        LNode2Alias *tmpNode = (LNode2Alias*)malloc(sizeof (LNode2Alias));
        tmpNode->data = value;
        tmpNode->next = linkedList2->next;
        linkedList2->next = tmpNode;
        scanf("%d", &value);
    }
    return linkedList2;
}

/**
 * 尾插法
 */
LinkedList2 list_tail_insert(LinkedList2 &linkedList2) {
    LNode2Alias *headNode = (LNode2Alias*)malloc(sizeof (LNode2Alias)); // 头结点
    headNode->data = 0;
    headNode->next = NULL;
    LNode2Alias *tail = headNode; // 定义尾指针
    linkedList2 = headNode; // 头指针
    int value = 0;
    scanf("%d", &value);
    while (value != 9999) {
        LNode2Alias *tmpNode = (LNode2Alias*)malloc(sizeof (LNode2Alias));
        tmpNode->data = value;
        tmpNode->next = NULL;
        tail->next = tmpNode;
        tail = tmpNode;
        scanf("%d", &value);
    }

    return linkedList2;
}

/**
 * 打印链表
 */
void printLinkedList2(LinkedList2 linkedList2) {
    linkedList2 = linkedList2->next;
    while (linkedList2 != NULL) {
        printf("%3d", linkedList2->data);
        linkedList2 = linkedList2->next;
    }
    printf("\n");
}

/**
 * 按位置查找
 */
LNode2Alias *getElement2(LinkedList2 linkedList2, int position) {
    if (position < 0) {
        return NULL;
    }
    if (position == 0) {
        return linkedList2;
    }
    linkedList2 = linkedList2->next;
    for (int i = 1; i < position&&linkedList2 != NULL; ++i) {
        linkedList2 = linkedList2->next;
    }
    return linkedList2;
}

/**
 * 按值查找
 */
LNode2Alias *locateElement(LinkedList2 linkedList2, ElementType e) {
    linkedList2 = linkedList2->next;
    while (linkedList2 != NULL && linkedList2->data != e) {
        linkedList2 = linkedList2->next;
    }
    return linkedList2;
}

#endif //LANGUAGE_CPP_LINKEDLIST2_H