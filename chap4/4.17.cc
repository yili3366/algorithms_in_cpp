#include <iostream>
#include <stdlib.h>
#include <math.h>

#include "errno.h"
#include "Complex.h"

int main(int argc, char *argv[])
{
    if (argc < 2) {
        std::cout << "usage: " << argv[0] <<" N " << std::endl;
        return ERRFALSE;
    }

    int N = atoi(argv[1]);

    std::cout << N << " complex roots of unity" << std::endl;

    for (int k = 0; k < N; k++) {
        float theta = 2.0 * 3.14159 * k / N;

        Complex t(cos(theta), sin(theta));
        Complex x = t;
        std::cout << k << ": " << t << "  ";

        for (int j = 0; j < N - 1; j++)
            x *= t;
        std::cout << x << std::endl;
    }

    return 0;
}
