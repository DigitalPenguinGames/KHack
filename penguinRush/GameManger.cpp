#include "GameManger.hpp"

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

GameManger::GameManger() :
  window(sf::VideoMode::getDesktopMode(),"Penguin Rush"),
  penguin(sf::VideoMode::getDesktopMode().height/2)
{
  up_ = false;
  down_ = false;
}

void GameManger::run() {
  sf::Clock clock;
  clock.restart();
  float deltaTime;
  while (window.isOpen()) {
      deltaTime = clock.restart().asSeconds();
      sf::Event event;
      while (window.pollEvent(event)) {
          if (event.type == sf::Event::Closed) window.close();
        }

      handleUltraHardwareOMG();

      obstacles.update(deltaTime);

      //Crear nuevos

      penguin.update(deltaTime);
      background.update(deltaTime);


      window.clear();
      background.draw(window);
      penguin.draw(window);
      obstacles.draw(window);
      window.display();
    }
}
