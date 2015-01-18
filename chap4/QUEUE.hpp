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
    void deletelist();
public:
    QUEUE();
    QUEUE(const QUEUE& rhs);
    QUEUE& operator=(const QUEUE& rhs);
    int empty() const;
    void put(Item x);
    Item get();
    ~QUEUE();
};

template <typename Item>
QUEUE<Item>::node::node(Item x)
{
    item = x;
    next = 0;
}

template <typename Item>
void QUEUE<Item>::deletelist()
{
    for (link t = head; t != 0; head = t) {
        t = head->next;
        delete head;
    }
}

template <typename Item>
QUEUE<Item>::QUEUE()
{
    head = 0;
}

template <typename Item>
QUEUE<Item>::QUEUE(const QUEUE& rhs)
{
    head = 0;
    *this = rhs;
}

template <typename Item>
QUEUE<Item>& QUEUE<Item>::operator=(const QUEUE& rhs)
{
    if (this == &rhs)
        return *this;

    deletelist();
    link t = rhs.head;

    while (t != 0) {
        put(t->item);
        t = t->next;
    }

    return *this;
}

template <typename Item>
QUEUE<Item>::~QUEUE()
{
    deletelist();
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
