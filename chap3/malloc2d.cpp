#include "malloc2d.h"

template <typename T>
T **malloc2d(int r, int c)
{
    T **t = new T*[r];
    for (int i = 0; i < r; i++) {
        t[i] = new T[c];
    }

    return t;
}

template <>
link **malloc2d(int r, int c)
{
    link **t = new link*[r];
    for (int i = 0; i < r; i++) {
        t[i] = new link[c];
    }

    return t;
}
