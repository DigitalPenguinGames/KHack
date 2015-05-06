#include "Background.hpp"

Background::Background(){
    sprites = std::vector<sf::Sprite> (constant::qttBackgrounds);
    textures = std::vector<sf::Texture> (constant::qttBackgrounds+1);
    secondSprites = std::vector<sf::Sprite> (constant::qttBackgrounds);


    textures[0].loadFromFile("res/background.png");
    textures[1].loadFromFile("res/background1.png");
    textures[2].loadFromFile("res/background2.png");
    textures[3].loadFromFile("res/background3.png");

    for(int i = 0; i < constant::qttBackgrounds; ++i){
        sprites[i].setTexture(textures[i]);
        secondSprites[i].setTexture(textures[i]);
        sprites[i].setPosition(0,0);
        secondSprites[i].setPosition(sprites[i].getLocalBounds().width,0);
    }
    textures[4].loadFromFile("res/background1_2.png");
    secondSprites[1].setTexture(textures[4]);
}

void Background::update(float deltatime){
    //      /cry
    for(int i = 0; i < constant::qttBackgrounds; ++i){
        sprites[i].move(-constant::backgroundSpeed[i]*deltatime, 0);
        secondSprites[i].move(-constant::backgroundSpeed[i]*deltatime, 0);

        if(sprites[i].getPosition().x <= -sprites[i].getLocalBounds().width)
            sprites[i].setPosition(sprites[i].getLocalBounds().width,0);
        if(secondSprites[i].getPosition().x <= -secondSprites[i].getLocalBounds().width)
            secondSprites[i].setPosition(secondSprites[i].getLocalBounds().width,0);
    }

}

void Background::draw(sf::RenderWindow &window){

    for(int i = 0; i < constant::qttBackgrounds; ++i){
        sprites[i].setScale(window.getSize().x/sprites[i].getLocalBounds().width,
                        window.getSize().y/sprites[i].getLocalBounds().height);
        secondSprites[i].setScale(window.getSize().x/secondSprites[i].getLocalBounds().width,
                        window.getSize().y/secondSprites[i].getLocalBounds().height);
        window.draw(sprites[i]);
        window.draw(secondSprites[i]);
    }

}
