#include "CTablica.h"

std::string CTablica::cocktailSort(int tableToSort[], int tableSize, bool ascent, bool print)
{
    bool swapped = true;
    int min = 0;
    int max = tableSize - 1;
    long long liczba_porownan = 0;
    long long liczba_przestawien = 0;

    while (swapped)
    {
        swapped = false;
        for (int i = min; i < max; i++)
        {
            liczba_porownan++;
            if (ascent)
            {
                if (tableToSort[i] > tableToSort[i + 1])
                {
                    std::swap(tableToSort[i], tableToSort[i + 1]);
                    swapped = true;
                    liczba_przestawien++;
                }
            }
            else
            {
                if (tableToSort[i] < tableToSort[i + 1])
                {
                    std::swap(tableToSort[i], tableToSort[i + 1]);
                    swapped = true;
                    liczba_przestawien++;
                }
            }
        }

        if (!swapped)
            break;

        swapped = false;
        max--;

        for (int i = max; i > min; i--)
        {
            liczba_porownan++;
            if (ascent)
            {
                if (tableToSort[i] < tableToSort[i - 1])
                {
                    std::swap(tableToSort[i], tableToSort[i - 1]);
                    swapped = true;
                    liczba_przestawien++;
                }
            }
            else
            {
                if (tableToSort[i] > tableToSort[i - 1])
                {
                    std::swap(tableToSort[i], tableToSort[i - 1]);
                    swapped = true;
                    liczba_przestawien++;
                }
            }
        }
        min++;
    }
    if (print)
    {
        std::cout << " " << liczba_porownan;
        std::cout << " " << liczba_przestawien << " \n";
    }
    std::string text = " " + std::to_string(liczba_porownan);
    text += " " + std::to_string(liczba_przestawien) + " \n";

    return text;
}

int partition(int tableToSort[], int low, int high, unsigned long long int &liczbaPorownan, unsigned long long int &liczbaPrzestawien)
{
    int pivot = tableToSort[high];
    int i = (low - 1);

    for (int j = low; j <= high - 1; j++)
    {
        liczbaPorownan++;
        if (tableToSort[j] <= pivot)
        {
            i++;
            std::swap(tableToSort[i], tableToSort[j]);
            liczbaPrzestawien++;
        }
    }
    std::swap(tableToSort[i + 1], tableToSort[high]);
    // liczbaPrzestawien++;
    return (i + 1);
}

std::string CTablica::Lomuto(int tableToSort[], int low, int high, unsigned long long int &liczbaPorownan, unsigned long long int &liczbaPrzestawien)
{
    if (low < high)
    {
        int pi = partition(tableToSort, low, high, liczbaPorownan, liczbaPrzestawien);

        Lomuto(tableToSort, low, pi - 1, liczbaPorownan, liczbaPrzestawien);
        Lomuto(tableToSort, pi + 1, high, liczbaPorownan, liczbaPrzestawien);
    }
    return " " + std::to_string(liczbaPorownan) + " " + std::to_string(liczbaPrzestawien) + "\n";
}

void heapify(int tableToSort[], int n, int i, unsigned long long int &liczbaPorownan, unsigned long long int &liczbaPrzestawien)
{
    liczbaPorownan++;
    int largest = i;

    // lewe dziecko
    int l = 2 * i + 1;

    // prawe dziecko
    int r = 2 * i + 2;

    // jesli lewe dziecko jest wieksze od korzenia
    if (l < n && tableToSort[l] > tableToSort[largest])
        largest = l;

    // jesli prawe dziecko jest wieksz od korzenia
    if (r < n && tableToSort[r] > tableToSort[largest])
        largest = r;

    // jesli najwiekszym nie jest korzen
    if (largest != i)
    {
        std::swap(tableToSort[i], tableToSort[largest]);
        liczbaPrzestawien++;
        heapify(tableToSort, n, largest, liczbaPorownan, liczbaPrzestawien);
    }
}

std::string CTablica::Heap(int tableToSort[], int tableSize, unsigned long long int &liczbaPorownan, unsigned long long int &liczbaPrzestawien)
{
    for (int i = tableSize / 2 - 1; i >= 0; i--)
        heapify(tableToSort, tableSize, i, liczbaPorownan, liczbaPrzestawien);

    for (int i = tableSize - 1; i > 0; i--)
    {
        std::swap(tableToSort[0], tableToSort[i]);
        heapify(tableToSort, i, 0, liczbaPorownan, liczbaPrzestawien);
    }
    return " " + std::to_string(liczbaPorownan) + " " + std::to_string(liczbaPrzestawien) + "\n";
}

int partitionHoare(int tableToSort[], int low, int high, unsigned long long int &liczbaPorownan, unsigned long long int &liczbaPrzestawien)
{
    int pivot = tableToSort[low];
    int i = low - 1, j = high + 1;

    while (true)
    {
        liczbaPorownan++;

        do
        {
            i++;
        } while (tableToSort[i] < pivot);

        do
        {
            j--;
        } while (tableToSort[j] > pivot);

        if (i >= j)
            return j;

        std::swap(tableToSort[i], tableToSort[j]);
        liczbaPrzestawien++;
    }
}

std::string CTablica::Hoare(int tableToSort[], int low, int high, unsigned long long int &liczbaPorownan, unsigned long long int &liczbaPrzestawien)
{
    if (low < high)
    {
        int pi = partitionHoare(tableToSort, low, high, liczbaPorownan, liczbaPrzestawien);

        Hoare(tableToSort, low, pi, liczbaPorownan, liczbaPrzestawien);
        Hoare(tableToSort, pi + 1, high, liczbaPorownan, liczbaPrzestawien);
    }
    return " " + std::to_string(liczbaPorownan) + " " + std::to_string(liczbaPrzestawien) + "\n";
}