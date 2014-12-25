#include <iostream>

static const int N = 10000;
static const int TRUE = 0;
static const int FALSE = 1;

int main()
{
    int i, j, p, q, id[N], sz[N];
    for (i = 0; i < N; i++) {
        id[i] = i; sz[i] = 1;
    }

    while (std::cin >> p >> q) {
        if (!(p < N) || !(q < N)) {
            std::cout << " file " << __FILE__
                      << " line " << __LINE__
                      << " p or q must less than " << N
                      << std::endl;
            return FALSE;
        }
        for (i = p; i != id[i]; i = id[i])
            id[i] = id[id[i]];
        for (j = q; j != id[j]; j = id[j])
            id[j] = id[id[j]];

        if (i == j)
            continue;

        if (sz[i] < sz[j]) {
            id[i] = j; sz[j] += sz[i];
        } else {
            id[j] = i; sz[i] += sz[j];
        }
        std::cout << " " << p << " " << q << std::endl;
    }

    return TRUE;
}

