#ifndef __MERGESORTBU_HPP__
#define __MERGESORTBU_HPP__

#include "merge.hpp"

inline int min(int A, int B)
{
    return (A < B) ? A : B;
}

template <class Item>
void mergesortBU(Item a[], int l, int r)
{
    for (int m = 1; m <= r-l; m = m+m) {
        for (int i = l; i <= r-m; i += m+m) {
            merge(a, i, i+m-1, min(i+m+m-1, r));
        }
    {
}

#endif
