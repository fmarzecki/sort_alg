#include <iostream>
#include <climits>
#include "CSortTablicy.h"
#include "CTablica.h"

int main()
{

    CTablica sortINT;
    CSortTablicy CsortINT;
    CsortINT.ilustrateLomutoSort();
    CsortINT.ilustrateCocktailSort();

    // int arr[] = {1,4,6,2};
    // int arr2[] = {1,4,6,2};

    // int n = sizeof(arr)/sizeof(arr[0]);
    // std::vector<int> wyniki;
    // int l = 0;
    // int k = 0;

    // std::cout << sortINT.Lomuto(arr, 0, n-1, l,k);
    // l=0;
    // k=0;
    // std::cout << sortINT.Lomuto(arr2, 0, n-1, l,k);
    // printf("\nSorted array: \n");
    // printTable<int>(arr, n);
    return 0;


}