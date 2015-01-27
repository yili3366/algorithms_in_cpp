#ifndef __RECURSIVE_QUICKSORT_HPP__
#define __RECURSIVE_QUICKSORT_HPP__

#include "../chap5/STACK.hpp"

inline void push2(STACK<int> &s, int A, int B)
{
    s.push(B);
    s.push(A);
}

template <class Item>
void quicksort(Item a[], int l, int r)
{
    STACK<int> s(50);
    push2(s, l, r);
    while (!s.empty()) {
        l = s.pop();
        r = s.pop();
        if (r <= l)
            continue;
        int i = partition(a, l, r);
        if (i-l > r-i) {
            push2(s, l, i-1);
            push2(s, i+1, r);
        } else {
            push2(s, i+1, r);
            push2(s, l, i-1);
        }
    }
}

#endif
