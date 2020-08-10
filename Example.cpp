
////////////////////////////////////////////////////////////
// Headers
////////////////////////////////////////////////////////////
#include "Example.h"
#include <string> 
#include <iostream>
#include <time.h>
#include <numeric>
#include <algorithm>

void startExample() {

	srand(time(NULL));

	std::vector <std::shared_ptr<crv::Curve>> shapes;

	generateRandomShapes(&shapes);
	outputShapes(&shapes);

	std::vector <std::shared_ptr<crv::Curve>> circles;
	splitVectorOfShapes(&shapes, &circles);

	std::sort(circles.begin(), circles.end(),
		[](std::shared_ptr<crv::Curve>& i, std::shared_ptr<crv::Curve>& j) {return i->getRadius() < j->getRadius(); });
	std::cout << "\nSorted Circles:\n";
	for (auto &i : circles) {
		std::cout << "Circle radius is " << i->getRadius() << std::endl;
	}

	std::cout << "\nTotal sum of all circles radius = " << std::accumulate(circles.begin(), circles.end(), 0,
		[](int i, const std::shared_ptr<crv::Curve>& o) { return o->getRadius() + i; });
}

void generateRandomShapes(std::vector <std::shared_ptr<crv::Curve>> * shapes) {
	int upperBound = 10; //!< upper bound of maximum generated curves per type
	int numberOfShapes = 3; //!< number of curves types
	int buf = rand() % numberOfShapes;  
	std::vector <int> currentShapeCount(numberOfShapes); //counting vector, where currentShapeCount[0] = n, n - number of current circles that must be created and ect.

	//fills vector with random amount of each type
	std::generate(currentShapeCount.begin(), currentShapeCount.end(), randomNumber); 

	while (std::accumulate(currentShapeCount.begin(), currentShapeCount.end(), 0) > 0) {

		//choosing new type of curve
		while (currentShapeCount[buf = rand() % numberOfShapes] == 0) {}

		switch (buf) {
		case 0:
			shapes->push_back(std::shared_ptr<crv::Curve>(new crv::Circle(rand() % upperBound + 1)));
			currentShapeCount[buf]--;
			break;
		case 1:
			shapes->push_back(std::shared_ptr<crv::Curve>(new crv::Ellipse(rand() % upperBound + 1, rand() % upperBound + 1)));
			currentShapeCount[buf]--;
			break;
		case 2:
			shapes->push_back(std::shared_ptr<crv::Curve>(new crv::Helix(rand() % upperBound + 1, rand() % upperBound + 1)));
			currentShapeCount[buf]--;
			break;
		default:
			break;
		}
	}
}

int randomNumber() { 
	//there must be at least one curve
	return (rand() % 10 + 1); 
}

void outputShapes(std::vector <std::shared_ptr<crv::Curve>> * shapes) {
	for (auto &i : *shapes) {

		crv::Point bufPoint = i->findPoint(PI / 4);
		crv::Point bufVector = i->tangentVector(PI / 4);
		switch (i->typeOfCurve()) {
		case CIRCLE:
			std::cout << "Circle\n";
			break;
		case ELLIPSE:
			std::cout << "Ellipse\n";
			break;
		case HELIX:
			std::cout << "Helix\n";
			break;
		default:
			break;
		}

		std::cout << "x = " << bufPoint.x << "\ty = " << bufPoint.y << "\tz = " << bufPoint.z << std::endl
			<< "Tanget vector\n" << "x = " << bufVector.x << "\ty = " << bufVector.y << "\tz = " << bufVector.z << "\n=================================\n";
	}
}

void splitVectorOfShapes(std::vector <std::shared_ptr<crv::Curve>> * shapes, std::vector <std::shared_ptr<crv::Curve>> * circles) {
	for (auto &i : *shapes) {
		if (i->typeOfCurve() == CIRCLE) {
			circles->push_back(i);
		}
	}
}
