//
// Created by 51676 on 2024/6/24.
//

#ifndef LANGUAGE_CPP_SQLIST_HEADER_H
#define LANGUAGE_CPP_SQLIST_HEADER_H

#include <stdio.h>

#define MaxSize 50
typedef int ElementType;
// 静态分配
typedef struct {
    ElementType data[MaxSize];
    int length; // 当前顺序表中有多少个元素
}SqList;

// 动态分配
typedef struct {
    // 定义了一个ElemType类型的指针，用于指向动态分配的内存空间
    // 由于顺序表中的元素类型均相同，所以可以通过指针偏移来进行存取数据
    ElementType *data;
    int max; // 动态数组的最大容量
    int length;
}SeqList;

/**
 * 插入元素
 * L 要插入元素的顺序表(或数组，底层是用数组实现的)
 * i 要插入的位置, 从1开始 到 L.length+1结束
 * e 要插入的元素
 */
bool ListInsert(SqList &L, int i, ElementType e) {
    // 注意：这里是 L.length, 而不是MaxSize。
    // 因为插入元素是顺序插入，即从第1个位置开始，到L.length+1结束之间的位置可以插入元素
    // 不会跳跃式的插入到L.length+2，因为中间不允许有空的位置出现
    if (i<1 || i > L.length + 1) { // 判断要插入的位置是否合法
        return false;
    }
    if (L.length + 1 > MaxSize) { // 超出最大空间了
        return false;
    }
    for (int j = L.length; j >= i; j--) {
        L.data[j] = L.data[j - 1];
    }
    L.data[i - 1] = e;
    L.length++;
    return true;
}

void printList(SqList L) {
    for (int i = 0; i < L.length; ++i) {
        printf("%3d", L.data[i]);
    }
    printf("\n");
}
#endif //LANGUAGE_CPP_SQLIST_HEADER_H
