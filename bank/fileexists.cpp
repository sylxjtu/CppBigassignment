#include <iostream>
#include <fstream>

bool fileExists(const char *fileName)
{
    std::ifstream infile(fileName);
    return infile.good();
}
