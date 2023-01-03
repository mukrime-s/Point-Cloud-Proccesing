#pragma once
#include "Transform.h"
#include "PointCloud.h"

class PointCloudGenerator
{
public:
	PointCloudGenerator();

	virtual PointCloud capture() = 0;
	virtual PointCloud captureFor() = 0;
	void setTransform(Transform);
	Transform getTransform();


private:
	Transform transform;


};

