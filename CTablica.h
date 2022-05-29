#pragma once
#include <iostream>
#include <climits>

class CTablica {
    public:
    
    void cocktailSort(int tableToSort[], int tableSize, bool ascent=true, bool print=true);
    void Lomuto(int tableToSort[], int tableSize);
    void Hoare(int tableToSort[], int tableSize);
    void Heap(int tableToSort[], int tableSize);
};


template <typename T>
void printTable(T tableToSort[], int tableSize) {
    for (int i = 0; i < tableSize; i++)
    {
        std::cout << tableToSort[i] << " ";
    }
}