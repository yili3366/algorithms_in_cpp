#include <iostream>
#include <stdlib.h>
#include <math.h>

typedef int Number;

const int TRUE = 0;
const int FALSE = 1;

Number randNum()
{
    return rand();
}

int main(int argc, char *argv[])
{
    if (argc != 2) {
        std::cout << "usage: ./3.2 integer" << std::endl;
        return FALSE;
    }

    int N = atoi(argv[1]);
    float m1 = 0.0, m2 = 0.0;

    for (int i = 0; i < N; i++) {
        Number x = randNum();
        m1 += ((float) x)/N;
        m2 += ((float) x*x)/N;
    }
    std::cout << "     Avg.: " << m1 << std::endl;
    std::cout << "Std. dev.: " << sqrt(m2-m1*m1) << std::endl;

    return 0;
}
