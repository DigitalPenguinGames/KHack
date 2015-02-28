#include "GameManger.hpp"

void GameManger::initObstacles() {

}

void GameManger::handleUltraHardwareOMG() {
    bool up = sf::Mouse::isButtonPressed(sf::Mouse::Button::Left);
    bool down = sf::Mouse::isButtonPressed(sf::Mouse::Button::Right);
    if (!up || !down) {
        if (up && !up_)
            penguin.setSpeed(constant::penguinSpeed);
        else if (down && !down_)
            penguin.setSpeed(constant::penguinSpeed);
    }
    up_ = up;
    down_ = down;
}

GameManger::GameManger() : window(sf::VideoMode::getDesktopMode(),"Penguin Rush") {
    initObstacles();
    up_ = false;
    down_ = false;
}

void GameManger::run() {
    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) window.close();
        }

        handleUltraHardwareOMG();

        for (auto it = obstacles.begin(); it != obstacles.end(); ++it) {
            obstacles.update(deltaTime);
        }
        if ((*obstacles.begin()).getPos().x < (*obstacles.begin()).getSize()) obstacles.erase(obstacles.begin());
        //Crear nuevos

        penguin.update(deltaTime);
        background.update(deltaTime);


        window.clear();
        background.draw(window);
        penguin.draw(window);
        for (auto it = obstacles.begin(); it != obstacles.end(); ++it) (*it).draw(window);
        window.display();
    }
}
