#include <iostream>
#include <stdlib.h>
#include "errno.h"
#include "POLY.hpp"

int main(int argc, char *argv[])
{
    if (argc < 2) {
        std::cout << "usage: " << argv[0] << " int float " << std::endl;
        return ERRFALSE;
    }

    if (atoi(argv[1]) < 0) {
        std::cout << "int mush great than 0" << std::endl;
        return ERRFALSE;
    }

    int N = atoi(argv[1]);
    float p = atof(argv[2]);

    std::cout << "Binomial coefficients" << std::endl;
    POLY<int> x(1,1);
    POLY<int> one(1, 0);
    POLY<int> t = x + one;
    POLY<int> y = t;

    for (int i = 0; i < N; i++) {
        y = y*t;
        std::cout << y << std::endl;
    }

    std::cout << y.eval(p) << std::endl;
}
