#include "Transform.h"
#include <iostream>
#include <math.h>
#include<Eigen/Dense>


//Eigen::Matrix3d rotationMatrix; 

double rotationMatrix[3][3];


Transform::Transform() {

	// Bir 3D space'ten başka bir 3D space'e dönüşüm(transformation) yapmak istiyorsak, 4x4 bir matrise ihtiyaç duyarız. 
	// 3D matris dönüşümü formülü gereği 4x4 bir matris oluşturulmuş gerekli index'lere gerekli değerler aktarılmıştır.
	/*this->transMatrix(0, 0) = 1;
	this->transMatrix(0, 1) = 0;
	this->transMatrix(0, 2) = 0;
	this->transMatrix(0, 3) = 0;

	this->transMatrix(1, 0) = 0;
	this->transMatrix(1, 1) = 1;
	this->transMatrix(1, 2) = 0;
	this->transMatrix(1, 3) = 0;

	this->transMatrix(2, 0) = 0;
	this->transMatrix(2, 1) = 0;
	this->transMatrix(2, 2) = 1;
	this->transMatrix(2, 3) = 0;

	this->transMatrix(3, 0) = 0;
	this->transMatrix(3, 1) = 0;
	this->transMatrix(3, 2) = 0;
	this->transMatrix(3, 3) = 1;*/
}
Transform::~Transform()
{

}

void Transform::setAngles(double a1, double a2, double a3) {
	// a1, a2 ve a3 değerleri x, y ve z ekseninde kaç derecelik dönüş yapılacağını belirtir.
	// angles[0] proje dökümanında verilen γ(gama) açısına ve x eksenindeki rotasyona
	// angles[1] β(beta) açısına ve y eksenindeki rotasyona
	// angles[2] ise α(alfa) açısına ve z eksenindeki rotasyonu temsil eder.
	using namespace Eigen;
	angles(0) = a1;
	angles(1) = a2;
	angles(2) = a3;
}


void Transform::setTrans(double t1, double t2, double t3) {
	// t1,t2 ve t3 değerleri elimizdeki noktayı veya koordinat sisteminin orijinini hangi eksenlerde ne kadara öteleyeceğimizi(translation) belirtir.
	// t1 x eksenine ait öteleme miktarını, t2 y eksenine ait öteleme miktarını ve t3 z eksenine ait öteleme miktarını tutar.
	// Bu değerler transMatrix'te [0,3] [1,3] ve [2,3] index'lerine setTranslation fonksiyonu ile atanırlar.
	using namespace Eigen;
	trans(0) = t1;
	trans(1) = t2;
	trans(2) = t3;
}


double* Transform::getAngles() {
	// Ayarlanmış açıları getirir.
	//Eigen kütüphanesi kullanımından dolayı, fonksiyondaki değerleri dinamik array'e aktararak düzenleme yaptık.
	double* anglesA = new double[3];
	for (int i = 0; i < 3; i++)
	{
		anglesA[i] = angles(i);
	}
	return anglesA;
}


double* Transform::getTrans() {
	// Ayarlanmış koordinat noktalarını getirir.
	//Eigen kütüphanesi kullanımından dolayı, fonksiyondaki değerleri dinamik array'e aktararak düzenleme yaptık.
	double* transA = new double[3];
	for (int i = 0; i < 3; i++)
	{
		transA[i] = trans(i);
	}
	return transA;
}


//void Transform::setRotation(double ang[]) {
//	// Proje dökümanında verilen rotasyon matrisinin açılarıyla beraber bulunduğu, işlemlerin yapılıp matris olarak oluşturulduğu fonksiyon.
//	rotationMatrix[0][0] = cos(angles[2]) * cos(angles[1]);
//	rotationMatrix[0][1] = (cos(angles[2]) * sin(angles[1]) * sin(angles[0])) - (sin(angles[2]) * cos(angles[0]));
//	rotationMatrix[0][2] = (cos(angles[2]) * sin(angles[1]) * cos(angles[0])) + (sin(angles[2]) * sin(angles[0]));
//
//	rotationMatrix[1][0] = sin(angles[2]) * cos(angles[1]);
//	rotationMatrix[1][1] = (sin(angles[2]) * sin(angles[1]) * sin(angles[0])) + (cos(angles[2]) * cos(angles[0]));
//	rotationMatrix[1][2] = (sin(angles[2]) * sin(angles[1]) * cos(angles[0])) - (cos(angles[2]) * sin(angles[0]));
//
//	rotationMatrix[2][0] = -sin(angles[1]);
//	rotationMatrix[2][1] = cos(angles[1]) * sin(angles[0]);
//	rotationMatrix[2][2] = cos(angles[1]) * cos(angles[0]);
//}


void Transform::setRotation(double ang[]) {
	// Proje dökümanında verilen rotasyon matrisinin açılarıyla beraber bulunduğu, işlemlerin yapılıp matris olarak oluşturulduğu fonksiyon.

	rotationMatrix[0][0] = ang[0];
	rotationMatrix[0][1] = ang[1];
	rotationMatrix[0][2] = ang[2];

	rotationMatrix[1][0] = ang[3];
	rotationMatrix[1][1] = ang[4];
	rotationMatrix[1][2] = ang[5];

	rotationMatrix[2][0] = ang[6];
	rotationMatrix[2][1] = ang[7];
	rotationMatrix[2][2] = ang[8];

}

