#ifndef PENGUIN_HPP
#define PENGUIN_HPP

#include <SFML/System.hpp>
#include <SFML/Graphics.hpp>
#include "Constants.hpp"

class Penguin {
private:
    float speed;
    int pos;
    int middle;
public:
    Penguin(int middle);
    void update(float deltaTime);
    void draw(sf::RenderWindow &window);
    void setSpeed(const float &value);
};

#endif // PENGUIN_HPP
