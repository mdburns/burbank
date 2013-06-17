/**
 * WorldCoord - a point in the world.
 * These are composed of the attributes of the world at that location
 * as well as a list of Agents and possibly an Entity.
 */

#ifndef __WORLDCOORD_H__
#define __WORLDCOORD_H__

#include "constants.h"

class WorldCoord {
  public:
    WorldCoord( int x, int y, float noise_value );
    virtual ~WorldCoord();

    hydration hydration_level;

  private:
    // coordinates
    int _x;
    int _y;
};

#endif
