#include "Transform.h"
#include <iostream>
#include <math.h>

Transform::Transform() {
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
	angles[0] = a1;
	angles[1] = a2;
	angles[2] = a3;
}


void Transform::setTrans(double t1, double t2, double t3) {
	trans[0] = t1;
	trans[1] = t2;
	trans[2] = t3;
}


double* Transform::getAngles() {
	return this->angles;
}


double* Transform::getTrans() {
	return this->trans;
}


void Transform::setRotation() {
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
	this->transMatrix[0][3] = this->trans[0];
	this->transMatrix[1][3] = this->trans[1];
	this->transMatrix[2][3] = this->trans[2];
}


Point Transform::doTransform(Point p) {
	Point returnPoint;
	double returnArray[4];
	double arr[4];

	arr[0] = p.getX();
	arr[1] = p.getY();
	arr[2] = p.getZ();
	arr[3] = 1;

	for (int i = 0; i < 4; i++) {
		returnArray[i] = 0;
		for (int k = 0; k < 4; k++) {
			returnArray[i] += this->transMatrix[i][k] * arr[k];
		}
	}

	returnPoint.setX(returnArray[0]);
	returnPoint.setY(returnArray[1]);
	returnPoint.setZ(returnArray[2]);

	return returnPoint;
}

PointCloud Transform::doTransform(PointCloud pc) {
	PointCloud returnCloud(pc.getPointNumber());
	Point tempPoint;

	for (int i = 0; i < returnCloud.getPointNumber(); i++) {
		tempPoint = doTransform(pc.getPoint(i));
		returnCloud.setPoint(i, tempPoint);
	}

	return returnCloud;
}