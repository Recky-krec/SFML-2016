#include <iostream>
#include "my_calculator.h"
#include <cmath>
#include <vector>


std::vector<double> calculate_y(double x, double x1, double y1, double r)
{
	std::vector<double> solutions;
	double ys1 = y1 + pow((r*r)-(x*x)+(2*x*x1)-(x1*x1),0.5);
	double ys2 = y1 - pow((r*r)-(x*x)+(2*x*x1)-(x1*x1),0.5);
	
	solutions.push_back(ys1);
	solutions.push_back(ys2);

	return solutions;
}