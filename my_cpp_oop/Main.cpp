#include <iostream>
#include <time.h>
#include "Container.h"
#include "Base.h"
#include "Shapes.h"
#include "ShapeFactory.h"

int main() {
	srand((uint32_t)time(NULL));

	ShapeFactory fact = ShapeFactory();

	Container<std::shared_ptr<Shape>> shapes = Container<std::shared_ptr<Shape>> ();


	for (int i = 0; i < 2000; i++) {
		shapes.add(std::shared_ptr<Shape>(fact.createRandomShape()));
	}


	for (int i = 0; i < 2000; i++) {
		std::cout << shapes.get(i)->print();
	}
	std::cout << "Number of all created shapes: " << Shape::getCount() << "\n";

	shapes.clear();

	std::cout << "Number after clearing: " << Shape::getCount() << "\n";
	
	
	int a;
	std::cin >> a;
}