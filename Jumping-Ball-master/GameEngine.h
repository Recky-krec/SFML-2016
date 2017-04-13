#ifndef GAMEENGINE_H
#define GAMEENGINE_H
#include "SFML/Graphics.hpp"
#include "Ball.h"

class GameEngine
{
public:
	GameEngine(sf::RenderWindow *win, Ball *circle);
	void run();
	void draw();

private:
	sf::RenderWindow *window;
	Ball *circle;

};

#endif // GAMEENGINE_H
