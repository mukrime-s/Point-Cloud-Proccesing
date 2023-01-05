/**
* @file PointCloudTest.cpp
* @Author Mukrime Sagiroglu ---->mkrimesagrglu@gmail.com
* @date Aralýk 2022
* @brief Point.h sýnýfý oluþturuldu.
*/
#pragma once
#include "Point.h"
using namespace std;
#include <list>
#include <string>
#include <iterator>
class PointCloud
{
private:
	int pointNumber;
	list <Point> points;
public:
	PointCloud();
	~PointCloud();
	//Point sýnýfýndan setPoint fonksiyonlarý alýndý
	void setPointX(int, double);
	void setPointY(int, double);
	void setPointZ(int, double);
	void setPointNumber(int); //point cloudun icindeki pointleri point objesi kullanarak setleyen foksiyon olusturuldu.
	void setPoint(list <Point>); // point classýndaki indexi pointin indexine esitler.
	//Point sýnýfýndan getPoint fonksiyonlarý alýndý sabit kalmasý için const kullanýldý.
	double getPointX(int);
	double getPointY(int);
	double getPointZ(int);
	list<Point> getPoint()const;////point cloudun icindeki pointleri point objesi kullanarak objeye erisen foksiyon olusturuldu.
	int getPointNumber()const;//pointNumberi döndürür.
	PointCloud operator+(PointCloud); //iki nokta bulutunun sahip olduðu noktalara sahip tek bir nokta bulutunu döndürür.
	void operator=(PointCloud* pcl); //bir nokta bulutunun baþka bir nokta bulutuna kopyalanmasýný saðlar.

	PointCloud deleteMovePoint(int);//secilen pointi listeden siler ve silinen pointten sonraki degerleri bir öncekine tasir.

};

