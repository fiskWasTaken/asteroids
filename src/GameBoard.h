//
// Created by fisk on 19/09/17.
//

#ifndef SFML_SANDBOX_GAMEBOARD_H
#define SFML_SANDBOX_GAMEBOARD_H

#include <stdio.h>
#include <vector>
#include "GamePiece.h"

using namespace std;

class GameBoard {
 public:
  inline GameBoard(unsigned long width, unsigned long height) {
    vector< vector<GamePiece> > board(width);

    for (int i = 0; i < width; i++)
      board[i].resize(height);

    this->board = board;
  }

  inline long getWidth() const {
    return board.size();
  }

  inline long getHeight() const {
    return board.at(0).size();
  }

  inline GamePiece getPiece(unsigned long x, unsigned long y) {
    return board.at(x).at(y);
  }

  inline void setPiece(unsigned long x, unsigned long y, GamePiece gamePiece) {
    board[x][y] = gamePiece;
  }

  inline bool unsetPiece(unsigned long x, unsigned long y) {
//    board[x][y] = NULL;
    return true;
  }

 private:
  vector< vector<GamePiece> > board;
};

#endif //SFML_SANDBOX_GAMEBOARD_H
