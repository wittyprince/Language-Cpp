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

void merge(int a[], int low, int mid, int high) {
    // 双指针方式合并
    // 使用额外的空间
    static int b[MaxSize]; // 静态变量
    for (int i = low; i <= high; ++i) { // 把 low ~ high 之间的数据复制到b[], 这是因为每次只需要保证当前low~high区间内元素有序就行了
        b[i] = a[i];
    }
    int i = low, j = mid + 1, k = low;
    // 注意: 这里的条件是 i <= mid && j <= high; 不是 i <= mid, j <= high;
    // 取 a[i] 和 a[j] 中较小的
    for (i = low, j = mid + 1; i <= mid && j <= high; ) {
        if (b[i] < b[j]) {
            a[k] = b[i];
            i++;
            k++;
        } else {
            a[k] = b[j];
            j++;
            k++;
        }
    }
    // 把 low ~ mid 和 mid+1 ~ high 中未处理完的数据 赋值到 a[] 中
    while (i <= mid) {
        a[k++] = b[i++];
    }
    while (j <= high) {
        a[k++] = b[j++];
    }

}

void mergeSort(int a[], int low, int high) {

    if (low < high) { // low == high 时, 表明只剩一个元素, 一个元素 有序
        int mid = (low + high) / 2;
        mergeSort(a, low, mid);
        mergeSort(a, mid + 1, high);
        merge(a, low, mid, high);
    }
}

int main() {
    int a[MaxSize] = {3, 87, 2, 93, 78, 56, 61, 38, 12, 40};
    int value;
    for (int i = 0; i < MaxSize; ++i) {
        scanf("%d", &value);
        a[i] = value;
    }
//    srand(time(NULL));
//    for (int i = 0; i < MaxSize; ++i) {
//        a[i] = rand() % 100;
//    }
    mergeSort(a, 0, MaxSize- 1);
    printArray(a, MaxSize);

    return 0;
}