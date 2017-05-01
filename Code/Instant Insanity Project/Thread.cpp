#include "Thread.h"
#include <iostream>

Thread::Thread(){
    side1 = 0;
    side2 = 0;
}

Thread::Thread(int front, int back){
    side1 = front;
    side2 = back;
}

int Thread::getSide1(){ return side1; }

int Thread::getSide2(){ return side2; }