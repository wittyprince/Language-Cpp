//
// Created by 51676 on 2024/7/5.
//

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

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

void adjust(int a[], int length, int idxOfLeftChildOfLastRoot, int idxOfLastRoot) {
    if (idxOfLeftChildOfLastRoot + 1 < length) {
        if (a[idxOfLeftChildOfLastRoot + 1] > a[idxOfLeftChildOfLastRoot]) {
            if (a[idxOfLeftChildOfLastRoot + 1] > a[idxOfLastRoot]) {
                swap(a[idxOfLeftChildOfLastRoot + 1], a[idxOfLastRoot]);
            }
        } else {
            if (a[idxOfLeftChildOfLastRoot] > a[idxOfLastRoot]) {
                swap(a[idxOfLeftChildOfLastRoot], a[idxOfLastRoot]);
            }
        }
    }
}

void adjustMaxHeap(int a[], int length) {
    int idxOfLastRoot = length / 2 - 1;
    while (idxOfLastRoot >= 0) {
//        int lastRoot = a[idxOfLastRoot];
        int idxOfLeftChildOfLastRoot = (idxOfLastRoot) * 2 + 1;
        // 判断最后一个父元素是否有右子节点,
        //      如果有, 判断是否大于父元素，
        //          如果大于, 则交换
        // 方法一：
//        if (idxOfLeftChildOfLastRoot + 1 < length) { // 说明有最后的右子节点 + 其他父节点肯定也有右子节点
//            if (a[idxOfLeftChildOfLastRoot + 1] > a[idxOfLastRoot]) {
//                // 注意, 这里不能用lastRoot来代替a[idxOfLastRoot], 因为下面的步骤是要交换两个数的值,
//                //      如果代替了, 那么交换的是lastRoot而不是数组a中的值
//                swap(a[idxOfLeftChildOfLastRoot + 1], a[idxOfLastRoot]);
//                //TODO 交换之后的子树也要调整为大顶堆
//                // 这里即使不继续调整, 也不影响最后排序的结果, 因为排序其实只关心最大值
//
//            }
//        }
//        // 判断是否需要交换 父元素 与 左子节点
//        if (a[idxOfLeftChildOfLastRoot] > a[idxOfLastRoot]) {
//            swap(a[idxOfLeftChildOfLastRoot], a[idxOfLastRoot]);
//            //TODO 同上
//        }
        // 此方法比上面写的两个if效率高一些, 因为不用交换两次，
        //      交换两次意味着需要把各自的子树 重新都要 调整一次
        // 注意，如果过程不一样, 那么中间步骤的中间结果也可能不同,
        //TODO      那么如果考试中问经过第一次遍历的结果，可能就不同
        // 书上的方法是选择较大的子节点进行交换, 然后再 调整
        // 方法二:
        if (idxOfLeftChildOfLastRoot + 1 < length) {
            if (a[idxOfLeftChildOfLastRoot + 1] > a[idxOfLeftChildOfLastRoot]) {
                if (a[idxOfLeftChildOfLastRoot + 1] > a[idxOfLastRoot]) {
                    swap(a[idxOfLeftChildOfLastRoot + 1], a[idxOfLastRoot]);
                    //TODO 继续调整子节点满足大顶堆
                }
            } else {
                if (a[idxOfLeftChildOfLastRoot] > a[idxOfLastRoot]) {
                    swap(a[idxOfLeftChildOfLastRoot], a[idxOfLastRoot]);
                    //TODO 继续调整子节点满足大顶堆
                }
            }
        }
        // 方法三：
        //TODO 递归实现后续子节点也满足大顶堆，如何实现 ？
//        int idxOfLeftChildOfLastRootAdjust = idxOfLeftChildOfLastRoot;
//        int idxOfLastRootAdjust = idxOfLastRoot;
//        while (idxOfLastRootAdjust <= length/2 -1 && idxOfLeftChildOfLastRootAdjust <= (idxOfLastRoot) * 2 + 1) {
//            adjust(a, length, idxOfLeftChildOfLastRootAdjust, idxOfLastRootAdjust);
//            idxOfLastRootAdjust = (idxOfLastRootAdjust) * 2 + 1; //TODO 分左右子树?
//            idxOfLeftChildOfLastRootAdjust = 2 * idxOfLastRootAdjust + 1;
//        }
        // 最后遍历条件调整
        idxOfLastRoot--;
    }
}

void heapSort(int a[], int length) {

    int tmp = length;
    while (tmp > 1) {
        // 调整为大顶堆
        adjustMaxHeap(a, tmp);
        // 排序
        swap(a[0], a[tmp - 1]);
        tmp--;
    }
}

//
void adjustMaxHeap2(int a[], int idxOfRoot, int length) {
    // 判断 根节点 与 子节点 元素的大小关系
    int dad = idxOfRoot;
    int son = dad * 2 + 1;
//    int idxOfLeftChild = idxOfRoot * 2 + 1;
//    int idxOfRightChild = idxOfRoot * 2 + 2; // 注意右子节点不一定存在
    while (son < length) { // 这里先判断左子树 < length, 并不代表右子树就满足<length要求。
        // 判断 左子结点 与 右子节点 的大小, son为较大节点的下标
        // a[son] < a[son + 1] 的优势 是不用分左右子树来分别处理
         if (son + 1 < length && a[son] < a[son + 1]) {
             son = son + 1;
         }
         if (a[son] > a[dad]) { // 判断(左、右)子节点 与 父节点 的大小
             swap(a[son], a[dad]);
            // 如果发生了交换, 那么需要遍历子节点, 以使子节点满足大顶堆
            dad = son;
            son = dad * 2 + 1;
         } else { // 未发生交换, 说明 root > max{left, right}
             break;
         }
    }
}

void heapSort2(int a[], int length) {
    int idxOfLastRoot = length / 2 - 1;
    while (idxOfLastRoot >= 0) {
        // 调整为大顶堆
        adjustMaxHeap2(a, idxOfLastRoot, length);
        idxOfLastRoot--;
    }
    // a[] 经过第一遍调整后, 各子树均满足大顶堆条件, 后续调整减少节点后的子树时, 不需要再进行整体遍历调整了
    // 排序
    swap(a[0], a[length - 1]);
    int leftElementNum = length - 1;
    while (leftElementNum > 0) {
        // 调整剩余元素为大顶堆
        //      注意：由于上面第一遍已经把全部调整了一遍以满足大顶堆条件, 所以这里只需要调整根节点为0及其后续子节点即可
        adjustMaxHeap2(a, 0, leftElementNum);
        // 交换
        swap(a[0], a[leftElementNum - 1]);
        // 改变循环遍历条件
        leftElementNum--;
    }
}

int main() {
    int a[MaxSize] = {3, 87, 2, 93, 78, 56, 61, 38, 12, 40};
//    srand(time(NULL));
//    for (int i = 0; i < MaxSize; ++i) {
//        a[i] = rand() % 100;
//    }
    printArray(a, MaxSize);
    heapSort2(a, MaxSize);
    printArray(a, MaxSize);
    return 0;
}
