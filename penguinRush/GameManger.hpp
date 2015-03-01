#ifndef GAMEMANGER_HPP
#define GAMEMANGER_HPP

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>


#include "Frontground.hpp"
#include "Penguin.hpp"
#include "ObstacleManager.hpp"
#include "Background.hpp"
#include "Constants.hpp"
#include "UI.hpp"

class GameManger {
private:
    sf::RenderWindow window;
    Background background;
    FrontGround frontgroud;
    ObstacleManager obstacles;
    Penguin penguin;

    UI ui;
    bool running;
    float timerRestart;

    bool up_;
    bool down_;

    // Sea
    sf::Texture sea;
    sf::Sprite seaSprite[2];

    // Portada
    bool portada;
    sf::Texture tPortada;
    sf::Sprite sPortada;

    void handleUltraHardwareOMG();
public:
    GameManger();
    void run();
    bool checkColissions();
};

#endif // GAMEMANGER_HPP
