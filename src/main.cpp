#include <iostream>

#include "World.h"
#include "wprint.h"

int main( int argc, char **argv ) {
  World * w = new World(5);
  wprint::print( *w );
  return 0;
}
