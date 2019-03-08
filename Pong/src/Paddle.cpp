#include "Paddle.h"

Paddle::Paddle(float sizeX, float sizeY, float initialPosX, float initialPosY)
	: sf::RectangleShape(sf::Vector2f(sizeX, sizeY))
{
	setFillColor(sf::Color::White);
	setPosition(initialPosX, initialPosY);

}
