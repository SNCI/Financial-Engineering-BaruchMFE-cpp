// Point.cpp
// Function implementation for the functions in the header file Point.hpp(Point classs with x- and y- coordinates.) 
// Implementation of added operators to the Point class.


#include "Point.hpp"
#include <cmath>
#include <sstream>

// Default constructor 
Point::Point() : m_x(0), m_y(0) // Colon syntax.

{	}


// Initialize using newx and newy
Point::Point(double newx, double newy) :m_x(newx),m_y(newy)
{	}


Point::Point(double xyval): m_x(xyval),m_y(xyval)				//Extra constructor for exercise 2.4.3
{	}


// Copy constructor
Point::Point(const Point& source)
{
    m_x = source.m_x;
	m_y = source.m_y;
}


// Destructor
Point::~Point()

{	}

// Getter function for coordinate x.
double Point::X() const		

{	return m_x;	}

//Setter function for coordinate x.
void Point::X(double newX)		

{ 	m_x = newX; }


// Getter function for coordinate y.
double Point::Y() const		

{	return m_y; }

//Setter function for coordinate y.
void Point::Y(double newY)		

{ 	m_y = newY; }


// Returns a string description of the point.
std::string Point::ToString() const

{
	std::stringstream sm_x, sm_y;	

	sm_x << m_x;
	sm_y << m_y;

	std::string str;
	str = "\"Point("+sm_x.str()+","+sm_y.str()+")\"";

	return str;
}

//Calculate the distance to the origin (0,0).
double Point::Distance() const	// DistanceOrigin() is changed to Distance().
{
	double dist_to_origin;
	dist_to_origin = sqrt(pow((m_x- 0),2) + pow((m_y- 0),2)); //sqrt returns only positive sqrt value. I didn't consider abs value.

	return dist_to_origin;

}

 // Calculate the distance between two given points.
 // Distance function will be implemented by passing the argument as a "const reference". Therefore at this occasion copy constructor will not be 
 //called.
double Point::Distance(const Point& p) const
{
	double dist_to_point;
	dist_to_point = sqrt(pow((m_x- p.X()),2) + pow((m_y- p.Y()),2));//sqrt returns only positive sqrt value. I didn't consider abs value.

	return dist_to_point;
}


/* Implementation of added operators to the Point class. */


//Negate the coordinates operator
Point Point::operator - () const
{ 
	return Point(-m_x,-m_y);
}

//Scale the coordinates operator
Point Point::operator * (double factor) const
{

	return Point(factor*m_x, factor*m_y);
}

//Add coordinates operator
Point Point::operator + (const Point& p) const
{ 

	return Point(m_x + p.m_x, m_y + p.m_y); 
}

//Equally compare operator
bool Point::operator== (const Point& P) const
{
    return (m_x == P.m_x && m_y == P.m_y );
}

//Assignment operator
Point& Point::operator = (const Point& source)
{
	// Avoid doing assign to myself
	if (this == &source)
		return *this;

	m_x = source.m_x;
	m_y = source.m_y;

	return *this;
}

//Scale the coordinates and assign
Point& Point::operator *= (double factor)
{

	(*this).m_x= (*this).m_x * factor;
	(*this).m_y= (*this).m_y * factor;

	return *this;

}
