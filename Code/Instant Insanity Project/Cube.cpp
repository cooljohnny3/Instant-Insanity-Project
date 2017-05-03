#include "Cube.h"
#include <string>

Cube::Cube(){
    thread1 = Thread();
    thread2 = Thread();
    thread3 = Thread();
	average = 0;
}

Cube::Cube(Thread pair1, Thread pair2, Thread pair3){
   thread1 = pair1;
   thread2 = pair2;
   thread3 = pair3; 
   average = calcAverage();
}


Thread Cube::getThread(int num){
    switch(num){
        case 1:
            return thread1;
        case 2:
            return thread2;
        case 3:
            return thread3;
        default:
            return Thread();
    }
} 

float Cube::calcAverage() {
	int t1 = thread1.getSide1() + thread1.getSide2();
	int t2 = thread2.getSide1() + thread2.getSide2();
	int t3 = thread3.getSide1() + thread3.getSide2();

	return (t1 + t2 + t3) / 3.0;
}

bool Cube::operator<(const Cube &cube2) {
	return average < cube2.average;
}