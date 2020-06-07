#pragma once

#include "Actor.h"
#include "player/Player.h"
#include <SFML/Graphics/ConvexShape.hpp>
#include <particles/ParticleSystem.h>
#include <entities/Ship.h>

class AIShip : public Ship
{
protected:
    const float rotThreshold = 7.5;

public:
    sf::Vector2f target;
    sf::Font font;

    explicit AIShip(WorldInterface *world) : Ship(world, NULL)
    {
        this->world = world;
        font.loadFromFile("Monospace.ttf");
    }

    sf::Vector2f relToTarget() {
        return target - pos;
    }

    sf::Vector2f getTarget()
    {
        Actor* chaseTarget = nullptr;

        auto target = pos;

        auto future = vector::fromAngleDeg(rot);

        target += future * 50.0f;

        auto actors = world->getActors();

        for (auto it = actors.begin(); it != actors.end(); it++)
        {
            auto actor = (*it);

            if (actor == this)
            {
                continue;
            }

            // todo: can we alter trajectory towards the player?

            auto dist = target - actor->pos;
            auto len = vector::len(dist);

            if (actor->getClass() == "ship") {
                if (chaseTarget == nullptr || distTo(actor) < distTo(chaseTarget)) {
                    chaseTarget = actor;
                }
            } 
            else if (len < 100)
            {
                target += dist / 2.0f;
            }
        }

        if (chaseTarget != nullptr) {
            auto dist = target - chaseTarget->pos;
            target -= dist / 2.0f;
        }
        
        return target;
    }

    float distTo(Actor* other) {
        return vector::len(pos - other->pos);
    }

    float desiredRotDeg() {
        return vector::angleDeg(getTarget() - pos);
    }

    void update()
    {
        auto rotVec = vector::fromAngleDeg(rot);
        auto relTarget = getTarget() - pos;
        auto norTargetVec = vector::nor(relTarget);
        auto adjustVec = rotVec - norTargetVec;
        auto adjust = vector::angleDeg(adjustVec);

        auto diff = vector::angleDeg(norTargetVec) - rot;
        
        if (diff > rotThreshold)
        {
            onAction(RIGHT, false);
        }
        else if (diff < -rotThreshold)
        {
            onAction(LEFT, false);
        }
        else
        {
            onAction(ACCELERATE, false);
        }

        auto r = rand() % 60;

        if (r == 0) {
            onAction(FIRE, false);
        }

        // parent update call, since it has all the physics
        Ship::update();
    }

    void renderDebug(sf::RenderWindow *r) {
        sf::RectangleShape reticule;
        reticule.setPosition(getTarget());
        reticule.setSize(sf::Vector2f(2.0f, 2.0f));
        reticule.setOutlineColor(sf::Color::Red);
        r->draw(reticule);

        sf::Color debugCol = sf::Color(255, 255, 255);

        sf::Text rotText("Rot deg " + std::to_string(rot), font, 12);
        rotText.setPosition(pos);
        rotText.setFillColor(debugCol);
        r->draw(rotText);

        sf::Text drotText("Desired rot deg " + std::to_string(desiredRotDeg()), font, 12);
        drotText.setPosition(pos + sf::Vector2f(0, 10));
        drotText.setFillColor(debugCol);
        r->draw(drotText);

        sf::Text relText("Rel to Target " + std::to_string(relToTarget().x), font, 12);
        relText.setPosition(pos + sf::Vector2f(0, 20));
        relText.setFillColor(debugCol);
        r->draw(relText);

    }
};