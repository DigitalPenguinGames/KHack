#include "Obstacle.hpp"
#include <iostream>

Obstacle::Obstacle(obstacle::obsType type, float x, float y) {
  switch (type) {
    case obstacle::Iceberg:
      text.loadFromFile("res/iceberg2.png");
      sprite.setOrigin(text.getSize().x/2,text.getSize().y/8);
      break;
//    case obstacle::Buoy:
//      text.loadFromFile("res/buoy.png");
//      sprite.setOrigin(0);
      break;
    default:
      std::cout << "Te olvidas de algo" << std::endl;
      break;
    }
  sprite.setTexture(text);
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

