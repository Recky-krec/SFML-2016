#ifndef CIRCLE_H
#define CIRCLE_H
#include "SFML/Graphics.hpp"
#include "my_calculator.h"


class Circle
{
public:
	Circle(double circleRadius,double circle_x, double circle_y);
	sf::CircleShape circle();
	sf::CircleShape dot();
	void dot_orbit();
	void set_orbit_speed(double speed);
	
private:
	double radius, x1, y1;
	double orbit_speed;
	
	double dot_x;
	double dot_y;
	
	bool pointA;
	bool pointB;
	
};

#endif // CIRCLE_H
