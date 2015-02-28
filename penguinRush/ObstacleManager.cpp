#include "ObstacleManager.hpp"

ObstacleManager::ObstacleManager() {
}

void ObstacleManager::update(float deltaTime) {
  for (auto it = obstacles.begin(); it != obstacles.end();++it) {
      (*it).update(deltaTime);
    }
  Obstacle* obstacle = &(*obstacles.begin());
}


void ObstacleManager::draw(sf::RenderWindow &window)
{
}
