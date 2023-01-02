/**
* @file PointCloudRecorder.cpp
* @Author Mukrime Sagiroglu ---->mkrimesagrglu@gmail.com
* @date Aralik 2022
* @brief PointCloud.h sýnýfý oluþturuldu.
*/
#pragma once
#include <iostream>
#include "PointCloud.h"
/**
* @brief Constructor fonksiyonu olusturuldu
*/
PointCloud::PointCloud()
{

}

PointCloud::PointCloud(int number)
{

}

/**
* @brief Destructor fonksiyonu olusturuldu
*/
PointCloud::~PointCloud()
{
}
/**
* @brief set fonsiyonlari olusturuldu.
*/
void PointCloud::setPointX(int index, double value)
{
	list<Point>::iterator iter = next(this->points.begin(), index);
	iter->getX();
}

void PointCloud::setPointY(int index, double value)
{
	list<Point>::iterator iter = next(this->points.begin(), index);
	iter->getY();
}

void PointCloud::setPointZ(int index, double value)
{
	list<Point>::iterator iter = next(this->points.begin(), index);
	iter->getZ();
}

void PointCloud::setPointNumber(int number)
{
	list<Point>::iterator iter = next(this->points.begin(), iter);
	iter->setX(value);
}
/**
* @brief point cloudun icindeki pointleri point objesi kullanarak setleyen foksiyon olusturuldu.
*/
void PointCloud::setPoint(int index, Point point)
{
	list<Point>::iterator iter = next(this->points.begin(), index);
	*iter = point;
}

double PointCloud::getPointX(int index)const
{
	list<Point>::iterator iter = next(this->points.begin(), index);
	return iter->getX();
	
}

double PointCloud::getPointY(int index)const
{
	list<Point>::iterator iter = next(this->points.begin(), index);
	return iter->getY();
}

double PointCloud::getPointZ(int index)const
{
	list<Point>::iterator iter = next(this->points.begin(), index);
	return iter->getZ();
}
/**
* @brief point cloudun icindeki pointleri point objesi kullanarak verilere erisen foksiyon olusturuldu.
*/
Point PointCloud::getPoint(int index)const
{
	list<Point>::iterator iter = next(this->points.begin(), index);
	return * iter;
}

int PointCloud::getPointNumber()const
{
	return this->points.size();
}
/**
* @brief + operator fonsiyonu iki nokta bulutunun sahip olduðu noktalara sahip tek bir nokta bulutunu döndürür
*/
const PointCloud PointCloud::operator+(PointCloud& pointCloud)
{
	PointCloud sum;
	list <Point>::iterator iter = this->points.begin();
	for (iter; iter != this->points.end(); iter++) {
		sum.points.push_back(*iter);
	}
	iter = pointCloud.points.begin();
	for (iter; iter != pointCloud.points.end(); iter++) {
		sum.points.push_back(*iter);
	}
	return sum;
}
/**
* @brief = operator fonsiyonu bir nokta bulutunun baþka bir nokta bulutuna kopyalanmasýný saðlar.
*/
const PointCloud PointCloud::operator=(PointCloud& pointCloud)/
{
	
	this->points = pointCloud.points;
}
/**
* @brief deleteMovePoint fonsiyonu secilen pointi listeden silmek ve silinen pointten sonraki degerleri bir öncekine tasiyan fonksiyondur.
*/

PointCloud PointCloud::deleteMovePoint(int index)
{
	list<Point>::iterator iter = next(this->points.begin(), index);
	this->points.erase(iter);
	return *this;
}

