#include "CSortTablicy.h"
#include "CTablica.h"

int* CSortTablicy::drawNumbers(int size) {
    int* tab  = new int[size];

    std::random_device rd; // obtain a random number from hardware
    std::mt19937 gen(rd()); // seed the generator
    std::uniform_int_distribution<> distr(0, 10000); // define the range

    for (int i = 0; i < size; i++)
    {
        tab[i] = distr(gen);
    }

    return tab;
}


int* CSortTablicy::insertElements(int size)
{
    int* tab = new int[size];
    for (int i = 0; i < size; i++)
    {
        tab[i] = sprawdzLiczbe<int>();
    }
    return tab;
}

void CSortTablicy::ilustrateMethods() {
    int* tab100 = drawNumbers(100);
    int* tab1000 = drawNumbers(1000);
    int* tab1000000 = drawNumbers(1000000);

    CTablica sort;

    std::cout << "cocktailSort  100     tablica uzupelniona losowymi liczbami" ; sort.cocktailSort(tab100,100);
    std::cout << "cocktailSort  1000    tablica uzupelniona losowymi liczbami" ; sort.cocktailSort(tab1000,1000);
    std::cout << "cocktailSort  1000000 tablica uzupelniona losowymi liczbami" ; sort.cocktailSort(tab1000000,10000);

    std::cout << "\n";

    std::cout << "cocktailSort  100     liczby uporzadkowane" ; sort.cocktailSort(tab100,100);
    std::cout << "cocktailSort  1000    liczby uporzadkowane" ; sort.cocktailSort(tab1000,1000);
    std::cout << "cocktailSort  1000000 liczby uporzadkowane" ; sort.cocktailSort(tab1000000,10000);

    std::cout << "\n";

    std::cout << "cocktailSort  100     liczby odwrotnie uporzadkowane" ; sort.cocktailSort(tab100,100,false);
    std::cout << "cocktailSort  1000    liczby odwrotnie uporzadkowane" ; sort.cocktailSort(tab1000,1000,false);
    std::cout << "cocktailSort  1000000 liczby odwrotnie uporzadkowane" ; sort.cocktailSort(tab1000000,10000,false);

    std::cout << "\n";

    // 10% na zlej pozycji
    sort.cocktailSort(tab100,0.10*100,true,false);
    sort.cocktailSort(tab1000,0.10*1000,true,false);
    sort.cocktailSort(tab1000000,0.10*10000,true,false);

    std::cout << "cocktailSort  100     liczby prawie posortowane" ; sort.cocktailSort(tab100,100,false);
    std::cout << "cocktailSort  1000    liczby prawie posortowane" ; sort.cocktailSort(tab1000,1000,false);
    std::cout << "cocktailSort  1000000 liczby prawie posortowane" ; sort.cocktailSort(tab1000000,10000,false);
}