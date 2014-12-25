#include <iostream>

static const int N = 20;
static const int TRUE = 0;
static const int FALSE = 1;

int main()
{
    int i, p, q, id[N];
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
        int t = id[p];

        if (t == id[q])
            continue;

        for (i = 0; i < N; i++)
            if (id[i] == t)
                id[i] = id[q];
        std::cout << " " << p << " " << q << std::endl;
    }

    return TRUE;
}
