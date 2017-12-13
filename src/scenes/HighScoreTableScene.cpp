#include <sstream>
#include <SFML/Graphics/Text.hpp>
#include "HighScoreTableScene.h"
void HighScoreTableScene::render(WindowRendererInterface *renderer) {
  auto window = renderer->getWindow();
  auto font = renderer->getFont();
  sf::Text titleText("High scores", font, 16);
  titleText.setPosition(0, 0);

  window->draw(titleText);

  int offset = 14;

  for (auto highscore : game->getHighScores().getScores()) {
    sf::Text lineText(highscore.name + " " + std::to_string(highscore.score), font, 16);
    lineText.setPosition(0, offset);

    window->draw(lineText);

    offset += 14;
  }
}

void HighScoreTableScene::handleEvents() {

}
void HighScoreTableScene::onVisible() {

}
