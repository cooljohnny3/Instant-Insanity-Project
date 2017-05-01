#include "Insanity.h"
#include "Checker.h"
#include <iostream>
#include <algorithm>
#include <fstream>
#include <sstream>

Insanity::Insanity() {}

Insanity::Insanity(std::string name){
    std::fstream f;
    std::string line;
    int  values[6];

    std::cout << "Reading cubes." << std::endl;
    f.open(name, std::ios::in);

    for(int i = 0; i < size; i++){
        std::getline(f, line);
        std::istringstream iss(line);
        for(int j = 0; j < 6; j++){
            iss >> values[j];
        }
        cubes[i] = Cube(Thread(values[0],  values[1]), Thread(values[2],  values[3]), Thread(values[4],  values[5])); 
    }
    f.close();
   std::cout << "Finished reading cubes." << std::endl; 
}

void Insanity::printCubes(){
   for(int i = 0; i < size; i++){
        for(int t = 1; t <= 3; t++)
            std::cout << cubes[i].getThread(t).getSide1() << "-" << cubes[i].getThread(t).getSide2() << " ";
        std::cout << std::endl;
    }
}

/*
Finds the smallest obstacle if it exists by checking all combinations of cubes
*/
std::vector<int> Insanity::obstacle(){
    int n = size;
    std::vector<int> listy;

    std::cout << "Finding obstacle..." << std::endl;

    for(int r = 2; r <= n; r++){
		std::vector<bool> v(n);
        std::fill(v.begin(), v.begin() + r, true);
        do {
            for (int i = 0; i < n; ++i) {
                if (v[i]) {
					std::cout << i+1 << " ";
                    listy.push_back(i+1);
                }
            }
			std::cout << "\n";

			
			if (!checkSet(listy)) {
				std::cout << "Done!" << std::endl;
				return listy;
			}
			checked.insert(listy); // set worked so add to checked
           
            listy.clear();
        } while (std::prev_permutation(v.begin(), v.end()));
    }
    std::cout << "Done!" << std::endl;
    return listy;
}

/*
Checks a vector containing cube numbers to see if they are an obstacle
Returns true if not an obstacle
*/
bool Insanity::checkSet(std::vector<int> &set){
	/*if (checked.insert(set).second == false){ // if already in set
		if(checkNewCube()) // check if able to add
			return true;
	}*/

    Checker c = Checker(cubes, set);	

    if(c.makeThreads())
        return true;
    return false;
}
