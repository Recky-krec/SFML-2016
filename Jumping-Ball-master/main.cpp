#include <iostream>
#include "SFML/Graphics.hpp"
#include "GameEngine.h"
#include "Ball.h"

using namespace std;

const int displayWidth = 1200;
const int displayHeight = 1000;

int main()
{
	//Window object
	sf::ContextSettings settings;
	settings.antialiasingLevel = 8;
	sf::RenderWindow window(sf::VideoMode(displayWidth,displayHeight), "Jumping-Ball",sf::Style::Default, settings);
	
	//Ball object
	Ball circle(displayWidth,displayHeight);
	
	//Game engine object
	GameEngine engine(&window, &circle);
	
	while(window.isOpen())
	{
		engine.run();
		engine.draw();
	}
	
	return 0;
}