#ifndef PEN_H
#define PEN_H
#include "SFML/Graphics.hpp"

class Pen
{
public:
	Pen(sf::RenderWindow *win);
	void write();
	bool get_pen_status();
	int get_pen_radius();
	void set_pen_status(bool status);
	void change_pen_radius(int delta);
	void up_arr_color();
	void down_arr_color();

private:
	int radius = 10;
	sf::RenderWindow *window;
	bool pen_down = false;
	
	int arr_color = 0;
	
	int r[10] = {255,124,0,220,253,255,0,255,0,0};
	int g[10] = {255,50,0,40,15,255,255,0,255,0};
	int b[10] = {255,220,0,30,213,0,255,0,0,255};
};

#endif // PEN_H
