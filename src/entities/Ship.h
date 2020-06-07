#pragma once

#include <SFML/System/Vector2.hpp>
#include <utility>
#include <vector>
#include <SFML/Graphics/Shape.hpp>
#include "world/WorldInterface.h"
#include "IActor.h"
#include "Actor.h"
#include "player/Player.h"
#include <SFML/Graphics/ConvexShape.hpp>
#include <particles/ParticleSystem.h>

class PlayerSession;

class Ship : public Actor, public IControllerListener
{
protected:
  const float MAX_SPEED = 4.0F;
  const float MAX_ROTATE_SPEED = 5.0F;
  const int FIRE_RATE = 5;
  const int ALT_FIRE_RATE = 20;

  sf::ConvexShape shape;
  ParticleSystem particleSystem;
  PlayerSession *playerSession;
  int altFireCooldown = 0;
  int fireCooldown = 0;
  bool isFiring = false;
  bool isFiringAltWeapon = false;
  bool isDestroyed = false;
  bool isThrusting = false;
  int invincibilityTimer = 100; // initial invincibility time on spawn in frames
  const sf::Color fillColor = sf::Color(255, 255, 255, 25);

public:
  sf::Color color;

  std::string getClass() override
  {
    return "ship";
  }

  explicit Ship(WorldInterface *world, PlayerSession *playerSession);
  ~Ship() override = default;

  void onAction(InputAction action, bool once) override;
  void update() override;
  bool isRecyclable() override;
  virtual void onDestroyed();

  PlayerSession *getPlayerSession() { return playerSession; }

  void onCollision(Actor *other)
  {
    if (other->getClass() == "ship")
    {
      onShipHit(dynamic_cast<Ship *>(other));
    }
  }

  void onShipHit(Ship *other)
  {
    // bounce
    auto diff = vel - other->vel;
    diff.x /= 1.1;
    diff.y /= 1.1;

    vel -= diff;
    other->vel += diff;
  }

  void renderTo(sf::RenderWindow *renderWindow) override;
  void renderThruster(sf::RenderWindow *renderWindow)
  {
    particleSystem.fuel(1);
  }
  void renderShip(sf::RenderWindow *renderWindow)
  {
    bool invisible = (invincibilityTimer / 3 % 2 != 0);

    if (invisible)
    {
      shape.setOutlineColor(sf::Color(50, 50, 50));
    }
    else
    {
      shape.setOutlineColor(color);
    }

    shape.setRotation(rot);
    shape.setPosition(pos);
    renderWindow->draw(shape);
  }

  bool isOnInvincibilityCooldown() { return invincibilityTimer > 0; }
  void setInvincibilityCooldown(int cooldown) { invincibilityTimer = cooldown; }

  void fireBullet();
  void fireAltWeapon();
};