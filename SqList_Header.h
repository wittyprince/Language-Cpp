//
// Created by 51676 on 2024/6/24.
//

#ifndef LANGUAGE_CPP_SQLIST_HEADER_H
#define LANGUAGE_CPP_SQLIST_HEADER_H

#include <stdio.h>

// #define定义的符号常量语句后不能有分号;
#define MaxSize 50
// typedef定义的别名后需要加分号;
typedef int ElementType;
// 静态分配
// 线性表(逻辑结构)的存储方式之一：顺序表
// 定义顺序表的实现方式(注意顺序表是物理结构)
// 底层是数组实现的
typedef struct {
    ElementType data[MaxSize]; // 底层用数组来实现
    int length; // 当前顺序表中有多少个元素
}SqList;


/**
 * 插入元素
 * L 要插入元素的顺序表(或数组，底层是用数组实现的)
 * idx 要插入的位置, 从1开始 到 L.length+1结束
 * e 要插入的元素
 */
bool ListInsert(SqList &L, int idx, ElementType e) {
    // 注意：这里是 L.length, 而不是MaxSize。
    // 因为插入元素是顺序插入，即从第1个位置开始，到L.length+1结束之间的位置可以插入元素
    // 不会跳跃式的插入到L.length+2，因为中间不允许有空的位置出现
    if (idx < 1 || idx > L.length + 1) { // ① 判断要插入的位置是否合法 idx 1 <= idx <= L.length
        return false;
    }
    if (L.length + 1 > MaxSize) { // ②判断是否超出最大空间了
        return false;
    }
    for (int j = L.length; j >= idx; j--) { // ③移动元素，从后往前移动元素
        L.data[j] = L.data[j - 1];
    }
    L.data[idx - 1] = e; // ④插入元素
    L.length++; // ⑤长度变更
    return true;
}

void printList(SqList L) {
    for (int i = 0; i < L.length; ++i) {
        printf("%3d", L.data[i]);
    }
    printf("\n");
}

/**
 * 删除顺序表中的元素
 * L 要删除元素的顺序表(或数组，底层是用数组实现的)
 * idx 要删除的元素的位置
 * e 位置i上的元素的值(即要被删除的元素的值)
 */
bool ListDelete(SqList &L, int idx, ElementType &e) {
    // 合法性检查 idx 1 <= idx <= L.length
    if (idx < 1 || idx > L.length) { // ①判断要删除的位置是否合法
        return false;
    }
    e = L.data[idx - 1]; // ②取要被删除的元素
    for (int j = idx; j < L.length; ++j) { // ③移动元素
        L.data[j - 1] = L.data[j];
    }
    L.length--; // ④修改长度

    return true;
}

/**
 * 查找某个元素的位置，找到就返回对应的位置，找不到返回0
 * L 要查找的顺序表
 * e 要查找的元素
 */
int LocateElement(SqList L, ElementType e) {
    for (int i = 0; i < L.length; ++i) {
        if (L.data[i] == e) {
            return i + 1;
        }
    }
    return 0;
}
#endif //LANGUAGE_CPP_SQLIST_HEADER_H
