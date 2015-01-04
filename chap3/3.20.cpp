#include <math.h>
#include <iostream>
#include <stdlib.h>
#include <stdio.h>

#include "Point.h"
//#include "malloc2d.h"

const int ERRFALSE = 1;
const int TRUE = 0;

struct node {
    point p;
    node *next;
    node(point pt, node* t)
    {
        p = pt;
        next = t;
    }
};

typedef node *link;
static link **grid;
static int G, cnt = 0;
static float d;

link **malloc2d(int r, int c)
{
    link **t = new link*[r];
    for (int i = 0; i < r; i++) {
        t[i] = new link[c];
    }

    return t;
}

float randFloat()
{
    return 1.0 * rand() / RAND_MAX;
}

void gridinsert(float x, float y)
{
    int X = x * G + 1;
    int Y = y * G + 1;
    point p;

    p.x = x;
    p.y = y;
    link s, t = new node(p, grid[X][Y]);

    for (int i = X - 1; i <= X + 1; i++) {
        for (int j = Y - 1; j <= Y + 1; j++) {
            for (s = grid[i][j]; s != NULL; s = s->next) {
                if (distance(s->p, t->p) < d) {
                fprintf(stderr, "file %s, line %d, s->p.x %f, s->p.y %f\n", __FILE__, __LINE__, s->p.x, s->p.y);
                    cnt++;
                }
            }
        }
    }

    grid[X][Y] = t;
}

int main(int argc, char *argv[])
{
    if (argc < 3) {
        std::cout << "usage: " << argv[0] <<" N M" << std::endl;
        return ERRFALSE;
    }

    if (!(atoi(argv[1]) > 0)) {
        std::cout << "argv[1]  must great than zero " << std::endl;
        return ERRFALSE;
    }

    if (!((atof(argv[2]) > 0.0) && (atof(argv[2]) < 1.0))) {
        std::cout << "argv[2] must great than 0.0 and lower than 1.0" << std::endl;
        return ERRFALSE;
    }

    int i, N = atoi(argv[1]);

    d = atof(argv[2]);
    G = 1 / d;

    grid = malloc2d(G + 2, G + 2);
    for (i = 0; i < G + 2; i++) {
        for (int j = 0; j < G + 2; j++) {
            grid[i][j] = NULL;
        }
    }

    for (i = 0; i < N; i++) {
        gridinsert(randFloat(), randFloat());
    }

    std::cout << cnt << " pairs within " << d << std::endl;

    return 0;
}
