#ifndef OBSTACLEMANAGER_HPP
#define OBSTACLEMANAGER_HPP

#include <vector>
#include <list>

#include "Obstacle.hpp"

class ObstacleManager {
private:
  std::vector<Obstacle> obsProto;
  std::list<Obstacle> obstacles;

  void initObstacles();
public:
  ObstacleManager();
};

#endif // OBSTACLEMANAGER_HPP
