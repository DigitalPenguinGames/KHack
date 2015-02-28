#ifndef OBSTACLE_HPP
#define OBSTACLE_HPP

#include "Constants.hpp"

class Obstacle {
private:

public:
    Obstacle(obstacle::obsType type);
    void update(float deltaTime);
};

#endif // OBSTACLE_HPP
