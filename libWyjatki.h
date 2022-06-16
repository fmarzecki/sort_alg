#pragma once
#include <fstream>
#include <exception>
#include <string>
using namespace std;

namespace MyRuntimeExceptions
{
    class FileOpenException : public std::runtime_error
    {
    public:
        FileOpenException() : runtime_error("Nie mozna otworzyc pliku"){}
        FileOpenException(std::string msg) : runtime_error(msg.c_str()){}
    };

    class SizeException : public std::runtime_error
    {
    public:
        SizeException() : runtime_error("Rozmiary tablic sie nie zgadzaja.") {}
    };
}

/*
 * Otwiera plik do odczytu
 * @param filename nazwa pliku do otwarcia
 * @param out referencja na strumień wejścia
 */
void openIFileStream(std::string filename, std::ofstream &in);

/*
* sprawdza czy wymiary tablic sie zgadzaja
* @param size - rozmiar tablicy znakow
* @param sizeFreq rozmiar tablicy czestotliwosci
*/
void checkSizes(int size, int sizeFreq);