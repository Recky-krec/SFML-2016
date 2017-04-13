#include "Circle.h"
#include "SFML/Graphics.hpp"
#include <cmath>
#include "my_calculator.h"
#include <iostream>


using namespace std;

Circle::Circle(double circleRadius,double circle_x, double circle_y)
: radius(circleRadius), x1(circle_x), y1(circle_y)
{
	orbit_speed = 0.5;
	dot_x = x1 - radius;
	dot_y = y1;
	pointA = false;
	pointB = false;
}

sf::CircleShape Circle::circle()
{
	sf::CircleShape circle(radius);
	circle.setFillColor(sf::Color(255,255,255));
	circle.setOutlineThickness(5);
	circle.setOutlineColor(sf::Color(0,0,0));
	circle.setOrigin(circle.getRadius(),circle.getRadius());
	circle.setPosition(x1,y1);
	return circle; // Returns the orbit "line" shape, in order to be drawn.
}


sf::CircleShape Circle::dot()
{
	sf::CircleShape dot(radius/6);
	dot.setFillColor(sf::Color(0,0,255));
	dot.setOrigin(dot.getRadius(),dot.getRadius());
	dot.setPosition(dot_x,dot_y);
	return dot; // Returns the blue planet shape, (updating x,y)
}

void Circle::set_orbit_speed(double speed)
{
	orbit_speed = speed;
}

void Circle::dot_orbit()
{
	if (dot_x - 0.1 < x1-radius && dot_x + 0.1 > x1 -radius && pointA == false)
	{
		// point A is the most left side point of the circunference (less x possible)
		pointB = false;
		pointA = true;
	}
	if (dot_x - 0.1 < x1+radius && dot_x + 0.1 > x1 + radius && pointB == false)
	{
		// point B is the most right side point of the circunference (plus x possible)
		pointA = false;
		pointB = true;
	}
	
	if (pointA)
	{
		//if (dot_x >= x1 + radius/2 || dot_x <= x1 - radius/2);
		dot_x += orbit_speed;
		
		vector<double> dot_y12; // a vector containing two solutions of the circunference equation
		dot_y12 = calculate_y(dot_x,x1,y1,radius);
		dot_y = dot_y12[0]; // only the first solution is interseting here.
	}
		
	else if (pointB)
	{
		dot_x -= orbit_speed;
	
		
		vector<double> dot_y12; // a vector containing two solutions of the circunference equation
		dot_y12 = calculate_y(dot_x,x1,y1,radius);
		dot_y = dot_y12[1]; // only the second solution is interseting here.
		
	}
	
}