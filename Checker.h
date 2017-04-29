#include "Cube.h"
#include <vector>

class Checker{
private:
    std::vector<int> count;
    std::vector<int> set;
    Cube *cubes;

public:
    Checker();
    Checker(Cube[], std::vector<int>&);
    bool makeThreads();
    bool makeThread1(int, int);
    bool makeThread2(int, int);
    bool checkThread(int, int);
};