#include "Insanity.h"
#include <iostream>

int main(){
    Insanity game = Insanity("Threads.txt");
    
    std::vector<Cube> obstacle = game.obstacle();

	if (obstacle.size() > 0) {
		for (int i = 0; i < obstacle.size(); i++) {
			std::cout << obstacle[i].getThread(1).getSide1() << "-" << obstacle[i].getThread(1).getSide2() << " ";
			std::cout << obstacle[i].getThread(2).getSide1() << "-" << obstacle[i].getThread(2).getSide2() << " ";
			std::cout << obstacle[i].getThread(3).getSide1() << "-" << obstacle[i].getThread(3).getSide2() << " ";
			std::cout << std::endl;
		}
    }

	else
		std::cout << "No obstacle exists" << std::endl;

	system("pause");
    return 0;
}