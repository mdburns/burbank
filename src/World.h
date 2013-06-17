/**
 * World - contains a grid of WorldCoord.
 */

#ifndef __WORLD_H__
#define __WORLD_H__

#include <vector>

#include "WorldCoord.h"

class World {
  public: 
    World( int seed );
    ~World();

    int worldSize();
    const WorldCoord& getCoord( int x, int y );

  private:
    std::vector<WorldCoord> *_grid;
};

#endif
