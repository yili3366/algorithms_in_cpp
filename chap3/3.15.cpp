#include <iostream>
#include <string.h>

static const int N = 10000;

int main(int argc, char *argv[])
{
    int i;
    char t;
    char a[N], *p = argv[1];

    for (i = 0; i < N-1; a[i] = t, i++) {
        if (!std::cin.get(t)) {
            break;
        }
    }
    a[i] = 0;
    for (i = 0; a[i] != 0; i++) {
        int j;
        for (j = 0; p[j] != 0; j++) {
            if (a[i+j] != p[j]) {
                break;
            }
        }
        if (p[j] == 0) {
            std::cout << i << " ";
        }
    }
    std::cout << std::endl;

    return 0;
}
