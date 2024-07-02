//
// Created by 51676 on 2024/7/2.
//

/**
 * 读取字符串abcdefghij，
 * 然后层次建树建立一颗二叉树，
 * 然后前序遍历输出abdhiejcfg，
 * 注意不要打印前序遍历几个汉字
 */

#include <stdio.h>
#include <stdlib.h>

typedef char ElementType;

typedef struct btNode {
    ElementType data;
    struct btNode *left;
    struct btNode *right;
} BTNode;

typedef struct btLinkedNode {
    BTNode *data;
    struct btLinkedNode *next;
} BTLinkedNode;

typedef struct btLinkedQueue {
    BTLinkedNode *front;
    BTLinkedNode *rear;
} BTLinkedQueue;

void preOrder(BTNode *root) {
    if (root != NULL) {
        putchar(root->data);
        preOrder(root->left);
        preOrder(root->right);
    }
}

void inOrder(BTNode *root) {
    if (root != NULL) {
        inOrder(root->left);
        putchar(root->data);
        inOrder(root->right);
    }
}

void postOrder(BTNode *root) {
    if (root != NULL) {
        postOrder(root->left);
        postOrder(root->right);
        putchar(root->data);
    }
}

void enQueue(BTLinkedQueue &linkedQueue, BTNode *btNode) {
    BTLinkedNode *linkedNode = (BTLinkedNode *)malloc(sizeof (BTLinkedNode));
    linkedNode->data = btNode;
    linkedNode->next = NULL;

    // 尾插法入队
    linkedQueue.rear->next = linkedNode;
    linkedQueue.rear = linkedQueue.rear->next;
}

void deQueue(BTLinkedQueue &linkedQueue, BTNode *&btNode) {
    if (linkedQueue.front == linkedQueue.rear) {
        return;
    }
    BTLinkedNode *firstNode = linkedQueue.front->next;
    btNode = firstNode->data;
    linkedQueue.front->next = firstNode->next;
    //TODO 判断方式 ?
    if (firstNode == linkedQueue.rear) { // 也可以用 firstNode == NUll 来判断锻炼后无节点 ?
        linkedQueue.rear = linkedQueue.front;
    }
    free(firstNode);
}

void levelOrder(BTNode *root) {
    BTLinkedQueue linkedQueue;
    // 初始化队列
    linkedQueue.front = linkedQueue.rear = (BTLinkedNode *)malloc(sizeof (BTLinkedNode));
    linkedQueue.rear->next = NULL;

    // 入队
    enQueue(linkedQueue, root);
    // 判断队列是否为空
    while (linkedQueue.front != linkedQueue.rear) {
        BTNode *tmpBTNode;
        // 把队列元素出队
        deQueue(linkedQueue, tmpBTNode);
        putchar(tmpBTNode->data);
        // 判断当前二叉树节点的左右孩子是否为空
        if (tmpBTNode->left != NULL) {
            enQueue(linkedQueue, tmpBTNode->left);
        }
        if (tmpBTNode->right != NULL) {
            enQueue(linkedQueue, tmpBTNode->right);
        }
    }
}



int main() {

    char c;
    // 读取字符, 构建根节点
    scanf("%c", &c);
    BTNode *root = (BTNode *) calloc(1, sizeof (BTNode));
    root->data = c;

    // 构建链表(或队列)用于存储二叉树节点
    BTLinkedNode *linkedNode = (BTLinkedNode *) calloc(1, sizeof (BTLinkedNode));
    linkedNode->data = root;
    linkedNode->next = NULL;
    // 声明一个链表(或队列)指针, 用于向后遍历链表(或队列)
    BTLinkedNode *currentLinkedNodePointer = linkedNode;

    while (scanf("%c", &c) && c != '\n') {
        // 构建临时二叉树节点
        BTNode *tmpBTNode = (BTNode *) calloc(1, sizeof (BTNode));
        tmpBTNode->data = c;
        // 构建链表(或队列)节点
        BTLinkedNode *tmpLinkedNode = (BTLinkedNode *) calloc(1, sizeof (BTLinkedNode));
        tmpLinkedNode->data = tmpBTNode;
        tmpLinkedNode->next = NULL;
        // 尾插法入链(或入队)
        linkedNode->next = tmpLinkedNode;
        linkedNode = linkedNode->next;
        // 判断是进入左子树还是右子树
        BTNode *currentBTNode = currentLinkedNodePointer->data;
        if (currentBTNode->left == NULL) {
            currentBTNode->left = tmpBTNode;
        } else if (currentBTNode->right == NULL) {
            currentBTNode->right = tmpBTNode;
            currentLinkedNodePointer = currentLinkedNodePointer->next;
        }
    }

//    preOrder(root);
//    printf("\n");
    inOrder(root);
    printf("\n");
    postOrder(root);
    printf("\n");
    levelOrder(root);
    printf("\n");

    return 0;
}