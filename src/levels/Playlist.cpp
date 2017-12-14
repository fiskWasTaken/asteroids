#include "Playlist.h"

void Playlist::init() {
  // todo: move all this to an external config file

  levels[0].name = "Level 1";
  levels[0].small_asteroid_count = 3;
  levels[0].medium_asteroid_count = 3;
  levels[0].large_asteroid_count = 0;
  levels[0].huge_asteroid_count = 0;

  levels[1].name = "Level 2";
  levels[1].small_asteroid_count = 3;
  levels[1].medium_asteroid_count = 3;
  levels[1].large_asteroid_count = 1;
  levels[1].huge_asteroid_count = 0;

  levels[2].name = "Level 3";
  levels[2].small_asteroid_count = 3;
  levels[2].medium_asteroid_count = 3;
  levels[2].large_asteroid_count = 3;
  levels[2].huge_asteroid_count = 0;

  levels[3].name = "Level 4";
  levels[3].small_asteroid_count = 3;
  levels[3].medium_asteroid_count = 3;
  levels[3].large_asteroid_count = 5;
  levels[3].huge_asteroid_count = 0;
}
