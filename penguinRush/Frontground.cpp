#include "Frontground.hpp"

FrontGround::FrontGround(){
    layers = std::vector<Layer>();
    Layer layer;
    layer.setTimer(sf::Vector2i(1,3));
    layer.setSpeed(sf::Vector2i(200,300));

    std::vector<sf::Texture> textures;
    sf::Texture tex;
    tex.loadFromFile("fish1.png");
    textures.push_back(tex);
    tex.loadFromFile("fish2.png");
    textures.push_back(tex);
    tex.loadFromFile("fish3.png");
    textures.push_back(tex);

    layer.setTextures(textures);

}

FrontGround::FrontGround(std::vector<std::string> paths){
    layers = std::vector<Layer>();
    Layer layer;
    layer.setTimer(sf::Vector2i(1,3));
    layer.setSpeed(sf::Vector2i(200,300));

    std::vector<sf::Texture> textures;
    sf::Texture tex;

    for(int i = 0; i < paths.size(); ++i){
        tex.loadFromFile(paths[i]);
        textures.push_back(tex);
    }

    layer.setTextures(textures);

}

void FrontGround::update(float deltatime){
    for(int i = 0; i < layers.size(); ++i){
        layers[i].update(deltatime);
    }
}

void FrontGround::draw(sf::RenderWindow &window){
    for(int i = 0; i < layers.size(); ++i){
        layers[i].draw(window);
    }
}
