#include "Graph.hpp"

Graph::Graph(SortingMethod* sortingMethod, int numberOfVertices){
    this->sortingMethod = sortingMethod;
    this->numberOfVertices = numberOfVertices;

    this->vertices = new Vertex*[numberOfVertices];

    for (int i = 0; i < numberOfVertices; i++)
    {
        this->vertices[i] = new Vertex();
    }
    
};

Graph::~Graph(){
    for (int i = 0; i < this->numberOfVertices; i++) delete this->vertices[i];

    delete[] this->vertices;
};

void Graph::insertVertex(int indexVertex, int numberOfNeighbors, string neighbors){
    Vertex* aux = this->vertices[indexVertex];

    aux->index = indexVertex;
    aux->numberOfNeighbors = numberOfNeighbors;

    aux->neighbors = new Vertex*[numberOfNeighbors];

    int initialPosition = 0;

    for (int i = 0; i < numberOfNeighbors; i++ )
    {
        int positionSpace = neighbors.find( ' ', initialPosition);
        int neighboor = stoi(neighbors.substr(initialPosition, positionSpace));
        aux->neighbors[i] = this->vertices[neighboor];

        initialPosition = positionSpace + 1;
    }
};

void Graph::insertColoring(string colors){
    int initialPositionString = 0;
    for (int i = 0; i < this->numberOfVertices; i++)
    {
        int finalPostionString = initialPositionString;

        while(colors[finalPostionString] != ' ' && colors[finalPostionString] != '\0') finalPostionString++;

        int color = stoi(colors.substr(initialPositionString, finalPostionString));

        initialPositionString = finalPostionString + 1;

        this->vertices[i]->color = color;
    }
    
    this->sortingMethod->sort(this->vertices, this->numberOfVertices);
};

Solution Graph::isThatAGreedColoring(){
    Solution s;
    int i = this->numberOfVertices - 1;
    while (this->vertices[i]->color > 1)
    {
        int j = this->vertices[i]->numberOfNeighbors - 1;
        int colorRequired = this->vertices[i]->color - 1; 

        this->sortingMethod->sort(this->vertices[i]->neighbors, this->vertices[i]->numberOfNeighbors);

        while (this->vertices[i]->neighbors[j]->color > 1)
        {
            if (this->vertices[i]->neighbors[j]->color < colorRequired) goto notGreedColoring;
            if (this->vertices[i]->neighbors[j]->color == colorRequired) colorRequired--;

            j--;
        }

        i--;
    }

    s.isAGreedCooloring = true;
    s.solution = this->vertices;
    return s;
    
    notGreedColoring:
        s.isAGreedCooloring = false;
        return s;

};