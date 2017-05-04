#pragma once

class Thread{
private:
	int id;
    int side1;
    int side2;

public:
    Thread();
    Thread(int, int, int);
    int getSide1();
    int getSide2();
	bool operator==(const Thread& t2) const;
};