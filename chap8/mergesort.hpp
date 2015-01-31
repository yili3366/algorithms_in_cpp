#ifndef __MERGESORT_HPP__
#define __MERGESORT_HPP__

#include "merge.hpp"

template <class Item>
void mergesort(Item a[], int l, int r)
{
    if (r <= l)
        return;
    int m = (r+l)/2;
    mergesort(a, l, m);
    mergesort(a, m+1, r);
    merge(a, l, m, r);
}
#endif
