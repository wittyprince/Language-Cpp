//
// Created by 51676 on 2024/6/24.
//

#ifndef LANGUAGE_CPP_SEQLIST_HEADER_H
#define LANGUAGE_CPP_SEQLIST_HEADER_H

#include <stdio.h>
#include <stdlib.h>

// typedef定义的别名后需要加分号;
typedef int ElementType;

// 动态分配
#define initSize 100
typedef struct {
    // 定义了一个ElemType类型的指针，用于指向动态分配的内存空间
    // 由于顺序表中的元素类型均相同，所以可以通过指针偏移来进行存取数据
    // 由于是一个指针，所以可以指向一个数组，且由于在声明数组时，数组变量也是指向数组开始的内存地址，
    //    所以这里ElementType *data;的用法没有问题
    //    即data可以指向一个长度不确定的数组，也叫“动态数组”
    // 注意，data 是我们声明的一个未初始化的动态数组，不要只把它看做是普通的指针。
    ElementType *data;
    int maxSize; // 动态数组的最大容量
    int length; // 记录当前顺序表的长度
}SeqList;

/**
 * 初始化顺序表
 */
void InitList(SeqList &L) {
    L.data = (ElementType *)malloc(sizeof (ElementType) * initSize);
    L.maxSize = initSize;
    L.length = 0;
}

bool ListInsert(SeqList &L) {


    return true;
}

#endif //LANGUAGE_CPP_SEQLIST_HEADER_H
