#ifndef FRAMEENGINE_H
#define FRAMEENGINE_H
#include "SFML/Graphics.hpp"
#include "Pen.h"

class FrameEngine
{
public:
	FrameEngine(sf::RenderWindow *win,Pen *pen);
	void run();
	void draw();

private:
	sf::RenderWindow *window;
	Pen *pen;

};

#endif // FRAMEENGINE_H
