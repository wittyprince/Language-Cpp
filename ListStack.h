// 基于 链表实现 栈
// Created by 51676 on 2024/6/28.
//

#ifndef LANGUAGE_CPP_LISTSTACK_H
#define LANGUAGE_CPP_LISTSTACK_H

#include <stdlib.h>

typedef int ElementType;

//TODO 对不对？
typedef struct ListStackNode {
    ElementType data; // 定义链表的数据域
    struct ListStackNode *next; // 定义链表的指针域
} ListStackNodeAlias;

void initListStack(ListStackNode *&listStack) {
    listStack = (ListStackNode*) malloc(sizeof (ListStackNode));
    listStack->data = 0;
    listStack->next = NULL;
}

bool pushIntoListStack(ListStackNode *listStack, ElementType e) {
    ListStackNode *top = (ListStackNode*) malloc(sizeof (ListStackNode));
    top->data = e;
    top->next = listStack->next;
    listStack->next = top;
    return true;
}

bool peekListStack(ListStackNode *listStack, ElementType &e) {
    ListStackNode *top = listStack->next;
    if (top == NULL) {
        return false;
    }
    e = top->data;
    return true;
}

bool popListStack(ListStackNode *listStack, ElementType &e) {
    ListStackNode *top = listStack->next;
    if (top == NULL) {
        return false;
    }
    e = top->data;
    listStack->next = top->next;
    free(top);
    top = NULL;
    return true;
}

#endif //LANGUAGE_CPP_LISTSTACK_H
