#ifndef OBSTACLE_HPP
#define OBSTACLE_HPP

#include "Constants.hpp"

class Obstacle {
private:

public:
    Obstacle(obsType::obsType type);
    void update(float deltaTime);
};

#endif // OBSTACLE_HPP
