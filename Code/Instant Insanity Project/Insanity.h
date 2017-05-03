#ifndef INSANITY_H
#define INSANITY_H

#include "Cube.h"
#include <string>
#include <vector>
#include <set>

class Insanity{
private:
    static const int size = 3;
    Cube cubes[size];
	std::set<std::vector<int>> checked;

public:
    Insanity();
    Insanity(std::string);
    void printCubes();
    std::vector<Cube> obstacle();
    bool checkSet(std::vector<Cube>);
};
#endif