#include <stdio.h>

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
    printf("%d", *p);

    modifyPointerWithC(&p, q);
    printf("%d", *p);
    return 0;
}
