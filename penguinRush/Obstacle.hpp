#ifndef OBSTACLE_HPP
#define OBSTACLE_HPP

#include <SFML/Graphics.hpp>
#include "Constants.hpp"

class Obstacle {
private:
    sf::Texture text;
    sf::Sprite sprite;
    sf::Vector2f pos;
public:
    Obstacle(obstacle::obsType type, float x, float y);
    void update(float deltaTime);
    void draw(sf::RenderWindow &window);
    bool isOutOfWindow();
};

#endif // OBSTACLE_HPP
