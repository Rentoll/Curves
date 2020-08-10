#ifndef CURVE_H
#define CURVE_H


////////////////////////////////////////////////////////////
// Headers
////////////////////////////////////////////////////////////
#include <utility>

namespace crv {

#define PI      3.14
#define CIRCLE  0
#define ELLIPSE 1
#define HELIX   2


////////////////////////////////////////////////////////////
/// \brief 3D Point with x, y and z coordinates
///
////////////////////////////////////////////////////////////
struct Point {
	double x, y, z;
};

////////////////////////////////////////////////////////////
/// \brief An abstract class of all curves with basic interaction with them
///
////////////////////////////////////////////////////////////
class Curve {

protected:
	int curveType; //!< type of curve
	double radius; //!< radius of curve
public:
	////////////////////////////////////////////////////////////
	/// \brief Initialization constructor
	///
	/// \param radi Initial radius (should be > 0)
	/// \param _curveType Initial Type of curve
	///
	////////////////////////////////////////////////////////////
	Curve(double radi, int _curveType);

	////////////////////////////////////////////////////////////
	/// \brief Radius getter
	///
	/// \return Radius of this object
	///
	////////////////////////////////////////////////////////////
	double getRadius();

	////////////////////////////////////////////////////////////
	/// \brief Get type of curve
	///
	/// \return Type of curve 
	///
	////////////////////////////////////////////////////////////
	int typeOfCurve();

	////////////////////////////////////////////////////////////
	/// \brief  Calculates a 3D point per parameter t along the curve
	///
	/// \param t Parameter at radians which using to find coordinates)
	///
	/// \return Point which contains an answer
	///
	////////////////////////////////////////////////////////////
	virtual Point findPoint(double t) = 0;

	////////////////////////////////////////////////////////////
	/// \brief Calculates a 3D vector per parameter t along the curve with first derivative and magnitude
	///
	/// \param t Parameter at radians which using to find coordinates
	///
	/// \return Point which contains an answer
	///
	////////////////////////////////////////////////////////////
	virtual Point tangentVector(double t) = 0;
};

////////////////////////////////////////////////////////////
/// \brief Curve that represents a Circle
///
////////////////////////////////////////////////////////////
class Circle : public Curve {
public:
	////////////////////////////////////////////////////////////
	/// \brief Initialization constructor
	///
	/// \param radi Initial radius (should be > 0)
	///
	////////////////////////////////////////////////////////////
	Circle(double radi);

	////////////////////////////////////////////////////////////
	/// \brief  Calculates a 3D point per parameter t along the Circle 
	///
	/// \param t Parameter at radians which using to find coordinates
	///
	/// \return Point which contains an answer
	///
	////////////////////////////////////////////////////////////
	Point findPoint(double t);

	////////////////////////////////////////////////////////////
	/// \brief  Calculates a 3D vector per parameter t along the Circle with first derivative and magnitude
	///
	/// \param t Parameter at radians which using to find coordinates
	///
	/// \return Point which contains an answer
	///
	////////////////////////////////////////////////////////////
	Point tangentVector(double t);

};

////////////////////////////////////////////////////////////
/// \brief Curve that represents an Ellipse
///
////////////////////////////////////////////////////////////
class Ellipse : public Curve {
private:
	double secondRadius; //!< Second radius of Ellipse
public:
	////////////////////////////////////////////////////////////
	/// \brief Initialization constructor
	///
	/// \param firstRadi First initial radius (should be > 0)
	/// \param secondRadi Second initial radius (should be > 0)
	///
	////////////////////////////////////////////////////////////
	Ellipse(double firstRadi, double secondRadi);

	////////////////////////////////////////////////////////////
	/// \brief  Calculates a 3D point per parameter t along the Ellipse
	///
	/// \param t Parameter at radians which using to find coordinates
	///
	/// \return Point which contains an answer
	///
	////////////////////////////////////////////////////////////
	Point findPoint(double t);

	////////////////////////////////////////////////////////////
	/// \brief  Calculates a 3D vector per parameter t along the Ellipse with first derivative and magnitude
	///
	/// \param t Parameter at radians which using to find coordinates
	///
	/// \return Point which contains an answer
	///
	////////////////////////////////////////////////////////////
	Point tangentVector(double t);

	////////////////////////////////////////////////////////////
	/// \brief Radius getter of an Ellipse
	///
	/// \param firstRadius Takes pointer to first radius
	/// \param firstRadius Takes pointer to second radius
	///
	////////////////////////////////////////////////////////////
	void getRadius(double* firstRadius, double* secondRadius);
};

////////////////////////////////////////////////////////////
/// \brief Curve that represents a Helix
///
////////////////////////////////////////////////////////////
class Helix : public Curve {
private:
	double step; //!< step of Helix
public:
	////////////////////////////////////////////////////////////
	/// \brief Initialization constructor
	///
	/// \param radi Initial radius (should be > 0)
	/// \param _step Initial step of Helix
	///
	////////////////////////////////////////////////////////////
	Helix(double radi, double _step);

	////////////////////////////////////////////////////////////
	/// \brief  Calculates a 3D point per parameter t along the Helix
	///
	/// \param t Parameter at radians which using to find coordinates
	///
	/// \return Point which contains an answer
	///
	////////////////////////////////////////////////////////////
	Point findPoint(double t);

	////////////////////////////////////////////////////////////
	/// \brief  Calculates a 3D vector per parameter t along the Helix with first derivative and magnitude
	///
	/// \param t Parameter at radians which using to find coordinates
	///
	/// \return Point which contains an answer
	///
	////////////////////////////////////////////////////////////
	Point tangentVector(double t);
};
}//namespace crv
#endif
