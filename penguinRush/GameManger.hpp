#ifndef GAMEMANGER_HPP
#define GAMEMANGER_HPP

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>


#include "Penguin.hpp"
#include "ObstacleManager.hpp"
#include "Background.hpp"
#include "Constants.hpp"

class GameManger {
private:
    sf::RenderWindow window;
    Background background;
    Penguin penguin;

    bool up_;
    bool down_;

    void initObstacles();
    void handleUltraHardwareOMG();
public:
    GameManger();
    void run();
};

#endif // GAMEMANGER_HPP
