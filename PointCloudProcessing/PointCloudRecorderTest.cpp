/**
* @file PointCloudRecorder.cpp
* @Author Mukrime Sagiroglu ---->mkrimesagrglu@gmail.com
* @date Aralik 2021
* @brief PointCloudRecorder Test kodu yazýldý.
*/
#include "PointCloudRecorder.h"
#include "PointCloud.h"
#include <string>
#include <iostream>
using namespace std;

int main()
{
	PointCloudRecorder pcr;
	pcr.setFile("test.txt");
	PointCloud pc(10);// test edilmek için 10 nokta eklendi.
	pc.addPoint(1, 2, 3);
	pc.addPoint(4, 5, 6);
	pc.addPoint(7, 8, 9);
	pc.addPoint(10, 11, 12);
	pc.addPoint(13, 14, 15);
	pc.addPoint(16, 17, 18);
	pc.addPoint(19, 20, 21);
	pc.addPoint(22, 23, 24);
	pc.addPoint(25, 26, 27);
	pc.addPoint(28, 29, 30);

	bool success = pcr.Save(pc);
	if (success)
		cout << "Point cloud saved to file." << endl;
	else
		cout << "Error !! Could not open file or save PointCloud." << endl;

	return 0;
}