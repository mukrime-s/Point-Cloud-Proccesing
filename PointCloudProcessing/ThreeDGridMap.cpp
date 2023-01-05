#include "ThreeDGridMap.h"
#include <iostream>
#include <fstream>

using namespace std;


ThreeDGridMap::ThreeDGridMap(int depth, double gridSize) : depth(depth), gridSize(gridSize) {


    for (int i = 0; i < depth; i++) {

        // Allocate memory blocks for
        // rows of each 2D array
        map[i] = new bool* [depth];

        for (int j = 0; j < depth; j++) {

            // Allocate memory blocks for
            // columns of each 2D array
            map[i][j] = new bool[depth];
        }
    }
    for (int i = 0; i < depth; i++) {
        for (int j = 0; j < depth; j++) {
            for (int k = 0; k < depth; k++) {

                // Assign values to the
                // memory blocks created
                map[i][j][k] = false;
            }
        }
    }
}

ThreeDGridMap::~ThreeDGridMap() {

    for (int i = 0; i < depth; i++) {
        for (int j = 0; j < depth; j++) {
            delete[] map[i][j];
        }
        delete[] map[i];
    }
    delete[] map;

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

void ThreeDGridMap::insertPointCloud(list<Point> pc) {
    
    

}
/**
* @brief insertPoint fonksiyonu bir nokta bulutu objesini haritaya eklemek icin kullanildi
*/
void ThreeDGridMap::insertPoint(list <Point> p ) {
    
    
    // Noktanýn hangi küpte olduðunu hesapla
    
    for (list<Point>::iterator i = p.begin(); i != p.end(); i++) {
      
        counter++;
        int x = i->getX() / gridSize;

        x += 300;
        int y = i->getY() / gridSize;

        y += 300;

        int z = i->getZ() / gridSize;

        z += 300;

        if (map[x][y][z] == false) {
            
            this->map[x][y][z] = true;//alýnan koordinatlar haritada true olarak isaretlenir.
            
        }

    }

}
/**
* @brief getGrid fonksiyonu gridleri döndürür.
*/
bool ThreeDGridMap::getGrid(int x, int y, int z) const
{
    return this->map[x][y][z];
}
/**
* @brief loadMap fonksiyonu hartayi olusturur.
*/
bool ThreeDGridMap::loadMap(const string& fileName) {
    
    ofstream mapFile(fileName);
    if (!mapFile) {
        cout << "Dosya acilamadi lütfen kontrol ediniz!! " << fileName << endl;
        return false;
    }
    //mapFile  depth;//yaratilan dosyadan depth bilgisi alinir.
    //mapFile >> gridSize;//yaratilan dosyadan gridSize bilgisi alinir.
    
    for (int x = 0; x < depth; x++) {//okunan bilgilere göre harita olusturuldu.
        for (int y = 0; y < depth; y++) {
            for (int z = 0; z < depth; z++) {
                if (this->map[x][y][z] == true) {
                    mapFile << x << " " << y << " " << z << endl;
                }
                               
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
    mapFile.close();
 
    
    return true;
}


