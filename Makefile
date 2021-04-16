event: event.h event.cpp
	g++ event.cpp -c -o event.o

date: date.cpp date.h
	g++ date.cpp -c -o date.o

database: date.h date.cpp database.cpp database.h event.h event.cpp
	g++ database.cpp -c -o database.o

main: date.o database.o event.o date.h database.h event.h
	g++ main.cpp -o main database.o date.o event.o