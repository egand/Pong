#pragma once

#include <SFML/Graphics.hpp>

class Ball : public sf::CircleShape {
private:
	float posX;
	float posY;
public:
	Ball(float radius, float initialPosX, float initialPosY);
};