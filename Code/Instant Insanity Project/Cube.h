#pragma once

#include "Thread.h"

class Cube{
private:
	float average;
    Thread thread1;
    Thread thread2;
    Thread thread3;

public:
    Cube();
    Cube(Thread, Thread, Thread);
    Thread getThread(int);
	float calcAverage();
	bool operator<(const Cube &cube2);
};
