#ifndef __UF_H__
#define __UF_H__

#include "uf.h"

class UF : public uf
{
private:
    // Implementation-dependent code
    int *id;
    int *sz;
    int find(int x);
public:
    UF(int);
    int find(int, int);
    void unite(int, int);
};
#endif
