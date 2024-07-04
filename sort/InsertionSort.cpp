//
// Created by 51676 on 2024/7/4.
//

// (直接)插入排序

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define arrSize 5

void insertionSort(int a[], int length) {
    int insertValue, j;
    bool moveFlag;
    for (int i = 1; i < length; ++i) {
        moveFlag = false;
        insertValue = a[i];
        for (j = i-1; j >= 0; j--) {
            if (a[j] > insertValue) {
                a[j + 1] = a[j];
                moveFlag = true;
            }
        }
        if (moveFlag) {
            a[j + 1] = insertValue;
        }
    }
}

void insertionSort2(int arr[], int length) {
    int insertValue, j;
    for (int i = 1; i < length; ++i) { //外层控制要插入的数
        insertValue = arr[i]; //保存要插入的数
        //内层控制比较,j要大于等于0，同时arr[j]大于insertval时，arr[j]位置元素往后覆盖
        // 注意：如果arr[j] > insertValue条件不满足, j--都不会执行了
        //      所以arr[j + 1] = insertValue;就是原地插入,
        //      不存在经过j--后, j的值发生变化的情况
        //      注意与insertionSort()方法的区别
        for (j = i-1; j >= 0 && arr[j] > insertValue; j--) {
            arr[j + 1] = arr[j];
        }
        arr[j + 1] = insertValue; //把要插入的元素放到对应的位置
    }
}

void printArray(int *a, int length) {
    for (int i = 0; i < length; ++i) {
        printf("%3d", a[i]);
    }
    printf("\n");
}

int main() {

    int a[arrSize] = {3, 7, 2, 8, 1};
    srand(time(NULL));
    for (int i = 0; i < arrSize; ++i) {
        a[i] = rand() % 100;
    }
    printArray(a, arrSize);
    insertionSort2(a, arrSize);
    printArray(a, arrSize);
    return 0;
}