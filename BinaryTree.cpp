//
// Created by 51676 on 2024/7/1.
//
#include <stdio.h>
#include <stdlib.h>
#include "BTNode.h"

// ===================================================================
void preOrder(BTNode *btNode) {
    if (btNode != NULL) {
        putchar(btNode->data); // 等价于 printf("%c", btNode->data);
        preOrder(btNode->left);
        preOrder(btNode->right);
    }
}

void inOrder(BTNode *btNode) {
    if (btNode != NULL) {
        inOrder(btNode->left);
        putchar(btNode->data);
        inOrder(btNode->right);
    }
}

void postOrder(BTNode *btNode) {
    if (btNode != NULL) {
        postOrder(btNode->left);
        postOrder(btNode->right);
        putchar(btNode->data);
    }
}

void levelOrder(BTNode *btNode) {
    LinkedQueueAlias *linkedQueue;
    initLinkedQueue(linkedQueue);
    enLinkedQueue(linkedQueue, btNode); // 把二叉树节点入队
    BTNode *tmpBTNode; // 存放出队的临时二叉树节点
    // 队列不为空时
    while (linkedQueue->front != linkedQueue->rear) {
        deLinkedQueue(linkedQueue, tmpBTNode); // 出队
        putchar(tmpBTNode->data); // 打印出队的二叉树节点的数据
        if (tmpBTNode->left != NULL) { // 如果出队的二叉树节点的左孩子不为空, 那么入队
            enLinkedQueue(linkedQueue, tmpBTNode->left);
        }
        if (tmpBTNode->right != NULL) { // 如果出队的二叉树节点的右孩子不为空, 那么入队
            enLinkedQueue(linkedQueue, tmpBTNode->right);
        }
    }

}
// ===================================================================

int main() {

    // 层次建树
    BTNode *root;
    // calloc 申请空间并对空间进行初始化, 会把结构体中的成员(元素)默认赋值为0值
    root = (BTNode *) calloc(1, sizeof (BTNode));
    char c;
    scanf("%c", &c);
    root->data = c;
    root->left = NULL;
    root->right = NULL;

    // 声明一个链表, btListNode指向当前链表的尾部, 用于后续尾插法入链表时使用
    BTListNode *btListNode = (BTListNode *) malloc(sizeof (BTListNode));
    btListNode->data = root;
    btListNode->next = NULL;
    // 当前链表指针, 用于入链表时判断当前的BTNode节点
    BTListNode *currentBtListNode = btListNode;
    // scanf()的返回值是成功赋值的变量数量, 发生错误时返回EOF.
    while (scanf("%c", &c) && c != '\n') {
        // 声明二叉树节点
        BTNode *tmpBTNode = (BTNode *) calloc(1, sizeof (BTNode));
        tmpBTNode->data = c;
        // 声明链表节点
        BTListNode *tmpListNode = (BTListNode *) malloc(sizeof (BTListNode));
        tmpListNode->data = tmpBTNode;
        tmpListNode->next = NULL;
        // 尾插法 入链表(或入队列)
        btListNode->next = tmpListNode;
        btListNode = btListNode->next;
        // 判断是进入左子树还是右子树
        BTNode *currentBtNode = currentBtListNode->data;
        if (currentBtNode->left == NULL) {
            currentBtNode->left = tmpBTNode;
        } else if (currentBtNode->right == NULL) {
            currentBtNode->right = tmpBTNode;
            // 右子树时要移动当前链表指针currentBtListNode
            currentBtListNode = currentBtListNode->next;
        }
    }
    // 前序遍历
    preOrder(root);
    printf("\n");
    // 中序遍历
    inOrder(root);
    printf("\n");
    // 后续遍历
    postOrder(root);
    printf("\n");

    // 层序遍历
    levelOrder(root);

    return 0;
}