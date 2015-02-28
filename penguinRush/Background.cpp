#include "Background.hpp"

Background::Background(){

    textures[0].loadFromFile("res/background.png");
    sprites[0].setTexture(textures[0]);
    sprites[0].setPosition(0,0);

    textures[1].loadFromFile("res/background1.png");
    sprites[1].setTexture(textures[1]);
    sprites[1].setPosition(0,0);

    textures[2].loadFromFile("res/background2.png");
    sprites[2].setTexture(textures[2]);
    sprites[2].setPosition(0,0);

    textures[3].loadFromFile("res/background3.png");
    sprites[3].setTexture(textures[3]);
    sprites[3].setPosition(0,0);

}

void Background::update(float deltatime){
    //      /cry
    for(int i = 0; i < constant::backgroundSpeed.size(); ++i){
        sprites[i].move(constant::backgroundSpeed[i]*deltatime, 0);
    }
}

void Background::draw(sf::RenderWindow &window){
    for(int i = 0; i < constant::backgroundSpeed.size(); ++i){
        sprites[i].setScale(window.getSize().x/sprite.getGlobalBounds().width,
                        window.getSize().y/sprite.getGlobalBounds().height);
        window.draw(sprites[i]);
    }
}
