#include <iostream>
#include <fstream>
#include <string>
#include<list>
#include<iterator>
#include"PointCloudGenerator.h"
#include"PointCloud.h"
#include"Point.h"
#include"Transform.h"


using namespace std;
class DepthCamera : public PointCloudGenerator
{
private:
	string fileName;
public:
	int counter = 0;

	DepthCamera();

	void setfileName(string fileName);
	string getfileName() const;

	PointCloud capture();
	PointCloud captureFor();
};

