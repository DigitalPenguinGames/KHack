#ifndef FRONTGROUND_HPP
#define FRONTGROUND_HPP

#include <vector>
#include "Layer.hpp"

class FrontGround {

    std::vector<Layer> layers;

public:
    FrontGround();
    FrontGround(std::vector<std::string> paths);

    void update(float deltatime);

    void draw(sf::RenderWindow & window);
};

#endif // FRONTGROUND_HPP
