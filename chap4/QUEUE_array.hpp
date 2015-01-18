#ifndef __QUEUE_ARRAY_HPP__
#define __QUEUE_ARRAY_HPP__

template <typename Item>
class QUEUE
{
private:
    Item *q;
    int N, head, tail;
public:
    QUEUE(int maxN);
    int empty() const;
    void put(Item item);
    Item get();
};

template <typename Item>
QUEUE<Item>::QUEUE(int maxN)
{
    q = new Item[maxN + 1];
    N = maxN + 1;
    head = N;
    tail = 0;
}

template <typename Item>
int QUEUE<Item>::empty() const
{
    return head % N == tail;
}

template <typename Item>
void QUEUE<Item>::put(Item item)
{
    q[tail++] = item;
    tail = tail % N;
}

template <typename Item>
Item QUEUE<Item>::get()
{
    head = head % N;
    return q[head++];
}
#endif
