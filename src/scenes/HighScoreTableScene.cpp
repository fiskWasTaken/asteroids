//
// Created by Fisk on 13/10/2017.
//

#include <sstream>
#include <SFML/Graphics/Text.hpp>
#include "HighScoreTableScene.h"
void HighScoreTableScene::render(RendererInterface *renderer) {
  auto window = renderer->getWindow();
  auto font = renderer->getFont();
  sf::Text titleText("High scores", *font, 16);
  titleText.setPosition(0, 0);

  window->draw(titleText);

  int offset = 14;

  for (auto highscore : game->getHighScores().getScores()) {
    std::stringstream text;
    text << highscore.name << " " << highscore.score;

    sf::Text lineText(text.str(), *font, 16);
    lineText.setPosition(0, offset);

    window->draw(lineText);

    offset += 14;
  }
}

void HighScoreTableScene::handleEvents() {

}
void HighScoreTableScene::onVisible() {

}
void HighScoreTableScene::onDestroy() {

}
