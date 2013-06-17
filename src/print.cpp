#include "print.h"
#include "constants.h"

char wat_char = '#';
char wet_char = '$';
char dam_char = '%';
char dry_char = '=';
char des_char = ':';

char * GREEN = "\033[32m";
char * BLUE = "\033[34m";
char * BGREEN = "\033[42m";
char * YELLOW = "\033[33m";
char * BBLUE = "\033[44m";
char * BYELLOW = "\033[43m";

void print(World * w) {
  for(int y = 0; y < w.gridSize; ++y) {
    for(int x = 0; x < w.gridSize; ++x) {
      std::cout << stringOf(w.getCoord(x, y));
    }
    std::cout << std::endl;
  }
}

std::string stringOf(WorldCoord w) {
  switch(w.hydration_value) {
    case WATER:
        return (BBLUE + BLUE) + wat_char;
      break;
    case WET:
        return (BGREEN + BLUE) + wet_char;
      break;
    case DAMP:
        return (BGREEN + GREEN) + dam_char;
      break;
    case DRY:
        return (BGREEN + YELLOW) + dam_char;
      break;
    case DESERT:
        return (BYELLOW + YELLOW) + des_char;
      break;
  }
}
