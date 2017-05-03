#include "LibraryChecker.h"
#include <iostream>
#include <cmath>

LibraryChecker::LibraryChecker(){}

LibraryChecker::LibraryChecker(std::vector<Cube> s){
	set = s;
	count = std::vector<int>(32);
}

void LibraryChecker::printList(){
	std::cout << threads.size() << " number of threads." << std::endl;
	for (int i = 0; i < threads.size(); i++) {
		for (int j = 0; j < threads[i].size(); j++) {
			std::cout << threads[i][j].getSide1() << "-" << threads[i][j].getSide2() << std::endl;
		}
		std::cout << std::endl;
	}
}

void LibraryChecker::makeThreads(){
	std::vector<Thread> threadlist;
	makeHelper(threadlist, 1, 0);
	makeHelper(threadlist, 2, 0);
	makeHelper(threadlist, 3, 0);
}

void LibraryChecker::makeHelper(std::vector<Thread> listy, int side, int cube){
	if ((cube == set.size()-1) && checkThread(side, cube)) {
		listy.push_back(set[cube].getThread(side)); // add last pair
		threads.push_back(listy);
		undoThread(side, cube); // undo the double in the check
		return;
	}

	if (checkThread(side, cube)){
		listy.push_back(set[cube].getThread(side)); // add the working side pair to the thread being made
		makeHelper(listy, 1, cube + 1);
		undoThread(1, cube + 1); // undo the threads added with prev recursive call
		makeHelper(listy, 2, cube + 1);
		undoThread(2, cube + 1); // undo the threads added with prev recursive call
		makeHelper(listy, 3, cube + 1);
		undoThread(3, cube + 1); // undo the threads added with prev recursive call
		return;
	}
}

/*
checks the sets of threads to see if 2 do not share a pair
*/
bool LibraryChecker::checkThreads(){
	Thread temp1, temp2;

	printList();

	if (threads.size() == pow(3, set.size()))
		return true;

	if (threads.size() == 0) // not able to make any threads
		return false; // found obstacle

	for (int i = 0; i < threads.size() - 1; i++) { // iterate through thread lists
		for (int j = 0; j < threads[i].size(); j++) { // iterate through curent thread list
			temp1 = threads[i][j]; // Thread being checked

			for (int k = i+1; k < threads.size(); k++) { // iterate through the other lists
				for (int l = 0; true; l++) { // itterate through 2nd list
					if (l == threads[k].size())
						return true;
					temp2 = threads[k][l];
					if (temp1 == temp2)
						break;
				}
			}
		}
	}
	return false; // no 2 threads could be put together, found obstacle
}

bool LibraryChecker::checkThread(int s, int c){
	Thread side = set[c].getThread(s);

	if (count[side.getSide1() - 1] + 1 > 2 || count[side.getSide2() - 1] + 1 > 2)
		return false;
	else {
		count[side.getSide1() - 1]++;
		count[side.getSide2() - 1]++;
		return true;
	}
}

void LibraryChecker::undoThread(int s, int c){
	Thread side = set[c].getThread(s);

	count[side.getSide1() - 1]--;
	count[side.getSide2() - 1]--;
}
