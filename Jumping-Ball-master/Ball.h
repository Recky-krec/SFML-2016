#ifndef BALL_H
#define BALL_H
#include "SFML/Graphics.hpp"

class Ball
{
public:
	Ball(const int displayWidth, const int displayHeight);
	//Ball careteristics
	sf::CircleShape circle();
	void physics();
	void move_up();
	void move_right();
	void move_left();
	void move_down();
	
	//Hardcoded obstacle
	void obstacle_physics();

private:
	const int displayWidth;
	const int displayHeight;
	
	int radius = 25;
	
	double gravity = 0.01;
	double accel = 0;
	double velocity = 0;
	
	double x_accel = 0;
	double x_velocity = 0;
	
	double x = displayWidth/2;
	double y = displayHeight - radius;

};

#endif // BALL_H
