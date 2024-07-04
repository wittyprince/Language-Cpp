//
// Created by 51676 on 2024/7/4.
//
#include <stdio.h>
#include <stdlib.h>
#include <time.h>


// 快速排序
#define len 5

int partition(int a[], int low, int high) {
    int pivot = a[low];
    while (low < high) {
        while (low < high && a[high] >= pivot) {
            high--;
        }
        if (a[high] < pivot) {
            a[low] = a[high];
            low++;
        }
        while (low < high && a[low] <= pivot) {
            low++;
        }
        if (a[low] > pivot) {
            a[high] = a[low];
            high--;
        }
    }
    a[low] = pivot;
    return low;
}

// partition()方法的精简版
int partition2(int a[], int low, int high) {
    int pivot = a[low];
    while (low < high) {
        while (low < high && a[high] >= pivot) {
            high--;
        }
        a[low] = a[high];
        while (low < high && a[low] <= pivot) {
            low++;
        }
        a[high] = a[low];
    }
    a[low] = pivot;
    return low;
}

void quickSort(int a[], int low, int high) {
    if (low < high) {
        int position = partition2(a, low, high);
        quickSort(a, low, position -1);
        quickSort(a, position + 1, high);
    }
}


void printArray(int *a, int length) {
    for (int i = 0; i < length; ++i) {
        printf("%3d", a[i]);
    }
    printf("\n");
}

int main() {

    int a[len]
    = {1, 5, 3, 2, 6};
    srand(time(NULL));
    for (int i = 0; i < len; ++i) {
        a[i] = rand() % 100;
    }
    printArray(a, len);
    quickSort(a, 0, 4);
    printArray(a, len);

    return 0;
}