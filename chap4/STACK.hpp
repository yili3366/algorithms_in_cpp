#ifndef __STACK_HPP__
#define __STACK_HPP__

template <typename Item>
class STACK
{
private:
    // Implementation-dependent code
    Item *s;
    int N;
public:
    STACK(int);
    int empty() const;
    void push(Item item);
    Item pop();
};

template <typename Item>
STACK<Item>::STACK(int maxN)
{
    s = new Item[maxN];
    N = 0;
}

template <typename Item>
int STACK<Item>::empty() const
{
    return N == 0;
}

template <typename Item>
void STACK<Item>::push(Item item)
{
    s[N++] = item;
}

template <typename Item>
Item STACK<Item>::pop()
{
    return s[--N];
}
#endif
