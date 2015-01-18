#ifndef __uf_H__
#define __uf_H__

class uf
{
public:
    virtual int find(int, int) = 0;
    virtual void unite(int, int) = 0;
};

#endif
