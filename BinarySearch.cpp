//
// Created by 51676 on 2024/7/2.
//
// 折半查找(二分查找)


#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef int ElementType;

typedef struct {
    ElementType *data; // 整型指针, 指向动态分配的内存空间
    int length; // 存储动态数据里元素的个数
} SeqTable; // 顺序表

void initTable (SeqTable &table, int length) {
    table.length = length;
    table.data = (ElementType *)malloc(sizeof (ElementType) * table.length);
    // 随机数生产
//    srand(time(NULL));
//    for (int i = 0; i < table.length; ++i) {
//        table.data[i] = rand() % 100;
//    }
    for (int i = 0; i < table.length; ++i) {
        table.data[i] = i * 2;
    }
}

void printTable(SeqTable table) {
    for (int i = 0; i < table.length; ++i) {
        printf("%3d", table.data[i]);
    }
    printf("\n");
}

// 二分查找, 时间复杂度logn
int binarySearch(SeqTable table, int searchValue) {
    int low = 0, high = table.length - 1;
    int mid;
    while (low <= high) {
        mid = (low + high) / 2;
        if (table.data[mid] < searchValue) {
            low = mid + 1;
        } else if (table.data[mid] > searchValue) {
            high = mid - 1;
        } else {
            return mid;
        }
    }
    return -1;
}

int compare(const void *left, const void *right) {
    return *(ElementType *)left - *(ElementType *)right; // 从小到大
}


int main() {

    SeqTable table;
    initTable(table, 6);
    printTable(table);
    // 使用qsort实现的快排
    qsort(table.data, table.length, sizeof (ElementType), compare);
    printTable(table);
    int value;
    printf("please input the value that you want to search:\n");
    scanf("%d", &value);
    int result = binarySearch(table, value);
    if (result != -1) {
        printf("index:%d", result);
    } else {
        printf("not found");
    }

    return 0;
}