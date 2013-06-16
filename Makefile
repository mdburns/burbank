CC = g++

CFLAGS = -g -Wall
OBJFILES = main.o

run: $(OBJFILES)
	$(CC) -o run $(OBJFILES)

main.o: main.cpp
	$(CC) -c main.cpp
