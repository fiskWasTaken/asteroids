#pragma once

#include <SFML/System/Vector2.hpp>
#include <SFML/System/Clock.hpp>
#include <SFML/Graphics/Color.hpp>
#include <SFML/Graphics/Image.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/Texture.hpp>
#include <vector>
#include <random>
#include <memory>
#include "Randomizer.h"

namespace Shape
{
  enum
  {
    CIRCLE,
    SQUARE
  };
}

struct particle_t
{
  sf::Vector2f pos; // Position
  sf::Vector2f vel; // Velocity
  sf::Color color;  // RGBA
};

class ParticleSystem
{
private:
  sf::Clock clock; // Used to scale particle motion
  sf::Color transparent = sf::Color(0, 0, 0, 0);
  sf::Image image; // See render() and remove()
  sf::Texture texture;
  Randomizer<int> rand;
  sf::Sprite sprite; // Connected to image
  sf::Color color = sf::Color(255, 255, 255, 255);
  float particleSpeed = 20.0f;
  ;                      // Pixels per second (at most)
  bool dissolve = false; // Dissolution enabled?
  unsigned char dissolutionRate = 4;
  unsigned char shape = Shape::CIRCLE;
  std::vector<std::unique_ptr<particle_t>> particles;

public:
  sf::Vector2f pos;     // Particle origin (pixel co-ordinates)
  sf::Vector2f gravity; // Affects particle velocities

  ParticleSystem(int width, int height)
  {
    image.create(width, height, transparent);
    texture.loadFromImage(image);
    sprite = sf::Sprite(texture);
    pos.x = 0.5f * width;
    pos.y = 0.5f * height;
    particles.reserve(1000);
  }

  ~ParticleSystem() = default;

  // Adds new particles to particleList
  void fuel(int count)
  {
    float angle;
    for (int i = 0; i < count; i++)
    {
      auto particle = particle_t();
      particle.pos.x = pos.x;
      particle.pos.y = pos.y;

      switch (shape)
      {
      case Shape::CIRCLE:
        angle = rand.rnd(0.0f, 6.2832f);
        particle.vel.x = rand.rnd(0.0f, std::cos(angle));
        particle.vel.y = rand.rnd(0.0f, std::sin(angle));
        break;
      case Shape::SQUARE:
        particle.vel.x = rand.rnd(-1.0f, 1.0f);
        particle.vel.y = rand.rnd(-1.0f, 1.0f);
        break;
      default:
        particle.vel.x = 0.5f; // Easily detected
        particle.vel.y = 0.5f; // Easily detected
      }

      if (particle.vel.x == 0.0f && particle.vel.y == 0.0f)
      {
        continue;
      }

      particle.color = color;
      particle.color.a = 255;
      particles.push_back(std::make_unique<particle_t>(particle));
    }
  }

  // Updates position, velocity and opacity of all particles
  void update()
  {
    float time = clock.restart().asSeconds();
    auto it = particles.begin();
    auto size = image.getSize();

    while (it != particles.end())
    {
      (*it)->vel.x += gravity.x * time;
      (*it)->vel.y += gravity.y * time;

      (*it)->pos.x += (*it)->vel.x * time * particleSpeed;
      (*it)->pos.y += (*it)->vel.y * time * particleSpeed;

      if (dissolve)
      {
        (*it)->color.a -= dissolutionRate;
      }

      if ((*it)->pos.x > size.x || (*it)->pos.x < 0 || (*it)->pos.y > size.y || (*it)->pos.y < 0 || (*it)->color.a < 10)
      {
        it = particles.erase(it);
      }
      else
      {
        ++it;
      }
    }
  }

  // Renders all particles onto image
  void render()
  {
    for (auto &particle : particles)
    {
      image.setPixel(
          static_cast<unsigned int>(particle->pos.x),
          static_cast<unsigned int>(particle->pos.y),
          particle->color);
    }
    texture.update(image);
  }

  // Removes all particles from image
  void remove()
  {
    for (auto &particle : particles)
    {
      image.setPixel(
          static_cast<unsigned int>(particle->pos.x),
          static_cast<unsigned int>(particle->pos.y),
          transparent);
    }
  }

  void setParticleSpeed(float speed) { particleSpeed = speed; }
  void setDissolve(bool enable) { dissolve = enable; }
  void setDissolutionRate(unsigned char rate) { dissolutionRate = rate; }
  void setShape(unsigned char shape) { this->shape = shape; }
  void setColor(sf::Color color) { this->color = color; }

  unsigned long getCount() { return particles.size(); }
  sf::Sprite &getSprite() { return sprite; }
};