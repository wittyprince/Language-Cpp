//
// Created by 51676 on 2024/7/2.
//
// 顺序查找

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef int ElementType;

typedef struct {
    ElementType *data; // 整型指针, 指向动态分配的内存空间
    int length; // 存储动态数据里元素的个数
} SeqTable; // 顺序表

void initTable (SeqTable &table, int length) {
    // 多申请一个空间, 用于存储哨兵
    table.length = length + 1;
    table.data = (ElementType *)malloc(sizeof (ElementType) * table.length);
    // 随机数生产
    srand(time(NULL));
    // 第0个用于存储哨兵, 从第1个开始存储数据
    for (int i = 1; i < table.length; ++i) {
        table.data[i] = rand() % 100;
    }
}

void printTable(SeqTable table) {
    // 第0个用于存储哨兵, 从第1个开始存储数据, 不使用哨兵也可以
    for (int i = 1; i < table.length; ++i) {
        printf("%3d", table.data[i]);
    }
    printf("\n");
}

// 普通顺序查找方法
int search(SeqTable table, int searchValue) {
    for (int i = 1; i < table.length; ++i) {
        if(table.data[i] == searchValue) {
            return i;
        }
    }
    return 0;
}

int search2(SeqTable table, int searchValue) {
    table.data[0] = searchValue; // 让零号元素作为哨兵
    int i;
    for (i = table.length - 1; i >= 0 && table.data[i] != searchValue; i--);
    return i;
}

int search3(SeqTable table, int searchValue) {
    table.data[0] = searchValue; // 让零号元素作为哨兵
    int i;
    for (i = table.length - 1; table.data[i] != searchValue; i--);
    return i;
}

int main() {

    SeqTable table;
    initTable(table, 6);
    printTable(table);
    int value;
    printf("please input the value that you want to search:\n");
    scanf("%d", &value);
    int result = search3(table, value);
    if (result) {
        printf("position:%d", result);
    } else {
        printf("not found");
    }

    return 0;
}