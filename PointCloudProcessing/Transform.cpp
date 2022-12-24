#include "Transform.h"
#include <iostream>
#include <math.h>

Transform::Transform() {

	// Bir 3D space'ten başka bir 3D space'e dönüşüm(transformation) yapmak istiyorsak, 4x4 bir matrise ihtiyaç duyarız. 
	// 3D matris dönüşümü formülü gereği 4x4 bir matris oluşturulmuş gerekli index'lere gerekli değerler aktarılmıştır.
	this->transMatrix[0][0] = 1;
	this->transMatrix[0][1] = 0;
	this->transMatrix[0][2] = 0;
	this->transMatrix[0][3] = 0;

	this->transMatrix[1][0] = 0;
	this->transMatrix[1][1] = 1;
	this->transMatrix[1][2] = 0;
	this->transMatrix[1][3] = 0;

	this->transMatrix[2][0] = 0;
	this->transMatrix[2][1] = 0;
	this->transMatrix[2][2] = 1;
	this->transMatrix[2][3] = 0;

	this->transMatrix[3][0] = 0;
	this->transMatrix[3][1] = 0;
	this->transMatrix[3][2] = 0;
	this->transMatrix[3][3] = 1;
}


void Transform::setAngles(double a1, double a2, double a3) {
	// a1, a2 ve a3 değerleri x, y ve z ekseninde kaç derecelik dönüş yapılacağını belirtir.
	// angles[0] proje dökümanında verilen γ(gama) açısına ve x eksenindeki rotasyona
	// angles[1] β(beta) açısına ve y eksenindeki rotasyona
	// angles[2] ise α(alfa) açısına ve z eksenindeki rotasyonu temsil eder.
	angles[0] = a1;
	angles[1] = a2;
	angles[2] = a3;
}


void Transform::setTrans(double t1, double t2, double t3) {
	// t1,t2 ve t3 değerleri elimizdeki noktayı veya koordinat sisteminin orijinini hangi eksenlerde ne kadara öteleyeceğimizi(translation) belirtir.
	// t1 x eksenine ait öteleme miktarını, t2 y eksenine ait öteleme miktarını ve t3 z eksenine ait öteleme miktarını tutar.
	// Bu değerler transMatrix'te [0,3] [1,3] ve [2,3] index'lerine setTranslation fonksiyonu ile atanırlar.
	trans[0] = t1;
	trans[1] = t2;
	trans[2] = t3;
}


double* Transform::getAngles() {
	// Ayarlanmış açıları getirir.
	return this->angles;
}


double* Transform::getTrans() {
	// Ayarlanmış koordinat noktalarını getirir.
	return this->trans;
}


void Transform::setRotation() {
	// Proje dökümanında verilen rotasyon matrisinin açılarıyla beraber bulunduğu, işlemlerin yapılıp matris olarak oluşturulduğu fonksiyon.
	rotationMatrix[0][0] = cos(angles[2]) * cos(angles[1]);
	rotationMatrix[0][1] = (cos(angles[2]) * sin(angles[1]) * sin(angles[0])) - (sin(angles[2]) * cos(angles[0]));
	rotationMatrix[0][2] = (cos(angles[2]) * sin(angles[1]) * cos(angles[0])) + (sin(angles[2]) * sin(angles[0]));

	rotationMatrix[1][0] = sin(angles[2]) * cos(angles[1]);
	rotationMatrix[1][1] = (sin(angles[2]) * sin(angles[1]) * sin(angles[0])) + (cos(angles[2]) * cos(angles[0]));
	rotationMatrix[1][2] = (sin(angles[2]) * sin(angles[1]) * cos(angles[0])) - (cos(angles[2]) * sin(angles[0]));

	rotationMatrix[2][0] = -sin(angles[1]);
	rotationMatrix[2][1] = cos(angles[1]) * sin(angles[0]);
	rotationMatrix[2][2] = cos(angles[1]) * cos(angles[0]);
}

void Transform::setTranslation() {
	// Öteleme(translation) için x, y ve z eksen bilgileri matris dönüşüm formülü gereğince transMatrix dizisinin belirtilen kısımlarında tutulur.
	this->transMatrix[0][3] = this->trans[0];
	this->transMatrix[1][3] = this->trans[1];
	this->transMatrix[2][3] = this->trans[2];
}


Point Transform::doTransform(Point p) {
	// returnPoint transform edilmiş noktanın orjin bilgilerine sahip bir nesnedir.
	Point returnPoint;
	// returnArray matris çarpımı sonucunda oluşan yeni koordinat bilgilerini tutan bir matristir.
	double returnArray[4];
	// arr noktanın mevcut koordinatlarını transform işlemi için tutan bir matristir.
	double arr[4];

	arr[0] = p.getX();
	arr[1] = p.getY();
	arr[2] = p.getZ();
	arr[3] = 1;
	// for döngüsü sonucunda matris çarpımı yapılmış olur ve yeni noktanın bilgileri oluşturulur.
	for (int i = 0; i < 4; i++) {
		returnArray[i] = 0;
		for (int k = 0; k < 4; k++) {
			returnArray[i] += this->transMatrix[i][k] * arr[k];
		}
	}

	returnPoint.setX(returnArray[0]);
	returnPoint.setY(returnArray[1]);
	returnPoint.setZ(returnArray[2]);
	// yeni noktanın bilgileri bir nesne olarak tutulur ve döndürülür.
	return returnPoint;
}

PointCloud Transform::doTransform(PointCloud pc) {
	// returnCloud nokta bulutlarını içeren bir nesnedir.
	PointCloud returnCloud(pc.getPointNumber());
	// tempPoint her bir noktanın transform işlemine dahil edilmesi için oluşturulmuş geçici bir nesnedir.
	Point tempPoint;
	// for döngüsü sonucunda nokta bulutundaki tüm noktalar transform işlemi yapılmış hale gelir.
	for (int i = 0; i < returnCloud.getPointNumber(); i++) {
		tempPoint = doTransform(pc.getPoint(i));
		returnCloud.setPoint(i, tempPoint);
	}
	// noktaların yeni koordinatları returnCloud nokta bulutu nesnesinde döndürülür.
	return returnCloud;
}