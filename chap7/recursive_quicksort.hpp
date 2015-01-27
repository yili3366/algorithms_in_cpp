#ifndef __RECURSIVE_QUICKSORT_HPP__
#define __RECURSIVE_QUICKSORT_HPP__

template <class Item>
void quicksort(Item a[], int l, int r)
{
    if (r <= l) return;
    int i = partition(a, l, r);
    quicksort(a, l, i-1);
    quicksort(a, i+1, r);
}

template <class Item>
int partition(Item a[], int l, int r)
{
    int i = l-1, j = r;
    Item v = a[r];
    for (;;) {
        while (a[++i] < v)
            ;

        while (v < a[--j]) {
            if (j == l) {
                break;
            }
        }

        if (i >= j)
            break;

        exch(a[i], a[j]);
    }
    exch(a[i], a[r]);

    return i;
}

#endif
