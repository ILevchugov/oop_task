#include <iostream>

#include "Container.h"

#include <time.h>

using namespace std;

int main() {

	Container<int> nums = Container<int>(2);
	nums.add(1);
	nums.add(3);
	nums.add(1);
	nums.add(2);
	nums.add(111);
	nums.add(12);
	nums.add(33);
	nums.add(12);
	nums.add(3);
	nums.add(1);
	nums.add(2);
	nums.add(111);
	nums.add(12);
	nums.add(33);

	Container<int> nums2 = Container<int>(nums);


	

	cout << nums2.size() << " ";
	cout << nums2.capacity() << " ";


	//nums2.clear();

	cout << " " << nums2.get(0);


	int a;
	cin >> a;
}