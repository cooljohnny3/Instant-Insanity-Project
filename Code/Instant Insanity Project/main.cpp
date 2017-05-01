#include "Insanity.h"
#include <iostream>

int main(){
    Insanity game = Insanity("Threads.txt");
    //game.printCubes();
    
    std::vector<int> obstacle = game.obstacle();

    for(int i = 0; i < obstacle.size(); i++){
        std::cout << obstacle[i] << " ";
    }

    std::cout << std::endl;
	system("pause");
    return 0;
}