Jeu : main.o position.o piece.o plateau.o
	g++  position.o piece.o plateau.o main.o -o Jeu

position.o : position.cpp position.h 
	g++ -c position.cpp 

piece.o : piece.cpp piece.h 
	g++ -c piece.cpp 

plateau.o : plateau.cpp plateau.h 
	g++ -c plateau.cpp 

main.o : main.cpp piece.h plateau.h position.h
	g++ -c main.cpp 

clean: 
	rm -rf *.o

