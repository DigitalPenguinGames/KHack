#include "ObstacleManager.hpp"

#include <iostream>


bool ObstacleManager::pixelColission(sf::Vector2f penguin) {
  sf::Image img = (*obstacles.begin())->getImage();
  sf::FloatRect rect = (*obstacles.begin())->getBounds();
  sf::Vector2f pixel;
  pixel.x = penguin.x-rect.left;
  pixel.y = penguin.y-rect.top;
  sf::Color color = img.getPixel(pixel.x, pixel.y);
  return color.a > 0.5;
}

ObstacleManager::ObstacleManager(int initX, int initY) :
  initX(initX),
  initY(initY),
  timer(0)
{
  initObstacles();
}

void ObstacleManager::initObstacles() {
  obstacles.clear();
  maxTime = constant::maxTimeObstacles;
  minTime = constant::minTimeObstacles;
}

void ObstacleManager::update(float deltaTime) {
  timer -= deltaTime;
  if (timer < 0) {
      int newObstacle = rand()%obstacle::qtt;
      obstacles.push_back(new Obstacle(static_cast<obstacle::obsType>(newObstacle), initX+300, initY));
      timer = minTime + (rand()%int(maxTime-minTime));
    }
  for (auto it = obstacles.begin(); it != obstacles.end();++it) {
      (*it)->update(deltaTime);
    }
  if (obstacles.size() > 0) {
      Obstacle* obs = (*obstacles.begin());
      if (obs->isOutOfWindow()) {
          delete obs;
          obstacles.erase(obstacles.begin());
        }
    }
}


void ObstacleManager::draw(sf::RenderWindow &window) {
  for (auto it = obstacles.begin(); it != obstacles.end();++it) {
      (*it)->draw(window);
    }
}

bool ObstacleManager::isColissioning(sf::Vector2f penguin) {
  if (obstacles.size() > 0) {
      sf::FloatRect aux = (*obstacles.begin())->getBounds();
      ;
      if (aux.contains(penguin.x,penguin.y)) return pixelColission(penguin);
    }
  return false;
}
