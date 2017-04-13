#include "FrameEngine.h"
#include "SFML/Graphics.hpp"
#include <iostream>
#include "Pen.h"

using namespace std;

FrameEngine::FrameEngine(sf::RenderWindow *win, Pen *pen)
: window(win), pen(pen)
{
}

void FrameEngine::run()
{
	sf::Event event;
	// while there are pending events...
	while (window->pollEvent(event))
	{
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
					pen->up_arr_color();
					break;
				}
				if(event.key.code == sf::Keyboard::Down)
				{
					pen->down_arr_color();
					break;
				}
				if(event.key.code == sf::Keyboard::Left)
				{
					window->clear(sf::Color::Black);
					break;
				}
				if(event.key.code == sf::Keyboard::Right)
				{
					window->clear(sf::Color::White);
					break;
				}
				
				
			case sf::Event::MouseButtonPressed:
				if (event.key.code == sf::Mouse::Left)
				{
					pen->set_pen_status(true);
					break;
				}
				
			case sf::Event::MouseButtonReleased:
				if (event.key.code == sf::Mouse::Left)
				{
					pen->set_pen_status(false);
					break;
				}

			case sf::Event::MouseWheelScrolled:
				pen->change_pen_radius(event.mouseWheelScroll.delta);
		}
	}
	
	
}

void FrameEngine::draw()
{
	window->display();
}