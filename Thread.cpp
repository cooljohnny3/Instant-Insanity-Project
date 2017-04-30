#include "Thread.h"

Thread::Thread(){
    side1 = 0;
    side2 = 0;
    used = false;
}

Thread::Thread(int front, int back){
    side1 = front;
    side2 = back;
    used =false;
}

int Thread::getSide1(){ return side1; }

int Thread::getSide2(){ return side2; }

bool Thread::isUsed(){ return used; }

void Thread::flip(){ used = !used; }