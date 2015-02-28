#include "Penguin.hpp"

Penguin::Penguin()
{
}


void Penguin::setSpeed(const float &value) { speed.y = value; }

void Penguin::setPos(const sf::Vector2f &value){ pos = value; }
