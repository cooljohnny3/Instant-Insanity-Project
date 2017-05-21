#pragma once
#include "Cube.h"
#include <vector>

class Checker{
private:
	bool path;
    std::vector<int> count1; //count for first thread
    std::vector<int> count2; //count for second thread
    std::vector<Cube> set; //list of cubes
	std::vector<std::vector<bool>> used; //bools of threads used for thread1

public:
    Checker();
    Checker(std::vector<Cube>);
    bool makeThreads();
	void makeThread(int);
    bool makeThread1(int, int);
    bool makeThread2(int, int);
    bool checkThread1(int, int);
    bool checkThread2(int, int);
	void undoThread1(int, int);
	void undoThread2(int, int);
};