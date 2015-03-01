#ifndef UI_HPP
#define UI_HPP

#include <SFML/Graphics.hpp>

class UI {
private:
  sf::Vector2f wSize;
  float timer;
  float highscores;
  sf::Font font;
  sf::Text tTimer;
  sf::Text tHighscores;
  sf::Text finalMsg;
  bool restart;
public:
  UI(sf::Vector2u wSize);
  void update(float deltaTime);
  void draw(sf::RenderWindow &window, bool running);
};

#endif // UI_HPP

