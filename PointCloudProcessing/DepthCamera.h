#include <iostream>
#include <fstream>
#include <string>
#include"PointCloud.h"
#include"Point.h"

using namespace std;
class DepthCamera
{

private:
	string fileName;
public:
	int counter = 0;

	DepthCamera();

	void setfileName(string fileName);
	string getfileName() const;

	PointCloud capture();
};

