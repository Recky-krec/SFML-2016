#include <iostream>
#include <SFML/Graphics.hpp>
#include "GameEngine.h"
#include <cmath>

using namespace std;

class Negative_Radius{};
class Negative_Coordinates{};

const int displayWidth = 1000;
const int displayHeight = 800;

int main()
{
    try
	{
		double circleRadius, circle_x, circle_y;
		
		cout << "*** Usage: Up == SpeedUp; Down == SpeedDown ***\n";
		cout << "**** Recommend values: 150 500 400 **** \n";
		cout << "Circle_Radius Circle_X Circle_Y : ";
		
		cin >> circleRadius >> circle_x >> circle_y;
		
		//Pre-conditions: Radius must be superior than 0; x and y must be superior/equal 0;
		if (!cin)
		{
			cin.clear();
			cin.ignore();
			circleRadius = 150;
			circle_x = 500;
			circle_y = 400;
		}
		if (circleRadius <= 0) throw Negative_Radius();
		if (circle_x < 0 || circle_y < 0) throw Negative_Coordinates();
		
	
		//Window object/settings
		sf::ContextSettings settings;
		settings.antialiasingLevel = 8;
		sf::RenderWindow window(sf::VideoMode(displayWidth, displayHeight), "circle-equation-simulator",sf::Style::Default, settings);
		//window.setFramerateLimit(60);
		
		//Engine/Circle Object
		Circle circle(circleRadius, circle_x, circle_y);
		GameEngine engine(&window, circle);
		
		while (window.isOpen())
		{
			engine.run();
		}	
	
		return 0;
	}
		
	catch(Negative_Radius)
	{
		cout << "Negative_Radius: user inputed negative radius (forbidden)" << endl;
		return 1;
	}
	catch(Negative_Coordinates)
	{
		cout << "Negative_Coordinates: user inputed negative coordinate (forbidden)" << endl;
		return 1;
	}
	catch(exception &e)
	{
		cout << "Error: " << e.what() << endl;
		return 1;
	}
	catch(...)
	{
		cout << "Unknow error, terminating" << endl;
		return 2;
	}
}