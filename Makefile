CC = g++

CFLAGS = -g -Wall
BUILDDIR = build
SRCDIR = src
BINDIR = bin

OBJFILES = $(BUILDDIR)/main.o

run: $(OBJFILES)
	$(CC) -o $(BINDIR)/run $(OBJFILES)

main.o: $(SRCDIR)/main.cpp
	$(CC) -c $(SRCDIR)/main.cpp -o $(BUILDDIR)/main.o
