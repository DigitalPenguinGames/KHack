#include "GameManger.hpp"

void GameManger::handleUltraHardwareOMG() {
  if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Escape)) window.close();
  bool up = sf::Mouse::isButtonPressed(sf::Mouse::Button::Left);
  bool down = sf::Mouse::isButtonPressed(sf::Mouse::Button::Right);
  if (!up || !down) {
      if (up && !up_)
        penguin.setSpeed(1);
      else if (down && !down_)
        penguin.setSpeed(-1);
    }
  up_ = up;
  down_ = down;
}

GameManger::GameManger() :
  window(sf::VideoMode::getDesktopMode(),"Penguin Rush"),
  penguin(sf::VideoMode::getDesktopMode().height/2),
  obstacles(sf::VideoMode::getDesktopMode().width,sf::VideoMode::getDesktopMode().height/2),
  o(obstacle::Iceberg,200,200)
{
  up_ = false;
  down_ = false;
  srand(time(NULL));
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

      bool gameFinished = checkColissions();

      window.clear();
      background.draw(window);
      penguin.draw(window);
      obstacles.draw(window);
      window.display();
    }
}

bool GameManger::checkColissions()
{
}
