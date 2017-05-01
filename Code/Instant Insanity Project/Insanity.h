#ifndef INSANITY_H
#define INSANITY_H

#include "Cube.h"
#include <string>
#include <vector>
#include <set>

class Insanity{
private:
    static const int size = 32;
    Cube cubes[size];
	std::set<std::vector<int>> checked;

public:
    Insanity();
    Insanity(std::string);
    void printCubes();
    std::vector<int> obstacle();
    bool checkSet(std::vector<int>&);
};
#endif