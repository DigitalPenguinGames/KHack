#include "Penguin.hpp"

#include <math.h>
#include <iostream>

Penguin::Penguin(int middle) : middle(middle), particles(1000) {
  text[0].loadFromFile("res/penguin1.png");
  text[1].loadFromFile("res/penguin2.png");
  sprite[0].setTexture(text[0]);
  sprite[1].setTexture(text[1]);
  float scale = ((middle*2.0f)/20.0f)/sprite[0].getLocalBounds().height;
  sprite[0].setScale(scale,scale);
  sprite[1].setScale(scale,scale);
  pos = middle;
  speed = 0;
  frame = 0;
  animationTimer = 0;
  jumping = false;
  penguinSpeedUp = middle*2;
  gravity = penguinSpeedUp*2.5;
  softGravity = middle;
  jumpingTimer = 0;
}

void Penguin::update(float deltaTime) {

  jumpingTimer -= deltaTime;
  if (jumpingTimer > 0 && !jumping) {
      jumpingTimer = 0;
      int value;
      if (dir == direction::up) value = -1;
      else value = 1;
      speed = value*penguinSpeedUp;
      jumping = true;
    }

  float aPos = pos;
  pos += deltaTime*speed;
  if (pos < middle/16) pos = middle/16;
  if (pos > 2*middle - middle/8) pos = 2*middle - middle/8;

  if ((aPos < middle && pos > middle && dir == direction::up  ) ||
      (aPos > middle && pos < middle && dir == direction::down)) {
      speed = speed / 10;
      jumping = false;
    }

  float auxGrav = (abs(pos-middle)<100?softGravity:gravity);

  if (pos < middle) speed += auxGrav*deltaTime;
  else speed -= auxGrav*deltaTime;

  animationTimer += deltaTime;
  while (animationTimer > constant::timeToNextFramePeng) {
      animationTimer -= constant::timeToNextFramePeng;
      frame = (frame + 1) % 2;
    }

  if((speed < 0 && pos < middle) || (speed > 0 && pos > middle) || std::abs(pos-middle) < 20 ) {
      particles.setEmitter(sf::Vector2f(sprite[frame].getPosition().x,
                                        sprite[frame].getPosition().y+sprite[frame].getGlobalBounds().height/2));
      sf::Time time;
      time = sf::seconds(deltaTime);
      particles.update(time, true);
    }
  else{
      sf::Time time;
      time = sf::seconds(deltaTime);
      particles.update(time, false);
    }

  sprite[frame].setRotation(std::atan2(speed,(constant::obstacleSpeed))*180/M_PI);
}

void Penguin::draw(sf::RenderWindow &window) {
  sprite[frame].setPosition(constant::penguinInitX,pos);
  window.draw(sprite[frame]);
  window.draw(particles);
}


void Penguin::setSpeed(const float &value) {
  if (value > 0) dir = direction::down;
  else dir = direction::up;
  jumpingTimer = 0.1;

}

sf::Vector2f Penguin::getHead() {
  float x = sprite[frame].getGlobalBounds().width+constant::penguinInitX;
  float y = sprite[frame].getGlobalBounds().height/2+pos;
  return sf::Vector2f(x,y);
}
