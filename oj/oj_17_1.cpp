//
// Created by 51676 on 2024/7/7.
//

#include <stdlib.h>
#include <time.h>
#include <stdio.h>

#define MaxSize 10

void printArray(int *a, int length) {
    for (int i = 0; i < length; ++i) {
        printf("%3d", a[i]);
    }
    printf("\n");
}

void swap(int &a, int &b) {
    int tmp = a;
    a = b;
    b = tmp;
}

// 选择排序
// 从前往后遍历, 每次选择最小的元素, 记录其下标min
// 遍历一遍后交换元素
void selectionSort(int a[], int length) {
    int i, j, min;
    for (i = 0; i < length; ++i) {
        min = i;
        for (j = i+1; j < length; ++j) {
            if (a[j] < a[min]) {
                min = j;
            }
        }
        swap(a[i], a[min]);

    }
}

void adjustMaxHeap(int a[], int idxOfRoot, int length) {
    int dad = idxOfRoot;
    int son = dad * 2 + 1;
    while (son < length) {
        // 找到 左、右子树 中 较大的那个
        if (son + 1 < length && a[son] < a[son + 1]) {
            son++;
        }
        // 判断是否需要和父节点交换
        if (a[dad] < a[son]) {
            swap(a[son], a[dad]);
            // 如果发生交换, 那么继续调整 其子节点 为大顶堆
            dad = son;
            son = dad * 2 + 1;
        } else {
            // 如果不需要交换, 那么后续节点也不需要调整
            break;
        }

    }

}

// 堆排序
void heapSort(int a[], int length) {
    // 分两步:
    // 1. 调整为大顶堆
    // 2. 排序
    int idxOfLastRoot = length / 2 -1; // 根节点从0开始
    // 经过本for循环遍历, 把 树 及 所有子树 由下而上的遍历 调整为 大顶堆
    for (int i = idxOfLastRoot; i >= 0; --i) {
        // 注意 adjustMaxHeap() 方法会调整 当前节点 及 其所有子节点 为 大顶堆
        adjustMaxHeap(a, i, length);
    }
    // 交换 第一个元素 与 根节点
    swap(a[0], a[length - 1]);

    // 把剩下的元素调整为大顶堆
//    for (int j = 0; j < length - 1; ++j) {
//        // 由于在上面的代码中, 已经把树及其所有子树 均调整为 大顶堆了,
//        // 只不过最后 把 根节点 与 最后一个节点进行了交换
//        // 所以这里只需要把根节点与该根节点的子树 自上而下的 遍历一次就行了
//        adjustMaxHeap(a, 0, length -1 - j);
//        // 排序
//        swap(a[0], a[length - 1 - 1 - j]);
//    }
    // 把上面的for循环简写为while循环更好理解
    int leftElementLength = length -1;
    while (leftElementLength > 0) { // 这里是>0, 不是>= 0
        adjustMaxHeap(a, 0, leftElementLength);
        swap(a[0], a[leftElementLength - 1]);

        leftElementLength--;
    }
}

int main() {
    int a[MaxSize];// = {3, 87, 2, 93, 78, 56, 61, 38, 12, 40};
    int value;
    for (int i = 0; i < MaxSize; ++i) {
        scanf("%d", &value);
        a[i] = value;
    }
//    srand(time(NULL));
//    for (int i = 0; i < MaxSize; ++i) {
//        a[i] = rand() % 100;
//    }

    int b[MaxSize];
    for (int i = 0; i < MaxSize; ++i) {
        b[i] = a[i];
    }
    selectionSort(b, MaxSize);
    printArray(b, MaxSize);

    int c[MaxSize];
    for (int i = 0; i < MaxSize; ++i) {
        c[i] = a[i];
    }
    heapSort(c, MaxSize);
    printArray(c, MaxSize);
    return 0;
}