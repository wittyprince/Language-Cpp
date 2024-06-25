//
// Created by 51676 on 2024/6/25.
//

#ifndef LANGUAGE_CPP_LINKEDLIST_H
#define LANGUAGE_CPP_LINKEDLIST_H

typedef int ElementType;

typedef struct LNode { // 单链表节点类型
    ElementType data; // 定义数据域
    struct LNode *next; // 定义指针
}LNode, *LinkedList; //

void initLinkedList(LinkedList &L) {
    // 定义头结点
    L = (LNode *)malloc(sizeof (LNode));
    L->data = 0;
    L->next = NULL;
}

/**
 * 头插法
 */
bool insertIntoLinkedListHead(LinkedList &L, ElementType e) {
    // 定义临时结点指针
    LNode *tmp = (LNode *)malloc(sizeof (LNode));
    tmp->data = e;
    // 头插法
    tmp->next = L->next;
    L->next = tmp;
    return true;
}

/**
 * 尾插法
 */
bool insertIntoLinkedListTail(LinkedList &L, ElementType e) {
    // 定义临时结点指针
    LNode *tmp = (LNode *)malloc(sizeof (LNode));
    tmp->data = e;
    tmp->next = NULL;
    LNode *cursor = L;
    while (cursor->next != NULL) {
        cursor = cursor->next;
    }

    cursor->next = tmp;

    return true;
}

void printLinkedList(LinkedList L) {
    while (L->next != NULL) {
        L = L->next;
        printf("%3d", L->data);
    }
    printf("\n");
}

/**
 * 按位置查找
 */
LNode *getElement(LinkedList L, int position) {
    if (position < 1) {
        return NULL;
    }
    LNode *cursor = L;
    for (int i = 1; i <= position && cursor != NULL; ++i) {
        if (cursor->next != NULL) {
            cursor = cursor->next;
        } else {
            cursor = NULL;
        }
    }
    return cursor;
}
/**
 * 按值查找
 */
LNode *locateElement(LinkedList L, ElementType e) {
    LNode *cursor = L->next;
    while (cursor != NULL && cursor->data != e) {
        cursor = cursor->next;
    }
    return cursor;
}


bool deleteNode() {
    return true;
}


#endif //LANGUAGE_CPP_LINKEDLIST_H
