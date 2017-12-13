#include <collision/SATCollisionModel.h>
#include <SFML/Graphics/ConvexShape.hpp>
#include <SFML/Graphics/RectangleShape.hpp>
#include <SFML/Graphics/Text.hpp>
#include <sstream>
#include "WorldRenderer.h"


void WorldRenderer::drawBg(WindowRendererInterface *renderer, World *world) {
  auto window = renderer->getWindow();

  auto vec = sf::Vector2f((float) world->getWidth(), (float) world->getHeight());
  sf::RectangleShape shape(vec);
  shape.setFillColor(sf::Color::Black);
  window->draw(shape);
}


void WorldRenderer::drawCollisionOffsets(WindowRendererInterface *renderer, World *world) {
  auto window = renderer->getWindow();

  for (auto obj : world->getObjects()) {
    auto points = getOffsetPoints(obj);
    auto shape = sf::ConvexShape();

    shape.setPointCount(points.size());

    for (size_t i = 0; i < points.size(); i++) {
      shape.setPoint(i, points[i]);
    }

    shape.setFillColor(sf::Color::Transparent);
    shape.setOutlineColor(sf::Color::Red);
    shape.setOutlineThickness(1.0F);
    window->draw(shape);
  }
}

void WorldRenderer::drawWorld(WindowRendererInterface *renderer, World *world) {
  auto window = renderer->getWindow();

  for (auto entity: world->getObjects()) {
    entity->renderTo(window);
  }
}

void WorldRenderer::drawTimings(WindowRendererInterface *renderer) {
  auto font = renderer->getFont();
  auto window = renderer->getWindow();
  auto view = renderer->getView();
  auto newTime = clock.getElapsedTime();
  auto text = "Frame time: " + std::to_string(newTime.asMicroseconds() - lastFrameTime.asMicroseconds());
  sf::Text timingText(text, font, 16);
  timingText.setPosition(4, view.getSize().y - 16);
  window->draw(timingText);
  lastFrameTime = newTime;
}