#ifndef INSANITY_H
#define INSANITY_H

#include "Cube.h"
#include <string>
#include <vector>

class Insanity{
private:
    std::vector<Cube> cubes;

public:
    Insanity();
    Insanity(std::string);
    void printCubes();
    std::vector<Cube> obstacle();
    bool checkSet(std::vector<Cube>);
};
#endif