#ifndef __STACK_LIST_HPP__
#define __STACK_LIST_HPP__

template <class Item>
class STACK
{
private:
    struct node {
        Item item;
        node* next;
        node(Item x, node* t);
    };
    typedef node *link;
    link head;
public:
    STACK(int);
    int empty() const;
    void push(Item x);
    Item pop();
};

template <class Item>
STACK<Item>::node::node(Item x, node* t)
{
    item = x;
    next = t;
}

template <class Item>
STACK<Item>::STACK(int)
{
    head = 0;
}

template <class Item>
int STACK<Item>::empty(int) const
{
    return head == 0;
}

template <class Item>
void STACK<Item>::push(Item x)
{
    head = new node(x, head);
}

template <class Item>
Item STACK<Item>::pop()
{
    Item v = head->item;
    link t = head->next;
    delete head;
    head = t;
    return v;
}
#endif
