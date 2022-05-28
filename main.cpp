#include <iostream>

void cocktailSort(int tableToSort[], int tableSize)
{

    bool swapped = true;
    int min = 0;
    int max = tableSize - 1;
    int liczba_porownan = 0;
    int liczba_przestawien = 0;

    while (swapped)
    {
        swapped = false;
        for (int i = min; i < max; i++)
        {
            liczba_porownan++;
            if (tableToSort[i] > tableToSort[i + 1])
            {
                std::swap(tableToSort[i], tableToSort[i + 1]);
                swapped = true;
                liczba_przestawien++;
            }
        }

        if (!swapped)
            break;

        swapped = false;
        max--;

        for (int i = max; i > min; i--)
        {
            liczba_porownan++;
            if(tableToSort[i] < tableToSort[i-1]){
                std::swap(tableToSort[i], tableToSort[i-1]);
                swapped = true;
                liczba_przestawien++;
            }
        }
        min++;
    }


    std:: cout << "Liczba przestawien: " << liczba_przestawien;
    std:: cout << "Liczba porownan: " << liczba_porownan << "\n";
}

void printTable(int tableToSort[], int tableSize) {
    for (int i = 0; i < tableSize; i++)
    {
        std::cout << tableToSort[i];
    }
}

int main()
{
    int tabToSort[]{4, 2, 3, 6, 1};
    cocktailSort(tabToSort,5);
    printTable(tabToSort,5);
    return 0;
}