#include "../chap3/list.h"

link merge(link a, link b)
{
    node dummy(0);
    link head = &dummy, c = head;

    while ((a != 0) && (b != 0)) {
        if (a->item < b->item) {
            c->next = a;
            c = a;
            a = a->next;
        } else {
            c->next = b;
            c = b;
            b = b->next;
        }
    }

    c->next = (a == 0) ? b : a;
    return head->next;
}
