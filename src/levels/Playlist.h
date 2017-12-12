#pragma once

#include "level_t.h"

class Playlist {
 private:
  level_t *levels;
  int pos = 0;

 public:
  void init();

  Playlist() {
    levels = new level_t[4];
    init();
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


