#include "ObstacleManager.hpp"

ObstacleManager::ObstacleManager() {
  for (int i = 0; i < obstacle::qtt; ++i) {

    }
}

void ObstacleManager::update(float deltaTime) {
  for (auto it = obstacles.begin(); it != obstacles.end();++it) {
      (*it).update(deltaTime);
    }
  Obstacle* obstacle = &(*obstacles.begin());
}


void ObstacleManager::draw(sf::RenderWindow &window) {
  for (auto it = obstacles.begin(); it != obstacles.end();++it) {
      (*it).draw(window);
    }
}
