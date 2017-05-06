#include "Insanity.h"
#include "Checker.h"
#include "LibraryChecker.h"
#include <iostream>
#include <algorithm>
#include <fstream>
#include <sstream>

Insanity::Insanity() {}

Insanity::Insanity(std::string name){
	cubes = std::vector<Cube>(32); // initialize cubes vector

    std::fstream f;
    std::string line;
    int  values[6];
	int threadID = 0;

    std::cout << "Reading cubes." << std::endl;
    f.open(name, std::ios::in);

    for(int i = 0; i < cubes.size(); i++){
        std::getline(f, line);
        std::istringstream iss(line);
        for(int j = 0; j < 6; j++){
            iss >> values[j];
        }
        cubes[i] = Cube(Thread(threadID ,values[0],  values[1]), Thread(threadID + 1, values[2],  values[3]), Thread(threadID + 2, values[4],  values[5]));
		threadID += 3;
    }
    f.close();
   std::cout << "Finished reading cubes." << std::endl; 

   std::cout << "Sorting cubes by averages..." << std::endl;
   std::sort(cubes.begin(), cubes.end()); // Sort cubes by average
   std::cout << "Done sorting" << std::endl;

   //printCubes();
}

void Insanity::printCubes(){
   for(int c = 0; c < cubes.size(); c++){
	   std::cout << c << " ";
        for(int t = 1; t <= 3; t++)
            std::cout << cubes[c].getThread(t).getSide1() << "-" << cubes[c].getThread(t).getSide2() << " ";
        std::cout << std::endl;
    }
}

/*
Finds the smallest obstacle if it exists by checking all combinations of cubes
*/
std::vector<Cube> Insanity::obstacle(){
	int count;
    int n = SIZE, r = SIZE, lo = 0, hi = SIZE;
    std::vector<Cube> listy;
	std::vector<Cube> prevList;

	std::cout << "Checking inital set..." << std::endl;

	//if (checkSet(cubes)) // if no obstacle with all then no obstacle at all
		//return listy;

	std::cout << "Initial set has obstacle.\nProceeding to rest..." << std::endl;

	// loop generating and trying combinations
    while(r > lo){
		r = 8;//(hi - lo) / 2; 

		std::cout << r << std::endl;

		// generates combos for n,r
		count = 1;
		std::vector<bool> v(n);
        std::fill(v.begin(), v.begin() + r, true);
        do {
			if(count % 1000 == 0)
				std::cout << count << std::endl;

            for (int i = 0; i < n; ++i) {
                if (v[i]) {
					/*std::cout << cubes[i].getThread(1).getSide1() << "-" << cubes[i].getThread(1).getSide2() << " ";
					std::cout << cubes[i].getThread(2).getSide1() << "-" << cubes[i].getThread(2).getSide2() << " ";
					std::cout << cubes[i].getThread(3).getSide1() << "-" << cubes[i].getThread(3).getSide2() << " ";
					std::cout << std::endl;*/
                    listy.push_back(cubes[i]);
                }
            }

			//std::cout << std::endl;

			// use DFS for threads
			if (true) { 
				if (!checkSet(listy)) {
					prevList = listy;
					break;
				}
			}

			// use library for threads
			else {
				if (!libraryCheckSet(listy)) {
					prevList = listy;
					break;
				}
			}

			count++;
            listy.clear();
        } while (std::prev_permutation(v.begin(), v.end()));

		if (lo <= hi) { // found correct r
			std::cout << "Found initial obstacle" << std::endl;
			return finalPart(r);
		}

		else if (prevList == listy) // last list had obstacle
			lo = r + 1;

		else // last list didn't have obstacle
			hi = r - 1;
    }
}

std::vector<Cube> Insanity::finalPart(int r) {
	int n = SIZE;
	std::vector<Cube> listy;

	std::cout << n << "C" << r << std::endl;

	// generates combos for n,r
	std::vector<bool> v(n);
	std::fill(v.begin(), v.begin() + r, true);

	do {
		for (int i = 0; i < n; ++i) {
			if (v[i]) {
				listy.push_back(cubes[i]);
			}
		}

		//std::cout << std::endl;

		// use DFS for threads
		if (r < 15) {
			if (!checkSet(listy)) {
				std::cout << "Obstacle found!" << std::endl;
				return listy;
			}
		}

		// use library for threads
		else {
			if (!libraryCheckSet(listy)) {
				std::cout << "Obstacle found!" << std::endl;
				return listy;
			}
		}

		listy.clear();
	} while (std::prev_permutation(v.begin(), v.end()));
}

/*
Checks a vector containing cubes to see if they are an obstacle recursivly
Returns true if not an obstacle
*/
bool Insanity::checkSet(std::vector<Cube> set){
    Checker c = Checker(set);

	return c.makeThreads();
}

/*
Checks a vector containing cubes to see if they are an obstacle with library
Returns true if not an obstacle
*/
bool Insanity::libraryCheckSet(std::vector<Cube> set){
	LibraryChecker c = LibraryChecker(set);

	c.makeThreads();
	return c.checkThreads();
}
