Project: main.o Insanity.o Cube.o Thread.o
	g++ -o Project main.o Insanity.o Cube.o Thread.o
	make clean
	
main.o: main.cpp Insanity.h
	g++ -c main.cpp

insanity.o: Insanity.cpp Insanity.h
	g++ -c Insanity.cpp

cube.o: Cube.cpp Cube.h
	g++ -c Cube.cpp

thread.o: Thread.cpp Thread.h
	g++ -c Thread.cpp

clean:
	rm *.o 