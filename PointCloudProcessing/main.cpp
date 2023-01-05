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

	cout << "Islem Baslatildi..." << endl;
	DepthCamera dp, dp2, dp3, dp4;
	PointCloud pc, pc2, pc3, pc4;


	list<Point>::iterator iter;
	list<Point> P1;
	list<Point> P2;
	list<Point> P3;
	list<Point> P4;

	dp.setfileName("cam.txt");
	dp2.setfileName("cam1.txt");
	dp3.setfileName("cam2.txt");
	dp4.setfileName("cam3.txt");

	pc = dp.captureFor();
	pc2 = dp2.captureFor();
	pc3 = dp3.captureFor();
	pc4 = dp4.captureFor();


	ThreeDGridMap* tgm = new ThreeDGridMap(1000, 0.03);
	P1 = pc.getPoint();
	tgm->insertPoint(P1);
	tgm->loadMap("3DSONUC.txt");
	delete tgm;
	//tgm.~ThreeDGridMap();


	ThreeDGridMap* tgm1 = new ThreeDGridMap(1000, 0.03);
	P2 = pc2.getPoint();
	tgm1->insertPoint(P2);
	tgm1->loadMap("3DSONUC1.txt");
	delete tgm1;
	//tgm1.~ThreeDGridMap();

	ThreeDGridMap* tgm2 = new ThreeDGridMap(1000, 0.03);
	P3 = pc3.getPoint();
	tgm2->insertPoint(P3);
	tgm2->loadMap("3DSONUC2.txt");
	delete tgm2;
	//tgm2.~ThreeDGridMap();

	ThreeDGridMap* tgm3 = new ThreeDGridMap(1000, 0.03);

	P4 = pc4.getPoint();
	tgm3->insertPoint(P4);
	tgm3->loadMap("3DSONUC3.txt");
	//tgm3.~ThreeDGridMap();
	delete tgm3;

	cout << "Islem Tamamlandi..." << endl;

	return 0;
}