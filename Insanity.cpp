#include "Insanity.h"
#include <iostream>
#include <algorithm>
#include <fstream>
#include <sstream>

Insanity::Insanity() {}

Insanity::Insanity(std::string name){
    std::fstream f;
    std::string line;
    int  values[6];
    f.open(name, std::ios::in);

    for(int i = 0; i < 5; i++){
        std::getline(f, line);
        std::istringstream iss(line);
        for(int j = 0; j < 6; j++){
            iss >> values[j];
        }
        cubes[i] = Cube(Thread(values[0],  values[1]), Thread(values[2],  values[3]), Thread(values[4],  values[5])); 
    }
    f.close();
    
}

void Insanity::printCubes(){
   for(int i = 0; i < 5; i++){
        for(int t = 1; t <= 3; t++)
            std::cout << cubes[i].getThread(t).getSide1() << "-" << cubes[i].getThread(t).getSide2() << " ";
        std::cout << std::endl;
    }
}

/*
Finds the smallest obstacle if it exists by checking all combinations of cubes
*/
std::vector<int> Insanity::obstacle(){
    int n = 5;
    std::vector<int> listy;
    std::vector<bool> v(n);

    for(int r = 2; r <= n; n++){
        std::fill(v.begin(), v.begin() + r, true);
        do {
            for (int i = 0; i < n; ++i) {
                if (v[i]) {
                    listy.push_back(i+1);
                }
            }
            if(!checkSet(listy))
                return listy;
            
            listy.clear();
        } while (std::prev_permutation(v.begin(), v.end()));
    }
    return listy;
}

/*
Checks a vector containing cube numbers to see if it is an obstacle
Returns true if not an obstacle

go through and try to make 2 threads systematically
if can make 2 threads then not obstacle
else return set
*/
bool Insanity::checkSet(std::vector<int> &set){
    //cubes
    for(int i = 0; i < set.size; i++){
        //threads
        for(int j = 0; j < 3; j++){
            
        }
    }
    return false;
}
