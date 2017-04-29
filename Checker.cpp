#include "Checker.h"

Checker::Checker(){}

Checker::Checker(Cube c[], std::vector<int> &s){
    set = s;
    cubes = c;
}

bool Checker::makeThreads(){
    return makeThread1(1, 1);
}

bool Checker::makeThread1(int side, int cube){
    if(!checkThread(side, cube))
        return false;
    if(side > 3)
        retrun false;
    if(cube > set.size())
        return true;
    return makeThread1(1, cube+1);
}

bool Checker::makeThread2(int side, int cube){
    if(!checkThread(side, cube) || side > 3 || cube > set.size())
        return false;
    return true;
}

/*
checks to see if the side can be added to the thread
if false then return false
else count for the respecitve number is increased and return true
*/
bool Checker::checkThread(int s, int c){
    Cube cube = cubes[c];
    Thread side = cube.getThread(s);

    if(count[side.getSide1()] + 1 > 2 || count[side.getSide2()] + 1 > 2)
        return false;

    else{
        count[side.getSide1()]++;
        count[side.getSide2()]++;
        return true;
    }
}
