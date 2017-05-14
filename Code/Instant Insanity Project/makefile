Project: main.o Insanity.o Cube.o Thread.o Checker.o
	g++ -std=c++11 -o Project main.o Insanity.o Cube.o Thread.o Checker.o
	make clean
	
main.o: main.cpp Insanity.h
	g++ -std=c++11 -c main.cpp

insanity.o: Insanity.cpp Insanity.h
	g++ -std=c++11 -c Insanity.cpp

cube.o: Cube.cpp Cube.h
	g++ -std=c++11 -c Cube.cpp

thread.o: Thread.cpp Thread.h
	g++ -std=c++11 -c Thread.cpp

checker.o: Checker.cpp Checker.h
	g++ -std=c++11 -c Checker.cpp

clean:
	rm *.o 