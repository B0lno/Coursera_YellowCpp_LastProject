token: token.h token.cpp
	g++ token.cpp -c -o token.o

node: node.h node.cpp
	g++ node.cpp -c -o node.o

condition_parser: token.h node.h node.o token.o
	g++ condition_parser.cpp -c -o condition_parser.o

event: event.h event.cpp
	g++ event.cpp -c -o event.o

date: date.cpp date.h
	g++ date.cpp -c -o date.o

database: date.h date.cpp database.cpp database.h event.h event.cpp
	g++ database.cpp -c -o database.o

main: date.o database.o event.o date.h database.h event.h
	g++ main.cpp -o main database.o date.o event.o