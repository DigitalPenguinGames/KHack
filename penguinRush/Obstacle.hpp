#ifndef OBSTACLE_HPP
#define OBSTACLE_HPP

#include <SFML/Graphics.hpp>
#include "Constants.hpp"

class Obstacle {
private:
    sf::Texture text;
    sf::Sprite sprite;
public:
    Obstacle(obstacle::obsType type);
    void update(float deltaTime);
    void draw(sf::RenderWindow &window);
};

#endif // OBSTACLE_HPP
