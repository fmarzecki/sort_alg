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
    CsortINT.ilustrateHeapSort();
    CsortINT.ilustrateHoareSort();

    return 0;
}