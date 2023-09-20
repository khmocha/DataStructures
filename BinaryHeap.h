#ifndef HEAPSORT_H
#define HEAPSORT_H

class BinaryHeap {
    private:
    public:
        int Size;
        int * Array;
        int CurrentSize;

        BinaryHeap();
        BinaryHeap(int NewSize);

        void Insert(int Data);
        void DeleteRoot(bool Heapifying = false, int HeapifyIndex = -1);
        void HeapSort();
        void Heapify();

        void Print();

        ~BinaryHeap();

};

#endif