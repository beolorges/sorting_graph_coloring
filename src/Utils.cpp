#include "Utils.hpp"

Vertex::Vertex(){
    this->color = 0;
    this->index = 0;
    this->numberOfNeighbors = 0;
    this->neighbors = NULL;
};


Vertex::~Vertex(){
    if(this->numberOfNeighbors > 0)
        delete[] this->neighbors;
};

Solution::Solution(){};
Solution::~Solution(){};