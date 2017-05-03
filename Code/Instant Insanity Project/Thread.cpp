#include "Thread.h"
#include <iostream>

Thread::Thread(){
	id = 0;
    side1 = 0;
    side2 = 0;
}

Thread::Thread(int ID, int front, int back){
	id = ID;
    side1 = front;
    side2 = back;
}

int Thread::getSide1(){ return side1; }

int Thread::getSide2(){ return side2; }

bool Thread::operator==(Thread &t2){ return id == t2.id; }
