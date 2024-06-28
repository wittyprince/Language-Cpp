//
// 栈stack
// Created by 51676 on 2024/6/28.
//

#ifndef LANGUAGE_CPP_SQSTACK_H
#define LANGUAGE_CPP_SQSTACK_H

#define MaxSize 10
typedef int ElementType;

typedef struct SqStack {
    ElementType data[MaxSize]; // 顺序存储，底层用数组实现
    int top; // 栈顶
}SqStack;

void initStack(SqStack &stack) {
    stack.top = -1;
}

bool isStackEmpty(SqStack stack) {
    return stack.top == -1;
}

bool isStackOverflow(SqStack stack) {
    return stack.top + 1 == MaxSize;
}

bool pushIntoStack(SqStack &stack, ElementType e) {
    if (stack.top + 1 == MaxSize) {
        return false;
    }
    stack.top ++;
    stack.data[stack.top] = e;
    return true;
}

bool peekStack(SqStack stack, ElementType &e) {
    if (stack.top == -1) {
        return false;
    }
    e = stack.data[stack.top];
    return true;
}

bool popStack(SqStack &stack, ElementType &e) {
    if (stack.top == -1) {
        return false;
    }
    e = stack.data[stack.top];
    stack.top--;
    return true;
}

#endif //LANGUAGE_CPP_SQSTACK_H
