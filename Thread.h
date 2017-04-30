#ifndef THREAD_H
#define THREAD_H

class Thread{
private:
        int side1;
        int side2;
        bool used;

public:
        Thread();
        Thread(int, int);
        int getSide1();
        int getSide2();
        bool isUsed();
        void flip();
};
#endif