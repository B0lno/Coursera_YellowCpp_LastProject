date: date.cpp date.h
	g++ date.cpp -c -o date.o

database: date.h date.cpp database.cpp database.h
	g++ database.cpp -c -o database.o