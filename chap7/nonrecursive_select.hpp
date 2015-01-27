#ifndef __NONRECURSIVE_SELECT_HPP__
#define __NONRECURSIVE_SELECT_HPP__

template <class Item>
void select(Item a[], int l, int r, int k)
{
    while (r > l) {
        int i = partition(a, l, r);
        if (i >= k)
            r = i-1;
        if (i <= k)
            l = i+1;
    }
}
#endif
