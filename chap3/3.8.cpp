#include <math.h>
#include <iostream>
#include <stdlib.h>
#include "Point.h"

const int ERRFALSE = 1;
const int TRUE = 0;

float randFloat()
{
    return 1.0 * rand() / RAND_MAX;
}

int main(int argc, char *argv[])
{
    if (argc < 3) {
        std::cout << "usage: " << argv[0] <<" N M" << std::endl;
        return ERRFALSE;
    }

    if (!(argv[1] > 0) && !(argv[2] > 0)) {
        std::cout << "N and M must great than zero" << std::endl;
        return ERRFALSE;
    }

    float d = atof(argv[2]);
    int i, cnt = 0, N = atoi(argv[1]);
    point *a = new point[N];

    for (i = 0; i < N; i++) {
        a[i].x = randFloat();
        a[i].y = randFloat();
    }

    for (i = 0; i < N; i++) {
        for (int j = i+1; j < N; j++) {
            if (distance(a[i], a[j]) < d) {
                cnt++;
            }
        }
    }

    std::cout << cnt << " pairs within " << d << std::endl;

    return 0;
}
