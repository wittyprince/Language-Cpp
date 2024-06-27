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

/**
 * 参考 printLinkedList2 ，更简洁易懂
 *
 * L 带头结点的链表, 可以考虑以L-next(即第一个节点)为起点来处理, 这样思路更清晰
 */
void printLinkedList(LinkedList L) {
    while (L->next != NULL) {
        L = L->next;
        printf("%3d", L->data);
    }
    printf("\n");
}

/**
 * 按位置查找
 * L            带头结点的单链表
 * position     要查找的位置
 *     0        表示返回头结点
 *     1~其他    表示该位置上的节点的指针
 */
LNode *getElement(LinkedList L, int position) {
    if (position < 0) {
        return NULL;
    }
    if (position == 0) {
        return L;
    }

    // 参考getElement2，更简洁易懂
    // 以L-next(即第一个节点)为起点来处理, 这样思路更清晰
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

/**
 * 插入节点
 *      -- 前插方式：在某节点的前面插入一个新节点
 *      -- 后插方式：在某节点的后面插入一个新节点
 *      -- 本方法采用后插方式，即找到position-1的节点，在其后插入新节点
 * L            带头结点的单链表
 * position     要插入的位置, 取值范围为 >=1
 * e            要插入的元素
 */
bool insertIntoList(LinkedList &L, int position, ElementType e) {
    if (position < 1) {
        return false;
    }
//    LNode *firstNode = L->next;
    LNode *prior = getElement(L, position - 1);
    if (prior == NULL) {
        return false;
    }
    LNode *tmp = (LNode *)malloc(sizeof (LNode));
    tmp->data = e;
    tmp->next = prior->next;
    prior->next = tmp;
    return true;
}

/**
 * 删除节点
 * L            带头结点的单链表
 * position     要删除的位置, 取值范围为 >=1
 */
bool deleteFromList(LinkedList &L, int position) {
    if (position < 1) {
        return false;
    }
    LNode *prior = getElement(L, position -1);
    if (prior == NULL || prior->next == NULL) {
        return false;
    }
    LNode *q = prior->next;
    prior->next = q->next;
    free(q);
    q = NULL; // 防止对free后的指针再次使用，发生内存错误
    return true;
}

/**
 * 求链表长度
 * L 带头结点的单链表
 */
int getLinkedListLength(LinkedList L) {
    int length = 0;
    while (L->next != NULL) {
        L = L->next;
        length++;
    }
    return length;
}


#endif //LANGUAGE_CPP_LINKEDLIST_H
