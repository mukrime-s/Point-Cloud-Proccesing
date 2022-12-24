#include <iostream>
#include "Point.h"

using namespace std;

int main() {


	cout << "Point Test" << endl;

	Point p1, p2, p3;
	p1.setX(0);
	p1.setY(5);
	p1.setZ(9);

	p2.setX(0);
	p2.setY(5);
	p2.setZ(9);

	p3.setX(3);
	p3.setY(6);
	p3.setZ(7);


	cout << "p1 x = " << p1.getX() << " p1 y = " << p1.getY() << " p1 z = " << p1.getZ() << endl;
	cout << "p2 x = " << p2.getX() <<  "p2 y = " << p2.getY() << " p2 z = " << p2.getZ() << endl;
	cout << "p3 x = " << p3.getX() << " p3 y = " << p3.getY() << " p3 z = " << p3.getZ() << endl;

	if (p1 == p2)
		cout << "p1 = p2" << endl;
	else
		cout << "p1 != p2" << endl;
	if (p1 == p3)
		cout << "p1 = p3" << endl;
	else
		cout << "p1 != p3" << endl;
	

	double uzaklik = p1.distance(p3);

	cout << "p1 p3 arasindaki uzaklik " << uzaklik << endl;

}