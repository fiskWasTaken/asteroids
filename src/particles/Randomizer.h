#pragma once

#include <random>

template <typename T>
class Randomizer {
 public:
  Randomizer() : device(), engine(device()) {};
  T rnd(T a, T b) {
    std::uniform_int_distribution<T> uni_dist(a, b);
    return uni_dist(engine);
  };
  
 private:
  std::random_device device;
  std::default_random_engine engine;
};