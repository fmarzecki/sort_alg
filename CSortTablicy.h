#pragma once
#include <iostream>
#include <climits>
#include <random>


class CSortTablicy {
    public:

    int* insertElements(int size);
    int* drawNumbers(int size);
    void ilustrateMethods();
};

template <typename T>
T sprawdzLiczbe()
{
	T liczba;
	int ok, podglad;
	do
	{
		ok = 1;
		std::cin >> liczba;
		if (std::cin.fail())                    //jesli wczytanie sie nie powiodlo
		{
			ok = 0;
			std::cin.clear();                   //czysci flage bledu strumienia
			std::cin.ignore(INT_MAX, '\n');     //usuwa wszystkie znaki z buforu strumienia a� do napotkania znaku '\n' 

		}
		else
		{
			while ((podglad = std::cin.get()) != '\n')  //cin.get() - pobierz znak ze strumienia 
			{
				if (podglad != ' ')            // Szukanie zb�dnych danych w strumieniu
				{
					ok = 0;
					std::cin.ignore(INT_MAX, '\n'); // czyszczenie strumienia
					break;
				}
			}
		}
		if (ok == 0) std::cout << "\n Nie podano wlasciwego typu danych. Sprobuj wpisac ponownie...\n\n ";
	} while (ok == 0);
	return liczba;
}





