#pragma once
#include <SFML/Graphics.hpp>

class Paddle : public sf::RectangleShape {
public:
	Paddle(float sizeX, float sizeY, float posX, float posY);
};
