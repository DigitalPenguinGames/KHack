#include "Obstacle.hpp"

Obstacle::Obstacle(obstacle::obsType type) {
  switch (type) {
    case obstacle::Iceberg:
//      text.loadFromFile("res/iceberg.png")
      break;
    case obstacle::Buoy:
      text.loadFromFile("res/buoy.png");
      break;
    default:
      break;
    }
}

void Obstacle::update(float deltaTime)
{
}

void Obstacle::draw(sf::RenderWindow &window) {
  window.draw(sprite);
}
