CC = g++

CFLAGS = -g -Wall
BUILDDIR = build
SRCDIR = src
BINDIR = bin

OBJFILES = $(BUILDDIR)/World.o $(BUILDDIR)/WorldCoord.o $(BUILDDIR)/wprint.o

run: $(OBJFILES)
	$(CC) -o $(BINDIR)/run $(OBJFILES) $(SRCDIR)/main.cpp

clean:
	rm -Rf build/* bin/run

$(BUILDDIR)/World.o: $(SRCDIR)/World.cpp
	$(CC) -c $(SRCDIR)/World.cpp -o $(BUILDDIR)/World.o

$(BUILDDIR)/WorldCoord.o: $(SRCDIR)/WorldCoord.cpp
	$(CC) -c $(SRCDIR)/WorldCoord.cpp -o $(BUILDDIR)/WorldCoord.o

$(BUILDDIR)/wprint.o: $(SRCDIR)/wprint.cpp
	$(CC) -c $(SRCDIR)/wprint.cpp -o $(BUILDDIR)/wprint.o
