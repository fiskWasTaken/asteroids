#pragma once

#include <vector>
#include <SFML/Window/Keyboard.hpp>
#include <levels/Playlist.h>
#include "GameInterface.h"
#include "player/PlayerSession.h"
#include "HighScores.h"

class Asteroids : public GameInterface {
 private:
  std::vector<PlayerSession *> *sessions;
  HighScores highScores;
  Playlist playlist;

 public:
  inline Asteroids() : GameInterface() {
    sessions = new std::vector<PlayerSession *>();
  }

  inline std::vector<PlayerSession *> *getSessions() const {
    return sessions;
  }

  void main() override;

  inline HighScores getHighScores() const {
    return highScores;
  }

  ControllerInterface *getDefaultKeyboardController();

  Playlist &getPlaylist();
  ControllerInterface *getDefaultJoystickController();
};
