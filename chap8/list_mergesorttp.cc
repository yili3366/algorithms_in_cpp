#include "../chap3/list.hpp"
#include "list_merge.hpp"

link mergesort(link c)
{
    if (c == 0 || c->next == 0) {
        return c;
    }

    link a = c, b = c->next;

    while ((b != 0) && (b->next != 0)) {
        c = c->next;
        b = b->next->next;
    }
    b = c->next;
    c->next = 0;
    return merge(mergesort(a), mergesort(b));
}
