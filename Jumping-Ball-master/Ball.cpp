#include "Ball.h"
#include "SFML/Graphics.hpp"
//REMOVE AFTER ---------------------------------------------------------
#include <iostream>
using namespace std;


Ball::Ball(const int displayWidth, const int displayHeight)
: displayWidth(displayWidth), displayHeight(displayHeight)
{
}

sf::CircleShape Ball::circle()
{
	sf::CircleShape circle(radius);
	circle.setFillColor(sf::Color(102,51,255));
	circle.setOrigin(circle.getRadius(),circle.getRadius());
	circle.setPosition(x,y);
	circle.setPointCount(100);
	return circle;
}

void Ball::physics()
{
	if (y > displayHeight - radius)
	{
		y = displayHeight - radius;
		velocity = -velocity + velocity/6;
		accel = 0;
		gravity = 0.01;
	}
	
	else if (x > displayWidth - radius)
	{
		x = displayWidth - radius;
		accel = 0;
		velocity = 0;
		x_accel = 0;
		x_velocity = -x_velocity + x_velocity/2;
	}
	
	else if (x < 0 + radius)
	{
		
		x = 0 + radius;
		accel = 0;
		velocity = 0;
		x_accel = 0;
		x_velocity = -x_velocity + x_velocity/2;
	}
	
	else if (velocity <= -2)
	{
		velocity += 0.5;
	}
	
	else if (accel <= -4)
	{
		accel += 0.5;
	}
	
	else
	{
		velocity += gravity;
		accel -= 0.001;
		y += velocity;
		x += x_velocity;

	}

}

void Ball::move_up()
{
	accel += -3;
	//cout << "Current Acellaration: " << accel << endl;
	velocity += accel;
	//cout << "Current Velocity: " << velocity << endl;
}

void Ball::move_right()
{
	x_accel = 0;
	x_accel += 2;
	x_velocity += x_accel;

}

void Ball::move_left()
{
	x_accel = 0;
	x_accel += -2;
	x_velocity += x_accel;

}

void Ball::move_down()
{
	gravity += 0.01;
	
}

void Ball::obstacle_physics()
{
	if ( (x+radius > 400 && x-radius < 700) && (y+radius >= 300  && y < 300+50) )
	{
		y = 300 - radius;
		velocity = -velocity + velocity/6;
		accel = 0;
		gravity = 0.01;
	}
	else if ( (x+radius > 400 && x-radius < 700) && (y-radius <= 300+50  && y > 300 ) )
	{
		
		accel = 0;
		velocity = 0;
		x_accel = 0;
		velocity = -velocity + velocity/2;
		
	}
}