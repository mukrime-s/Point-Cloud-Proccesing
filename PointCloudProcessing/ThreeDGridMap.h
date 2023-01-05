#include <iostream>
#include<vector>
#include"PointCloud.h"
#include"Point.h"
#include"Map.h"

using namespace std;
class ThreeDGridMap : public Map
{
private:
	
	int counter = 0;
	double gridSize;
	int depth;
	bool*** map = new bool** [depth];
	int* lpoint = new int [depth];

public:
	
	ThreeDGridMap(int depth, double gridSize);
	~ThreeDGridMap();
	void setDepth(int depth);
	int getDepth() const;
	void setGridSize(double gridSize);
	double getGridSize() const;
	void insertPointCloud(list<Point> pc);
	void insertPoint(list <Point> p);
	bool getGrid(int x, int y, int z) const;
	bool loadMap(const string& fileName);
	bool saveMap(const string& fileName);

};

