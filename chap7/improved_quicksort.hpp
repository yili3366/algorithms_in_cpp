#ifndef __IMPROVED_QUICKSORT_HPP__
#define __IMPROVED_QUICKSORT_HPP__

#include "../chap6/exch.hpp"
#include "../chap6/insertion.hpp"

static const int M = 10;
template <class Item>
void quicksort(Item a[], int l, int r)
{
    if (r-l <= M)
        return;

    exch(a[(l+r)/2], a[r-1]);
    compexch(a[l], a[r-1]);
    compexch(a[l], a[r]);
    compexch(a[r-1], a[r]);
    int i = partition(a, l+1, r-1);
    quicksort(a, l, i-1);
    quicksort(a, i+1, r);
}

template <class Item>
void hybridsort(Item a[], int l, int r)
{
    quicksort(a, l, r);
    insertion(a, l, r);
}

#endif
