#pragma once

#include <IGame.h>
#include <renderer/WorldRenderer.h>
#include <waves/WaveGenerator.h>
#include "IScene.h"
#include <SFML/Graphics/Shader.hpp>

struct respawn_timer_t
{
  PlayerSession *session;
  int time;
};

class GameScene : public IScene, public IControllerListener
{
private:
  const int BASE_WAVE_INTERVAL_TIME = 1000;
  const int RESPAWN_TIME = 50;

  IGame *game;
  World world;
  std::vector<std::unique_ptr<respawn_timer_t>> respawnTimers;
  PlayerSession *pauseInitiator = nullptr;
  WorldRenderer worldRenderer;
  WaveGenerator waveGenerator;
  sf::Shader shader;
  sf::Clock clock;

  int waveTimer = 0;
  int waveId = 0;

  bool paused = false;

  void startRespawnTimer(PlayerSession *playerSession);

public:
  explicit GameScene(IGame *game);
  ~GameScene() override
  {
    game->getControllers().getFirst()->setDelegate(nullptr);
  }

  void render(IWindowRenderer *renderer) override
  {
    auto view = renderer->getView();
    auto window = renderer->getWindow();

    worldRenderer.drawBg(renderer, &world);

    sf::RectangleShape bg(view.getSize());

    shader.setUniform("u_time", clock.getElapsedTime().asSeconds());
    shader.setUniform("u_resolution", view.getSize());
    window->draw(bg, &shader);

    worldRenderer.drawWorld(renderer, &world);

    drawHud(renderer);
    drawWaveBar(renderer);
  }

  void onVisible() override
  {
    waveTimer = 50;

    for (const auto &session : game->getSessions())
    {
      session->spawnShip(&world);
    }
  }

  void onAction(InputAction action, bool once)
  {
    if (action == InputAction::PAUSE && once)
    {
      paused = false;
      pauseInitiator->player->getController()->setDelegate(pauseInitiator->ship);
    }
  }

  void pause(PlayerSession *initiator)
  {
    paused = true;
    pauseInitiator = initiator;
    initiator->player->getController()->setDelegate(this);
  }

  void drawHud(IWindowRenderer *renderer);
  void main() override;

  void onShipDestroyed(PlayerSession *playerSession)
  {
    if (playerSession == nullptr)
    {
      printf("ship without related session died, ignoring\n");
      return;
    }

    playerSession->player->getController()->setDelegate(nullptr);
    startRespawnTimer(playerSession);
  }

  void startWave()
  {
    waveGenerator.generate(&world, waveId);

    for (const auto &session : game->getSessions())
    {
      session->ship->setInvincibilityCooldown(100);
    }

    waveTimer = BASE_WAVE_INTERVAL_TIME;
    waveId++;
  }

  void updateRespawnTimers()
  {
    auto it = respawnTimers.begin();

    while (it != respawnTimers.end())
    {
      auto timer = **it;

      (**it).time--;

      if ((**it).time == 0)
      {
        (**it).session->lives--;

        if ((**it).session->lives > 0)
        {
          (**it).session->spawnShip(&world);
        }

        it = respawnTimers.erase(it);
      }
      else
      {
        ++it;
      }
    }
  }

  int getRemainingPlayerCount()
  {
    // todo: map/filter/reduce?
    int count = 0;

    for (const auto &session : game->getSessions())
      if (session->lives > 0)
        count++;

    return count;
  }

  void drawWaveBar(IWindowRenderer *renderer);
};
