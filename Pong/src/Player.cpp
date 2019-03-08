#include "Player.h"

Player::Player(Paddle * paddle)
{
	this->paddle = paddle;
	this->score = 0;
}

Player::Player(Paddle * paddle, sf::Keyboard::Key moveUp, sf::Keyboard::Key moveDown)
	: Player(paddle)
{
	bindKeys(moveUp, moveDown);
}

void Player::bindKeys(sf::Keyboard::Key moveUp, sf::Keyboard::Key moveDown)
{
	bindMoveUpKey(moveUp);
	bindMoveDownKey(moveDown);
}

void Player::input(float bottomBoundary)
{
	if (sf::Keyboard::isKeyPressed(moveUp)) {
		if (paddle->getPosition().y > 0) {
			paddle->move(sf::Vector2f(0, -0.15));
		}
		
	}
	else if (sf::Keyboard::isKeyPressed(moveDown)) {
		if (paddle->getPosition().y + paddle->getLocalBounds().height < bottomBoundary) {
			paddle->move(sf::Vector2f(0, 0.15));
		}
	}
}
