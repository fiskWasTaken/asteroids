#include "TemporaryParticle.h"

void TemporaryParticle::update() {

}

bool TemporaryParticle::isRecyclable() {
  return particle->getCount() == 0;
}

void TemporaryParticle::renderTo(sf::RenderWindow *renderWindow) {
  particle->remove();
  particle->update();
  particle->render();

  auto sprite = particle->getSprite();
  sprite.setPosition(pos.x - 64, pos.y - 64);
  renderWindow->draw(sprite);
}

TemporaryParticle::~TemporaryParticle() {
  delete particle;
}
