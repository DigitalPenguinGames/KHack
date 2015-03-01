#include "GameManger.hpp"

void GameManger::handleUltraHardwareOMG() {
  if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Escape)) window.close();
  if (running) {
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
  else if(timerRestart > 1) {
      bool up = sf::Mouse::isButtonPressed(sf::Mouse::Button::Left);
      bool down = sf::Mouse::isButtonPressed(sf::Mouse::Button::Right);
      if (up || down) {
          obstacles.initObstacles();
          running = true;
        }
    }
}


GameManger::GameManger() :
  window(sf::VideoMode::getFullscreenModes()[0],"Penguin Rush",sf::Style::Fullscreen),
  penguin(window.getSize().y*1.05/2),
  obstacles(window.getSize().x,window.getSize().y*1.05/2),
  ui(window.getSize()),
  running(true),
  portada(true)
{
  sea.loadFromFile("res/sea.png");
  seaSprite[0].setTexture(sea);
  seaSprite[0].setPosition(0,0);
  seaSprite[0].setScale(window.getSize().x/float(sea.getSize().x),
                        window.getSize().y*1.05/float(sea.getSize().y));
  seaSprite[1].setTexture(sea);
  seaSprite[1].setPosition(window.getSize().x,0);
  seaSprite[1].setScale(window.getSize().x/float(sea.getSize().x),
                        window.getSize().y*1.05/float(sea.getSize().y));
  up_ = false;
  down_ = false;
  srand(time(NULL));

  // Portada shiet
  tPortada.loadFromFile("res/portada.png");
  sPortada.setTexture(tPortada);
  sPortada.setScale(window.getSize().x/float(tPortada.getSize().x), window.getSize().y/float(tPortada.getSize().y));
  sPortada.setPosition(0,0);
}


void GameManger::run() {
  sf::Clock clock;
  clock.restart();
  float deltaTime;
  while (window.isOpen()) {
      deltaTime = clock.restart().asSeconds();
      if (portada) {
          sf::Event event;
          while (window.pollEvent(event)) {
              if (event.type == sf::Event::Closed) window.close();
              else if (event.type == sf::Event::MouseButtonPressed &&
                       (event.mouseButton.button == sf::Mouse::Right ||
                        event.mouseButton.button == sf::Mouse::Left))
                       portada = false;
          }
          window.clear();
          window.draw(sPortada);
          window.display();
      }
      else {
          timerRestart += deltaTime;
          sf::Event event;
          while (window.pollEvent(event)) {
              if (event.type == sf::Event::Closed) window.close();
            }

          handleUltraHardwareOMG();

          obstacles.update(deltaTime);
          penguin.update(deltaTime);

          bool gameFinished = checkColissions();
          if (gameFinished) {
              running = false;
              obstacles.stop();
              timerRestart = 0;
            }

          background.update(deltaTime);
          frontgroud.update(deltaTime, window);
          seaSprite[0].move(sf::Vector2f(-constant::obstacleSpeed*deltaTime,0));
          seaSprite[1].move(sf::Vector2f(-constant::obstacleSpeed*deltaTime,0));
          if (seaSprite[0].getPosition().x < -seaSprite[0].getGlobalBounds().width)
            seaSprite[0].move(seaSprite[0].getGlobalBounds().width*2,0);
          if (seaSprite[1].getPosition().x < -seaSprite[1].getGlobalBounds().width)
            seaSprite[1].move(seaSprite[1].getGlobalBounds().width*2,0);
          ui.update(deltaTime);

          window.clear();
          background.draw(window);
          penguin.draw   (window);
          obstacles.draw (window);
          frontgroud.draw(window);
          window.draw(seaSprite[0]);
          window.draw(seaSprite[1]);
          ui.draw(window,running);
          window.display();
        }
    }
}

bool GameManger::checkColissions() {
  sf::Vector2f penguinHead = penguin.getHead();
  return obstacles.isColissioning(penguinHead);
}
