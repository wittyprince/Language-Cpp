//
// Created by 51676 on 2024/7/3.
//

#include <stdio.h>
#include <stdlib.h>

#define length 5
//typedef int ElementType;
//
//typedef struct bsNode {
//    ElementType *data;
//    int length;
//} BSNode;

int search(int a[]) {

    return 0;
}

int MidSearch(int A[], int B[], int len) {
    int s1 = 0, d1 = len -1, m1, s2 = 0, d2 = len - 1, m2;
    while (s1 < d1 && s2 < d2) {
        m1 = (s1 + d1) / 2;
        m2 = (s2 + d2) / 2;
        if (A[m1] < B[m2]) {
            s1 = m1;
            d2 = m2;
        } else if ( A[m1] > B[m2]) {
            d1 = m1;
            s2 = m2;
        } else {
            return A[m1];
        }
    }
    if (s1 == d1) {
        if (s2 < d2) {
            if (A[s1] <= B[s2]) {
                return B[s2];
            } else if (A[s1] >= B[d2]) {
                return B[d2];
            } else {
                return A[s1];
            }
        } else if (s2 == d2) {
            // return A[m1] > B[m2] ? B[m2] : A[m1];
        }
    } else if (s2 == d2) {
        if (s1 < d1) {
            if (B[s2] <= A[s1]) {
                return A[s1];
            } else if (B[s2] >= A[d1]) {
                return A[d1];
            } else {
                return B[s2];
            }

        } else if (s1 == s2) {
            // return A[m1] > B[m2] ? B[m2] : A[m1];
        }
    }

    return A[m1] > B[m2] ? B[m2] : A[m1];
}

int main() {

    int A[length] =
            {11, 13, 15, 17, 19};
//            {1, 2, 3, 4, 5};
    int B[length] =
            {2, 4, 6, 8, 20};
//            {6, 7, 8, 9, 10};
    int mid = MidSearch(A, B, length);
    printf("%d", mid);

    return 0;
}