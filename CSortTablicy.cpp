#include "CSortTablicy.h"

int* CSortTablicy::drawNumbers(int size) {
    int* tab  = new int[size];

    std::random_device rd; 
    std::mt19937 gen(rd()); 
    std::uniform_int_distribution<> distr(0, 10000); 

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

void CSortTablicy::ilustrateCocktailSort(std::ofstream &file) {
    int* tab100 = drawNumbers(100);
    int* tab1000 = drawNumbers(1000);
    int* tab1000000 = drawNumbers(1000000);

    CTablica sort;

    file << "cocktailSort  100     liczby losowe" << sort.cocktailSort(tab100,100);
    file << "cocktailSort  1000    liczby losowe" << sort.cocktailSort(tab1000,1000);
    file << "cocktailSort  1000000 liczby losowe" << sort.cocktailSort(tab1000000,100000);

    file << "\n";

    file << "cocktailSort  100     liczby uporzadkowane" << sort.cocktailSort(tab100,100);
    file << "cocktailSort  1000    liczby uporzadkowane" << sort.cocktailSort(tab1000,1000);
    file << "cocktailSort  1000000 liczby uporzadkowane" << sort.cocktailSort(tab1000000,100000);

    file << "\n";

    file << "cocktailSort  100     liczby odwrotnie uporzadkowane" << sort.cocktailSort(tab100,100,false);
    file << "cocktailSort  1000    liczby odwrotnie uporzadkowane" << sort.cocktailSort(tab1000,1000,false);
    file << "cocktailSort  1000000 liczby odwrotnie uporzadkowane" << sort.cocktailSort(tab1000000,100000,false);

    file << "\n";

    // 10% na zlej pozycji
    sort.cocktailSort(tab100,0.10*100,true,false);
    sort.cocktailSort(tab1000,0.10*1000,true,false);
    sort.cocktailSort(tab1000000,0.10*10000,true,false);

    file << "cocktailSort  100     liczby prawie posortowane" << sort.cocktailSort(tab100,100,false);
    file << "cocktailSort  1000    liczby prawie posortowane" << sort.cocktailSort(tab1000,1000,false);
    file << "cocktailSort  1000000 liczby prawie posortowane" << sort.cocktailSort(tab1000000,100000,false);
    file << "\n";
}

void CSortTablicy::ilustrateLomutoSort(std::ofstream &file) {
    int* tab100 = drawNumbers(100);
    int* tab1000 = drawNumbers(1000);
    int* tab1000000 = drawNumbers(1000000);

    unsigned long long p = 0, s = 0;
    CTablica sort;
    
    file << "LomutoSort  100     liczby losowe" ; file << sort.Lomuto(tab100, 0, 100-1,p,s ); p=0;s=0;
    file << "LomutoSort  1000    liczby losowe" ; file <<  sort.Lomuto(tab1000, 0, 1000-1, p,s);p=0;s=0;
    file << "LomutoSort  1000000 liczby losowe" ; file << sort.Lomuto(tab1000000, 0, 100000-1, p,s);p=0;s=0;

    file << "\n";

    file << "LomutoSort  100     liczby uporzadkowane" ; file << sort.Lomuto(tab100, 0, 100-1,p,s ); p=0;s=0;
    file << "LomutoSort  1000    liczby uporzadkowane" ; file << sort.Lomuto(tab1000, 0, 1000-1, p,s);p=0;s=0;
    // file << "LomutoSort  1000000 liczby uporzadkowane" ; file << sort.Lomuto(tab1000000, 0, 10000-1, p,s);p=0;s=0;

    file << "\n";

    sort.cocktailSort(tab100,100,false,false);
    sort.cocktailSort(tab1000,1000,false,false);
    sort.cocktailSort(tab1000000,10000,false,false);

    file << "LomutoSort  100     liczby uporzadkowane odwrotnie" ; file << sort.Lomuto(tab100, 0, 100-1,p,s ); p=0;s=0;
    file << "LomutoSort  1000    liczby uporzadkowane odwrotnie" ; file << sort.Lomuto(tab1000, 0, 1000-1, p,s);p=0;s=0;
    file << "LomutoSort  1000000 liczby uporzadkowane odwrotnie" ; file << sort.Lomuto(tab1000000, 0, 10000-1, p,s);p=0;s=0;

    file << "\n";

    // 10% na zlej pozycji
    sort.cocktailSort(tab100,0.10*100,false,false);
    sort.cocktailSort(tab1000,0.10*1000,false,false);
    sort.cocktailSort(tab1000000,0.10*10000,false,false);

    file << "LomutoSort  100     liczby prawie posortowane" ; file << sort.Lomuto(tab100, 0, 100-1,p,s ); p=0;s=0;
    file << "LomutoSort  1000    liczby prawie posortowane" ; file << sort.Lomuto(tab1000, 0, 1000-1, p,s);p=0;s=0;
    // file << "LomutoSort  1000000 liczby prawie posortowane" ; file << sort.Lomuto(tab1000000, 0, 10000-1, p,s);p=0;s=0;

    file << "\n";
}

void CSortTablicy::ilustrateHeapSort(std::ofstream &file) {
    int* tab100 = drawNumbers(100);
    int* tab1000 = drawNumbers(1000);
    int* tab1000000 = drawNumbers(1000000);

    unsigned long long p = 0, s = 0;
    CTablica sort;
    
    file << "HeapSort  100     liczby losowe" ; file << sort.Heap(tab100,100,p,s); p=0;s=0;
    file << "HeapSort  1000    liczby losowe" ; file <<  sort.Heap(tab1000,1000-1, p,s);p=0;s=0;
    file << "HeapSort  1000000 liczby losowe" ; file << sort.Heap(tab1000000,100000-1, p,s);p=0;s=0;

    file << "\n";

    file << "HeapSort  100     liczby uporzadkowane" ; file << sort.Heap(tab100,100-1,p,s ); p=0;s=0;
    file << "HeapSort  1000    liczby uporzadkowane" ; file << sort.Heap(tab1000, 1000-1, p,s);p=0;s=0;
    file << "HeapSort  1000000 liczby uporzadkowane" ; file << sort.Heap(tab1000000, 100000-1, p,s);p=0;s=0;

    file << "\n";

    sort.cocktailSort(tab100,100,false,false);
    sort.cocktailSort(tab1000,1000,false,false);
    sort.cocktailSort(tab1000000,10000,false,false);

    file << "HeapSort  100     liczby uporzadkowane odwrotnie" ; file << sort.Heap(tab100,100-1,p,s ); p=0;s=0;
    file << "HeapSort  1000    liczby uporzadkowane odwrotnie" ; file << sort.Heap(tab1000, 1000-1, p,s);p=0;s=0;
    file << "HeapSort  1000000 liczby uporzadkowane odwrotnie" ; file << sort.Heap(tab1000000, 100000-1, p,s);p=0;s=0;

    file << "\n";

    // 10% na zlej pozycji
    sort.cocktailSort(tab100,0.10*100,false,false);
    sort.cocktailSort(tab1000,0.10*1000,false,false);
    sort.cocktailSort(tab1000000,0.10*10000,false,false);

    file << "HeapSort  100     liczby prawie posortowane" ; file << sort.Heap(tab100,100-1,p,s ); p=0;s=0;
    file << "HeapSort  1000    liczby prawie posortowane" ; file << sort.Heap(tab1000, 1000-1, p,s);p=0;s=0;
    file << "HeapSort  1000000 liczby prawie posortowane" ; file << sort.Heap(tab1000000, 100000-1, p,s);p=0;s=0;

    file << "\n";
}

void CSortTablicy::ilustrateHoareSort(std::ofstream &file) {
    int* tab100 = drawNumbers(100);
    int* tab1000 = drawNumbers(1000);
    int* tab1000000 = drawNumbers(1000000);
    
    unsigned long long p = 0, s = 0;
    CTablica sort;
    
    file << "HoareSort  100     liczby losowe" ; file << sort.Hoare(tab100,0,100-1,p,s); p=0;s=0;
    file << "HoareSort  1000    liczby losowe" ; file << sort.Hoare(tab1000,0,1000-1,p,s); p=0;s=0;
    file << "HoareSort  1000000 liczby losowe" ; file << sort.Hoare(tab1000000,0,1000-1,p,s); p=0;s=0;

    file << "\n";

    file << "HoareSort  100     liczby uporzadkowane" ; file << sort.Hoare(tab100,0,100-1,p,s ); p=0;s=0;
    file << "HoareSort  1000    liczby uporzadkowane" ; file << sort.Hoare(tab1000,0, 1000-1, p,s);p=0;s=0;
    file << "HoareSort  1000000 liczby uporzadkowane" ; file << sort.Hoare(tab1000000,0, 100000-1, p,s);p=0;s=0;

    file << "\n";

    sort.cocktailSort(tab100,100,false,false);
    sort.cocktailSort(tab1000,1000,false,false);
    sort.cocktailSort(tab1000000,10000,false,false);

    file << "HoareSort  100     liczby uporzadkowane odwrotnie" ; file << sort.Hoare(tab100,0,100-1,p,s ); p=0;s=0;
    file << "HoareSort  1000    liczby uporzadkowane odwrotnie" ; file << sort.Hoare(tab1000,0, 1000-1, p,s);p=0;s=0;
    file << "HoareSort  1000000 liczby uporzadkowane odwrotnie" ; file << sort.Hoare(tab1000000, 0,10000-1, p,s);p=0;s=0;

    file << "\n";

    // 10% na zlej pozycji
    sort.cocktailSort(tab100,0.10*100,false,false);
    sort.cocktailSort(tab1000,0.10*1000,false,false);
    sort.cocktailSort(tab1000000,0.10*10000,false,false);

    file << "HoareSort  100     liczby prawie posortowane" ; file << sort.Hoare(tab100,0,100-1,p,s ); p=0;s=0;
    file << "HoareSort  1000    liczby prawie posortowane" ; file << sort.Hoare(tab1000,0, 1000-1, p,s);p=0;s=0;
    file << "HoareSort  1000000 liczby prawie posortowane" ; file << sort.Hoare(tab1000000,0, 10000-1, p,s);p=0;s=0;

    file << "\n";
}