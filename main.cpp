#include <iostream>
#include <climits>
#include "CSortTablicy.h"
#include "CTablica.h"
#include <fstream>

int main()
{

    CTablica sortINT;
    CSortTablicy CsortINT;
    std::ofstream file("wyjscie.txt");

    CsortINT.ilustrateLomutoSort(file);
    CsortINT.ilustrateCocktailSort(file);
    CsortINT.ilustrateHeapSort(file);
    CsortINT.ilustrateHoareSort(file);

    return 0;
}