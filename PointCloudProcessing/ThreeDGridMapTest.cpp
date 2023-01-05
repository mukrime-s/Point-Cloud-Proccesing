#include<iostream>
#include<string>
#include<fstream>
#include<list>
#include<iterator>
#include "DepthCamera.h"
#include "PointCloud.h"
#include "Point.h"
#include "ThreeDGridMap.h"
using namespace std;

int main() {


	DepthCamera dp;
	PointCloud pc;
	string dosyaAdi;

	list<Point>::iterator iter;
	list<Point> P1;



	cout << "Bir dosya adi girin  = " << endl;
	cin >> dosyaAdi;
	dp.setfileName(dosyaAdi);

	//cout << pc.getPointNumber()<<endl;

	pc = dp.captureFor();

	P1 = pc.getPoint();
	ThreeDGridMap tgm(1000, 0.03);

	tgm.insertPoint(P1);
	tgm.loadMap("3DSONUC3.txt");





	cout << pc.getPointNumber();
	P1 = pc.getPoint();





	return 0;
}