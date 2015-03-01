#include "UI.hpp"

#include "GameManger.hpp"

UI::UI(){
  timer = 0;
}

void UI::update(float deltaTime) {
  timer += deltaTime;
}


