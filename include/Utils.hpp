#ifndef UTILS_HPP
#define UTILS_HPP

#include "stdlib.h"

class Vertex
{
    public:
    Vertex();
    ~Vertex();

    Vertex** neighbors;
    int numberOfNeighbors;
    int color;
    int index;
};


class  Solution
{
    public: 
    Solution();
    ~Solution();

    bool isAGreedCooloring;
    Vertex** solution;
};

#endif