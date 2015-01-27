#ifndef __RECURSIVE_SELECT_HPP__
#define __RECURSIVE_SELECT_HPP__

template <class Item>
void select(Item a[], int l, int r, int k)
{
    if (r <= l)
        return;

    int i = partition(a, l, r);

    if (i > k) {
        select(a, l, i-1, k);
    }

    if (i < k) {
        select(a, i+1, r, k);
    }
}
#endif
