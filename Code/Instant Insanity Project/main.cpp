#include "Insanity.h"
#include <iostream>

int main(){
    Insanity game = Insanity("Threads.txt");
    //game.printCubes();
    
    std::vector<Cube> obstacle = game.obstacle();

    for(int i = 0; i < obstacle.size(); i++){
        std::cout << obstacle[i].getThread(1).getSide1() + "-" << obstacle[i].getThread(1).getSide1() + " ";
		std::cout << obstacle[i].getThread(2).getSide1() + "-" << obstacle[i].getThread(2).getSide1() + " ";
		std::cout << obstacle[i].getThread(3).getSide1() + "-" << obstacle[i].getThread(3).getSide1() + " ";
		std::cout << std::endl;
    }

	system("pause");
    return 0;
}