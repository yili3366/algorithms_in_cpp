#include "../chap4/QUEUE_list.hpp"
#include "list_merge.hpp"

link mergesort(link t)
{
    QUEUE<link> Q(max);

    if (t == 0 || t->next == 0)
        return t;

    for (link u = 0; t != 0; t = u) {
        u = t->next;
        t->next = 0;
        Q.put(t);
    }

    t = Q.get();
    while (!Q.empty()) {
        Q.put(t);
        t = merge(Q.get(), Q.get());
    }

    return t;
}
