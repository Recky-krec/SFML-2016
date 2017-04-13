#include "Pen.h"
#include "SFML/Graphics.hpp"
#include <iostream>
using namespace std;

Pen::Pen(sf::RenderWindow *win)
: window(win)
{
}

int Pen::get_pen_radius()
{
	return radius;
}

void Pen::change_pen_radius(int delta)
{
	radius += delta;
}

void Pen::set_pen_status(bool status)
{
	pen_down = status;
}

bool Pen::get_pen_status()
{
	return pen_down;
}

void Pen::up_arr_color()
{
	if (arr_color == 9)
		{
			arr_color == 9;
		}
	else
		arr_color += 1;
}

void Pen::down_arr_color()
{
	if (arr_color == 0)
		{
			arr_color == 0;
		}
	else
		arr_color -= 1;
	
}

void Pen::write()
{
	sf::Vector2i localPosition = sf::Mouse::getPosition(*window);
	//cout << "X: " << localPosition.x << " Y: " << localPosition.y << endl;
	
	//sf::Vertex line[] =
	//{
    //sf::Vertex(sf::Vector2f(localPosition.x, localPosition.y)),
    //sf::Vertex(sf::Vector2f(0, 0))
	//};
	//window->draw(line, 2, sf::Lines);
	
	sf::CircleShape circle(radius);
	circle.setFillColor(sf::Color(r[arr_color],g[arr_color],b[arr_color]));
	circle.setOrigin(circle.getRadius(),circle.getRadius());
	circle.setPosition(localPosition.x,localPosition.y);
	window->draw(circle);
	
}

