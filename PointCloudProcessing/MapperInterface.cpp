#include "MapperInterface.h"

void MapperInterface::addGenerator(PointCloudGenerator* generator)
{
}

void MapperInterface::setRecorder(PointCloudRecorder* newRecorder)
{
}

bool MapperInterface::generate()
{
	return false;
}

bool MapperInterface::recordPointCloud()
{
	return false;
}

bool MapperInterface::recordMap()
{
	return false;
}

bool MapperInterface::insertMap()
{
	return false;
}
