#pragma once
#include <iostream>
#include <climits>
#include <vector>
#include <string>

class CTablica {
    public:
    
    void cocktailSort(int tableToSort[], int tableSize, bool ascent=true, bool print=true);
    std::string Lomuto(int tableToSort[], int low, int high, unsigned long long int &liczbaPorownan, unsigned long long int &liczbaPrzestawien);
    std::string Hoare(int tableToSort[], int low, int high, unsigned long long int &liczbaPorownan, unsigned long long int &liczbaPrzestawien);
    std::string Heap(int tableToSort[], int tableSize, unsigned long long int &liczbaPorownan, unsigned long long int &liczbaPrzestawien);
};

/*
* wyswietla tablice
* @param tableToSort tablica do posortowania
* @param tableSize rozmiar tablicy
*/
template <typename T>
void printTable(T tableToSort[], int tableSize) {
    for (int i = 0; i < tableSize; i++)
    {
        std::cout << tableToSort[i] << " ";
    }
}

/*
* ostatni element jest pivotem, 
* elementy mniejsze pojawia sie na lewo od niego
* elementy wieksze od pivotu na prawo

* @param tableToSort tablica do sortowania
* @param low indeks od ktorego zaczynamy sortowac
* @param high indeks ostatniego elementu w tablicy
*/
int partition(int tableToSort[], int low, int high, unsigned long long int &liczbaPorownan,unsigned long long int &liczbaPrzestawien);


/*
*pierwszy element jest pivotem, wszystkie elementy mniejsze od pivotu
* znajda sie po jego lewej stronie, a wieksze po prawej, zwraca indeks
*najmiejszego elementu po lewej czesci piwotu

* @param tableToSort tablica do sortowania
* @param low indeks od ktorego zaczynamy sortowac
* @param high indeks ostatniego elementu w tablicy
*/
int partitionHoare(int tableToSort[], int low, int high, unsigned long long int &liczbaPorownan,unsigned long long int &liczbaPrzestawien);

/* 
* przywraca wlasnoci kopca
* rodzic musi miec wieksza wartosc od dzieci,
* jesli tak nie jest, rodzic zamienia sie miejscem z dzieckiem

* @param tableToSort tablica do sortowania
* @param n rozmiar tablicy
* @param i wezeł i-ty
*/
void heapify(int tableToSort[], int n, int i, unsigned long long int &liczbaPorownan, unsigned long long int &liczbaPrzestawien);