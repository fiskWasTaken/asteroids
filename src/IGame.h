#pragma once

#include <scenes/IScene.h>
#include "world/World.h"
#include "player/PlayerSession.h"
#include <input/ControllerManager.h>
#include <scenes/SceneLibrary.h>

class IGame
{
protected:
  SceneLibrary<SceneFunc> library;
  std::vector<std::shared_ptr<PlayerSession>> sessions;
  ControllerManager controllers;
  IScene *scene = nullptr;
  long tick = 0;

public:
  void stop(){};
  virtual void main() = 0;
  void setScene(IScene *scene)
  {
    if (this->scene != nullptr)
    {
      delete (this->scene);
    }

    this->scene = scene;
    scene->onVisible();
  }

  ControllerManager &getControllers()
  {
    return controllers;
  }

  std::vector<std::shared_ptr<PlayerSession>> &getSessions() { return sessions; }


  IScene *getScene() { return scene; }
};