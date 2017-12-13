#pragma once

#include "level_t.h"
#include <list>

class Playlist {
 private:
  const int LEVEL_COUNT = 4;
  level_t *levels;
  int pos = 0;

 public:
  void init();

  Playlist() {
    levels = new level_t[LEVEL_COUNT];
    init();
  }

  level_t getLevel() {
    return levels[pos];
  }

  bool next() {
    if (pos >= LEVEL_COUNT - 1)
      return false;

    pos++;
    return true;
  }

  bool prev() {
    if (pos <= 0)
      return false;

    pos--;
    return true;
  }

  bool rewind() {
    pos = 0;
  }
};


