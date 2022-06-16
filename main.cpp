#include <iostream>
#include <climits>
#include "CSortTablicy.h"
#include "CTablica.h"
#include "libWyjatki.h"
#include <fstream>

int main()
{

    CTablica sortINT;
    CSortTablicy CsortINT;
    std::ofstream file;
    
    try {
        openIFileStream("wyjscie.txt", file);
    }
    catch (MyRuntimeExceptions::FileOpenException &err) {
        std::cerr << err.what();
    }

    CsortINT.ilustrateCocktailSort(file);
    CsortINT.ilustrateLomutoSort(file);
    CsortINT.ilustrateHoareSort(file);
    CsortINT.ilustrateHeapSort(file);


    return 0;
}