//
// Created by 51676 on 2024/7/1.
//
#include <stdio.h>
#include <stdlib.h>
#include "BTNode.h"


int main() {

    BTNode *root;
    // calloc 会把结构体中的成员(元素)默认赋值为0值
    root = (BTNode *) calloc(1, sizeof (BTNode));
    char c;
    scanf("%c", &c);
    root->data = c;
    root->lChild = NULL;
    root->rChild = NULL;

    // 声明一个链表, btListNode指向当前链表的尾部, 用于后续尾插法入链表时使用
    BTListNode *btListNode = (BTListNode *) malloc(sizeof (BTListNode));
    btListNode->btNodePointer = root;
    btListNode->nextBtListNode = NULL;
    // 当前链表指针, 用于入链表时判断当前的BTNode节点
    BTListNode *currentBtListNode = btListNode;
    // scanf()的返回值是成功赋值的变量数量, 发生错误时返回EOF.
    while (scanf("%c", &c) && c != '\n') {
        // 声明二叉树节点
        BTNode *tmpBTNode = (BTNode *) calloc(1, sizeof (BTNode));
        tmpBTNode->data = c;
        // 声明链表节点
        BTListNode *tmpListNode = (BTListNode *) malloc(sizeof (BTListNode));
        tmpListNode->btNodePointer = tmpBTNode;
        tmpListNode->nextBtListNode = NULL;
        // 尾插法 入链表(或入队列)
        btListNode->nextBtListNode = tmpListNode;
        btListNode = btListNode->nextBtListNode;
        // 判断是进入左子树还是右子树
        BTNode *currentBtNode = currentBtListNode->btNodePointer;
        if (currentBtNode->lChild == NULL) {
            currentBtNode->lChild = tmpBTNode;
        } else if (currentBtNode->rChild == NULL) {
            currentBtNode->rChild = tmpBTNode;
            // 右子树时要移动当前链表指针currentBtListNode
            currentBtListNode = currentBtListNode->nextBtListNode;
        }
    }

    return 0;
}