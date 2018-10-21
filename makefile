# Makefile de chevres
# créer à l'aide du tuto : https://gl.developpez.com/tutoriel/outil/makefile/



hello : gui.o  main.o
	g++ -o main gui.o main.o


gui.o : src/Interface/gui.cpp
	g++ -o gui.o -c src/Interface/gui.cpp -W -Wall 

main.o : src/main.cpp
	g++ -o main.o -c src/main.cpp -W -Wall
