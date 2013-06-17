#include "WorldCoord.h"

WorldCoord::WorldCoord( int x, int y, float noise_value ) {
  _x = x;
  _y = y;

  hydration_level = ( noise_value < WATER_THRESHOLD ? WATER : DESERT );
} 

WorldCoord::~WorldCoord() {}
