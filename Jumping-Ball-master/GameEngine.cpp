#include "GameEngine.h"
#include "SFML/Graphics.hpp"
#include "Ball.h"
#include <iostream>
using namespace std;

GameEngine::GameEngine(sf::RenderWindow *win, Ball *circle)
: window(win), circle(circle)
{
}

void GameEngine::run()
{
	sf::Event event;

	// while there are pending events...
	while (window->pollEvent(event))
	{
		// check the type of the event...
		switch (event.type)
		{
			// window closed
			case sf::Event::Closed:
				window->close();
				break;

			// key pressed
			case sf::Event::KeyPressed:
				if(event.key.code == sf::Keyboard::Up)
				{
					circle->move_up();
				}
				
				else if(event.key.code == sf::Keyboard::Right)
				{
					circle->move_right();
				}
				
				else if(event.key.code == sf::Keyboard::Left)
				{
					circle->move_left();
				}
				
				else if(event.key.code == sf::Keyboard::Down)
				{
					circle->move_down();
				}
				
				break;
			case sf::Event::KeyReleased:
				break;

			// we don't process other types of events
			default:
				break;
		}
	}
}

void GameEngine::draw()
{
	window->clear(sf::Color::White);
	
	circle->physics();
	circle->obstacle_physics();
	window->draw(circle->circle());
	
	//hardcoding a ractangule shape(obstacle)
	sf::RectangleShape obst(sf::Vector2f(300,50));
	obst.setPosition(400,300);
	obst.setFillColor(sf::Color(32,255,125));
	
	window->draw(obst);
	
	window->display();
}