#pragma once

#include <particles/ParticleSystem.h>
#include "AbstractWorldObject.h"

/**
 * TemporaryParticle will clean itself up once the amount of particles in the system drops to 0
 */
class TemporaryParticle : public AbstractWorldObject {
 private:
  ParticleSystem *particle;

 public:
  explicit TemporaryParticle(WorldInterface *world, ParticleSystem *particle);

  void update() override;
  bool isRecyclable() override;
  void renderTo(sf::RenderWindow *renderWindow) override;

  ~TemporaryParticle() override;
};


