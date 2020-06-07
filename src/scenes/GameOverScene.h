#pragma once

#include <IGame.h>
#include "IScene.h"

class GameOverScene : public IScene, public IControllerListener
{
private:
  IGame *game;

public:
  explicit GameOverScene(IGame *game)
  {
    this->game = game;
  }

  ~GameOverScene()
  {
    game->getControllers().getFirst()->setDelegate(nullptr);
  }

  void render(IWindowRenderer *renderer) override
  {
    auto window = renderer->getWindow();
    auto view = renderer->getView();
    auto font = renderer->getFont();

    sf::Text startTitleText("Game Over", font, 16);
    sf::Text startPromptText("Press Fire to return to the main menu", font, 16);

    auto center = view.getSize().x / 2;
    auto middle = view.getSize().y / 2;

    drawing::centreText(startTitleText);
    drawing::centreText(startPromptText);

    startTitleText.setPosition(center, middle - 14);
    startPromptText.setPosition(center, middle);

    window->draw(startTitleText);
    window->draw(startPromptText);
  }

  void onVisible() override
  {
    game->getSessions().clear();
    game->getControllers().getFirstAvailable()->setDelegate(this);
  }

  void onAction(InputAction action, bool once) override;
};