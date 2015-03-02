#ifndef LAYER_HPP
#define LAYER_HPP

#include <list>
#include <SFML/Graphics.hpp>

class Layer{

private:
    float time;
    float spawnTimer;
    sf::Vector2i timer;
    sf::Vector2i speed;
    std::list<float> speeds;
    std::vector<sf::Texture> textures;
    std::list<sf::Sprite> activeSprites;

public:


    Layer();

    void setTextures(std::vector<sf::Texture> & newTextures);

    void update(float deltatime, sf::RenderWindow &window);

    void draw(sf::RenderWindow &window);

    sf::Vector2i getTimer() const;
    sf::Vector2i getSpeed() const;

    void setTimer(const sf::Vector2i &value);
    void setSpeed(const sf::Vector2i &value);
};

#endif // LAYER_HPP
