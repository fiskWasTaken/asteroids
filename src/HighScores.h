#pragma once

#include <string>
#include <vector>
#include <algorithm>

struct HighScore {
  std::string name;
  int score;
};

class HighScores {
 private:
  std::vector<HighScore> scores;

 public:
  HighScores() {
    scores.push_back((HighScore) {"fisk", 900});
    scores.push_back((HighScore) {"is", 800});
    scores.push_back((HighScore) {"not", 700});
    scores.push_back((HighScore) {"good", 600});
    scores.push_back((HighScore) {"at", 500});
    scores.push_back((HighScore) {"this", 400});
    scores.push_back((HighScore) {"sort", 300});
    scores.push_back((HighScore) {"of", 200});
    scores.push_back((HighScore) {"thing", 100});
    scores.push_back((HighScore) {"!!!", 50});

    sort();
  }

  const std::vector<HighScore> getScores() const {
    return scores;
  }

  void sort() {
  }
};