#ifndef GAMEENGINE_H
#define GAMEENGINE_H
#include "SFML/Graphics.hpp"
#include "Circle.h"

class GameEngine
{
public:
	GameEngine(sf::RenderWindow *window, Circle circle);
	void run();

private:
	sf::RenderWindow *window;
	Circle circle;
	double speed;

};

#endif // GAMEENGINE_H
