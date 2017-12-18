#pragma once

#include <random>

class Randomizer {
 public:
  Randomizer() : device_(), engine_(device_()) {};
  int rnd(int a, int b) {
    std::uniform_int_distribution<int> uni_dist(a, b);
    return uni_dist(engine_);
  };
  float rnd(float a, float b) {
    std::uniform_real_distribution<double> uni_dist(a, b);
    return static_cast<float>(uni_dist(engine_));
  };
 private:
  std::random_device device_;
  std::default_random_engine engine_;
};