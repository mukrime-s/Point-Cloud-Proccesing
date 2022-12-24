/**
* @file PointCloudTest.cpp
* @Author Mukrime Sagiroglu ---->mkrimesagrglu@gmail.com
* @date Aralýk 2022
* @brief Point.h sýnýfý oluþturuldu.
*/
#pragma once
#include "Point.h"
using namespace std;
class PointCloud:public Point
{
private:
	Point* points;
	int pointNumber;
public:
	PointCloud();
	PointCloud(int);//Dizinin boyutu, nesne yaratýlýrken constructor fonksiyonunda bir parametre olarak alýnýr.
	//Point sýnýfýndan setPoint fonksiyonlarý alýndý
	void setPointX(int, double);
	void setPointY(int, double);
	void setPointZ(int, double);
	void setPointNumber(int); //point cloudun icindeki pointleri point objesi kullanarak setleyen foksiyon olusturuldu.
	void setPoint(int, Point); // point classýndaki indexi pointin indexine esitler.
	//Point sýnýfýndan getPoint fonksiyonlarý alýndý sabit kalmasý için const kullanýldý.
	const double getPointX(int)const;
	const double getPointY(int)const;
	const double getPointZ(int)const;
	Point getPoint(int)const;////point cloudun icindeki pointleri point objesi kullanarak objeye erisen foksiyon olusturuldu.
	const int getPointNumber()const;//pointNumberi döndürür.
	const PointCloud operator+(const PointCloud&); //iki nokta bulutunun sahip olduðu noktalara sahip tek bir nokta bulutunu döndürür.
	const PointCloud operator=(const PointCloud&); //bir nokta bulutunun baþka bir nokta bulutuna kopyalanmasýný saðlar.

	PointCloud deleteMovePoint(int);//secilen pointi listeden siler ve silinen pointten sonraki degerleri bir öncekine tasir.

};

