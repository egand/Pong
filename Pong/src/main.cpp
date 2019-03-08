#include <SFML/Graphics.hpp>
#include <string>
#include <ctime>
#include <cstdlib>
#include "Ball.h"
#include "Paddle.h"
#include "Player.h"

/* TODO
	constant variables
	set velocity based on where the ball touch the paddle
	player score
	a bit more UI for the game
	menu
	multiplayer
	singleplayer with computer
*/

namespace Pong
{
	const int WinW = 800;
	const int WinH = 600;
	const int PaddleW = 20;
	const int PaddleH = 100;
	const int WinMarginW = 30;
}


bool checkScore(Ball *b, Player* p1, Player* p2);

int main()
{
	srand(time(0));
	sf::RenderWindow window(sf::VideoMode(Pong::WinW, Pong::WinH), "Pong");
	Ball ball(7, 400, 300, rand() % 2 ? Direction::LEFT : Direction::RIGHT, rand() % 2 ? Direction::TOP : Direction::BOTTOM, 0.05);
	Paddle paddle1(Pong::PaddleW, Pong::PaddleH, Pong::WinMarginW, Pong::WinH / 2 - (Pong::PaddleH / 2));
	Paddle paddle2(Pong::PaddleW, Pong::PaddleH, Pong::WinW - (Pong::PaddleW + Pong::WinMarginW), Pong::WinH / 2 - (Pong::PaddleH / 2));
	Player p1(&paddle1, sf::Keyboard::Key::W, sf::Keyboard::Key::S);
	Player p2(&paddle2, sf::Keyboard::Key::Up, sf::Keyboard::Key::Down);
	sf::Font font;
	font.loadFromFile("arial.ttf");
	
	sf::Text text;
	text.setFont(font);
	text.setCharacterSize(20);
	text.setPosition(Pong::WinW / 2 - 15, 10);

	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}
		text.setString(std::to_string(p1.getScore()) + " | " + std::to_string(p2.getScore()));
		
		window.clear();
		p1.input(window.getSize().y);
		p2.input(window.getSize().y);
		ball.checkCollision(&window, &paddle1, &paddle2);
		ball.move();
		if (checkScore(&ball, &p1, &p2))
			ball.reset(400, 300, rand()%2 ? Direction::LEFT : Direction::RIGHT, rand() % 2 ? Direction::TOP : Direction::BOTTOM, 0.05);
		window.draw(ball);
		window.draw(paddle1);
		window.draw(paddle2);
		window.draw(text);
		window.display();
	}

	return 0;
}

bool checkScore(Ball *b, Player* p1, Player* p2)
{
	if (b->getPosition().x <= 0) {
		p1->incrementScore();
		return true;
	}
		
	else if (b->getPosition().x >= Pong::WinW) {
		p2->incrementScore();
		return true;
	}
	return false;
}