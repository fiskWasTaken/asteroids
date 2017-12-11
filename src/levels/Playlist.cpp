#include "Playlist.h"

void Playlist::init() {
  // todo: move all this to an external config file

  levels[0].name = "Level 1";
  levels[0].small_asteroid_count = 3;
  levels[0].medium_asteroid_count = 2;
  levels[0].large_asteroid_count = 0;

  levels[1] = {
      "Level 2",
      3,
      5,
      0
  };

  levels[2] = {
      "Level 3",
      3,
      2,
      1
  };
}
