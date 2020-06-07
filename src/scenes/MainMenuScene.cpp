#include <SFML/Graphics/Text.hpp>
#include <sstream>
#include <SFML/Graphics/ConvexShape.hpp>
#include <utility/drawing.h>
#include <SFML/Graphics/Shader.hpp>
#include <SFML/Graphics/RectangleShape.hpp>
#include "MainMenuScene.h"
#include "GameScene.h"
#include "StressTestScene.h"

void MainMenuScene::render(IWindowRenderer *renderer) {
  auto window = renderer->getWindow();
  auto view = renderer->getView();
  auto font = renderer->getFont();

  sf::Text startTitleText("Asterpop", font, 32);
  sf::Text startPromptText("Press Fire to start", font, 16);
  sf::Text startLicenseText("fisk, 2017-2020", font, 12);
  sf::Text menuOptionText("< " + menuOptions[selected].string + " >", font, 16);

  auto center = view.getSize().x / 2;
  auto middle = view.getSize().y / 2;

  startTitleText.setPosition(center, middle - 64);
  startTitleText.setRotation(-5);
  menuOptionText.setPosition(center, middle);
  startPromptText.setPosition(center, middle + 16);
  startLicenseText.setPosition(center, view.getSize().y - 24);

  drawing::centreText(startTitleText);
  drawing::centreText(startPromptText);
  drawing::centreText(startLicenseText);
  drawing::centreText(menuOptionText);

  sf::RectangleShape bg(view.getSize());

  shader.setUniform("u_time", clock.getElapsedTime().asSeconds());
  shader.setUniform("u_resolution", view.getSize());
  window->draw(bg, &shader);

  worldRenderer.drawWorld(renderer, &world);
  window->draw(startTitleText);
  window->draw(startPromptText);
  window->draw(startLicenseText);
  window->draw(menuOptionText);
}

void MainMenuScene::onAction(InputAction action, bool once) {
  if (action == InputAction::FIRE && once) {
    menuOptions[selected].onSelect(game);
  }

  if (action == InputAction::LEFT && once) {
    selected--;

    if (selected < 0) {
      selected = static_cast<int>(menuOptions.size() - 1);
    }
  }

  if (action == InputAction::RIGHT && once) {
    selected = (selected + 1) % menuOptions.size();
  }
}

void MainMenuScene::onVisible() {
  game->getControllers().getFirst()->setDelegate(this);
  WaveGenerator generator;
  generator.generate(&world, 10);
}

void MainMenuScene::main() {
  world.update();
}
MainMenuScene::~MainMenuScene() {}

MainMenuScene::MainMenuScene(IGame *game) : world(game, 640, 480) {
  this->game = game;

  // load only the fragment shader
  if (!this->shader.loadFromFile("assets/nebulae.frag", sf::Shader::Fragment))
  {
    exit(253);
  }

  menu_option_t onePlayer;
  onePlayer.string = "1 Player";
  onePlayer.onSelect = [](IGame *game) {
    game->getControllers().undelegateAll();

    auto player = new Player("Player 1");
    PlayerSession session(player);
    auto sessionPtr = std::make_shared<PlayerSession>(session);
    player->setController(game->getControllers().getFirstAvailable());
    game->getSessions().push_back(sessionPtr);

    game->setScene(new GameScene(game));
  };

  menu_option_t twoPlayers;
  twoPlayers.string = "2 Players";
  twoPlayers.onSelect = [](IGame *game) {
    game->getControllers().undelegateAll();

    auto player = new Player("Player 1");
    PlayerSession session(player);
    auto sessionPtr = std::make_shared<PlayerSession>(session);
    player->setController(game->getControllers().getFirstAvailable());
    game->getSessions().push_back(sessionPtr);

    // fixes a bug with controller delegation, until I sort it out again...
    // TODO@ we need to handle delegation through the player instance instead of doing these redelegation gymnastics.
    game->getControllers().getFirstAvailable()->setDelegate(new Ship(new World(game, 1, 1), &session));

    auto controller2 = game->getControllers().getFirstAvailable();

    if (controller2 != nullptr) {
      auto player2 = new Player("Player 2");
      player2->setColor(sf::Color(58, 144, 163));
      PlayerSession session2(player2);
      auto session2Ptr = std::make_shared<PlayerSession>(session2);
      player2->setController(controller2);
      game->getSessions().push_back(session2Ptr);
    }

    game->setScene(new GameScene(game));
  };

  menu_option_t benchmark;
  benchmark.string = "Stress Test";
  benchmark.onSelect = [](IGame *game) {
    game->getControllers().undelegateAll();
    game->setScene(new StressTestScene(game));
  };

  this->menuOptions.push_back(onePlayer);
  this->menuOptions.push_back(twoPlayers);
  this->menuOptions.push_back(benchmark);
}
