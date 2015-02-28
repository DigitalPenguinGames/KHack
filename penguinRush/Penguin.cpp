#include "Penguin.hpp"

Penguin::Penguin(int middle) : middle(middle) {
}

void Penguin::update(float deltaTime) {
  pos = deltaTime*speed;
  if (pos < middle) speed -= constant::gravity*deltaTime;
  else speed += constant::gravity*deltaTime;

//  if (std::abs(speed) < 5) speed = 0;
}

void Penguin::draw(sf::RenderWindow &window) {

}


void Penguin::setSpeed(const float &value) { speed = value; }
