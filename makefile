test.out: main.o bwindow.o vector.o environnement.o agent.o proie.o predateur.o
	g++ -o test.out main.o bwindow.o vector.o environnement.o agent.o proie.o predateur.o -lX11 -L/usr/X11R6/lib

main.o: main.cpp
	g++ -c main.cpp 

bwindow.o: bwindow.cpp bwindow.h
	g++ -c bwindow.cpp

vector.o: vector.h vector.cpp
	g++ -c vector.cpp -o vector.o 

environnement.o: environnement.h vector.h
	g++ -c environnement.cpp -o environnement.o	

agent.o: agent.h vector.h
	g++ -c agent.cpp -o agent.o 

proie.o: proie.h proie.cpp agent.h
	g++ -c proie.cpp -o proie.o

predateur.o: predateur.h predateur.cpp agent.h
	g++ -c predateur.cpp -o predateur.o 

clean :
	rm *.o *.out