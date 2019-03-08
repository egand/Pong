#pragma once

#include "Paddle.h"

class Player {
private:
	int score;
	Paddle* paddle;
	sf::Keyboard::Key moveUp;
	sf::Keyboard::Key moveDown;
public:
	Player(Paddle* paddle);
	Player(Paddle* paddle, sf::Keyboard::Key moveUp, sf::Keyboard::Key moveDown);
	inline void incrementScore() { score = score + 1; }
	inline void resetScore() { score = 0; }
	inline int getScore() { return score; }
	void bindKeys(sf::Keyboard::Key moveUp, sf::Keyboard::Key moveDown);
	inline void bindMoveUpKey(sf::Keyboard::Key moveUp) { this->moveUp = moveUp; }
	inline void bindMoveDownKey(sf::Keyboard::Key moveDown) { this->moveDown = moveDown; }
	void input(float bottomBoundary);
};