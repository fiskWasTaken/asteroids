#pragma once

#include <particles/ParticleInterface.h>
#include "AbstractWorldObject.h"

class ParticleEmitter : public AbstractWorldObject {
 private:
  ParticleInterface particle;

 public:
  explicit ParticleEmitter(WorldInterface *world, ParticleInterface particle) : AbstractWorldObject(world) {
    this->particle = particle;
  }

  void update() override;
  bool isRecyclable() override;
  void renderTo(sf::RenderWindow *renderWindow) override;
};


