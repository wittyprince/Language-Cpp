// 基于 链表实现 栈
// Created by 51676 on 2024/6/28.
//

#ifndef LANGUAGE_CPP_LINKEDSTACK_H
#define LANGUAGE_CPP_LINKEDSTACK_H

#include <stdlib.h>

typedef int ElementType;

// 对不对？  对
typedef struct ListStackNode {
    ElementType data; // 定义链表的数据域
    struct ListStackNode *next; // 定义链表的指针域
} ListStackNodeAlias;

void initListStack(ListStackNodeAlias *&listStack) {
    listStack = (ListStackNodeAlias*) malloc(sizeof (ListStackNodeAlias));
    listStack->data = 0;
    listStack->next = NULL;
}

bool isListStackEmpty(ListStackNodeAlias *listStack) {
    return listStack->next == NULL;
}

/**
 * 如果用单链表实现栈，实现方法是链表的头插法，
 *   入栈时，从链表头部插入；
 *   出栈时，从链表头部删除。
 * @param listStack
 * @param e
 * @return
 */
bool pushIntoListStack(ListStackNodeAlias *listStack, ElementType e) {
    // 初始化新结点
    ListStackNodeAlias *top = (ListStackNodeAlias*) malloc(sizeof (ListStackNodeAlias));
    top->data = e;
    top->next = NULL;
    // 头插法
    top->next = listStack->next;
    listStack->next = top;
    return true;
}

bool peekListStack(ListStackNodeAlias *listStack, ElementType &e) {
    ListStackNodeAlias *top = listStack->next;
    if (top == NULL) {
        return false;
    }
    e = top->data;
    return true;
}

bool popListStack(ListStackNodeAlias *listStack, ElementType &e) {
    ListStackNodeAlias *top = listStack->next;
    if (top == NULL) {
        return false;
    }
    e = top->data;
    listStack->next = top->next;
    free(top);
    top = NULL;
    return true;
}

#endif //LANGUAGE_CPP_LINKEDSTACK_H
