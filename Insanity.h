#ifndef INSANITY_H
#define INSANITY_H

#include "Cube.h"
#include <string>
#include <vector>

class Insanity{
private:
    static const int size = 5;
    Cube cubes[size];

public:
    Insanity();
    Insanity(std::string);
    void printCubes();
    std::vector<int> obstacle();
    bool checkSet(std::vector<int>&);
};
#endif