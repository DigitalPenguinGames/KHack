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

class GameManger {
private:
    sf::RenderWindow window;
    Background background;
    FrontGround frontgroud;
    ObstacleManager obstacles;
    Penguin penguin;

    bool up_;
    bool down_;

    // Sea
    sf::Texture sea;
    sf::Sprite seaSprite[2];

    void handleUltraHardwareOMG();
public:
    GameManger();
    void run();
    bool checkColissions();
};

#endif // GAMEMANGER_HPP
