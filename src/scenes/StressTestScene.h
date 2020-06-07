#pragma once

#include <input/IControllerListener.h>
#include <renderer/WorldRenderer.h>
#include <IGame.h>
#include "IScene.h"

class StressTestScene : public IScene, public IControllerListener
{
private:
  IGame *game;
  World world;
  WorldRenderer worldRenderer;

public:
  explicit StressTestScene(IGame *game) : world(game, 640, 480)
  {
    this->game = game;
  }

  void render(IWindowRenderer *renderer) override
  {
    auto window = renderer->getWindow();
    auto view = renderer->getView();
    auto font = renderer->getFont();

    sf::Text startTitleText("Stress test - press fire button to exit.", font, 16);

    startTitleText.setPosition(4, 0);

    worldRenderer.drawWorld(renderer, &world);
    worldRenderer.drawTimings(renderer);

    window->draw(startTitleText);
  }
  
  void onAction(InputAction action, bool once) override;

  void onVisible() override
  {
    game->getControllers().getFirst()->setDelegate(this);

    WaveGenerator generator;
    generator.generate(&world, 500);
  }

  void main() override
  {
    world.update();
  }

  ~StressTestScene() override
  {
    game->getControllers().getFirst()->setDelegate(nullptr);
  }
};
