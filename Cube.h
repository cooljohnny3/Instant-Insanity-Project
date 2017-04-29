#include "Thread.h"

#ifndef CUBE_H
#define CUBE_H

class Cube{
private:
    Thread thread1;
    Thread thread2;
    Thread thread3;

public:
    Cube();
    Cube(Thread, Thread, Thread);
    Thread getThread(int);    
};
#endif