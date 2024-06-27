//
// Created by 51676 on 2024/6/27.
//

#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;
    struct node *next;
} NODE;

// 初始化
void initLinkedList(NODE *&L) {
    // 定义头结点
    L = (NODE *)malloc(sizeof (NODE));
    L->data = 0;
    L->next = NULL;
}

/**
 * 尾插法
 */
bool insertIntoLinkedListTail(NODE *&L, int e) {
    // 定义临时结点指针
    NODE *tmp = (NODE *)malloc(sizeof (NODE));
    tmp->data = e;
    tmp->next = NULL;
    NODE *cursor = L;
    while (cursor->next != NULL) {
        cursor = cursor->next;
    }
    cursor->next = tmp;
    return true;
}

void printLinkedList(NODE *L) {
    while (L->next != NULL) {
        L = L->next;
        printf("%3d", L->data);
    }
    printf("\n");
}

/**
 * 双指针法
 */
void findMiddle(NODE *L, NODE *L2) {
    NODE *p, *q;
    p = q = L->next;
    if (p == NULL) {
        return;
    }
    while (p != NULL && p->next != NULL && p->next->next != NULL) {
        p = p->next->next;
        q = q->next;
    }
    L2->next = q->next;
    q->next = NULL;
}

/**
 * 逆置
 */
void reverse(NODE* L) {
    NODE *r, *s, *t;
    r = L->next;
    if (r == NULL) {
        return;
    }
    s = r->next;
    if (s == NULL) {
        return;
    }
    t = s->next;
    if (t == NULL) { // 要不要均可, 此段逻辑在最后已被包含
        s->next = r;
        r->next = NULL;
        L->next = s;
        return;
    }
    while (t != NULL) {
        s->next = r;
        r = s;
        s = t;
        t = t->next;
    }
    s->next = r;
    L->next->next = NULL;
    L->next = s;
}

void merge(NODE*L, NODE *L2) {
    NODE *cursor, *s, *t;
    s = L->next;
    t = L2->next;
    cursor = s;
    s = s->next;
    while (s != NULL && t != NULL) {
        cursor->next = t;
        t = t->next;
        cursor = cursor->next;
        cursor->next = s;
        s = s->next;
        cursor = cursor->next;
    }
    if (s != NULL) {
        cursor->next = s;
    }
    if (t != NULL) {
        cursor->next = t;
    }
}

int main() {
    NODE *L;
    initLinkedList(L);
    insertIntoLinkedListTail(L, 1);
    insertIntoLinkedListTail(L, 2);
    insertIntoLinkedListTail(L, 3);
//    insertIntoLinkedListTail(L, 4);
//    insertIntoLinkedListTail(L, 5);
//    insertIntoLinkedListTail(L, 6);
//    insertIntoLinkedListTail(L, 7);
//    insertIntoLinkedListTail(L, 8);

    NODE *L2;
    initLinkedList(L2);
    findMiddle(L, L2);
    printf("L:");
    printLinkedList(L);
    printf("\n");
    printf("L2:");
    printLinkedList(L2);
    printf("\n");
    printf("reversed L2:");
    reverse(L2);
    printLinkedList(L2);
    printf("\n");

    NODE *L3;
    initLinkedList(L3);
    merge(L, L2);
    printf("merged L:");
    printLinkedList(L);
    printf("\n");

    return 0;
}
