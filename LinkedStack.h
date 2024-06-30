// 基于 链表实现 栈
// Created by 51676 on 2024/6/28.
//

#ifndef LANGUAGE_CPP_LINKEDSTACK_H
#define LANGUAGE_CPP_LINKEDSTACK_H

#include <stdlib.h>

typedef int ElementType;

// 对不对？  对
typedef struct LinkedStackNode {
    ElementType data; // 定义链表的数据域
    struct LinkedStackNode *next; // 定义链表的指针域
} LinkedStackNodeAlias;

void initLinkedStack(LinkedStackNodeAlias *&linkedStack) {
    linkedStack = (LinkedStackNodeAlias*) malloc(sizeof (LinkedStackNodeAlias));
    linkedStack->data = 0;
    linkedStack->next = NULL;
}

bool isLinkedStackEmpty(LinkedStackNodeAlias *linkedStack) {
    return linkedStack->next == NULL;
}

/**
 * 如果用单链表实现栈，实现方法是链表的头插法，
 *   入栈时，从链表头部插入；
 *   出栈时，从链表头部删除。
 * @param linkedStack
 * @param e
 * @return
 */
bool pushIntoLinkedStack(LinkedStackNodeAlias *linkedStack, ElementType e) {
    // 初始化新结点
    LinkedStackNodeAlias *top = (LinkedStackNodeAlias*) malloc(sizeof (LinkedStackNodeAlias));
    top->data = e;
    top->next = NULL;
    // 头插法
    top->next = linkedStack->next;
    linkedStack->next = top;
    return true;
}

bool peekLinkedStack(LinkedStackNodeAlias *linkedStack, ElementType &e) {
    LinkedStackNodeAlias *top = linkedStack->next;
    if (top == NULL) {
        return false;
    }
    e = top->data;
    return true;
}

bool popLinkedStack(LinkedStackNodeAlias *linkedStack, ElementType &e) {
    LinkedStackNodeAlias *top = linkedStack->next;
    if (top == NULL) {
        return false;
    }
    e = top->data;
    linkedStack->next = top->next;
    free(top);
    top = NULL;
    return true;
}

#endif //LANGUAGE_CPP_LINKEDSTACK_H
