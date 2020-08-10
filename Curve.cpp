
////////////////////////////////////////////////////////////
// Headers
////////////////////////////////////////////////////////////
#include "Curve.h"
#include <cassert>
#include <math.h>


namespace crv {
////////////////////////////////////////////////////////////
Curve::Curve(double radi, int _curveType) :
	radius{ radi > 0 ? radi : 
	throw "Invalid first argument for curve constructor. Radius must be more than 0" },
	curveType{ _curveType } {}


////////////////////////////////////////////////////////////
double Curve::getRadius() { 
	return radius; 
}


////////////////////////////////////////////////////////////
int Curve::typeOfCurve() { 
	return curveType; 
}


////////////////////////////////////////////////////////////
Circle::Circle(double radi) : 
	Curve(radi, CIRCLE) {}



////////////////////////////////////////////////////////////
Point Circle::findPoint(double t) {
	Point point;

	//finds point with parametric equation of Circle
	// x(t) = r * cos(t)
	// y(t) = r * sin(t)
	// z constantly equal to zero
	point.x = radius * cos(t);
	point.y = radius * sin(t);
	point.z = 0;
	return point;
}


////////////////////////////////////////////////////////////
Point Circle::tangentVector(double t) {
	Point vector;
	//Finds magnitude where its equalt to 
	// ||r'(t)||

	double magnitude = sqrt(pow(-1 * radius * sin(t), 2) + pow(radius * cos(t), 2));

	//Finds tangent vector, where
	//          r'(t)
	//  T(t) = ---------
	//         ||r'(t)||
	vector.x = (-1 * radius * sin(t)) / magnitude;
	vector.y = (radius * cos(t)) / magnitude;
	vector.z = 0;
	return vector;
}


////////////////////////////////////////////////////////////
Ellipse::Ellipse(double firstRadi, double secondRadi) : 
	Curve(firstRadi, ELLIPSE),
	secondRadius{ secondRadi > 0 ? secondRadi : throw "Invalid second argument for curve constructor. Radius must be more than 0" } {}


////////////////////////////////////////////////////////////
Point Ellipse::findPoint(double t) {
	Point point;

	//finds point with parametric equation of Ellipse
	// x(t) = r0 * cos(t)
	// y(t) = r1 * sin(t)
	// z constantly equal to zero
	point.x = radius * cos(t);
	point.y = secondRadius * sin(t);
	point.z = 0;
	return point;
}


////////////////////////////////////////////////////////////
Point Ellipse::tangentVector(double t) {
	//Finds magnitude where its equalt to 
	// ||r'(t)||
	double magnitude = sqrt(pow(-1 * radius * sin(t), 2) + pow(secondRadius * cos(t), 2));
	Point vector;

	//Finds tangent vector, where
	//          r'(t)
	//  T(t) = ---------
	//         ||r'(t)||
	vector.x = (-1 * radius * sin(t)) / magnitude;
	vector.y = (secondRadius * cos(t)) / magnitude;
	vector.z = 0;
	return vector;
}


////////////////////////////////////////////////////////////
void Ellipse::getRadius(double* firstRadius, double* secondRadius) {
	*firstRadius = radius;
	*secondRadius = this->secondRadius;
}


////////////////////////////////////////////////////////////
Helix::Helix(double radi, double _step) : 
	Curve(radi, HELIX), 
	step{ _step } {}


////////////////////////////////////////////////////////////
Point Helix::findPoint(double t) {
	Point point;

	//finds point with parametric equation of Helix
	point.x = radius * cos(t);
	point.y = radius * sin(t);
	point.z = step / (2 * PI) * t;
	return point;
}


////////////////////////////////////////////////////////////
Point Helix::tangentVector(double t) {
	Point vector;
	//Finds magnitude where its equalt to 
	// ||r'(t)||
	double magnitude = sqrt(pow(-1 * radius * sin(t), 2) + pow(radius * cos(t), 2) + pow(step / (2 * PI), 2));

	//Finds tangent vector, where
	//          r'(t)
	//  T(t) = ---------
	//         ||r'(t)||
	vector.x = (-1 * radius * sin(t)) / magnitude;
	vector.y = (radius * cos(t)) / magnitude;
	vector.z = (step / (2 * PI)) / magnitude;
	return vector;
}
} //namespace crv