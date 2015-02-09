#ifndef __TRIPLE_QUICKSORT_HPP__
#define __TRIPLE_QUICKSORT_HPP__

#include "../chap6/exch.hpp"

template <class Item>
int operator==(const Item &A, const Item &B)
{
    return !less(A, B) && !less(B, A);
}

template <class Item>
void quicksort(Item a[], int l, int r)
{
    int k;
    Item v = a[r];
    int index;

    if (r <= l)
        return;
    int i = l-1, j = r, p = l-1, q = r;
    for (;;) {
        while (a[++i] < v)
            ;
        while (v < a[--j]) {
            if (j == l) {
                break;
            }
        }
        if (i >= j) {
            break;
        }

        exch(a[i],a[j]);

        if (a[i] == v) {
            p++;
            exch(a[p],a[i]);
        }

        if (v == a[j]) {
        q--;
        exch(a[q],a[j]);
        }
    }

    exch(a[i], a[r]);
    j = i - 1;
    i = i + 1;

    fprintf(stderr, "i %d, j %d, p %d, q %d\n", i, j, p, q);
    for (index = 0; index < 15; index++) {
        fprintf(stderr, "a[%d] is %d\n", index, a[index]);
    }

    for (k = l  ; k <= p; k++, j--) {
        exch(a[k], a[j]);
    }

    for (k = r-1; k >= q; k--, i++) {
        exch(a[k], a[i]);
    }

    quicksort(a, l, j);
    quicksort(a, i, r);
}

#endif
