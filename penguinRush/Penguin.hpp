#ifndef PENGUIN_HPP
#define PENGUIN_HPP

#include <SFML/System.hpp>
#include <SFML/Graphics.hpp>
#include "Constants.hpp"

class Penguin {
private:
    float speed;
    float pos;
    int middle;

    float penguinSpeedUp;
    float gravity;

    // Texture && Sprite
    sf::Texture text[2];
    sf::Sprite sprite[2];
    int frame;
    float animationTimer;
public:
    Penguin(int middle);
    void update(float deltaTime);
    void draw(sf::RenderWindow &window);
    void setSpeed(const float &value);
};

#endif // PENGUIN_HPP
