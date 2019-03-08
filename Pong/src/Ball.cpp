#include "Ball.h"

Ball::Ball(float radius, float initialPosX, float initialPosY, Direction dX, Direction dY, float angle)
	: sf::CircleShape(radius)
{
	setPosition(initialPosX, initialPosY);
	setFillColor(sf::Color::White);
	this->dX = dX;
	this->dY = dY;
	this->angle = angle;
}

void Ball::reset(float initialPosX, float initialPosY, Direction dX, Direction dY, float angle)
{
	setPosition(initialPosX, initialPosY);
	this->dX = dX;
	this->dY = dY;
	this->angle = angle;
}

void Ball::move()
{
	sf::CircleShape::move(dX*angle, dY*angle);
}

void Ball::checkCollision(sf::RenderWindow * window, Paddle * p1, Paddle * p2)
{
	if (getGlobalBounds().intersects(p1->getGlobalBounds()) || getGlobalBounds().intersects(p2->getGlobalBounds()))
		toggleDirectionX();
	if (getPosition().y <= 0 || getPosition().y >= window->getSize().y)
		toggleDirectionY();
}
