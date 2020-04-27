#pragma once
#define _USE_MATH_DEFINES

#include "Container.h"
#include <iostream>
#include <math.h>
#include "Base.h"
#include "Container.h"
#include <sstream>

static double const eps = 0.001;

class Shape : public Printable {
public:
	Shape() {
		++sm_count;
	}

	Shape(Shape const& shape) {
		++sm_count;
	}

	virtual ~Shape() {
		--sm_count;
	}

	 static int getCount() {
		 return sm_count;
	}

private: 
	static int sm_count;
};

int Shape::sm_count = 0;

class Point : public Shape, public Named {
public:
	
	Point(double x, double y): 
		Named("Point"),
		m_x(x),
		m_y(y) {}

	Point(std::string name, double x, double y) :
		Named(name),
		m_x(x),
		m_y(y) {}
		
	double getX() const {
		return m_x;
	}

	double getY() const {
		return m_y;
	}

	std::string print() const override {
		std::stringstream description;
		description << Named::print() << "\n"
			<< "x: " << m_x << " y: " << m_y << "\n";
		return description.str();
	}


private:
	double m_x;
	double m_y;
};

class Circle : public Shape, public Named {
public:
	Circle(std::string name, double radius):
		Named(name),
		m_radius(radius) {
		if (radius <= 0) {
			throw "Wrong radius";
		}
	}

	Circle(double radius) :
		Circle("Circle", radius) {}

	double getRadius() {
		return m_radius;
	}

	double getArea() const {
		return M_PI * m_radius * m_radius;
	}

	std::string print() const override {
		std::stringstream description;
		description << Named::print() << "\n"
			<< "Radius: " << m_radius << "\n"
			<< "Area: " << getArea() << "\n";
		return description.str();
	}
	
private:
	double m_radius;
};

class Rectangle : public Shape, public Named {
public:
	Rectangle(std::string name, Point & pointA, Point & pointB): 
		Named(name),
		m_pointA(&pointA),
		m_pointB(&pointB) {
		if (pointA.getX() == pointB.getX() || pointA.getY() == pointB.getY()) {
			throw ("wrong points");
		}
	
	}

	Rectangle(Point & pointA, Point & pointB):
		Rectangle("Reactangle", pointA, pointB) {}

	~Rectangle() {
		delete m_pointA;
		delete m_pointB;
	}

	double getArea() const {
		return abs((m_pointA->getX() - m_pointB->getX()) * (m_pointA->getY() - m_pointB->getY()));
	}

	Point getPointA() {
		return * m_pointA;
	}

	Point getPointB() {
		return * m_pointB;
	}

	std::string print() const override {
		std::stringstream description;
		description << Named::print() << "\n"
			<< "Point A: " << m_pointA->print()
			<< "Point B: " << m_pointB->print()
			<< "Area = " << getArea() << "\n";
			return description.str();
	}

private:
	Point * m_pointA;
	Point * m_pointB;
};


class Square : public Shape, public Named {
public:
	Square(std::string name, Rectangle & rectangle) :
		Named(name),
		m_squareRect(&rectangle) {
		if (isSquareExist() == false) {
			throw "Wrong square";
		}
	}

	Square(Rectangle & rectangle) :
		Square("Square", rectangle) {}

	~Square() {
		delete m_squareRect;
	}

	std::string print() const override {
		std::stringstream description;
		description << Named::print() << "\n"
			<< m_squareRect->print()<<"\n";
		return description.str();
	}
private:
	Rectangle * m_squareRect;

	bool isSquareExist() {
		Point pointA = m_squareRect->getPointA();
		Point pointB = m_squareRect->getPointB();
		return (abs(abs(pointA.getX() - pointB.getX()) - abs(pointA.getY() - pointB.getY())) < eps);
	}
};

double calcDistance(Point const & pointA, Point const & pointB) {
	return sqrt((pointA.getX() - pointB.getX()) * (pointA.getX() - pointB.getX()) +
		(pointA.getY() - pointB.getY()) * (pointA.getY() - pointB.getY()));
}


class Polyline : public Shape, public Named {

public:

	Polyline(std::string name, Container<Point> const & points) :
		Named(name),
		m_points(points) {}

	Polyline(Container<Point> & points) :
		Polyline("Polyline", points) {}

	~Polyline() {
		m_points.clear();
	}

	void addPoint(Point const & point) {
		m_points.add(point);
	}

	double calcLength() const {
		double length = 0;
		for (uint32_t i = 0; i < m_points.size() - 1; i++) {
			length += calcDistance(m_points.get(i), m_points.get(i + 1));
		}
		return length;
	}

	std::string print() const override {
		std::stringstream description;
		description << Named::print() << "\n";
		for (uint32_t i = 0; i < m_points.size(); i++) {
			description << m_points.get(i).print();
		}
		description << "Length = " << calcLength() << "\n";
		return description.str();
	}

private:
	Container<Point> m_points;
};

class Polygon : public Shape, public Named {
public:
	Polygon(std::string name, Container<Point> const & points) :
		Named(name),
		m_points(points) {
	}

	Polygon(Container<Point> const & points):
		Polygon("Polygon", points) {}

	~Polygon() {
		m_points.clear();
	}

	double calcPerimetr() const {
		double length = 0;
		for (uint32_t i = 0; i < m_points.size() - 1; i++) {
			length += calcDistance(m_points.get(i), m_points.get(i + 1));
		}
		length += calcDistance(m_points.get(0), m_points.get(m_points.size()-1));
		return length;
	}

	std::string print() const override {
		std::stringstream description;
		description << Named::print() << "\n";

		for (uint32_t i = 0; i < m_points.size(); i++) {
			description << m_points.get(i).print();
		}

		description << "Perimetr = " << calcPerimetr() << "\n";

		return description.str();
	}

private:
	Container<Point> m_points;
};
