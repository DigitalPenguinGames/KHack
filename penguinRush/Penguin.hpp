#ifndef PENGUIN_HPP
#define PENGUIN_HPP

#include <SFML/System.hpp>

class Penguin {
private:
    sf::Vector2f speed;
    sf::Vector2f pos;
public:
    Penguin();
    void setSpeed(const float &value);
    sf::Vector2f getPos() const;
};

#endif // PENGUIN_HPP
