#ifndef BACKGROUND_HPP
#define BACKGROUND_HPP

#include <vector>
#include <iostream>
#include <SFML/Graphics.hpp>
#include "Constants.hpp"

class Background {

private:

    std::vector<int> speeds;
    std::vector<sf::Sprite> sprites;
    std::vector<sf::Texture> textures;


public:
    Background();

    void update(float deltatime);

    void draw(sf::RenderWindow& window);
};

#endif // BACKGROUND_HPP
