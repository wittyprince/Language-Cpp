//
// Created by 51676 on 2024/7/5.
//

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// 选择排序
#define MaxSize 5

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

void selectionSort(int arr[], int length) {
    int i, j, min, selectionValue;
    for (i = 0; i < length; ++i) {
        selectionValue = arr[i];
        min = i;
        for (j = i; j < length; ++j) {
            if (arr[j] < arr[min]) {
                min = j;
            }
        }
        arr[i] = arr[min];
        arr[min] = selectionValue;
    }
}

void selectionSort2(int arr[], int length) {
    int i, j, min;
    for (i = 0; i < length; ++i) {
        min = i;
        for (j = i; j < length; ++j) {
            if (arr[j] < arr[min]) {
                min = j;
            }
        }
        if (i != min) {
            swap(arr[i], arr[min]);
        }
    }
}

int main() {

    int a[MaxSize] = {3, 7, 2, 8, 1};
    srand(time(NULL));
    for (int i = 0; i < MaxSize; ++i) {
        a[i] = rand() % 100;
    }

    printArray(a, MaxSize);
    selectionSort2(a, MaxSize);
    printArray(a, MaxSize);

    return 0;
}
