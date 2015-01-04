class node
{
public:
    node(int x, node* t) {
        item = x; next = t;
    }

    int item;
    node* next;
};

typedef node *link;


