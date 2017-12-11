#pragma once

#include "level_t.h"

class Playlist {
 private:
  level_t *levels;
  int pos = 0;

 public:
  void init();

  Playlist() {
    levels = new level_t[3];
    init();

    levels[0] = {
        "Level 1",
        0,
        2,
        3
    };

    levels[1] = {
        "Level 2",
        0,
        5,
        3
    };

    levels[2] = {
        "Level 3",
        1,
        2,
        3
    };
  }

  level_t getLevel() {
    return levels[pos];
  }

  bool next() {
    pos++;
    return true;
  }

  bool prev() {
    pos--;
    return true;
  }

  bool rewind() {
    pos = 0;
  }
};


