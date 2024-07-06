//
// Created by 51676 on 2024/7/5.
//

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// 归并排序

#define MaxSize 7

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
    // 声明一个静态变量, 无论递归多少次都只有一个数组b[]
    static int b[MaxSize];
    for (int m = low; m <= high; ++m) {
        b[m] = a[m]; // 把数组a[]的值赋值给数组b[]
    }
    int i, j, k = low;
    for (i = low, j = mid + 1; i <= mid && j <= high;) {
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
    while (i <= mid) {
        a[k++] = b[i++];
    }
    while (j <= high) {
        a[k++] = b[j++];
    }
}

void mergeSort(int a[], int low, int high) {
    if (low < high) {
        int mid = (low + high) / 2;
        mergeSort(a, low, mid);
        mergeSort(a, mid + 1, high);
        merge(a, low, mid, high);
    }
}

int main() {

    int a[MaxSize] = {49, 38, 65, 97, 76, 13, 27};
//            {3, 87, 2, 93, 78, 56, 61, 38, 12, 40};
    srand(time(NULL));
    for (int i = 0; i < MaxSize; ++i) {
        a[i] = rand() % 100;
    }
    printArray(a, MaxSize);
    mergeSort(a, 0, MaxSize - 1);
    printArray(a, MaxSize);

    return 0;
}
