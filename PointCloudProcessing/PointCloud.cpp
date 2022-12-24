#pragma once
#include <iostream>
#include "PointCloud.h"

PointCloud::PointCloud()
{
	this->pointNumber = 1;
	this->points = new Point[this->pointNumber];
}

PointCloud::PointCloud(int number)
{
	
	pointNumber = number;
	this->points = new Point[pointNumber];
}

void PointCloud::setPointX(int index, double value)
{
	this->points[index].setX(value);
}

void PointCloud::setPointY(int index, double value)
{
	this->points[index].setY(value);
}

void PointCloud::setPointZ(int index, double value)
{
	this->points[index].setZ(value);
}

void PointCloud::setPointNumber(int number)
{
	pointNumber = number;
	this->points = new Point[pointNumber];
}

void PointCloud::setPoint(int index, Point point)  //point cloudun icindeki pointleri point objesi kullanarak setleyen foksiyon olusturuldu.
{
	this->points[index] = point;
}

const double PointCloud::getPointX(int index)
{
	return this->points[index].getX();
	
}

const double PointCloud::getPointY(int index)
{
	return this->points[index].getY();
}

const double PointCloud::getPointZ(int index)
{
	return this->points[index].getZ();
}

Point PointCloud::getPoint(int index)//point cloudun icindeki pointleri point objesi kullanarak verilere erisen foksiyon olusturuldu.
{
	return this->points[index];
}

const int PointCloud::getPointNumber()
{
	return pointNumber;
}

const PointCloud PointCloud::operator+(const PointCloud& pointCloud)//iki nokta bulutunun sahip olduðu noktalara sahip tek bir nokta bulutunu döndürür.
{
	int size = pointNumber + pointCloud.pointNumber;
	int count = 0;
	PointCloud sum(size);

	for (int m = 0; m < pointNumber; m++) {
		sum.points[m] = this->points[m];
	}
	for (int s = pointNumber; s < size; s++) {
		sum.points[s] = pointCloud.points[count];
		count++;
	}

	return sum;

}

const PointCloud PointCloud::operator=(const PointCloud& pointCloud)//bir nokta bulutunun baþka bir nokta bulutuna kopyalanmasýný saðlar.
{
	delete[] this->points;
	pointNumber = pointCloud.pointNumber;
	this->points = new Point[pointNumber];

	for (int m = 0; m < pointNumber; m++) {
		this->points[m] = pointCloud.points[m];
	}

	return *this;

}

PointCloud PointCloud::deleteMovePoint(int index)//secilen pointi listeden silmek ve silinen pointten sonraki degerleri bir öncekine tasiyan fonksiyon
{
	for (int i = 0; i < pointNumber; i++) {
		if (i == index) {
			while (i < pointNumber) {
				points[i] = points[i + 1];// secilen idexten sonraki indexler bir sola shift ettirilir. Böylece secilen deger listeden slinmis olur.
				i++;
			}
			pointNumber = pointNumber - 1; //listeden bir deger cýkarýldýgý icin pointNumberden de eksiltilir.
			break;
		}
	}

	return *this;
}

