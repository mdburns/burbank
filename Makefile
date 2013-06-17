CC = g++

CFLAGS = -g -Wall
BUILDDIR = build
SRCDIR = src
BINDIR = bin

OBJFILES = $(BUILDDIR)/main.o $(BUILDDIR)/World.o $(BUILDDIR)/WorldCoord.o $(BUILDDIR)/print.o

run: $(OBJFILES)
	$(CC) -o $(BINDIR)/run $(OBJFILES)

$(BUILDDIR)/main.o: $(SRCDIR)/main.cpp
	$(CC) -c $(SRCDIR)/main.cpp -o $(BUILDDIR)/main.o

$(BULDDIR)/World.o: $(SRCDIR)/World.cpp
	$(CC) -c $(SRCDIR)/World.cpp -o $(BUILDDIR)/WorldCoord.o

$(BULDDIR)/WorldCoord.o: $(SRCDIR)/WorldCoord.cpp
	$(CC) -c $(SRCDIR)/WorldCoord.cpp -o $(BUILDDIR)/WorldCoord.o

$(BULDDIR)/print.o: $(SRCDIR)/print.cpp
	$(CC) -c $(SRCDIR)/print.cpp -o $(BUILDDIR)/print.o
