#ifndef __STACK_UNIQUE_HPP_
#define __STACK_UNIQUE_HPP_

template <typename Item>
class STACK
{
private:
    Item *s, *t; int N;
public:
    STACK(int maxN);

    int empty() const;
    void push(Item item);
    Item pop();
};

template <typename Item>
STACK<Item>::STACK(int maxN)
{
    s = new Item[maxN];
    N = 0;
    t = new Item[maxN];

    for (int i = 0; i < maxN; i++)
        t[i] = 0;
}

template <typename Item>
int STACK<Item>::empty() const
{
    return N == 0;
}

template <typename Item>
void STACK<Item>::push(Item item)
{
    if (t[item] == 1)
        return;

    s[N++] = item;
    t[item] = 1;
}

template <typename Item>
Item STACK<Item>::pop()
{
    t[s[--N]] = 0;
    return s[N];
}
#endif
