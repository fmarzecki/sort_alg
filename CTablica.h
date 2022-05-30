#pragma once
#include <iostream>
#include <climits>
#include <vector>
#include <string>

class CTablica {
    public:
    
    void cocktailSort(int tableToSort[], int tableSize, bool ascent=true, bool print=true);
    std::string Lomuto(int tableToSort[], int low, int high, long long &liczbaPorownan, long long &liczbaPrzestawien);
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


int partition(int arr[], int low, int high);

 
