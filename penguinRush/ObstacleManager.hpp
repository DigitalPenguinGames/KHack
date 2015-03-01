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

  bool running;

  bool pixelColission(sf::Vector2f penguin);
public:
  ObstacleManager(int initX, int initY);
  void initObstacles();
  void update(float deltaTime);
  void draw(sf::RenderWindow &window);
  bool isColissioning(sf::Vector2f penguin);
  void stop();
};

#endif // OBSTACLEMANAGER_HPP
