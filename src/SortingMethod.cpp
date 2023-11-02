#include "SortingMethod.hpp"

SortingMethod::~SortingMethod(){};

// ------------------------------------- BUBBLE SORT -----------------------------------------

BubbleSort::BubbleSort(){};

BubbleSort::~BubbleSort(){};

void BubbleSort::sort(Vertex** v, int numberOfVertices){

    for (int i = 0; i < numberOfVertices; i++){
        for(int j = 1; j < numberOfVertices - i; j++){
            if(v[j]->color < v[j-1]->color){
                Vertex* aux = v[j];
                v[j] = v[j-1];
                v[j-1] = aux;
            }
            
        }
    }

};

// ------------------------------------- SELECTION SORT -----------------------------------------

SelectionSort::SelectionSort(){};

SelectionSort::~SelectionSort(){};

void SelectionSort::sort(Vertex** v, int numberOfVertices){

    for (int i = 0; i < numberOfVertices; i++){
        int max = numberOfVertices - i - 1;

        for(int j = 0 ; j < numberOfVertices - i - 1 ; j++){

            // Segunda condição do if serve para manter a estabilidade do vetor. 
            // Sabemos que o index menor do vertice significa que ele foi inserido antes.
            if(v[max]->color < v[j]->color || ( v[max]->color == v[j]->color && v[max]->index < v[j]->index ) )
                max = j;
        }

        Vertex* aux = v[numberOfVertices - i - 1];
        v[numberOfVertices - i - 1] = v[max];
        v[max] = aux;
    }

};

// ------------------------------------- INSERTION SORT -----------------------------------------

InsertionSort::InsertionSort(){};

InsertionSort::~InsertionSort(){};

void InsertionSort::sort(Vertex** v, int numberOfVertices){

    for (int i = 1; i < numberOfVertices; i++)
    {
        Vertex* aux = v[i];
        int j = i - 1;

        while (j >= 0 && aux->color < v[j]->color)
        {
            v[j + 1] = v[j];
            j--;
        }
        
        v[j + 1] = aux;
    }
};

// ------------------------------------- MERGE SORT -----------------------------------------

MergeSort::MergeSort(){};

MergeSort::~MergeSort(){};

void MergeSort::sort(Vertex** v, int numberOfVertices){
    this->mergeSort(v, numberOfVertices - 1, 0);
}

void MergeSort::mergeSort(Vertex** v, int numberOfVertices, int ini){

    if(ini < numberOfVertices){
        int mid = ini + ((numberOfVertices - ini)/2);

        mergeSort(v, mid, ini);
        mergeSort(v, numberOfVertices, mid + 1);

        merge(v, ini, mid, numberOfVertices);
    }

};

void MergeSort::merge(Vertex** v, int ini, int mid, int end){
    int const arrayLeftSize = mid - ini + 1;
    int const arrayRightSize = end - mid;

    // Criando vetores auxiliares para armazenar os sub arrays
    Vertex** arrayLeftAux = new Vertex*[arrayLeftSize];
    Vertex** arrayRightAux = new Vertex*[arrayRightSize];

    // Populando vetores auxiliares
    for (int i = 0; i < arrayLeftSize; i++) arrayLeftAux[i] = v[ini + i];
    for (int i = 0; i < arrayRightSize; i++) arrayRightAux[i] = v[mid + 1 + i];

    int indexLeftArray = 0, indexRightArray = 0;

    while(indexLeftArray < arrayLeftSize && indexRightArray < arrayRightSize){
        if(arrayLeftAux[indexLeftArray]->color <= arrayRightAux[indexRightArray]->color){
            v[ini] = arrayLeftAux[indexLeftArray];
            indexLeftArray++;
        } else {
            v[ini] = arrayRightAux[indexRightArray];
            indexRightArray++;
        }
        ini++;
    } 

    while(indexLeftArray < arrayLeftSize){
        v[ini] = arrayLeftAux[indexLeftArray];
        indexLeftArray++;
        ini++;
    }

    while(indexRightArray < arrayRightSize){
        v[ini] = arrayRightAux[indexRightArray];
        indexRightArray++;
        ini++;
    }

    // Deletando os vetores auxiliares criados.
    delete[] arrayLeftAux;
    delete[] arrayRightAux;
}

// ------------------------------------- QUICK SORT -----------------------------------------
// TODO: CORRIGIR NAO ESTABILIDADE DO ALGORITMO
QuickSort::QuickSort(){};

QuickSort::~QuickSort(){};

void QuickSort::sort(Vertex** v, int numberOfVertices){
    this->quickSort(0, numberOfVertices - 1, v);
};

void QuickSort::quickSort(int left, int right, Vertex** v){
    int i, j;
    this->divide(left, right, &i, &j, v);
    if(left < j) this->quickSort(left, j, v);
    if(i < right) this->quickSort(i, right, v);
}

void QuickSort::divide(int left, int right, int *i, int *j, Vertex** A){
    Vertex *x, *w;
    *i = left; 
    *j = right;

    x = A[(*i + *j)/2]; /* obtem o pivo x */
    do
    { 
        while (x->color > A[*i]->color) (*i)++;
        while (x->color < A[*j]->color) (*j)--;
        if (*i <= *j)
        { 
            w = A[*i]; 
            A[*i] = A[*j]; 
            A[*j] = w;

        (*i)++; 
        (*j)--;
        }
    } while (*i <= *j);
}

// ------------------------------------- HEAP SORT -----------------------------------------
HeapSort::HeapSort(){};

HeapSort::~HeapSort(){};

void HeapSort::sort(Vertex** v, int numberOfVertices){
    this->fullHeapfy(v, --numberOfVertices);

		while (numberOfVertices >= 0)
    {
        Vertex* aux = v[numberOfVertices];
        v[numberOfVertices] = v[0];
        v[0] = aux;
				
				numberOfVertices--;

				this->heapfy(v, numberOfVertices, 0);
    }
    
};

void HeapSort::fullHeapfy(Vertex** v, int lastElement){
		int left = lastElement/2 + 1;

		while(left > 0){
			left--;
			this->heapfy(v, lastElement, left);
		}


}

void HeapSort::heapfy(Vertex** v, int lastElement, int i){
		while(i*2 + 2 <= lastElement){
				int max = i*2 + 1;

				if(v[max]->color < v[i*2 + 2]->color) max = i*2 + 2;

				if(!(v[i]->color < v[max]->color)){
						break; 
				}

				Vertex* aux = v[max];
				v[max] = v[i];
				v[i] = aux;

				i = max;

		}

}


// ------------------------------------------------ LEO SORT ------------------------------------------------

LeoSort::LeoSort(){};

LeoSort::~LeoSort(){};

void LeoSort::sort(Vertex** v, int numberOfElements){
		this->leoSort(v, 0, numberOfElements - 1);
}

void LeoSort::leoSort(Vertex** v, int left, int right){
		
		if(left - right > 64){
				int mid = (right - left)/ 2;

				leoSort(v, left, mid);
				leoSort(v, mid + 1, right);
				this->mergeSort.merge(v, left, mid, right);
		}
		
		while(right > left){
			int max = right;

			for(int i = right; i >= left; i--) if(v[i]->color > v[max]->color) max = i;

			if(max != right){
				Vertex* aux = v[right];
				v[right] = v[max];
				v[max] = aux;
			}
			
			right--;

		}


}

