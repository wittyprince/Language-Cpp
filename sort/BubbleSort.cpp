//
// Created by 51676 on 2024/7/4.
//


#include <stdio.h>

#define len 5

void swap(int &a, int &b) {
    int tmp = a;
    a = b;
    b = tmp;
}

// 从后向前遍历
// 大数放在后面
void bubbleSort(int a[], int length) {
    for (int j = length - 1; j >= 0; j--) {
        for (int i = length -1; i > length - 1 - j; i--) {
            if (a[i] < a[i - 1]) { // 把小的元素放在前面
                swap(a[i], a[i - 1]);
            }
        }
    }
}

// 从前向后遍历
// 大数放在后面
void bubbleSort2(int a[], int length) {
    for (int i = 0; i < length - 1; ++i) {
        for (int j = 0; j < length - 1/* - i*/; ++j) {
            if (a[j] > a[j + 1]) { // 把大的元素放在后面
                swap(a[j], a[j + 1]);
            }
        }
    }
}

// 从前向后 + 从后向前
void bubbleSort3(int a[], int length) {
    for (int i = 0; i < length; ++i) {
        for (int j = length - 1; j > i; j--) {
            if (a[j] < a[j - 1]) { // 把小元素放在前面
                swap(a[j], a[j - 1]);
            }
        }
    }
}

// 从前向后 + 从后向前
void bubbleSort4(int a[], int length) {
    bool moveFlag;
    for (int i = 0; i < length; ++i) {
        moveFlag = false;
        for (int j = length - 1; j > i; j--) {
            if (a[j] < a[j - 1]) { // 把小元素放在前面
                swap(a[j], a[j - 1]);
                moveFlag = true;
            }
        }
        if (!moveFlag) {
            break; // 如果一趟比较没有发生任何交换，说明有序，提前结束排序
        }
    }
}

void printArray(int *a, int length) {
    for (int i = 0; i < length; ++i) {
        printf("%3d", a[i]);
    }
    printf("\n");
}

int main() {
    int a[len] = {1, 5, 3, 2, 6};
    printArray(a, len);
    bubbleSort3(a, len);
    printArray(a, len);
    return 0;
}
