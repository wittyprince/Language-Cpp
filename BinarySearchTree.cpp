//
// Created by 51676 on 2024/7/3.
//

// 二叉查找树(二叉排序树)BinarySearchTree
#include <stdio.h>
#include <stdlib.h>

typedef int KeyType;
typedef struct bstNode {
    KeyType data;
    struct bstNode *left;
    struct bstNode *right;
}BSTNode, *BSTree;

bool insertIntoBSTree(BSTree &root, KeyType key) {
    if (root == NULL) { // root为NULL, 代表此时树还未创建, 为新节点申请空间, 第一个节点作为树根
        root = (BSTNode*)malloc(sizeof (BSTNode));
        root->data = key;
        root->left = root->right = NULL;
    }
    // 判断待插入元素key的位置
    BSTree cursor = root, parent;
    // cursor非空时, 一直遍历,
    // 遍历结束时, cursor为空,
    // 所以要想把待插入的元素key放到cursor的位置,
    // 需要知道cursor的parent, 否则无法关联
    // 注意：这里其实是想找cursor的parent的位置
    while (cursor) {
        // 由于不考虑相等元素的插入情况, 所以这里可以在if判断的前面写parent = cursor;
        // 注意：和 searchBSTree2() 方法中查找父节点写法的区别
        parent = cursor;
        if (cursor->data > key) {
            cursor = cursor->left;
        } else if (cursor->data < key) {
            cursor = cursor->right;
        } else { // cursor->data == key
            return false; // 相等, 不插入, 返回, 这是因为考试的时候, 一般不考虑相等元素的插入情况
        }
    }
    // 为待插入元素申请空间
    BSTNode *tmpBSTNode = (BSTNode*) malloc(sizeof (BSTNode));
    tmpBSTNode->data = key;
    tmpBSTNode->left = tmpBSTNode->right = NULL;
    // 由于cursor中没有parent之类的指针可以去主动关联parent,
    // 所以需要通过parent来主动关联cursor
    //      所以通过如 cursor = tmpBSTNode;语句来给cursor赋值是没用的。
    //      因为curs没有关联到它自己的父亲节点。
//    cursor = tmpBSTNode;
    // 下面通过parent来关联新节点
    // 再次判断新节点需要放置的位置, 即左孩子还是右孩子
    if (key < parent->data) {
        parent->left = tmpBSTNode;
    } else if(key > parent->data) {
        parent->right = tmpBSTNode;
    } else { // 相等
        return false; // 不插入, 返回
    }
    return true;
}

void createBSTree(BSTree &root, KeyType arr[], int length) {
    root = NULL;
    for (int i = 0; i < length; ++i) {
        insertIntoBSTree(root, arr[i]);
    }
}

bool searchBSTree(BSTree root, KeyType key) {
    while (root) {
        if (root->data > key) {
            root = root->left;
        } else if (root->data < key) {
            root = root->right;
        } else {
            return true;
        }
    }
    return false;
}

bool searchBSTree2(BSTree root, KeyType key, BSTNode *&parent) {
    parent = NULL; // 存储待查找节点的父亲节点
    while (root) {
        if (root->data > key) {
            parent = root;
            root = root->left;
        } else if (root->data < key) {
            parent = root;
            root = root->right;
        } else {
            return true;
        }
    }
    return false;
}

void inOrder(BSTNode *root) {
    if (root != NULL) { // 注意：这里是if判断, 不是while循环
        inOrder(root->left);
        printf("%3d", root->data);
        inOrder(root->right);
    }
}

int main() {

    BSTree root = NULL;
//    KeyType str[7] = {1, 2, 3, 4, 5, 6, 7};
//    KeyType str[7] = {1, 1, 1, 1, 1, 1, 1};
    KeyType str[7] = {54, 20, 66, 40, 28, 79, 58};
    createBSTree(root, str, 7);
    bool searchResult = searchBSTree(root, 7);
    if (searchResult) {
        printf("searched\n");
    } else {
        printf("not searched\n");
    }
    BSTNode *parent = NULL;
    searchBSTree2(root, 1, parent);
    if (searchResult) {
        printf("searched, parent\n");
    } else {
        printf("not searched, parent\n");
    }

    inOrder(root);
    printf("\n");

    return 0;
}