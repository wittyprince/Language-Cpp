//
// Created by 51676 on 2024/7/2.
//
#include <stdio.h>
#include <stdlib.h>

typedef int ElementType;

typedef struct btNode {
    ElementType weight;
    struct btNode *left;
    struct btNode *right;
} BTNode;

typedef struct linkedNode {
    BTNode *data;
    struct linkedNode *next;
} LinkedNode;

int preOrder(BTNode *root, int deep) {
    // wpl 声明为静态局部变量, 类似于全局变量, 只会初始化1次
    static int wpl = 0;
    if (root != NULL) {
        //判断当为叶子结点时，将对应叶子结点weight和deep相乘，加到wpl上
        if(root->left==NULL && root->right==NULL)
        {
            wpl+=root->weight*deep;
        }
        printf("%d", root->weight);
        preOrder(root->left, deep + 1);
        preOrder(root->right, deep + 1);
    }
    return wpl;
}

int main() {

//    char c;
//    scanf("%c", &c);
    int value;
    BTNode *root; // 声明二叉树节点
    // 输入: 1 2 3 4 5 6 7 8 a
    scanf("%d", &value); // 读取一个数字, 用于构造二叉树节点
    // 初始化root根节点
    root = (BTNode *) calloc(1, sizeof (BTNode));
    root->weight = value;
//    root->left = root->right = NULL;

    // 声明一个链表(队列)用于存储二叉树节点
    LinkedNode *linkedNode;
    // 初始化链表(队列)
    linkedNode = (LinkedNode *) calloc(1, sizeof (LinkedNode));
    linkedNode->data = root; // 把root根节点加入链表(队列)
//    linkedNode->next = NULL;
    // 当前链表(队列)指针, 用于当前放入链表(队列)的二叉树节点
    LinkedNode *currentPointer = linkedNode;
    // 读取一个数字, 用于构造二叉树节点
    while (scanf("%d", &value)) {
        // 声明二叉树节点, 并赋默认0值
        BTNode *btNode = (BTNode *) calloc(1, sizeof (BTNode));
        btNode->weight = value;
        // root->left = root->right = NULL;
        // 构造链表(队列)节点
        LinkedNode *tmpLinkedNode = (LinkedNode *) calloc(1, sizeof (LinkedNode));
        tmpLinkedNode->data = btNode;
        tmpLinkedNode->next = NULL;
        // 使用尾插法, 把二叉树节点加入到链表(队列)中
        linkedNode->next = tmpLinkedNode;
        linkedNode = linkedNode->next;
        // 判断是进入左子树还是右子树
        BTNode *currentBTNode = currentPointer->data;
        if(currentBTNode->left == NULL) {
            currentBTNode->left = btNode;
        } else if(currentBTNode->right == NULL) {
            currentBTNode->right = btNode;
            // 右子树时要移动当前链表指针currentPointer
            currentPointer = currentPointer->next;
        }
    }

    int result = preOrder(root, 0);
    printf("result:%d\n", result);



    return 0;
}