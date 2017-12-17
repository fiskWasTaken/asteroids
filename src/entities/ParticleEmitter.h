#pragma once

#include <particles/ParticleSystem.h>
#include "AbstractWorldObject.h"

class ParticleEmitter : public AbstractWorldObject {
 private:
  ParticleSystem *particle;

 public:
  explicit ParticleEmitter(WorldInterface *world, ParticleSystem *particle) : AbstractWorldObject(world) {
    this->particle = particle;
  }

  void update() override;
  bool isRecyclable() override;
  void renderTo(sf::RenderWindow *renderWindow) override;

  virtual ~ParticleEmitter();
};


