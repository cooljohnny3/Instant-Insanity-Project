#include "Insanity.h"
#include "Checker.h"
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

    std::cout << "Reading cubes." << std::endl;
    f.open(name, std::ios::in);

    for(int i = 0; i < cubes.size(); i++){
        std::getline(f, line);
        std::istringstream iss(line);
        for(int j = 0; j < 6; j++){
            iss >> values[j];
        }
        cubes[i] = Cube(Thread(values[0],  values[1]), Thread(values[2],  values[3]), Thread(values[4],  values[5])); 
    }
    f.close();
   std::cout << "Finished reading cubes." << std::endl; 

   std::cout << "Sorting cubes by averages..." << std::endl;
   std::sort(cubes.begin(), cubes.end()); // Sort cubes by average
   std::cout << "Done sorting" << std::endl;
}

void Insanity::printCubes(){
   for(int c = 0; c < cubes.size(); c++){
        for(int t = 1; t <= 3; t++)
            std::cout << cubes[c].getThread(t).getSide1() << "-" << cubes[c].getThread(t).getSide2() << " ";
        std::cout << std::endl;
    }
}

/*
Finds the smallest obstacle if it exists by checking all combinations of cubes
*/
std::vector<Cube> Insanity::obstacle(){
    int n = 2; //number to go to
    std::vector<Cube> listy;

    std::cout << "Finding obstacle..." << std::endl;

    for(int r = 2; r <= n; r++){
		std::vector<bool> v(n);
        std::fill(v.begin(), v.begin() + r, true);
        do {
            for (int i = 0; i < n; ++i) {
                if (v[i]) {
					std::cout << i+1 << " ";
                    listy.push_back(cubes[i]);
                }
            }
			std::cout << std::endl;

			
			if (!checkSet(listy)) {
				std::cout << "Obstacle found!" << std::endl;
				return listy;
			}
           
			std::cout << std::endl;
            listy.clear();
        } while (std::prev_permutation(v.begin(), v.end()));
    }
    std::cout << "Obstacle not found." << std::endl;
    return listy;
}

/*
Checks a vector containing cube numbers to see if they are an obstacle
Returns true if not an obstacle
*/
bool Insanity::checkSet(std::vector<Cube> set){
    Checker c = Checker(set);

    if(c.makeThreads())
        return true;
    return false;
}
