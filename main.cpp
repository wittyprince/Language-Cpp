//#include <stdio.h>
#include "SqList.h"
#include "SeqList.h"
#include "LinkedList.h"
#include "LinkedList2.h"
#include "SqStack.h"
#include "LinkedStack.h"
#include "SqCircularQueue.h"
#include "LinkedQueue.h"
#include "LinkedCircularQueue.h"

/**
 * 在子函数中修改主函数的变量值
 * 使用C语言方式来实现
 */
void changeWithC(int *j) {
    *j = *j + 1;
}

/**
 * 在子函数中修改主函数的变量值
 * 使用Cpp语言方式来实现
 * 注意C语言中是不支持此种写法的
 */
void changeWithCpp(int &j) { // 形参中的&写法 称为 引用
    j = j + 1;
}

void changeWithCppWithNoEffect(int j) {
    j = j + 1;
}

void modifyPointerWithCpp(int *&a, int *b) { // 引用必须和变量名紧邻
    a = b;
}

void modifyPointerWithC(int **a, int *b) { // 引用必须和变量名紧邻
    *a = b;
}

int main() {
    int i = 10;
    printf("modify with C before change: %d\n", i);
    changeWithC(&i);
    printf("modify with C after  change: %d\n", i);
    changeWithCpp(i);
    printf("modify with Cpp after  change: %d\n", i);
    changeWithCppWithNoEffect(i);
    printf("modify with CppWithNoEffect after  change: %d\n", i);

    printf("-----------------------------------\n");

    int *p = NULL;
    int a = 10;
    int *q = &a;
//    p = q;
    modifyPointerWithCpp(p, q);
    printf("%d\n", *p);

    modifyPointerWithC(&p, q);
    printf("%d\n", *p);

    //==================Sequence List start=======================
    // 顺序表
    printf("----Sequence List start ----\n");
    // 定义一个顺序表变量
//    SqList sqList = {1, 2, 3, 4, 5}; // 这么赋值是不对的，因为sqList 是一个结构体，只不过结构体中包含了一个数组
    SqList sqList; // 这里声明的是一个结构体对象
    // 赋值
    // 这么赋值也是不对的，编译不通过
    // 数组的赋值只能在声明的时候, 如 int arr[10] = {1, 2, 3, 4, 5, 0};
//    sqList.data = {1, 2, 3, 4, 5};
    // 否则只能通过数组成员来赋值
    sqList.data[0] = 1;
    sqList.data[1] = 2;
    sqList.data[2] = 3;
    sqList.length = 3; // 此句指明了数组的长度，非常重要，否则会把length之后的默认值也打印出来

    printSqList(sqList);
    bool ret;
    ret = insertIntoSqList(sqList, 4, 9);
    if (ret) {
        printf("insert success\n");
        printSqList(sqList);
    } else {
        printf("insert fail\n");
    }

    ElementType deletedElement;
    bool deleted = deleteFromSqList(sqList, 5, deletedElement);
    if (deleted) {
        printf("delete success\n");
        printf("the deleted element is:%d\n", deletedElement);
        printSqList(sqList);
    } else {
        printf("delete failed\n");
    }

    int idx = locateSqListElement(sqList, 9);
    printf("idx= %d\n", idx);

    //TODO 使用动态分配方式
    SeqList seqList;
    InitList(seqList);

    printf("----Sequence List end ----\n");
    //==================Sequence List end=======================

    printf("----Linked List start ----\n");
    // 定义一个链表
    // 等价于 LinkedListNodeAlias *linkedList
    // 等价于 struct LinkedListNode *linkedList
    // 有个问题是 什么时候定义为 结构体, 什么时候定义为 结构体指针 ?
    LinkedList linkedList; // 这里声明的是一个结构体指针
    initLinkedList(linkedList);
    insertIntoLinkedListHead(linkedList, 1);
    insertIntoLinkedListHead(linkedList, 2);
    insertIntoLinkedListHead(linkedList, 3);
    printLinkedList(linkedList);
    insertIntoLinkedListTail(linkedList, 4);
    insertIntoLinkedListTail(linkedList, 5);
    printLinkedList(linkedList);

    LinkedListNodeAlias *gotElement = getElement(linkedList, 7);

    LinkedListNodeAlias *locatedElement = locateElement(linkedList, 6);

    bool insertResult = insertIntoLinkedList(linkedList, 7, 6);
    if (insertResult) {
        printf("insert into LinkedList success\n");
        printLinkedList(linkedList);
    } else {
        printf("insert into LinkedList failed\n");
    }

    bool deletedFromList = deleteFromLinkedList(linkedList, 6);
    if (deletedFromList) {
        printf("delete success\n");
        printLinkedList(linkedList);
    } else {
        printf("delete failed\n");
    }

    int theLengthOfLinkedList = getLinkedListLength(linkedList);
    printf("theLengthOfLinkedList: %d\n", theLengthOfLinkedList);

    printf("----Linked List end ----\n");

    printf("----Linked List2 start ----\n");
//    LinkedList2 linkedList2;
//    list_head_insert(linkedList2);
//    printLinkedList2(linkedList2);
//    list_tail_insert(linkedList2);
//    printLinkedList2(linkedList2);
//    LNode2Alias *lNode2 = getElement2(linkedList2, 5);
//    LNode2Alias *locatedElement2 = locateElement(linkedList2, 4);
//    bool insertedIntoList2 = insertIntoList2(linkedList2, 5, 9);
//    if (insertedIntoList2) {
//        printf("insert into list2 success\n");
//        printLinkedList2(linkedList2);
//    } else {
//        printf("insert into list2 failed\n");
//    }
//    bool deletedFromList2 = deleteFromList2(linkedList2, 4);
//    if (deletedFromList2) {
//        printf("delete from List2 success\n");
//        printLinkedList2(linkedList2);
//    } else {
//        printf("delete from List2 failed\n");
//    }

    printf("----Linked List2 end ----\n");

    printf("----Sq Stack start ----\n");
    SqStack stack; // 这里声明的是一个结构体对象
    initStack(stack);
    pushIntoStack(stack, 1);
    pushIntoStack(stack, 2);
    pushIntoStack(stack, 3);
    pushIntoStack(stack, 4);
    ElementType e;
    peekStack(stack, e);
    printf("e=%d", e);
    ElementType e2;
    popStack(stack, e2);
    printf("%d", e2);

    printf("----Sq Stack end ----\n");

    printf("----Linked Stack start ----\n");
    LinkedStackNodeAlias *linkedStack; // 这里声明的是一个结构体指针
    initLinkedStack(linkedStack);
    pushIntoLinkedStack(linkedStack, 1);
    pushIntoLinkedStack(linkedStack, 2);

    ElementType peekElement;
    peekLinkedStack(linkedStack, peekElement);
    printf("peekElement=%d\n", peekElement);
    pushIntoLinkedStack(linkedStack, 3);
    peekLinkedStack(linkedStack, peekElement);
    printf("peekElement=%d\n", peekElement);
    ElementType popElement;
    popLinkedStack(linkedStack, popElement);
    printf("popElement=%d\n", popElement);
    popLinkedStack(linkedStack, popElement);
    printf("popElement=%d\n", popElement);
    printf("----Linked Stack end ----\n");

    printf("----Sq Queue start ----\n");
    SqCircularQueueAlias sqQueue; // 这里声明的是一个结构体
    initSqQueue(sqQueue);
    bool sqQueueEmpty = isSqQueueEmpty(sqQueue);
    if (sqQueueEmpty) {
        printf("sqQueueEmpty empty\n");
    } else {
        printf("sqQueueEmpty not empty\n");
    }
    enSqQueue(sqQueue, 1);
    enSqQueue(sqQueue, 2);
    enSqQueue(sqQueue, 3);
    ElementType deQueueElement;
    deSqQueue(sqQueue, deQueueElement);
    printf("deQueueElement:%d\n", deQueueElement);
    deSqQueue(sqQueue, deQueueElement);
    printf("deQueueElement:%d\n", deQueueElement);

    printf("----Sq Queue end ----\n");

    printf("----Linked Queue start ----\n");
    //TODO 需要声明为结构体指针吗？ 这里也可以声明为结构体
    // 声明为结构体时, 需要修改initLinkedQueue()方法
    LinkedQueueAlias *linkedQueue;
    initLinkedQueue(linkedQueue);
    enLinkedQueue(linkedQueue, 1);
    enLinkedQueue(linkedQueue, 2);
    enLinkedQueue(linkedQueue, 3);
    ElementType deLinkedQueueElement;
    deLinkedQueue(linkedQueue, deLinkedQueueElement);
    printf("deLinkedQueueElement: %d\n", deLinkedQueueElement);
    deLinkedQueue(linkedQueue, deLinkedQueueElement);
    printf("deLinkedQueueElement: %d\n", deLinkedQueueElement);
    deLinkedQueue(linkedQueue, deLinkedQueueElement);
    printf("----Linked Queue end ----\n");

    printf("----Linked Circular Queue start ----\n");
    LinkedCircularQueueAlias linkedCircularQueue; //TODO 需要声明为结构体指针吗？
    initLinkedCircularQueue(linkedCircularQueue);
    ElementType deLinkedCircularQueueElement;
    bool deLinkedCircularQueueFlag = deLinkedCircularQueue(linkedCircularQueue, deLinkedCircularQueueElement);
    if (deLinkedCircularQueueFlag) {
        printf("deLinkedCircularQueue success: %d\n", deLinkedCircularQueueElement);
    } else {
        printf("deLinkedCircularQueue failed\n");
    }
    enLinkedCircularQueue(linkedCircularQueue, 1);
    enLinkedCircularQueue(linkedCircularQueue, 2);
    enLinkedCircularQueue(linkedCircularQueue, 3);
    deLinkedCircularQueueFlag = deLinkedCircularQueue(linkedCircularQueue, deLinkedCircularQueueElement);
    if (deLinkedCircularQueueFlag) {
        printf("deLinkedCircularQueue success: %d\n", deLinkedCircularQueueElement);
    } else {
        printf("deLinkedCircularQueue failed\n");
    }
    enLinkedCircularQueue(linkedCircularQueue, 4);
    deLinkedCircularQueueFlag = deLinkedCircularQueue(linkedCircularQueue, deLinkedCircularQueueElement);
    if (deLinkedCircularQueueFlag) {
        printf("deLinkedCircularQueue success: %d\n", deLinkedCircularQueueElement);
    } else {
        printf("deLinkedCircularQueue failed\n");
    }

    printf("----Linked Circular Queue end ----\n");
    return 0;
}
