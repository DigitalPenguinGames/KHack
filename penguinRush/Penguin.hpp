#ifndef PENGUIN_HPP
#define PENGUIN_HPP

#include <SFML/System.hpp>
#include <SFML/Graphics.hpp>

#include "Constants.hpp"
#include "ParticleSystem.hpp"

class Penguin {
private:

    bool jumping;

    float pos;
    int frame;
    int middle;
    float speed;
    float gravity;
    float softGravity;
    float animationTimer;
    float penguinSpeedUp;

    // Texture && Sprite
    sf::Texture text[2];
    sf::Sprite sprite[2];

    direction::dir dir;

    ParticleSystem particles;


public:
    Penguin(int middle);
    void update(float deltaTime);
    void draw(sf::RenderWindow &window);
    void setSpeed(const float &value);
    sf::Vector2f getHead();
};

#endif // PENGUIN_HPP
