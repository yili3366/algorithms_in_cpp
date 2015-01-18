#include <iostream>
#include <string.h>
#include "STACK.hpp"

int main(int argc, char *argv[])
{
    char *a = argv[1];
    int N = strlen(a);
    STACK<int> save(N);

    for (int i = 0; i < N; i++) {
        if (a[i] == '+')
            save.push(save.pop() + save.pop());
        if (a[i] == '*')
            save.push(save.pop() * save.pop());
        if ((a[i] >= '0') && (a[i] <= '9'))
            save.push(0);
        while ((a[i] >= '0') && (a[i] <= '9'))
            save.push(10 * save.pop() + (a[i++] - '0'));
    }
    std::cout << save.pop() << std::endl;

    return 0;
}
