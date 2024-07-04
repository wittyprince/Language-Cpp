//
// Created by 51676 on 2024/7/4.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MaxSize 10

void swap(int &a, int &b) {
    int tmp = a;
    a = b;
    b = tmp;
}

void bubbleSort(int arr[], int length) {
    for (int i = 0; i < length; ++i) {
        for (int j = length - 1; j > i; j--) {
            if (arr[j] < arr[j - 1]) {
                swap(arr[j], arr[j -1]);
            }
        }
    }
}

int partition(int arr[], int low, int high) {
    int pivot = arr[low];
    while (low < high) {
        while (low < high && arr[high] > pivot) {
            high--;
        }
        arr[low] = arr[high];
        while (low < high && arr[low] < pivot) {
            low++;
        }
        arr[high] = arr[low];
    }
    arr[low] = pivot;
    return low;
}

void quickSort(int arr[], int low, int high) {
    if (low < high) {
        int position = partition(arr, low, high);
        quickSort(arr, low, position - 1);
        quickSort(arr, position + 1, high);
    }
}

void insertionSort(int arr[], int length) {
    int insertValue, j;
    for (int i = 1; i < length; ++i) {
        insertValue = arr[i];
        for (j = i - 1; j >= 0 && arr[j] > insertValue; --j) {
            arr[j + 1] = arr[j];
        }
        arr[j+1] = insertValue;
    }
}

void printArray(int arr[], int length) {
    for (int i = 0; i < length; ++i) {
        printf("%3d", arr[i]);
    }
    printf("\n");

}

int main() {

    int value = 0;
    int arr[MaxSize];
    for (int i = 0; i < MaxSize; ++i) {
        scanf("%d", &value);
        arr[i] = value;
    }

    int bubbleArr[MaxSize];
    for (int i = 0; i < MaxSize; ++i) {
        bubbleArr[i] = arr[i];
    }
//    printArray(bubbleArr, MaxSize);
    bubbleSort(bubbleArr, MaxSize);
    printArray(bubbleArr, MaxSize);

    int quickArr[MaxSize];
    for (int i = 0; i < MaxSize; ++i) {
        quickArr[i] = arr[i];
    }
//    printArray(quickArr, MaxSize);
    quickSort(quickArr, 0, MaxSize - 1);
    printArray(quickArr, MaxSize);

    int insertionArr[MaxSize];
    for (int i = 0; i < MaxSize; ++i) {
        insertionArr[i] = arr[i];
    }
    insertionSort(insertionArr, MaxSize);
    printArray(insertionArr, MaxSize);


    return 0;
}