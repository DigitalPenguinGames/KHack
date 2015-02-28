#ifndef BACKGROUND_HPP
#define BACKGROUND_HPP

#include <iostream>
#include <SFML/Graphics.hpp>

class Background {

private:
    sf::Sprite sprite;
    sf::Texture texture;


public:
    Background();

    void update(float deltatime);

    void draw(sf::RenderWindow& window);
};

#endif // BACKGROUND_HPP
