#ifndef CHECKER_H
#define CHECKER_H

#include "Cube.h"
#include <vector>

class Checker{
private:
    std::vector<int> count1; //count or first thread
    std::vector<int> count2; //count for second thread
    std::vector<int> set; //list of cube numbers
    Cube *cubes; //reference to cubes

public:
    Checker();
    Checker(Cube[], std::vector<int>&);
    void printCubes();
    void printSet();
    bool makeThreads();
    bool makeThread1(int, int);
    bool makeThread2(int, int);
    bool checkThread1(int, int);
    bool checkThread2(int, int);
    void undoThread1(int, int);
    void undoThread2(int, int);
};
#endif