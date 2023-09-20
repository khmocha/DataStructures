#include "BinaryHeap.h"
#include <iostream>

BinaryHeap::BinaryHeap() {
    Size = 0;
    CurrentSize = 0;
    Array = nullptr;
}

BinaryHeap::BinaryHeap(int NewSize) {
    if (NewSize <= 0) {
        std::cerr << "Invalid Binary Heap Size" << std::endl;
        return;
    } 

    Size = NewSize;
    CurrentSize = 0;
    Array = new int [Size];
}

void BinaryHeap::Insert(int Data) {
    if (CurrentSize == Size) {
        std::cerr << "No more available space for insertion" << std::endl;
        return;
    }

    Array[CurrentSize] = Data;
    int CurrentIndex = CurrentSize;
    
    CurrentSize++;

    while (CurrentIndex > 0) {
        if (Array[CurrentIndex] > Array[(CurrentIndex - 1) / 2]) {
            std::swap(Array[CurrentIndex], Array[(CurrentIndex - 1) / 2]);
            CurrentIndex = (CurrentIndex - 1) / 2;
        } else {
            return;
        }
    }
    
    if (Array[CurrentIndex] > Array[(CurrentIndex - 1) / 2]) {
        std::swap(Array[CurrentIndex], Array[(CurrentIndex - 1) / 2]);
        CurrentIndex = (CurrentIndex - 1) / 2;
    }
}

void BinaryHeap::DeleteRoot(bool Heapifying, int HeapifyIndex) {
    if (CurrentSize == 0) {
        std::cerr << "There are no available data to delete" << std::endl;
        return;
    }

    int CurrentIndex = 0;

    if (Heapifying == false) {
        std::swap(Array[0], Array[--CurrentSize]);
    } else {
        CurrentIndex = HeapifyIndex;
    }

    int GreaterChild;
    int YoungerChild;

    while (CurrentIndex < CurrentSize) {
        if (CurrentIndex * 2 + 1 < CurrentSize && CurrentIndex * 2 + 2 < CurrentSize) {
            if (Array[CurrentIndex * 2 + 1] > Array[CurrentIndex * 2 + 2]) {
                GreaterChild = CurrentIndex * 2 + 1;
                YoungerChild = CurrentIndex * 2 + 2;
            } else {
                GreaterChild = CurrentIndex * 2 + 2;
                YoungerChild = CurrentIndex * 2 + 1;
            }

            if (Array[CurrentIndex] < Array[GreaterChild]) {
                std::swap(Array[CurrentIndex], Array[GreaterChild]);
            } else if (Array[CurrentIndex] < Array[YoungerChild]) {
                std::swap(Array[CurrentIndex], Array[YoungerChild]);
                GreaterChild = YoungerChild;
            } else {
                break;
            }

            CurrentIndex = GreaterChild;

        } else if (CurrentIndex * 2 + 1 < CurrentSize) {
            if (Array[CurrentIndex] < Array[CurrentIndex * 2 + 1]) {
                std::swap(Array[CurrentIndex], Array[CurrentIndex * 2 + 1]);
            } 
            break;

        } else {
            break;
        }
    }
}

void BinaryHeap::HeapSort() {
    int OriginalSize = CurrentSize;

    for (int i = 0; i < OriginalSize; i++) {
        DeleteRoot();
    }

    CurrentSize = OriginalSize;
}

void BinaryHeap::Heapify() {
    if (CurrentSize == 0) {
        std::cerr << "No available data to heapify" << std::endl;
        return;
    }

    int EndingParentSize = 0;
    int Multiplier = 1;

    while (EndingParentSize < CurrentSize) {
        EndingParentSize += Multiplier;
        Multiplier *= 2;
    }

    EndingParentSize -= (Multiplier / 2);

    std::cout << EndingParentSize << std::endl;

    for (int i = EndingParentSize - 1; i > -1; i--) {
        DeleteRoot(true, i);
    }
}

void BinaryHeap::Print() {
    for (int i = 0; i < CurrentSize; i++) {
        std::cout << Array[i] << " ";
    }

    std::cout << std::endl;
}

BinaryHeap::~BinaryHeap() {
    if (Array != nullptr) {
        delete [] Array;
        Array = nullptr;
    }
}


