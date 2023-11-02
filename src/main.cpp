#include "Graph.hpp"
#include "iostream"

using namespace std;

char sortingMethod;
SortingMethod* s;

void handleOptions(){
    switch (sortingMethod){
    case 'b':
        s = new BubbleSort();
        break;

    case 's':
        s = new SelectionSort();
        break;

    case 'i':
        s = new InsertionSort();
        break;

    case 'm':
        s = new MergeSort();
        break;
    
    case 'q':
        s = new QuickSort();
        break;

		case 'p':
				s = new HeapSort();
				break;

		case 'y':
				s = new LeoSort();
				break;

		default:
        cout << "Metodo nao implementado\n";
        abort();
    }
}


int main(){

    int numberOfVertices;

    cin >> sortingMethod >> numberOfVertices;

    handleOptions();

    Graph g(s, numberOfVertices);

    for (int i = 0; i < numberOfVertices; i++)
    {
        int numberOfNeighbors;
        string neighbors;

        cin >> numberOfNeighbors;
        getline(cin, neighbors);
        

        g.insertVertex(i, numberOfNeighbors, neighbors.substr(1));
    }

    string colors;

    getline(cin, colors);

    g.insertColoring(colors);

    Solution sol = g.isThatAGreedColoring();

    if(sol.isAGreedCooloring){
        cout << "1 ";
        for (int i = 0; i < numberOfVertices - 1; i++)
        {
            cout << sol.solution[i]->index << ' ';
        }
        cout << sol.solution[numberOfVertices - 1]->index << '\n';
    } else {
        cout << "0\n";
    }

    delete s;

}
