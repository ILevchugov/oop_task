#pragma once
#include "time.h"
#include "stdio.h"
#include "stdlib.h"
#include "Shapes.h"

class ShapeFactory {
public:
	Shape * createRandomShape() {
		switch (randomInt(1, 5)) {
			case 1: 
				return createPoint();
			case 2:
				return createCircle();
			case 3:
				return createRectangle();
			case 4:
				return createSquare();
			case 5:
				return createPolyline();
			case 6:
				return createPolygon();
		}
	}
	Point * createPoint() {
		double x = randomDouble(0, 10);
		double y = randomDouble(0, 10);
		return new Point(x, y);
	}

	Circle * createCircle() {
		double radius = randomDouble(0, 10);
		return new Circle(radius);
	}


	Rectangle * createRectangle() {
		Point * pointA = createPoint();
		Point * pointB = createPoint();
		return new Rectangle(*pointA, *pointB);
	}

	Square * createSquare() {
		Point * pointA = createPoint();
		double side = randomDouble(0, 10);
		Point * pointB = new Point(pointA->getX() + side, pointA->getY() + side);

		Rectangle * rect = new Rectangle(*pointA, *pointB);

		return new Square(*rect);
	}

	Polyline * createPolyline() {
		Container<Point> points = Container<Point>();
		int pointsNum = randomInt(0, 10);
		for (int i = 0; i < 5; i++) {
			Point * point = createPoint();
			points.add(*point);
			delete point;
		}
		Polyline * polyline = new Polyline(points);
		points.clear();
		return polyline;
	}

	Polygon * createPolygon() {
		Container<Point> points = Container<Point>();
		int pointsNum = randomInt(0, 10);
		for (int i = 0; i < pointsNum; i++) {
			Point * point = createPoint();
			points.add(*point);
			delete point;
		}
		Polygon * polygon = new Polygon(points);
		points.clear();
		return polygon;
	}

private:
	double randomDouble(double min, double max) {
		double num = (double)rand() / RAND_MAX;
		return min + num * (max - min);
	}
	int randomInt(int min, int max) {
		return min + rand() % max;
	}

	static const uint32_t SHAPE_TYPES_NUM = 6;

};