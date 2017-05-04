#pragma once

#include "Cube.h"
#include <vector>

class LibraryChecker {
private:
	std::vector<Cube> set; //list of cubes
	std::vector<std::vector<Thread>*> threads; //list of all threads
	std::vector<int> count; //count for thread

public:
	LibraryChecker();
	LibraryChecker(std::vector<Cube>);
	void printList();
	void makeThreads();
	void makeHelper(std::vector<Thread>, int, int);
	bool checkThreads();
	bool checkThread(int, int);
	void undoThread(int, int);
};