void Transform::setRotation(Eigen::Vector3d ang) {
	// Proje dökümanında verilen rotasyon matrisinin açılarıyla beraber bulunduğu, işlemlerin yapılıp matris olarak oluşturulduğu fonksiyon.

	rotationMatrix[0][0] = cos(ang(2)) * cos(ang(1));
	rotationMatrix[0][1] = (cos(ang(2)) * sin(ang(1)) * sin(ang(0))) - (sin(ang(2)) * cos(ang(0)));
	rotationMatrix[0][2] = (cos(ang(2)) * sin(ang(1)) * cos(ang(0))) + (sin(ang(2)) * sin(ang(0)));
	rotationMatrix[1][0] = sin(ang(2)) * cos(ang(1));
	rotationMatrix[1][1] = (sin(ang(2)) * sin(ang(1) * sin(ang(0))) + (cos(ang(2)) * cos(ang(0))));
	rotationMatrix[1][2] = (sin(ang(2)) * sin(ang(1)) * cos(ang(0))) - (cos(ang(2)) * sin(ang(0)));
	rotationMatrix[2][0] = -sin(ang(1));
	rotationMatrix[2][1] = cos(ang(1)) * sin(ang(0));
	rotationMatrix[2][2] = cos(ang(1)) * cos(ang(0));
}


void Transform::setTranslation() {
	// Öteleme(translation) için x, y ve z eksen bilgileri matris dönüşüm formülü gereğince transMatrix dizisinin belirtilen kısımlarında tutulur.
	using namespace Eigen;
	for (int j = 0; j < 3; j++) {
		for (int i = 0; i < 3; i++) {
			transMatrix(i, j) = rotationMatrix[i][j];
		}
	}

	//Kalan degerler ataniyor.
	this->transMatrix(3, 0) = 0;
	this->transMatrix(3, 1) = 0;
	this->transMatrix(3, 2) = 0;
	this->transMatrix(3, 3) = 1;
	this->transMatrix(0, 3) = this->trans[0];
	this->transMatrix(1, 3) = this->trans[1];
	this->transMatrix(2, 3) = this->trans[2];



}
void Transform::setTranslation(Eigen::Vector3d tr) {
	// Öteleme(translation) için x, y ve z eksen bilgileri matris dönüşüm formülü gereğince transMatrix dizisinin belirtilen kısımlarında tutulur.

	using namespace Eigen;
	for (int j = 0; j < 3; j++) {
		for (int i = 0; i < 3; i++) {
			transMatrix(i, j) = rotationMatrix[i][j];
		}
	}

	this->transMatrix(3, 0) = 0;//Kalan degerler ataniyor.
	this->transMatrix(3, 1) = 0;
	this->transMatrix(3, 2) = 0;
	this->transMatrix(3, 3) = 1;
	this->transMatrix(0, 3) = tr(0);
	this->transMatrix(1, 3) = tr(1);
	this->transMatrix(2, 3) = tr(2);

}


list<Point> Transform::doTransform(list<Point> p) {
	using namespace Eigen;

	list <Point> returnTransform;
	list<Point>::iterator iter;
	Point returnPoint;
	Vector4d Arr, returnArray;
	iter = p.begin();

	Arr(0) = iter->getX();
	Arr(1) = iter->getY();
	Arr(2) = iter->getZ();
	Arr(3) = 1;


	for (iter = p.begin(); iter != p.end(); iter++)
	{
		Arr(0) = iter->getX();
		Arr(1) = iter->getY();
		Arr(2) = iter->getZ();
		Arr(3) = 1;
		returnArray = transMatrix * Arr;
		returnPoint.setX(returnArray(0));
		returnPoint.setY(returnArray(1));
		returnPoint.setZ(returnArray(2));

		returnTransform.push_back(returnPoint);
	}

	// yeni noktanın bilgileri bir nesne olarak tutulur ve döndürülür.
	return returnTransform;


}

PointCloud Transform::doTransform(PointCloud pc) {
	// returnCloud nokta bulutlarını içeren bir nesnedir.
	PointCloud returnCloud;
	// tempPoint her bir noktanın transform işlemine dahil edilmesi için oluşturulmuş geçici bir nesnedir.
	list <Point> tempPoint;
	tempPoint = pc.getPoint();
	// for döngüsü sonucunda nokta bulutundaki tüm noktalar transform işlemi yapılmış hale gelir.
	returnCloud.setPoint(doTransform(tempPoint));


	//for (int i = 0; i < pc.getPointNumber(); i++) {
	//	tempPoint = doTransform(tempPoint);
	//	pc.setPoint(tempPoint);
	//}
	// noktaların yeni koordinatları returnCloud nokta bulutu nesnesinde döndürülür.
	return returnCloud;
}