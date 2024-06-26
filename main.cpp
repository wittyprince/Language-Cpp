//#include <stdio.h>
#include "SqList_Header.h"
#include "SeqList_Header.h"
#include "LinkedList.h"
#include "LinkedList2.h"

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

    // 顺序表
    printf("----Sequence List start ----\n");
    // 定义一个顺序表变量
//    SqList sqList = {1, 2, 3, 4, 5}; // 这么赋值是不对的，因为sqList 是一个结构体，只不过结构体中包含了一个数组
    SqList sqList;
    // 赋值
    // 这么赋值也是不对的，编译不通过
    // 数组的赋值只能在声明的时候, 如 int arr[10] = {1, 2, 3, 4, 5, 0};
//    sqList.data = {1, 2, 3, 4, 5};
    // 否则只能通过数组成员来赋值
    sqList.data[0] = 1;
    sqList.data[1] = 2;
    sqList.data[2] = 3;
    sqList.length = 3; // 此句指明了数组的长度，非常重要，否则会把length之后的默认值也打印出来

    printList(sqList);
    bool ret;
    ret = ListInsert(sqList, 4, 9);
    if (ret) {
        printf("insert success\n");
        printList(sqList);
    } else {
        printf("insert fail\n");
    }

    ElementType deletedElement;
    bool deleted = ListDelete(sqList, 5, deletedElement);
    if (deleted) {
        printf("delete success\n");
        printf("the deleted element is:%d\n", deletedElement);
        printList(sqList);
    } else {
        printf("delete failed\n");
    }

    int idx = LocateElement(sqList, 9);
    printf("idx= %d\n", idx);

    // 使用动态分配方式
    SeqList seqList;
    InitList(seqList);

    printf("----Sequence List end ----\n");

    printf("----Link List start ----\n");

    LinkedList linkedList; // 定义一个链表
    initLinkedList(linkedList);
    insertIntoLinkedListHead(linkedList, 1);
    insertIntoLinkedListHead(linkedList, 2);
    insertIntoLinkedListHead(linkedList, 3);
    printLinkedList(linkedList);
    insertIntoLinkedListTail(linkedList, 4);
    insertIntoLinkedListTail(linkedList, 5);
    printLinkedList(linkedList);

    LNode *gotElement = getElement(linkedList, 7);

    LNode *locatedElement = locateElement(linkedList, 6);

    bool insertResult = insertIntoList(linkedList, 7, 6);
    if (insertResult) {
        printf("insert into LinkedList success\n");
        printLinkedList(linkedList);
    } else {
        printf("insert into LinkedList failed\n");
    }

    bool deletedFromList = deleteFromList(linkedList, 6);
    if (deletedFromList) {
        printf("delete success\n");
        printLinkedList(linkedList);
    } else {
        printf("delete failed\n");
    }

    int theLengthOfLinkedList = getLinkedListLength(linkedList);
    printf("theLengthOfLinkedList: %d\n", theLengthOfLinkedList);

    printf("----Link List end ----\n");

    printf("----Link List2 start ----\n");
    LinkedList2 linkedList2;
//    list_head_insert(linkedList2);
//    printLinkedList2(linkedList2);
//    list_tail_insert(linkedList2);
//    printLinkedList2(linkedList2);
//    LNode2Alias *lNode2 = getElement2(linkedList2, 5);
//    LNode2Alias *locatedElement2 = locateElement(linkedList2, 4);

    printf("----Link List2 end ----\n");

    return 0;
}
