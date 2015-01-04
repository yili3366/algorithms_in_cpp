#include <iostream>

int lg(int);
int main()
{
    for (int N = 1000; N <= 1000000000; N *= 10)
        std::cout << lg(N) << " " << N << std::endl;

    return 0;
}

int lg(int N)
{
    int i;

    for (i = 0; N > 0; i++, N /= 2)
        ;

    return i;
}
