#include "IScene.h"
#include <IGame.h>
#include <scenes/MainMenuScene.h>

#define MIN(a,b) (((a)<(b))?(a):(b))
#define MAX(a,b) (((a)>(b))?(a):(b))

class SplashScene : public IScene
{
protected:
    IGame *game;

public:
    sf::Clock clock;
    sf::Sprite logo;
    sf::Texture logoTex;

    SplashScene(IGame *game)
    {
        this->game = game;
        if (!logoTex.loadFromFile("kemohaus.png")) {
            printf("cannot load logo - are we in the correct working directory?");
            exit(1);
        }
    }
    ~SplashScene() {}

    void onVisible() override
    {
    }

    void main() override
    {
        auto time = clock.getElapsedTime();
        
        if (time.asMilliseconds() > 3000) {
            game->setScene(new MainMenuScene(game));
        }
    }

    void render(IWindowRenderer *renderer) override
    {
        auto time = clock.getElapsedTime();
        auto w = renderer->getWindow();
    
        auto opacity = MAX(MIN(time.asMilliseconds() - 500, 1000) / 1000.0, 0);
        auto wSize = w->getSize();

        auto size = logoTex.getSize();
        logo.setTexture(logoTex);
        logo.setOrigin(size.x / 2, size.y / 2);
        logo.setColor(sf::Color(255,255,255, opacity * 255));
        logo.setPosition(320, 240);

        w->draw(logo);
    }
};