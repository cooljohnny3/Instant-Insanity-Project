#include "Cube.h"
#include <string>

Cube::Cube(){
    thread1 = Thread();
    thread2 = Thread();
    thread3 = Thread();
}

Cube::Cube(Thread pair1, Thread pair2, Thread pair3){
   thread1 = pair1;
   thread2 = pair2;
   thread3 = pair3; 
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
            return Thread(0, 0);
    }
} 