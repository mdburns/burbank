#include <iostream>

#include "World.h"
#include "print.h"

int main( int argc, char **argv ) {
  World w = new World( 5 );
  print::print(w);
  return 0;
}
