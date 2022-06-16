#include "libWyjatki.h"
void openIFileStream(std::string filename, std::ofstream &in)
{
    in.open(filename.c_str());
    if (!in.good())
    {
        throw MyRuntimeExceptions::FileOpenException("Nie mozna otworzyc pliku wejsciowego");
    }
}


void checkSizes(int size, int sizeFreq) {

    if (size!=sizeFreq) {
        throw MyRuntimeExceptions::SizeException();
    }

}
