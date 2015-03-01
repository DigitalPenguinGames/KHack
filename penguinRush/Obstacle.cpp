#include "Obstacle.hpp"
#include <iostream>

Obstacle::Obstacle(obstacle::obsType type, float x, float y) {
  switch (type) {
    case obstacle::Iceberg:
      text.loadFromFile("res/iceberg2.png");
      break;
    case obstacle::Buoy:
      text.loadFromFile("res/buoy.png");
      break;
    case obstacle::Bottle:
      text.loadFromFile("res/bottle.png");
    default:
      std::cout << "Te olvidas de algo" << std::endl;
      break;
    }
  sprite.setTexture(text);
  switch (type) {
    case obstacle::Iceberg:
      sprite.setOrigin(0,sprite.getGlobalBounds().height/6);
      break;
    case obstacle::Buoy:
      sprite.setOrigin(0,sprite.getGlobalBounds().height*4/5);
    case obstacle::Bottle:
      sprite.setOrigin(0,sprite.getLocalBounds().height/2);
    default:
      break;
    }
  pos = sf::Vector2f(x,y);
}

void Obstacle::update(float deltaTime) {
  pos.x -= constant::obstacleSpeed*deltaTime;
  sprite.setPosition(pos);
}

void Obstacle::draw(sf::RenderWindow &window) {
  window.draw(sprite);
}

bool Obstacle::isOutOfWindow() {
  return pos.x < -sprite.getLocalBounds().width;
}

const sf::FloatRect &Obstacle::getBounds() {
  return sprite.getGlobalBounds();
}

sf::Image Obstacle::getImage() {
  return text.copyToImage();
}

sf::Vector2f Obstacle::getPosition() {
  return pos;
}

