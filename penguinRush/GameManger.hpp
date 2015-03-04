#ifndef GAMEMANGER_HPP
#define GAMEMANGER_HPP

#include <SFML/Audio.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>

#include "UI.hpp"
#include "Penguin.hpp"
#include "Constants.hpp"
#include "Background.hpp"
#include "Frontground.hpp"
#include "ObstacleManager.hpp"

class GameManger {
private:

    Penguin penguin;
    Background background;
    FrontGround frontgroud;
    sf::RenderWindow window;
    ObstacleManager obstacles;

    UI ui;
    bool up_;
    bool down_;
    bool running;
    float timerRestart;

    // Sea
    sf::Texture sea;
    sf::Sprite seaSprite[2];

    // Portada
    bool portada;
    sf::Texture tPortada;
    sf::Sprite sPortada;
    sf::Text press;
    sf::Font font;
    sf::Music music;
    sf::Text yo;

      sf::Music song;

    void handleUltraHardwareOMG();

public:
    GameManger();
    void   run();
    bool checkColissions();
};

#endif // GAMEMANGER_HPP
