#include <iostream>
#include "Container.h"
#include "Base.h"
#include "Shapes.h"

using namespace std;

int main() {

	
	//Shape shape2 = Point("point", 5, 6);


	Shape* rect = new Rectangle(* new Point(2, 4), * new Point(3, 5));

	Shape* circle = new Circle(1);

	Container<Shape*> shapes = Container<Shape*>(2);
	shapes.add(new Point("my point", 5, 6));
	
	Shape* shape = shapes.get(0);

	cout << shape->print() << " ";

	//shape->~Shape();
	

	cout << rect->print() << " ";

	cout << circle->print() << " ";

	cout << Shape::getCount() << " ";

	shapes.add(new Point("my point", 5, 10));

	cout << Shape::getCount();
	//Container<int> nums2 = Container<int>(nums);


	




	//nums2.clear();

	

	int a;
	cin >> a;
}