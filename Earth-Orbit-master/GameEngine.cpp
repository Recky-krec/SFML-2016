#include "GameEngine.h"
#include "SFML/Graphics.hpp"
#include "Circle.h"
#include <iostream>

GameEngine::GameEngine(sf::RenderWindow *window, Circle circle)
: window(window), circle(circle)
{
	speed = 0.5;
}

void GameEngine::run()
{
	sf::Event event;
	while (window->pollEvent(event))
	{
		switch(event.type)
		{
			case sf::Event::Closed:
				window->close();
				break;
			
			case sf::Event::KeyPressed:
				if (event.key.code == sf::Keyboard::Up)
					{
						if (speed >= 0.7) speed = 1;
						else speed += 0.1;
						
						circle.set_orbit_speed(speed);
						std::cout << "SPEED : " << speed << std::endl;
						break;
					}
				if (event.key.code == sf::Keyboard::Down)
					{
						if (speed <= 0.1) speed = 0.1;
						else speed -= 0.1;
						
						circle.set_orbit_speed(speed);
						break;
						
					}
			
			
		}
	}
	
	window->clear(sf::Color(255,255,255));
	
	window->draw(circle.circle());
	window->draw(circle.dot());
	//i'm cheating, because i'm applying logic here ;D
	circle.dot_orbit();
	
	window->display();
	
}