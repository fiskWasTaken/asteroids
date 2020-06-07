#pragma once

#include <particles/ParticleSystem.h>
#include "Actor.h"

/**
 * TemporaryParticle will clean itself up once the amount of particles in the system drops to 0
 */
class TemporaryParticle : public Actor
{
private:
  ParticleSystem *particle;

public:
  explicit TemporaryParticle(WorldInterface *world, ParticleSystem *particle) : Actor(world)
  {
    this->particle = particle;
  }

  void update() override {};
  
  bool isRecyclable() override
  {
    return particle->getCount() == 0;
  }

  void renderTo(sf::RenderWindow *renderWindow) override
  {
    particle->remove();
    particle->update();
    particle->render();

    auto sprite = particle->getSprite();
    sprite.setPosition(pos.x - 64, pos.y - 64);
    renderWindow->draw(sprite);
  }

  ~TemporaryParticle() override
  {
    delete particle;
  }
};
