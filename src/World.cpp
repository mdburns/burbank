#include "World.h"
#include "constants.h"

World::World( int seed ) {
  // make the world
  _grid = new std::vector<WorldCoord>();

  for ( int i = 0; i < worldSize(); ++i ) {
    for ( int j = 0; j < worldSize(); ++j ) {
      _grid.add( new WorldCoord( i, j, 0.4f ) );
    }
  }
}

World::~World() {
  // delete the world
  delete _grid;
}

inline int World::worldSize() { return WORLD_SIZE; }

const WorldCoord& World::getCoord( int x, int y ) {
  return _grid[ ( y * WORLD_SIZE ) + x ];
}
