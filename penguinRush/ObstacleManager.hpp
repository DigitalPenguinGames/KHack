#ifndef OBSTACLEMANAGER_HPP
#define OBSTACLEMANAGER_HPP

#include <vector>
#include <list>
#include <SFML/Graphics.hpp>

#include "Obstacle.hpp"

class ObstacleManager {
private:
  int initX;
  int initY;

  std::list<Obstacle*> obstacles;

  float maxTime;
  float minTime;
  float timer;

  void initObstacles();
public:
  ObstacleManager(int initX, int initY);
  void update(float deltaTime);
  void draw(sf::RenderWindow &window);
};

#endif // OBSTACLEMANAGER_HPP
