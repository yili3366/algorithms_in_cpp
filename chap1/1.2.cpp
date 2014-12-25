#include <iostream>

static const int N = 20;
static const int TRUE = 0;
static const int FALSE = 1;

int main()
{
    int i, j, p, q, id[N];
    for (i = 0; i < N; i++)
        id[i] = i;

    while (std::cin >> p >> q) {
        if (!(p < N) || !(q < N)) {
            std::cout << " file " << __FILE__
                      << " line " << __LINE__
                      << " p or q must less than " << N
                      << std::endl;
            return FALSE;
        }

        for (i = p; i != id[i]; i = id[i])
            ;

        for (j = q; j != id[j]; j = id[j])
            ;

        if (i == j)
            continue;

        id[i] = j;
        std::cout << " " << p << " " << q << std::endl;
    }

    return TRUE;
}
