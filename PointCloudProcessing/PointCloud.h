#pragma once
#include "Point.h"
using namespace std;


class PointCloud
{
private:
	int pointNumber;


public:
	PointCloud();
	void setpointNumber(int
	
	
	
	
	);
	int getpointNumber() const;



	PointCloud operator+(PointCloud Pc);
	void operator=(PointCloud* Pc);


};

