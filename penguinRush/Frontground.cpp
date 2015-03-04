#include "Frontground.hpp"

FrontGround::FrontGround(){
    layers = std::vector<Layer>();
    Layer layer;
    layer.setTimer(sf::Vector2i(3,8));
    layer.setSpeed(sf::Vector2i(300,500));

    std::vector<sf::Texture> textures;
    sf::Texture tex;
    tex.loadFromFile("res/fish1.png");
    textures.push_back(tex);
    tex.loadFromFile("res/fish2.png");
    textures.push_back(tex);
    tex.loadFromFile("res/fish3.png");
    textures.push_back(tex);

    layer.setTextures(textures);

    layers.push_back(layer);
}

FrontGround::FrontGround(std::vector<std::string> paths){
    layers = std::vector<Layer>();
    Layer layer;
    layer.setTimer(sf::Vector2i(1,3));
    layer.setSpeed(sf::Vector2i(200,300));

    std::vector<sf::Texture> textures;
    sf::Texture tex;

    for(uint i = 0; i < paths.size(); ++i){
        tex.loadFromFile(paths[i]);
        textures.push_back(tex);
    }

    layer.setTextures(textures);
    layers.push_back(layer);

}

void FrontGround::update(float deltatime, sf::RenderWindow &window){
    for(uint i = 0; i < layers.size(); ++i){
        layers[i].update(deltatime, window);
    }
}

void FrontGround::draw(sf::RenderWindow &window){
    for(uint i = 0; i < layers.size(); ++i){
        layers[i].draw(window);
    }
}
