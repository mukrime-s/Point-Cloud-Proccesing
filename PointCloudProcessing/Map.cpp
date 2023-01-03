#include "Map.h"
#include <iostream>
#include <fstream>
#include <iostream>
using namespace std;

Map::Map()
{
}

Map::~Map()
{
}

void Map::getPointClouds(vector<PointCloud> pointClouds)
{
}

void Map::setPointClouds(vector<PointCloud> pointClouds)
{
}

void Map::insertPointCloud(PointCloud& pc)
{
}

void Map::insertPoint(Point& p)
{
}

bool Map::loadMap(std::string fileName)
{
	return false;
}
/**
* @brief saveMap fonksiyonu fileName dosyasýna haritanýn pointCloud nesnelerini kaydeder.
*/
//
bool Map::saveMap(std::string fileName)
{
    ofstream outputFile(fileName);
    if (outputFile.is_open())
    {
        for (int i = 0; i < pointClouds.size(); ++i)
        {
            for (int j = 0; j < pointClouds[i].getPointNumber(); ++j)
            {
                outputFile << pointClouds[i].getPointX(j) << "\t" << pointClouds[i].getPointY(j) << "\t" << pointClouds[i].getPointZ(j) << "\n";
            }
        }
        return true;
    }
    return false;
}
