#ifndef __QUEUE_LIST_H__
#define __QUEUE_LIST_H__

template <typename Item>
class QUEUE
{
private:
    struct node
    {
        Item item;
        node* next;
        node(Item x);
    };

    typedef node *link;
    link head, tail;
public:
    QUEUE(int);
    int empty() const;
    void put(Item x);
    Item get();
};

template <typename Item>
QUEUE<Item>::node::node(Item x)
{
    item = x;
    next = 0;
}

template <typename Item>
QUEUE<Item>::QUEUE(int)
{
    head = 0;
}

template <typename Item>
int QUEUE<Item>::empty() const
{
    return head == 0;
}

template <typename Item>
void QUEUE<Item>::put(Item x)
{
    link t = tail;
    tail = new node(x);
    if (head == 0) {
        head = tail;
    } else {
        t->next = tail;
    }
}

template <typename Item>
Item QUEUE<Item>::get()
{
    Item v = head->item;
    link t = head->next;
    delete head;
    head = t;

    return v;
}
#endif
