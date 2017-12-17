#include "ParticleSystem.h"
#include <sstream>

ParticleSystem::ParticleSystem(int width, int height) {
  transparent = sf::Color(0, 0, 0, 0);
  image.create(width, height, transparent);
  texture.loadFromImage(image);
  sprite = sf::Sprite(texture);
  pos.x = 0.5f * width;
  pos.y = 0.5f * height;
  particleSpeed = 20.0f;
  dissolve = false;
  dissolutionRate = 4;
  shape = Shape::CIRCLE;
  particles.reserve(1000);
}

ParticleSystem::~ParticleSystem() = default;

void ParticleSystem::fuel(int count) {
  float angle;
  for (int i = 0; i < count; i++) {
    auto particle = Particle();
    particle.pos.x = pos.x;
    particle.pos.y = pos.y;

    switch (shape) {
      case Shape::CIRCLE:angle = randomizer.rnd(0.0f, 6.2832f);
        particle.vel.x = randomizer.rnd(0.0f, std::cos(angle));
        particle.vel.y = randomizer.rnd(0.0f, std::sin(angle));
        break;
      case Shape::SQUARE:particle.vel.x = randomizer.rnd(-1.0f, 1.0f);
        particle.vel.y = randomizer.rnd(-1.0f, 1.0f);
        break;
      default:particle.vel.x = 0.5f; // Easily detected
        particle.vel.y = 0.5f; // Easily detected
    }

    if (particle.vel.x == 0.0f && particle.vel.y == 0.0f) {
      continue;
    }

    particle.color.r = static_cast<sf::Uint8>(randomizer.rnd(233, 255));
    particle.color.g = static_cast<sf::Uint8>(randomizer.rnd(147, 167));
    particle.color.b = static_cast<sf::Uint8>(randomizer.rnd(55, 77));
    particle.color.a = 255;
    particles.push_back(std::make_unique<Particle>(particle));
  }
}

void ParticleSystem::update() {
  float time = clock.restart().asSeconds();

  auto it = particles.begin();

  while (it != particles.end()) {
    (**it).vel.x += gravity.x * time;
    (**it).vel.y += gravity.y * time;

    (**it).pos.x += (**it).vel.x * time * particleSpeed;
    (**it).pos.y += (**it).vel.y * time * particleSpeed;

    if (dissolve) {
      (**it).color.a -= dissolutionRate;
    }

    if ((**it).pos.x > image.getSize().x || (**it).pos.x < 0 || (**it).pos.y > image.getSize().y || (**it).pos.y < 0
        || (**it).color.a < 10) {
      it = particles.erase(it);
    } else {
      ++it;
    }
  }
}

void ParticleSystem::render() {
  for (auto &particle : particles) {
    image.setPixel(
        static_cast<unsigned int>(particle->pos.x),
        static_cast<unsigned int>(particle->pos.y),
        particle->color
    );
  }
  texture.update(image);
}

void ParticleSystem::remove() {
  for (auto &particle : particles) {
    image.setPixel(
        static_cast<unsigned int>(particle->pos.x),
        static_cast<unsigned int>(particle->pos.y),
        transparent
    );
  }
}