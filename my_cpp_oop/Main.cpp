#include <iostream>
#include "Container.h"
#include "Base.h"
#include "Shapes.h"

using namespace std;

int main() {

	
	//Shape shape2 = Point("point", 5, 6);




	Container<Shape*> shapes = Container<Shape*>(2);
	shapes.add(new Point("my point", 5, 6));
	
	Shape* shape = shapes.get(0);

	cout << shape->print() << " ";

	//shape->~Shape();
	
	cout << shape->print() << " ";

	cout << Shape::getCount() << " ";

	shapes.add(new Point("my point", 5, 10));

	cout << Shape::getCount();
	//Container<int> nums2 = Container<int>(nums);


	




	//nums2.clear();

	

	int a;
	cin >> a;
}