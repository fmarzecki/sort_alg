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

void CSortTablicy::ilustrateCocktailSort() {
    int* tab100 = drawNumbers(100);
    int* tab1000 = drawNumbers(1000);
    int* tab1000000 = drawNumbers(1000000);

    CTablica sort;

    std::cout << "cocktailSort  100     liczby losowe" ; sort.cocktailSort(tab100,100);
    std::cout << "cocktailSort  1000    liczby losowe" ; sort.cocktailSort(tab1000,1000);
    std::cout << "cocktailSort  1000000 liczby losowe" ; sort.cocktailSort(tab1000000,10000);

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
    std::cout << "\n";

}

void CSortTablicy::ilustrateLomutoSort() {
    int* tab100 = drawNumbers(100);
    int* tab1000 = drawNumbers(1000);
    int* tab1000000 = drawNumbers(1000000);

    long long p = 0, s = 0;
    CTablica sort;
    std::vector<int> wyniki;
    
    std::cout << "LomutoSort  100     liczby losowe" ; std::cout << sort.Lomuto(tab100, 0, 100-1,p,s ); p=0;s=0;
    std::cout << "LomutoSort  1000    liczby losowe" ; std::cout <<  sort.Lomuto(tab1000, 0, 1000-1, p,s);p=0;s=0;
    std::cout << "LomutoSort  1000000 liczby losowe" ; std::cout << sort.Lomuto(tab1000000, 0, 10000-1, p,s);p=0;s=0;

    std::cout << "\n";

    std::cout << "LomutoSort  100     liczby uporzadkowane" ; std::cout << sort.Lomuto(tab100, 0, 100-1,p,s ); p=0;s=0;
    std::cout << "LomutoSort  1000    liczby uporzadkowane" ; std::cout <<  sort.Lomuto(tab1000, 0, 1000-1, p,s);p=0;s=0;
    std::cout << "LomutoSort  1000000 liczby uporzadkowane" ; std::cout << sort.Lomuto(tab1000000, 0, 100-1, p,s);p=0;s=0;

    std::cout << "\n";

    sort.cocktailSort(tab100,100,false,false);
    sort.cocktailSort(tab1000,1000,false,false);
    sort.cocktailSort(tab1000000,10000,false,false);

    printTable<int>(tab100,100);

    std::cout << "LomutoSort  100     liczby uporzadkowane odwrotnie" ; std::cout << sort.Lomuto(tab100, 0, 100-1,p,s ); p=0;s=0;
    std::cout << "LomutoSort  1000    liczby uporzadkowane odwrotnie" ; std::cout << sort.Lomuto(tab1000, 0, 1000-1, p,s);p=0;s=0;
    std::cout << "LomutoSort  1000000 liczby uporzadkowane odwrotnie" ; std::cout << sort.Lomuto(tab1000000, 0, 100-1, p,s);p=0;s=0;

    std::cout << "\n";

    // // 10% na zlej pozycji
    // sort.cocktailSort(tab100,0.10*100,true,false);
    // sort.cocktailSort(tab1000,0.10*1000,true,false);
    // sort.cocktailSort(tab1000000,0.10*10000,true,false);

    // std::cout << "LomutoSort  100     liczby uporzadkowane" ; sort.Lomuto(tab100, 0, 100-1, wyniki);
    //     std::cout << " "<< wyniki[wyniki.size()-2] << " " << wyniki[wyniki.size()-1] << "\n";
    // std::cout << "LomutoSort  1000    liczby uporzadkowane" ; sort.Lomuto(tab1000, 0, 1000-1, wyniki);
    //     std::cout << " "<< wyniki[wyniki.size()-2] << " " << wyniki[wyniki.size()-1] << "\n";
    // std::cout << "LomutoSort  1000000 liczby uporzadkowane" ; sort.Lomuto(tab1000000, 0, 10000-1, wyniki);;
    //     std::cout << " "<< wyniki[wyniki.size()-2] << " " << wyniki[wyniki.size()-1] << "\n";

    std::cout << "\n";
}