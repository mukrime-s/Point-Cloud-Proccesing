#include<iostream>
#include<string>
#include<fstream>
#include<list>
#include<iterator>
#include "DepthCamera.h"
#include "PointCloud.h"
#include "Point.h"
using namespace std;

int main() {


	DepthCamera dp;
	PointCloud pc;
	string dosyaAdi;


	list<Point>::iterator iter;
	list<Point> P1;
	list<Point> P2;
	list<Point> P3;
	list<Point> P4;


	cout << "Bir dosya adi girin  = " << endl;
	cin >> dosyaAdi;
	dp.setfileName(dosyaAdi);

	//cout << pc.getPointNumber()<<endl;

	pc = dp.captureFor();

	P1 = pc.getPoint();

	ofstream camsonuc("camsonuc1.txt");
	ofstream cam1sonuc("cam1sonuc1.txt");
	ofstream cam2sonuc("cam2sonuc2.txt");
	ofstream cam3sonuc("cam3sonuc3.txt");

	while (dosyaAdi != "q") {



		if (dosyaAdi == "cam.txt") {


			for (iter = P1.begin(); iter != P1.end(); iter++)
				camsonuc << iter->getX() << " " << iter->getY() << " " << iter->getZ() << endl;
		}
		if (dosyaAdi == "cam1.txt") {


			for (iter = P1.begin(); iter != P1.end(); iter++)
				cam1sonuc << iter->getX() << " " << iter->getY() << " " << iter->getZ() << endl;
		}
		if (dosyaAdi == "cam2.txt") {


			for (iter = P1.begin(); iter != P1.end(); iter++)
				cam2sonuc << iter->getX() << " " << iter->getY() << " " << iter->getZ() << endl;
		}
		if (dosyaAdi == "cam3.txt") {


			for (iter = P1.begin(); iter != P1.end(); iter++)
				cam3sonuc << iter->getX() << " " << iter->getY() << " " << iter->getZ() << endl;
		}

		cout << "Bir dosya adi girin  = " << endl;
		cin >> dosyaAdi;
		dp.setfileName(dosyaAdi);


		pc = dp.captureFor();

		P1 = pc.getPoint();

	}

	cout << pc.getPointNumber();
	P1 = pc.getPoint();

	//for (iter = P1.begin(); iter != P1.end(); iter++)
	//	cout << iter->getX() << " " << iter->getY() << " " << iter->getZ() << endl;

	cam1sonuc.close();




	return 0;
}