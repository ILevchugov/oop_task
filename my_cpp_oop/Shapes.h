#pragma once

#include "Base.h"
#include "Container.h"
#include <sstream>

class Shape : public Printable {
public:
	Shape() {
		++sm_count;
	}

	Shape(Shape const& shape) {
		++sm_count;
	}

	 ~Shape() {
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
		x(x),
		y(y) {}

	Point(std::string name, double x, double y) :
		Named(name),
		x(x),
		y(y) {}

	double getX() const {
		return x;
	}

	double getY() const {
		return y;
	}

	std::string print() const override {
		std::stringstream description;
		description <<Named::print()
			<< " " << x << " " << y;
		return description.str();
	}


private:
	double x;
	double y;
};
