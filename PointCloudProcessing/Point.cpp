#include "Point.h"
#include <iostream>
#include<math.h>

using namespace std;
//Constructor fonksiyonu

Point::Point(double a = 0, double b = 0, double c = 0) :x(a), y(b), z(c) {};

//Bu fonk. point sýnýfý içindeki x deðiþkenine atama iþlemi yapar.
void Point::setX(double x) {
	this->x = x;
}
//Bu fonk poin sýnýfý içindeki x deðiþkenine eriþim imkaný saðlar.
double Point::getX()const {
	return this->x;
}

//Bu fonk. point sýnýfý içindeki y deðiþkenine atama iþlemi yapar.
void Point::setY(double y) {
	this->y = y;
}
//Bu fonk poin sýnýfý içindeki y deðiþkenine eriþim imkaný saðlar.
double Point::getY()const {
	return this->y;
}
//Bu fonk. point sýnýfý içindeki z deðiþkenine atama iþlemi yapar.
void Point::setZ(double z) {
	this->z = z;
}
//Bu fonk poin sýnýfý içindeki z deðiþkenine eriþim imkaný saðlar.
double Point::getZ() const {
	return this->z;
}
//Bu fonksiyon iki pointin birbirine eþit olup olmadýðýný kontrol eder. Eþitse true döndürür, deðilse false.
bool Point::operator==(const Point& other) const {
	if (this->x == other.x && this->y == other.y && this->z == other.z)
		return true;
	else
		return false;
}

//Bu fonk iki adet Pointin birbirine uzaklýðýný hesaplar ve döndürür.
const double Point::distance(const Point& q)  {

	return sqrt(pow((this->x - q.x), 2) + pow((this->y - q.y), 2) + pow((this->z - q.z), 2));
}





