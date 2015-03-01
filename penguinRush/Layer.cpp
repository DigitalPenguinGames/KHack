#include <iostream>
#include "Layer.hpp"

Layer::Layer(){
    time = 0.0;
    spawnTimer = 0.0;
    timer.x = 1; timer.y = 2;
    speed.x = 200; speed.y = 300;
    speeds = std::list<float> ();
    textures = std::vector<sf::Texture> ();
    activeSprites = std::list<sf::Sprite> ();

}

void Layer::setTextures(std::vector<sf::Texture> &newTextures){
    textures = newTextures;
}

void Layer::update(float deltatime, sf::RenderWindow& window){
//    std::cout << "spoiler" << std::endl;
    time += deltatime;
    auto speedIt = speeds.begin();
    for(auto it = activeSprites.begin(); it != activeSprites.end(); ++it){
        (*it).move(-(*speedIt)*deltatime, 0);
        ++speedIt;
    }

    if(time >= spawnTimer){
        sf::Sprite sprite;
        sprite.setTexture(textures[rand()%textures.size()]);
        float posY = window.getSize().y/2 + rand()%window.getSize().y/2 +20;
        sprite.setPosition(window.getSize().x,posY);
        activeSprites.push_back(sprite);
        speeds.push_back((rand())%(speed.y-speed.x) + speed.x);
//std::cout << "penguins" << std::endl;
        spawnTimer = (rand())%(timer.y-timer.x) + timer.x;
        time = 0.0;
    }

    auto it = activeSprites.begin();
    if((*it).getPosition().x < -(*it).getLocalBounds().width){
        activeSprites.pop_front();
    }

}

void Layer::draw(sf::RenderWindow &window){
    for(auto it = activeSprites.begin(); it != activeSprites.end(); ++it){
        window.draw(*it);
    }
}

sf::Vector2i Layer::getTimer() const            { return timer; }

void Layer::setTimer(const sf::Vector2i &value) { timer = value;}

sf::Vector2i Layer::getSpeed() const            {  return speed;}

void Layer::setSpeed(const sf::Vector2i &value) { speed = value;}
