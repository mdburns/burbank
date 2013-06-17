#ifndef __NOISE_H__
#define __NOISE_H__

#include "../burbank_types.h"

#define DEFAULT_OCTAVES 2
#define DEFAULT_DIMENSIONS 2

namespace noise {
  float perlin( v3f tl, v3f tr, v3f bl, v3f br, float x_pos, float y_pos,
      int octave = DEFAULT_OCTAVES, int dim = DEFAULT_DIMENSIONS );
}

#endif
