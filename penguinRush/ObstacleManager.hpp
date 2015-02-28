#ifndef OBSTACLEMANAGER_HPP
#define OBSTACLEMANAGER_HPP

#include <vector>
#include <list>
#include <SFML/Graphics.hpp>

#include "Obstacle.hpp"

class ObstacleManager {
private:
  std::vector<Obstacle> obsProto;
  std::list<Obstacle> obstacles;

  void initObstacles();
public:
  ObstacleManager();
  void update(float deltaTime);
  void draw(sf::RenderWindow &window);
};

#endif // OBSTACLEMANAGER_HPP
