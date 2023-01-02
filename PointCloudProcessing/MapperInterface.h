#pragma once
#include <vector>
#include "PointCloud.h"
#include "PointCloudGenerator.h"
#include "PointCloudRecorder.h"
#include "Map.h"
class MapperInterface
{
private:
	PointCloud pointCloud;
	PointCloud patch;
	vector<PointCloudGenerator*> generators;
	PointCloudRecorder* recorder;
	Map* map;
public:
	void addGenerator(PointCloudGenerator* generator);
	void setRecorder(PointCloudRecorder* newRecorder);
	bool generate();
	bool recordPointCloud();
	bool recordMap();
	bool insertMap();

};

