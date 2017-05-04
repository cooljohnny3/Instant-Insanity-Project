Project: main.o Insanity.o Cube.o Thread.o Checker.o LibraryChecker.o
	g++ -o Project main.o Insanity.o Cube.o Thread.o Checker.o LibraryChecker.o
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

libraryChecker.o: libraryChecker.cpp libraryChecker.h
	g++ -c LibraryChecker.cpp

clean:
	rm *.o 