#pragma once

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
	bool libraryCheckSet(std::vector<Cube>);
};