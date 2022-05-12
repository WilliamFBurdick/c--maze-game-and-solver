
mazerunner: main.o Player.o Screen.o Solver.o
	g++ main.o Player.o Screen.o Solver.o -o mazerunner

main: main.cpp Player.h Solver.h Screen.h
	g++ -c main.cpp

Player.o: Player.cpp Player.h Screen.o Stack.h Node.h
	g++ -c Player.cpp

Solver.o: Solver.cpp Solver.h Screen.o Stack.h Node.h
	g++ -c Solver.cpp

Screen.o: Screen.cpp Screen.h
	g++ -c Screen.cpp

clean:
	rm -f mazerunner *.o *.h.gch