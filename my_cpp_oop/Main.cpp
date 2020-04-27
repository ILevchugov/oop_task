#include <iostream>
#include <time.h>
#include "Container.h"
#include "Base.h"
#include "Shapes.h"
#include "ShapeFactory.h"

using namespace std;

int main() {
	srand(time(NULL));


	ShapeFactory fact = ShapeFactory();
	//Container<shared_ptr<Shape>> shapes;
	Container<shared_ptr<Shape>> shapes = Container<shared_ptr<Shape>> ();

	for (int i = 0; i < 2000; i++) {
		shapes.add(shared_ptr<Shape>(fact.createRandomShape()));
	}
	for (int i = 0; i < 2000; i++) {
		std::cout << shapes.get(i)->print();
	}

	
	std::cout << "before delete"<<Shape::getCount() << "\n";
	std::cout <<"hapes size" << shapes.size() << "\n";
	

	shapes.clear();

	std :: cout << "after delete" << Shape::getCount() << "\n";
	


	//Container<shared_ptr<Shape>> shapes;
	//shapes.add(shared_ptr<Shape>(fact.createPoint()));

	shapes.clear();
	Container<Point> points;
	points.add(Point(3, 5));
	points.add(Point(4, 5));

	points.clear();


	std ::cout << Shape::getCount() << " ";
	
	int a;
	std::cin >> a;
}