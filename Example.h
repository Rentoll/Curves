#ifndef EXAMPLE_H
#define EXAMPLE_H

////////////////////////////////////////////////////////////
// Headers
////////////////////////////////////////////////////////////
#include "Curve.h"
#include <memory>
#include <vector>

void startExample();
//Returns random number between 1 and 10
int randomNumber();
//Filling vector of curves with circles/ellipses/helixes
void generateRandomShapes(std::vector <std::shared_ptr<crv::Curve>> * shapes);
//Outputs vector of curves with 3d point at PI/4
void outputShapes(std::vector <std::shared_ptr<crv::Curve>> * shapes);
//Separates pointers on circles from shapes vector and saving them in circles vector
void splitVectorOfShapes(std::vector <std::shared_ptr<crv::Curve>> * shapes, std::vector <std::shared_ptr<crv::Curve>> * circles);
#endif // EXAMPLE_H
