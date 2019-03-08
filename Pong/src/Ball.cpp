#include "Ball.h"

Ball::Ball(float radius, float initialPosX, float initialPosY)
	: sf::CircleShape(radius)
{
	this->posX = initialPosX;
	this->posY = initialPosY;
	setPosition(this->posX, this->posY);
	setFillColor(sf::Color::White);

}
