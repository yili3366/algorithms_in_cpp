#include <iostream>
#include <stdlib.h>
#include <math.h>

#include "POINT.h"
#include "errno.h"

int main(int argc, char *argv[])
{
    if (argc < 3) {
        std::cout << "usage: " << argv[0] <<" N M" << std::endl;
        return ERRFALSE;
    }

    if (!(atoi(argv[1]) >= 0)) {
        std::cout << "argv[1]  must great than zero " << std::endl;
        return ERRFALSE;
    }

    if (!((atof(argv[2]) >= 0.0) && (atof(argv[2]) <= 1.0))) {
        std::cout << "argv[2] must great than 0.0 and lower than 1.0" << std::endl;
        return ERRFALSE;
    }

    float d = atof(argv[2]);
    int i, cnt = 0, N = atoi(argv[1]);

    POINT *a = new POINT[N];
    for (i = 0; i < N; i++) {
        for (int j = i+1; j < N; j++) {
            if (a[i].distance(a[j]) < d) {
                cnt++;
            }
        }
    }
    std::cout << cnt << " pairs within " << d << std::endl;

    return 0;
}
