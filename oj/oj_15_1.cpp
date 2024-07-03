//
// Created by 51676 on 2024/7/3.
//
#include <stdio.h>
#include <stdlib.h>

typedef int KeyType;

typedef struct bstNode {
    KeyType data;
    struct bstNode *left;
    struct bstNode *right;
} BSTNode;

void insertIntoBSTNode(BSTNode *&root, int value) {
    if (root == NULL) {
        root = (BSTNode*)malloc(sizeof (BSTNode ));
        root->data = value;
        root->left = root->right = NULL;
        return;
    }
    if (value < root->data) {
        insertIntoBSTNode(root->left, value);
    } else if (value > root->data) {
        insertIntoBSTNode(root->right, value);
    } else {
        return;
    }
}

void inOrder(BSTNode *&root, int a[], int &idx) {
    // 这里idx也可以声明为静态局部变量
    // 静态局部变量只会初始化一次, 在函数内有效, 和全局变量类似
//    static int idx = 0;
    if (root) { // 注意：这里是递归，用的是if，不是循环的时候用的while
        inOrder(root->left, a, idx);
        printf("%3d", root->data);
        a[idx] = root->data;
        idx++;
        inOrder(root->right, a, idx);
    }
}

void binarySearch(int a[], int value, int &idx) {
    int low = 0, high = 9, mid;
    while (low <= high) {
        mid = (low + high) / 2;
        if (value < a[mid]) {
            high = mid - 1;
        } else if (value > a[mid]) {
            low = mid + 1;
        } else {
            idx = mid;
            break;
        }
    }
}

int main() {

    BSTNode* root = NULL;
    int value;
//    scanf("%d", &value);
//    root = (BSTNode*)malloc(sizeof (BSTNode ));
//    root->data = value;
//    root->left = root->right = NULL;

    for (int i = 0; i < 10; ++i) {
        scanf("%d", &value);
        insertIntoBSTNode(root, value);
    }

    int idx = 0;
    int a[10] = {0};
    inOrder(root, a, idx);
    printf("\n");

//    for (int i = 0; i < 10; ++i) {
//        printf("%d,", a[i]);
//    }
    int res = 0;
    binarySearch(a, 21, res);
    printf("%d\n", res);

    return 0;
}