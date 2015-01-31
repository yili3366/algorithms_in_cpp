#ifndef __MERGESORTAB_HPP__
#define __MERGESORTAB_HPP__

#include "mergeAB.hpp"

template <class Item>
void mergesortABr(Item a[], Item b[], int l, int r)
{
    if (r-l <= 10) {
        insertion(a, l, r);
         return;
    }

    int m = (l+r)/2;
    mergesortABr(b, a, l, m);
    mergesortABr(b, a, m+1, r);
    mergeAB(a+l, b+l, m-l+1, b+m+1, r-m);
}

template <class Item>
void mergesortAB(Item a[], int l, int r)
{
    static Item aux[maxN];

    for (int i = l; i <= r; i++)
        aux[i] = a[i];
    mergesortABr(a, aux, l, r);
}
#endif
