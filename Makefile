date: date.cpp date.h
	g++ date.cpp -c -o date.o

database: date.h date.cpp database.cpp database.h
	g++ database.cpp -c -o database.o

main: date.o database.o date.h database.h
	g++ main.cpp -o main database.o date.o