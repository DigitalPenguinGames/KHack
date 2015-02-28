#ifndef BACKGROUND_HPP
#define BACKGROUND_HPP

#include <vector>
#include <iostream>
#include <SFML/Graphics.hpp>
#include "Constants.hpp"

class Background {

private:

    std::vector<sf::Sprite> sprites;
    std::vector<sf::Texture> textures;
    std::vector<sf::Sprite> secondSprites;


public:
    Background();

    void update(float deltatime);

    void draw(sf::RenderWindow& window);
};

#endif // BACKGROUND_HPP
