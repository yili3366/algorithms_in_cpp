#include <iostream>
#include <stdio.h>

const int M = 4;
const int maxN = 32;

void distcount(int a[], int l, int r)
{
    int i, j, cnt[M];
    static int b[maxN];

    for (j = 0; j < M; j++) {
        cnt[j] = 0;
    }

    for (i = l; i <= r; i++) {
        cnt[a[i] + 1]++;
    }

    for (j = 1; j < M; j++) {
        cnt[j] += cnt[j - 1];
    }

    for (i = l; i <= r; i++) {
        b[cnt[a[i]]++] = a[i];
//        fprintf(stderr, "cnt[%d] is %d\n", a[i], cnt[a[i]] - 1);
    }

    for (i = l; i <= r; i++) {
//        a[i] = b[i - 1];
        a[i] = b[i];
//        fprintf(stderr, "a[%d] is %d\n", i, a[i]);
    }
}

//int main()
//{
//    int array[] = {0, 3, 3, 0, 1, 1, 0, 3, 0, 2, 0, 1, 1, 2, 0};
//    int i;
//
//    distcount(array, 0, 14);
//
//    return 0;
//}
