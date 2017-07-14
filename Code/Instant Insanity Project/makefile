Project: main.o Insanity.o Cube.o Thread.o Checker.o
	g++ -std=c++11 -pthread -o Project main.o Insanity.o Cube.o Thread.o Checker.o
	make clean
	
main.o: main.cpp Insanity.h
	g++ -c main.cpp

insanity.o: Insanity.cpp Insanity.h
	g++ -c Insanity.cpp

cube.o: Cube.cpp Cube.h
	g++ -c Cube.cpp

thread.o: Thread.cpp Thread.h
	g++ -c Thread.cpp

checker.o: Checker.cpp Checker.h
	g++ -c Checker.cpp

clean:
	rm *.o 