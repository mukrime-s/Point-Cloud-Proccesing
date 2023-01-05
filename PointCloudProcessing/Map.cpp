#include "Map.h"
#include <iostream>
#include <fstream>
#include <iostream>
using namespace std;

Map::Map(){

}

Map::~Map()
{
}
/**
* @brief getPointClouds fonksiyonu map sýnýfýnýn pointClouds vektörünün kopyasýný alýp parametre olarak aldýðý pointClouds vektörüne kopyalar.
*/

void Map::getPointClouds(vector<PointCloud> pointClouds)
{
    pointClouds = this->pointClouds;

}
/**
* @brief setPointClouds fonksiyonu parametre olarak aldýðý pointClouds vektörünü Map sýnýfýnýn pointClouds vektörüne atar
*/

void Map::setPointClouds(vector<PointCloud> pointClouds)
{
    this->pointClouds = pointClouds;
}
/**
* @brief insertPointCloud fonksiyonu PointCloud sýnýfýndan bir nesnenin Map sýnýfýnýn pointClouds vektörüne eklenmesini saðlar. 
*/

void Map::insertPointCloud(PointCloud& pc)
{
    this->pointClouds.push_back(pc);
}
/**
* @brief insertPointCloud fonksiyonu parametre olarak aldýðý p deðiþkenini Map sýnýfýnýn points vektörüne push_back ile ekler. 
*/
void Map::insertPoint(Point& p)
{
    this->points.push_back(p);
}
/**
* @brief loadMap fonksiyonu, harita verisi içeren bir dosyayý okuyarak Map sýnýfýnýn üyelerini doldurmayý saðlar.
*/
bool Map::loadMap(std::string fileName)
{
	return false;
}
/**
* @brief saveMap fonksiyonu fileName dosyasýna haritanýn pointCloud nesnelerini kaydeder.
*/

bool Map::saveMap(std::string fileName)
{
    ofstream mapFile(fileName);
    if (mapFile.is_open())
    {
        for (int i = 0; i < pointClouds.size(); ++i)
        {
            for (int j = 0; j < pointClouds[i].getPointNumber(); ++j)
            {
                mapFile << pointClouds[i].getPointX(j) << "\t" << pointClouds[i].getPointY(j) << "\t" << pointClouds[i].getPointZ(j) << "\n";
            }
        }
        return true;
    }
    else {
        cout << "Dosya acýlamadý kontrol edin!!" << endl;
        return false;
        
    }
    
}
