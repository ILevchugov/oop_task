#include <iostream>
#include "Container.h"
#include "Base.h"
#include "Shapes.h"

using namespace std;

int main() {

	
	//Shape shape2 = Point("point", 5, 6);


	Shape* rect = new Rectangle(* new Point(2, 4), * new Point(3, 5));

	Shape* circle = new Circle(1);

	Shape * square = new Square(* new Rectangle(*new Point(2, 4), *new Point(3, 5)));

	Container<Point*> points = Container<Point*>(10);
	points.add(new Point(1, 2));
	points.add(new Point(1, 3));
	points.add(new Point(1, 4));
	points.add(new Point(1, 5));





	Shape * polyline = new Polyline(points);



	Container<Shape*> shapes = Container<Shape*>(2);
	shapes.add(new Point("my point", 5, 6));
	shapes.add(circle);
	shapes.add(square);
	shapes.add(rect);
	shapes.add(polyline);




	
	//rect->~Shape();
	//shapes.clear();
	//delete rect;
	//delete square;

	//shape = shapes.get(0);
	//cout << shape->print() << " ";
	//shape->~Shape();
	//rect->~Shape();
	//circle->~Shape();
	//square->~Shape();
	cout << Shape::getCount() << "\n";

	for (int i = 0; i < shapes.size(); i++) {
		cout << shapes.get(i)->print();
	}

	shapes.clear();
	

	//cout << rect->print() << " ";

	//cout << circle->print() << " ";

	cout << Shape::getCount() << " ";

	//shapes.add(new Point("my point", 5, 10));

	//cout << Shape::getCount();
	//Container<int> nums2 = Container<int>(nums);


	




	//nums2.clear();

	

	int a;
	cin >> a;
}