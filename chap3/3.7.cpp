#include <iostream>
#include <stdlib.h>

const int ERRFALSE = 1;
const int TRUE = 0;


int heads()
{
    return rand() < RAND_MAX/2;
}

int main(int argc, char *argv[])
{
    if (argc < 2) {
        std::cout << "usage: ./3.7 N M" << std::endl;
        return ERRFALSE;
    }

    if (!(argv[1] > 0) && !(argv[2] > 0)) {
        std::cout << "N and M must great than zero" << std::endl;
        return ERRFALSE;
    }

    int i, j, cnt;
    int N = atoi(argv[1]), M = atoi(argv[2]);
    int *f = new int[N+1];

    for (j = 0; j <= N; j++)
        f[j] = 0;

    for (i = 0; i < M; i++, f[cnt]++) {
        for (cnt = 0, j = 0; j <= N; j++) {
            if (heads()) {
                cnt++;
            }
        }
     }

    for (j = 0; j <= N; j++) {
        if (f[j] == 0) {
            std::cout << ".";
        }

        for (i = 0; i < f[j]; i+=10) {
            std::cout << "*";
        }
        std::cout << std::endl;
    }
}
