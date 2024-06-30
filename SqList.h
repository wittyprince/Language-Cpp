//
// Created by 51676 on 2024/6/24.
//

#ifndef LANGUAGE_CPP_SQLIST_H
#define LANGUAGE_CPP_SQLIST_H

#include <stdio.h>

// #define定义的符号常量语句后不能有分号;
#define MaxSize 50
// typedef定义的别名后需要加分号;
typedef int ElementType;
// 顺序表
// 线性表的实现方式之一, 说到实现, 所以顺序表是存储结构
// 顺序表底层实现是基于 数组 实现的，又分为 静态分配 和 动态分配
// 静态分配
typedef struct {
    ElementType data[MaxSize]; // 底层用数组来实现
    int length; // 当前顺序表中有多少个元素
} SqList;


/**
 * 插入元素
 * @param L         要插入元素的顺序表
 * @param position  要插入的位置, 从1开始 到 L.length+1结束
 *                  注意 顺序表中元素的位置 和 元素在数组中下标不一样,
 *                      位置从1开始, 下标从0开始
 * @param e         要插入的元素
 */
bool insertIntoSqList(SqList &L, int position, ElementType e) {
    // 注意：这里是 L.length, 而不是MaxSize。MaxSize是用来判断是否溢出的。
    // 因为插入元素是顺序插入，即从第1个位置开始，到L.length+1结束之间的位置可以插入元素
    // 不会跳跃式的插入到L.length+2，因为中间不允许有空的位置出现
    // 所以position的取值范围为: 1 <= position <= L.length + 1
    if (position < 1 || position > L.length + 1) { // ① 判断要插入的位置是否合法
        return false;
    }
    if (L.length + 1 > MaxSize) { // ②判断是否超出最大空间了
        return false;
    }
    for (int j = L.length; j >= position; j--) { // ③移动元素，从后往前移动元素
        L.data[j] = L.data[j - 1];
    }
    L.data[position - 1] = e; // ④插入元素
    L.length++; // ⑤长度变更
    return true;
}

void printSqList(SqList L) {
    for (int i = 0; i < L.length; ++i) {
        printf("%3d", L.data[i]);
    }
    printf("\n");
}

 /**
  * 删除顺序表中的元素
  * @param L            要删除元素的顺序表
  * @param position     要删除的元素的位置
  * @param e            位置position上的元素的值(即要被删除的元素的值)
  * @return             true or false
  */
bool deleteFromSqList(SqList &L, int position, ElementType &e) {
    // 合法性检查 position 1 <= position <= L.length
    if (position < 1 || position > L.length) { // ①判断要删除的位置是否合法
        return false;
    }
    e = L.data[position - 1]; // ②取要被删除的元素
    for (int j = position; j < L.length; ++j) { // ③移动元素
        L.data[j - 1] = L.data[j];
    }
    L.length--; // ④修改长度

    return true;
}

/**
 * 查找某个元素的位置，找到就返回对应的位置，找不到返回0
 * @param L     要查找的顺序表
 * @param e     要查找的元素
 */
int locateSqListElement(SqList L, ElementType e) {
    for (int i = 0; i < L.length; ++i) {
        if (L.data[i] == e) {
            return i + 1;
        }
    }
    return 0;
}

/**
 * 查找第position个位置上的元素
 */
bool getSqListElement(SqList L, int position, ElementType &e) {
    if (position < 1 || position > L.length) {
        return false;
    }
    e = L.data[position - 1];
    return true;
}
#endif //LANGUAGE_CPP_SQLIST_H
