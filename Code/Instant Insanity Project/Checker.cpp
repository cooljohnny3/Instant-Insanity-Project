#include "Checker.h"
#include <iostream>
#include <algorithm>

Checker::Checker(){}

Checker::Checker(std::vector<Cube> s){
    set = s;
    count1 = std::vector<int>(32);
    count2 = std::vector<int>(32);
	used = std::vector<std::vector<bool>>(3, std::vector<bool>(32));
}

bool Checker::makeThreads(){
	return makeThread1(1, 0) || makeThread1(2, 0) || makeThread1(3,0);
}

bool Checker::makeThread1(int side, int cube){
    if(cube >= set.size()){ //finished threads
		return true;
    }

	//std::cout << "1 " << set[cube].getThread(side).getSide1() << "-" << set[cube].getThread(side).getSide2() << std::endl;

    if(!checkThread1(side, cube)){ //check counts
        //std::cout << "Count1 too high" << std::endl;
        return false;
    }

    used[side-1][cube] = true; //mark side as used

	if (makeThread2(1, cube) || makeThread2(2, cube) || makeThread2(3, cube)) { // if can add 2nd thread
		if (makeThread1(1, cube + 1) || makeThread1(2, cube + 1) || makeThread1(3, cube + 1)) // if can make rest of first thread
			return true;
	}

	used[side - 1][cube] = false; // mark side as unused
	undoThread1(side, cube); // undo count
	return false;
}

bool Checker::makeThread2(int side, int cube){
	//std::cout << "2 " << set[cube].getThread(side).getSide1() << "-" << set[cube].getThread(side).getSide2() << std::endl;

	bool check = checkThread2(side, cube);
	bool use = used[side - 1][cube];
	
	if (check && !use) //if not used and count ok true
		return true;

	//if (use)
		//std::cout << "Already used" << std::endl;

	//else if (!check)
		//std::cout << "Count2 too high" << std::endl;

	undoThread2(side, cube);
	return false;
}

/*
checks to see if the side can be added to the thread
if false then return false
else count for the respecitve number is increased and return true
*/
bool Checker::checkThread1(int s, int c){
	Thread side = set[c].getThread(s);

    if(count1[side.getSide1()-1] + 1 > 2 || count1[side.getSide2()-1] + 1 > 2)
        return false;
    else{
        count1[side.getSide1()-1]++;
        count1[side.getSide2()-1]++;
        return true;
    }
}

bool Checker::checkThread2(int s, int c){
    Thread side = set[c].getThread(s);

    if(count2[side.getSide1()-1] + 1 > 2 || count2[side.getSide2()-1] + 1 > 2)
        return false;

    else{
        count2[side.getSide1()-1]++;
        count2[side.getSide2()-1]++;
        return true;
    }
}

void Checker::undoThread1(int s, int c){
	Thread side = set[c].getThread(s);

	count1[side.getSide1() - 1]--;
	count1[side.getSide2() - 1]--;
}

void Checker::undoThread2(int s, int c){
	Thread side = set[c].getThread(s);

	count2[side.getSide1() - 1]--;
	count2[side.getSide2() - 1]--;
}
