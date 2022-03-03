#ifndef POINT_H
#define POINT_H

#include <iostream>
#include <ostream>
using namespace std;

class Point {
	// Simple Point class holds 2-dimensional points 
	// - member data
	//   m_x : x-coordinate
	//	 m_y : y-ccordinate
	
	// - Role of four : default constructor, copy constructor, assignment operator, destructor are included
	// - Methods 
	// Setters , Getters
	// Operator overloading : will return ostream object that represents (x,y)-coordinate

private:
	double m_x;
	double m_y;
public:
	Point() :m_x(0.0), m_y(0.0) {};
	Point(const double& n_x, const double& n_y) :m_x(n_x), m_y(n_y) {};
	Point(const Point& obj) {
		m_x = obj.m_x;
		m_y = obj.m_y;
	}
	Point& operator=(const Point& obj) {
		m_x = obj.m_x;
		m_y = obj.m_y;
		return *this;
	}
	~Point() { cout << "Point desctructor called" << endl; }
	
	// Setters
	void X(const double& x) {
		m_x = x;
	}
	void Y(const double& y) {
		m_y = y;
	}

	// Getters
	double X() const {
		return m_x;
	}
	double Y() const {
		return m_y;
	}

	friend ostream& operator<<(ostream& os, const Point& obj) {
		os <<"2-D Point : (" << obj.m_x << " , " << obj.m_y<<" )";
		return os;

	}

};
#endif // !POINT_H

