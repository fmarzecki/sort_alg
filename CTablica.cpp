#include "CTablica.h"

void CTablica::cocktailSort(int tableToSort[], int tableSize, bool ascent, bool print)
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
}

int partition(int tableToSort[], int low, int high, long long &liczbaPorownan, long long &liczbaPrzestawien)
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
    liczbaPrzestawien++;
    return (i + 1);
}

std::string CTablica::Lomuto(int tableToSort[], int low, int high, long long &liczbaPorownan, long long &liczbaPrzestawien)
{

    if (low < high)
    {
        int pi = partition(tableToSort, low, high, liczbaPorownan, liczbaPrzestawien);

        Lomuto(tableToSort, low, pi - 1,liczbaPorownan, liczbaPrzestawien);
        Lomuto(tableToSort, pi + 1, high, liczbaPorownan, liczbaPrzestawien);
    }

    return " " + std::to_string(liczbaPorownan) + " " + std::to_string(liczbaPrzestawien) + "\n";
}
