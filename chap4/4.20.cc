#include <iostream>
#include <stdlib.h>

#include "errno.h"
#include "QUEUE.hpp"
//#include "QUEUE_array.hpp"

static const int M = 4;

int main(int argc, char *argv[])
{
    if (argc < 2) {
        std::cout << "usage: " << argv[0] <<" N " << std::endl;
        return ERRFALSE;
    }

    int N = atoi(argv[1]);
    QUEUE<int> queues[M];

    for (int i = 0; i < N; i++, std::cout << std::endl) {
        int in = rand() % M, out = rand() % M;
        queues[in].put(i);
        std::cout << i << " in ";
        if (!queues[out].empty())
            std::cout << queues[out].get() << " out";

        std::cout << std::endl;

        for (int k = 0; k < M; k++, std::cout << std::endl) {
            QUEUE<int> q = queues[k];
            std::cout << k << ": ";

            while (!q.empty())
                std::cout << q.get() << " ";
        }
    }
}
