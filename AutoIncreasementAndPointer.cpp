//
// Created by 51676 on 2024/7/7.
//
// 自增自减运算符 与 取值运算符
#include <stdio.h>

void printArray(int *a, int length) {
    for (int i = 0; i < length; ++i) {
        printf("%3d", a[i]);
    }
    printf("\n");
}

int main() {
    int a[3] = {1, 2, 3};
    int *p;
    int j;
    p = a; //p指向数组起始元素
    j = *p++; //先把*p的值赋给j，然后对p加1。等价于语句 j=*p;p++;
    printf("%d %d %d \n", a[0], j, *p);
    j=p[0]++;  //先把p[0]赋给j，然后对p[0]加1。等价于语句 j=p[0];p[0]++
    printf("a[0]=%d,j=%d,*p=%d\n",a[0],j,*p);
    // 这里要注意: p++ 与 p[0]++ 是有区别的
    // p++ 只是把指针p向后移动了一个位置, 即 p = p + 1;
    // 而 p[0]++ 是把 p[1]的值 赋值给 p[0], 即 p[0] = p[0] + 1; 也即 p[0] = p[1];

    int b[3] = {1, 2, 3};
    int *p2 = b;
    printf("%d\n", *p2); // 1
    p2 = p2+1;
    printf("%d\n", *p2); // 2

    int c[3] = {1, 2, 3};
    int *p3 = c;
    printf("%d\n", *p3); // 1
    p3[0] = p3[0] + 1;
    printf("%d\n", *p3); // 2
    printArray(c, 3); //  2  2  3

    return 0;
}