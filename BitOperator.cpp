//
// Created by 51676 on 2024/7/7.
//
// 位运算

#include <stdio.h>

int main() {

    short i = 5;//short是short int的缩写，是2个字节的整型，int 是4个字节
    short j;
    j=i << 1;//一个变量移动以后自身不会变化
    printf("j=%d\n", j);//左移是乘2，结果为10
//    i=-8;
    j = i >> 1;
    printf("j=%d\n", j);//右移是除2，结果是2
    printf("-----------------\n");

    i = 0x8011;
    unsigned short s = 0x8011;//在short前加unsigned
    unsigned short r = 0;
    j = i >> 1;//对i右移，对有符号数进行右移
    r = s >> 1;//对s右移，对无符号数进行右移
    printf("j=%d,r=%u\n", j, r);// j=-16376,r=16392 结果是不一样的
    printf("-----------------\n");

    //接下来来看  按位与，按位或，按位异或，按位取反
    i = 5, j = 7;
    printf("i & j=%d\n", i & j); // 5
    printf("i | j=%d\n", i | j); // 7
    printf("i ^ j=%d\n", i ^ j); // 2
    printf("~i=%d\n", ~i); // -6
    return 0;
}