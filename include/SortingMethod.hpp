#ifndef SORTING_METHOD_HPP
#define SORTING_METHOD_HPP

#include "Utils.hpp"

class SortingMethod
{
    public:
        virtual ~SortingMethod();

        virtual void sort(Vertex** v, int numberOfElements) = 0;
};


class BubbleSort : public SortingMethod
{

public:
    BubbleSort();
    ~BubbleSort();

    void sort(Vertex** v, int numberOfElements);
};

class SelectionSort : public SortingMethod
{

public:
    SelectionSort();
    ~SelectionSort();

    void sort(Vertex** v, int numberOfElements);
};

class InsertionSort : public SortingMethod
{

public:
    InsertionSort();
    ~InsertionSort();

    void sort(Vertex** v, int numberOfElements);
};

class MergeSort : public SortingMethod
{
    private:
    void merge(Vertex** v, int ini, int mid, int end);
    void mergeSort(Vertex** v, int numberOfVertices, int ini);

    public:
    MergeSort();
    ~MergeSort();

    void sort(Vertex** v, int numberOfElements);
		
		friend class LeoSort;

};

class QuickSort : public SortingMethod
{
private:
    void quickSort(int left, int right, Vertex** v);
    void divide(int left, int right, int *i, int *j, Vertex** A);

public:
    QuickSort();
    ~QuickSort();

    void sort(Vertex** v, int numberOfElements);
};

class HeapSort : public SortingMethod
{
private:
    void heapfy(Vertex** v, int lastElement, int i);
		void fullHeapfy(Vertex** v, int lastElement);

public:
    HeapSort();
    ~HeapSort();

    void sort(Vertex** v, int numberOfElements);
};

class LeoSort : public SortingMethod
{
private:
		MergeSort mergeSort;
		
		void leoSort(Vertex** v, int ini, int end);
public:
		LeoSort();
		~LeoSort();

		void sort(Vertex** v, int numberOfElements);
};

#endif
