#include <iostream>
#include "SFML/Graphics.hpp"
#include "FrameEngine.h"
#include "Pen.h"

using namespace std;

int displayWidth = 1280;
int displayHeight = 720;

int main() 
{
	sf::ContextSettings settings;
	settings.antialiasingLevel = 8;
	sf::RenderWindow window(sf::VideoMode(displayWidth,displayHeight), "Painter",sf::Style::Default, settings);
	
	//window.setFramerateLimit(60); //Delete "//" at the start of the line if you want the program to run less recurse expensively.

	Pen pen(&window);
	
	FrameEngine engine(&window, &pen);
	
	while(window.isOpen())
	{
		engine.run();
		
		if (pen.get_pen_status() == true)
		{
			pen.write();
		}
		else if (pen.get_pen_status() == false){}
		
		engine.draw();
		
	}
	
	return 0;
}
