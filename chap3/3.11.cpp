#include <stdlib.h>
#include <math.h>
#include "node.h"

const int N = 100;

int main()
{
    class node heada(0, 0);
    link a = &heada, t = a;

    for (int i = 0; i < N; i++) {
        t = (t->next = new node(rand() % 1000, 0));
    }
    class node headb(0, 0);
    link u, x, b = &headb;
    for (t = a->next; t != 0; t = u) {
        u = t->next;
        for (x = b; x->next != 0; x = x->next) {
            if (x->next->item > t->item)
                break;
        }
        t->next = x->next;
        x->next = t;
    }
}
