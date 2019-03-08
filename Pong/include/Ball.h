#pragma once

#include <SFML/Graphics.hpp>
#include "Paddle.h"
enum Direction { LEFT = -1, RIGHT = 1, TOP = -1, BOTTOM = 1 };

class Ball : public sf::CircleShape 
{
private:
	Direction dX, dY;
	float angle;

public:
	Ball(float radius, float initialPosX, float initialPosY, Direction dX, Direction dY, float angle);
	inline Direction getDirectionX() { return dX; }
	inline Direction getDirectionY() { return dY; }
	inline void toggleDirectionX() { dX = dX == Direction::LEFT ? Direction::RIGHT : Direction::LEFT; }
	inline void toggleDirectionY() { dY = dY == Direction::TOP ? Direction::BOTTOM : Direction::TOP; }
	inline void setDirectionX(Direction dX) { this->dX = dX; }
	inline void setDirectionY(Direction dY) { this->dY = dY; }
	void reset(float initialPosX, float initialPosY, Direction dX, Direction dY, float angle);
	void move();
	void checkCollision(sf::RenderWindow* window, Paddle* p1, Paddle* p2);

};