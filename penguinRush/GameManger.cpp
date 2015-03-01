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
  obstacles(sf::VideoMode::getDesktopMode().width,sf::VideoMode::getDesktopMode().height/2)
{
  sea.loadFromFile("res/sea.png");
  seaSprite[0].setTexture(sea);
  seaSprite[0].setPosition(0,0);
  seaSprite[0].setScale(sf::VideoMode::getDesktopMode().width/float(sea.getSize().x),
                        sf::VideoMode::getDesktopMode().height/float(sea.getSize().y));
  seaSprite[1].setTexture(sea);
  seaSprite[1].setPosition(sf::VideoMode::getDesktopMode().width,0);
  seaSprite[1].setScale(sf::VideoMode::getDesktopMode().width/float(sea.getSize().x),
                        sf::VideoMode::getDesktopMode().height/float(sea.getSize().y));
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
      frontgroud.update(deltaTime, window);
      bool gameFinished = checkColissions();
      if (gameFinished) obstacles.initObstacles();

      seaSprite[0].move(sf::Vector2f(-constant::obstacleSpeed*deltaTime,0));
      seaSprite[1].move(sf::Vector2f(-constant::obstacleSpeed*deltaTime,0));
      if (seaSprite[0].getPosition().x < -seaSprite[0].getGlobalBounds().width)
        seaSprite[0].move(seaSprite[0].getGlobalBounds().width*2,0);
      if (seaSprite[1].getPosition().x < -seaSprite[1].getGlobalBounds().width)
        seaSprite[1].move(seaSprite[1].getGlobalBounds().width*2,0);

      window.clear();
      background.draw(window);
      penguin.draw   (window);
      obstacles.draw (window);
      frontgroud.draw(window);
      window.draw(seaSprite[0]);
      window.draw(seaSprite[1]);
      window.display();
    }
}

bool GameManger::checkColissions() {
  sf::Vector2f penguinHead = penguin.getHead();
  return obstacles.isColissioning(penguinHead);
}
