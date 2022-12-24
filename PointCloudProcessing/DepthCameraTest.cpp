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

	cout << "Bir dosya adi girin  = "<<endl;
	cin >> dosyaAdi;
	dp.setfileName(dosyaAdi);

	cout << pc.getPointNumber()<<endl;
	
	pc = dp.capture();

	cout << pc.getPointNumber();



	return 0;
}