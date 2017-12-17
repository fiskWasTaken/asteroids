#include "ParticleEmitter.h"

void ParticleEmitter::update() {

}

bool ParticleEmitter::isRecyclable() {
  return particle->getCount() == 0;
}

void ParticleEmitter::renderTo(sf::RenderWindow *renderWindow) {
  particle->remove();
  particle->update();
  particle->render();

  auto sprite = particle->getSprite();
  sprite.setPosition(pos.x - 64, pos.y - 64);
  renderWindow->draw(sprite);
}

ParticleEmitter::~ParticleEmitter() {
  delete particle;
}
