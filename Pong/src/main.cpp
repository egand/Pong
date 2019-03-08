#include <SFML/Graphics.hpp>
#include "Ball.h"
#include "Paddle.h"
#include "Player.h"

int main()
{
	sf::RenderWindow window(sf::VideoMode(800, 600), "Pong");
	Ball ball(7, 400, 300);
	Paddle paddle1(20, 100, 30, 300);
	Paddle paddle2(20, 100, 770, 300);
	Player p1(&paddle1, sf::Keyboard::Key::W, sf::Keyboard::Key::S);
	Player p2(&paddle2, sf::Keyboard::Key::Up, sf::Keyboard::Key::Down);

	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}

		window.clear();
		p1.input(window.getSize().y);
		p2.input(window.getSize().y);
		window.draw(ball);
		window.draw(paddle1);
		window.draw(paddle2);
		window.display();
	}

	return 0;
}