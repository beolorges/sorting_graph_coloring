#ifndef GRAPH_HPP
#define GRAPH_HPP

#include "SortingMethod.hpp"
#include "iostream"

using namespace std;

class Graph
{
private:
    Vertex** vertices;
    int numberOfVertices;
    SortingMethod* sortingMethod;

public:
    Graph(SortingMethod* sortingMethod, int numberOfVertices);
    ~Graph();

    void insertVertex(int indexVertex, int numberOfNeighboors, string neighboors);

    void insertColoring(string colors);

    Solution isThatAGreedColoring();
};



#endif