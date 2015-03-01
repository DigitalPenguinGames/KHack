#include "UI.hpp"
#include "GameManger.hpp"
#include <sstream>

UI::UI(sf::Vector2u wSize) :
  wSize(wSize),
  restart(true),
  timer(0)
{
  font.loadFromFile("res/font.otf");
  tTimer.setFont(font);
  tTimer.setColor(sf::Color::Black);
  tHighscores.setFont(font);
  tHighscores.setColor(sf::Color::Black);
  finalMsg.setFont(font);
  finalMsg.setColor(sf::Color::Black);
  finalMsg.setCharacterSize(60);
  finalMsg.setString("You lose!");
  finalMsg.setOrigin(finalMsg.getLocalBounds().width/2,0);
  finalMsg.setPosition(wSize.x/2, wSize.y/8);

  yourScore.setFont(font);
  yourScore.setColor(sf::Color::Black);
  yourScore.setCharacterSize(60);
  yourScore.setString("Your score is:");
  yourScore.setOrigin(yourScore.getLocalBounds().width/2,0);
  yourScore.setPosition(wSize.x/2, wSize.y*3/8);

  restartex.setFont(font);
  restartex.setColor(sf::Color::Black);
  restartex.setCharacterSize(60);
  restartex.setString("Step on pad to restart the game!");
  restartex.setOrigin(restartex.getLocalBounds().width/2,0);
  restartex.setPosition(wSize.x/2, wSize.y*6/8);

    //llegir del fitxer a highscores
    std::string score;
    std::ifstream myfile ("res/Spoiler.txt");
    if (myfile.is_open()) {
      std::getline(myfile,score);
      myfile.close();
    }
    else std::cout << "Unable to open file" << std::endl;
    highscores = std::stoi(score);
    tHighscores.setString(score);


}

void UI::update(float deltaTime) {
  timer += deltaTime*1234;
}

void UI::draw(sf::RenderWindow &window, bool running) {
  if (running) {
      if (restart) {
          restart = 0;
          timer = 0;


          tTimer.setCharacterSize(30);
          tTimer.setOrigin(0,0);
          tTimer.setPosition(50,50);

          tHighscores.setCharacterSize(30);
          tHighscores.setOrigin(tHighscores.getLocalBounds().width,0);
          tHighscores.setPosition(wSize.x-50,50);
        }
      std::stringstream text2;
      text2 << int(timer);
      std::string str = text2.str();
      tTimer.setString(str);

      window.draw(tTimer);
      window.draw(tHighscores);
    }
  else {
      if (!restart) {
          restart = true;

          tTimer.setCharacterSize(40);
          tTimer.setOrigin(tTimer.getLocalBounds().width/2,0);
          tTimer.setPosition(wSize.x/2,wSize.y/2);

          tHighscores.setCharacterSize(30);
          tHighscores.setOrigin(tHighscores.getLocalBounds().width,0);
          tHighscores.setPosition(wSize.x-50,50);



          if (timer > highscores) {

              highscores = timer;
              std::stringstream text2;
              text2 << int(highscores);
              std::string str = text2.str();
              tHighscores.setString(str);
              tHighscores.setOrigin(tHighscores.getLocalBounds().width,0);
              tHighscores.setPosition(wSize.x-50,50);

              //escriure highscore
              std::ofstream myfile ("res/Spoiler.txt");
                if (myfile.is_open()) {
                    myfile << str;

                    myfile.close();
                }
                else std::cout << "Unable to open file";

              system("python scripts/yoAll.py");

            }
        }

      else {
          window.draw(tTimer);
          window.draw(tHighscores);
          window.draw(finalMsg);
          window.draw(yourScore);
          window.draw(restartex);
        }
    }
}


