#include "Cube.h"
#include <string>
#include <vector>

class Insanity{
private:
    Cube cubes[5];

public:
    Insanity();
    Insanity(std::string);
    void printCubes();
    std::vector<int> obstacle();
    bool checkSet(std::vector<int>&);
};