#include "Cube.h"
#include <string>
#include <vector>

class Insanity{
private:
    Cube cubes[32];

public:
    Insanity();
    Insanity(std::string);
    void printCubes();
    std::vector<int> obstacle();
    bool checkSet(std::vector<int>&);
};