#include "list.h"

#include <stdlib.h>

link freelist;
void construct(int N)
{
    freelist = new node[N+1];
    for (int i = 0; i < N; i++)
        freelist[i].next = &freelist[i+1];
    freelist[N].next = 0;
}

link newNode(int i)
{
    link x = remove(freelist);
    x->item = i; x->next = x;
    return x;
}

void deleteNode(link x)
{
    insert(freelist, x);
}

void insert(link x, link t)
{
    t->next = x->next;
    x->next = t;
}

link remove(link x)
{
    link t = x->next;
    x->next = t->next;
    return t;
}

link next(link x)
{
    return x->next;
}

Item item(link x)
{
    return x->item;
}
