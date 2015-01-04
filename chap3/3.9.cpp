#include <iostream>
#include <stdlib.h>

const int ERRFALSE = 1;
const int TRUE = 0;

struct node
{
    int item; node* next;
    node(int x, node* t) {
        item = x; next = t;
    }
};

typedef node *link;

int main(int argc, char *argv[])
{

    std::cout << "argc is " << argc << std::endl;
    std::cout << argv[0] << " " << argv[1] << " " << argv[2] << std::endl;

    if (argc < 3) {
        std::cout << "usage: " << argv[0] <<" N M" << std::endl;
        return ERRFALSE;
    }

    if (!(argv[1] > 0) && !(argv[2] > 0)) {
        std::cout << "N and M must great than zero" << std::endl;
        return ERRFALSE;
    }

    if (atoi(argv[2]) > atoi(argv[1])) {
        std::cout << "M must great than N" << std::endl;
        return ERRFALSE;
    }

    int i, N = atoi(argv[1]), M = atoi(argv[2]);
    link t = new node(1, 0); t->next = t;
    link x = t;

    for (i = 2; i <= N; i++)
        x = (x->next = new node(i, t));
    while (x != x->next) {
        for (i = 1; i < M; i++)
            x = x->next;
        x->next = x->next->next;
    }
    std::cout << x->item << std::endl;
}

