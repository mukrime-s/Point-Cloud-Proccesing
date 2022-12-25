#include "ThreeDGridMap.h"
#include<iostream>

using namespace std;


ThreeDGridMap::ThreeDGridMap(int depth, double gridSize) : depth(depth), gridSize(gridSize) {
    // Tüm küplerin deðerini false yap
    for (int i = 0; i < depth; i++) {
        for (int j = 0; j < depth; j++) {
            for (int k = 0; k < depth; k++) {
                map[i][j][k] = false;
            }
        }
    }
}

//Set get fonksiyonlarý

void ThreeDGridMap::setDepth(int depth)
{
    this->depth = depth;
};

int ThreeDGridMap::getDepth() const
{

    return this->depth;

};

void ThreeDGridMap::setGridSize(double gridSize)
{

    this->gridSize = gridSize;


};

double ThreeDGridMap::getGridSize() const
{

    return this->gridSize;

};


//void ThreeDGridMap::insertPointCloud(PointCloud&  pc) {
//    // PointCloud'taki her bir noktayý haritaya ekle
//    for (int i = 0; i < pc.getPointNumber(); i++) {
//        insertPoint(pc.getPoint(i));
//    }
//}
//
//void ThreeDGridMap::insertPoint(Point& p) {
//    // Noktanýn hangi küpte olduðunu hesapla
//    double i = p.getX() / gridSize;
//    double j = p.getY() / gridSize;
//    double k = p.getZ() / gridSize;
//
//    // Küpü true olarak iþaretle
//    map[i][j][k] = true;
//};


bool ThreeDGridMap::loadMap(const string& fileName) {
    // Haritayý dosyadan oku
    return true;
};


bool ThreeDGridMap::saveMap(const string& fileName) {

    // Haritayý dosyaya kaydet
    return true;
};


