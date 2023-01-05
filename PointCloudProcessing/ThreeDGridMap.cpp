#include "ThreeDGridMap.h"
#include <iostream>
#include <fstream>

using namespace std;


ThreeDGridMap::ThreeDGridMap(int depth, double gridSize) : depth(depth), gridSize(gridSize) {
    for (int x = 0; x < depth; x++) {
        for (int y = 0; y < depth; y++) {
            for (int z = 0; z < depth; z++) {
                map[x][y][z] = false;
            }
        }
    }
}

//Set get fonksiyonlarý

void ThreeDGridMap::setDepth(int depth)
{
    this->depth = depth;
}

int ThreeDGridMap::getDepth() const
{

    return this->depth;

}

void ThreeDGridMap::setGridSize(double gridSize)
{

    this->gridSize = gridSize;


}

double ThreeDGridMap::getGridSize() const
{

    return this->gridSize;

}

/**
* @brief insertPointCloud fonksiyonu bir nokta bulutu objesini haritaya eklemek icin kullanildi
*/

void ThreeDGridMap::insertPointCloud(list<Point>* pc) {
    for (list<Point>::iterator i = pc->begin(); i != pc->end(); i++) {
        insertPoint(*i);
    }
}
/**
* @brief insertPoint fonksiyonu bir nokta bulutu objesini haritaya eklemek icin kullanildi
*/
void ThreeDGridMap::insertPoint(Point& p) {
    // Noktanýn hangi küpte olduðunu hesapla
    int x = p.getX();
    int y = p.getY();
    int z = p.getZ();
    this->map[x][y][z] = true;//alýnan koordinatlar haritada true olarak isaretlenir.
}
/**
* @brief getGrid fonksiyonu gridleri döndürür.
*/
bool ThreeDGridMap::getGrid(int x, int y, int z) const
{
    return map[x][y][z];
}
/**
* @brief loadMap fonksiyonu hartayi olusturur.
*/
bool ThreeDGridMap::loadMap(const string& fileName) {
    ifstream mapFile(fileName);
    if (!mapFile) {
        cout << "Dosya acilamadi lütfen kontrol ediniz!! " << fileName << endl;
        return false;
    }
    mapFile >> depth;//yaratilan dosyadan depth bilgisi alinir.
    mapFile >> gridSize;//yaratilan dosyadan gridSize bilgisi alinir.
    for (int x = 0; x < depth; x++) {//okunan bilgilere göre harita olusturuldu.
        for (int y = 0; y < depth; y++) {
            for (int z = 0; z < depth; z++) {
                mapFile >> map[x][y][z];
            }
        }
    }
    mapFile.close();
    return true;
    
}
/**
* @brief saveMap fonksiyonu  harita verilerini dosyaya kaydeder.
*/

bool ThreeDGridMap::saveMap(const string& fileName) {
    ofstream mapFile(fileName);
    if (!mapFile) {
        cout << "Dosya acilamadi lütfen kontrol ediniz!! " << fileName << endl;
        return false;
    }
    mapFile << depth << " " << gridSize << endl;
    for (int x = 0; x < depth; x++) {//dosyayi kaydetme islemi
        for (int y = 0; y < depth; y++) {
            for (int z = 0; z < depth; z++) {
                mapFile << map[x][y][z] << " ";
            }
            mapFile << endl;
        }
        mapFile << endl;
    }

    mapFile.close();
    return true;
}


