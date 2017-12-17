#ifndef PARTICLE_H
#define PARTICLE_H

#include <SFML/System/Vector2.hpp>
#include <SFML/System/Clock.hpp>
#include <SFML/Graphics/Color.hpp>
#include <SFML/Graphics/Image.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/Texture.hpp>
#include <vector>
#include <random>
#include <memory>

class Randomizer {
 public:
  Randomizer() : device_(), engine_(device_()){};
  int rnd(int a, int b) {
    std::uniform_int_distribution<int> uni_dist(a, b);
    return uni_dist(engine_);
  };
  float rnd(float a, float b) {
    std::uniform_real_distribution<double> uni_dist(a, b);
    return static_cast<float>(uni_dist(engine_));
  };
 private:
  std::random_device device_;
  std::default_random_engine engine_;
};

namespace Shape { enum { CIRCLE, SQUARE }; }

struct Particle
{
  sf::Vector2f pos; // Position
  sf::Vector2f vel; // Velocity
  sf::Color color;  // RGBA
};

class ParticleSystem
{
 public:
  ParticleSystem( int width, int height );
  ~ParticleSystem();

  void fuel( int count ); // Adds new particles to particleList
  void update(); // Updates position, velocity and opacity of all particles
  void render(); // Renders all particles onto image
  void remove(); // Removes all particles from image

  void setPosition( float x, float y ) { pos.x = x; pos.y = y; }
  void setGravity( float x, float y ) { gravity.x = x; gravity.y = y; }
  void setParticleSpeed( float speed ) { particleSpeed = speed; }
  void setDissolve( bool enable ) { dissolve = enable; }
  void setDissolutionRate( unsigned char rate ) { dissolutionRate = rate; }
  void setShape( unsigned char shape ) { this->shape = shape; }

  unsigned long getCount() { return particles.size(); }
  sf::Sprite& getSprite() { return sprite; }

 private:
  sf::Vector2f    pos; // Particle origin (pixel co-ordinates)
  sf::Vector2f    gravity;  // Affects particle velocities
  sf::Clock   clock;    // Used to scale particle motion
  sf::Color   transparent;  // sf::Color( 0, 0, 0, 0 )
  sf::Image   image;    // See render() and remove()
  sf::Texture texture;
  Randomizer  randomizer;
  sf::Sprite  sprite;   // Connected to image
  float       particleSpeed;// Pixels per second (at most)
  bool        dissolve; // Dissolution enabled?
  unsigned char   dissolutionRate;
  unsigned char   shape;

  std::vector<std::unique_ptr<Particle>> particles;
};

#endif