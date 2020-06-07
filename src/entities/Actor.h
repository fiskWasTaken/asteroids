#pragma once

#include <SFML/Graphics/Shape.hpp>
#include <SFML/System/Vector2.hpp>
#include <utility>
#include <vector>

#include <entities/behaviours/Behaviour.h>
#include <world/WorldInterface.h>
#include "IActor.h"



class WorldInterface;

class Actor : public IActor {
 protected:
  WorldInterface *world;

 public:
  std::vector<Behaviour*> behaviours;

  virtual void update() = 0;
  virtual bool isRecyclable() = 0;

  virtual void onCollision(Actor *other) {}

  virtual ~Actor() {}

  explicit Actor(WorldInterface *world) {
    this->world = world;
    pos = sf::Vector2f(0, 0);
    vel = sf::Vector2f(0, 0);
    acc = sf::Vector2f(0, 0);
    rot = 0.0F;
  }
};
