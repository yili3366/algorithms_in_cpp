#include <iostream>
#include <string.h>
#include "STACK.hpp"

int main(int argc, char *argv[])
{
    char *a = argv[1]; int N = strlen(a);
    STACK<char> ops(N);

    for (int i = 0; i < N; i++) {
        if (a[i] == ')')
            std::cout << ops.pop() << " ";
        if ((a[i] == '+') || (a[i] == '*'))
            ops.push(a[i]);
        if ((a[i] >= '0') && (a[i] <= '9'))
            std::cout << a[i] << " ";
    }

    std::cout << std::endl;
}
