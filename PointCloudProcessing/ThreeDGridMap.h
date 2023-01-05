#include <iostream>
#include"PointCloud.h"
#include"Point.h"
#include"Map.h"

using namespace std;
class ThreeDGridMap:public Map
{
private:
	
	bool map[100][100][100];
	double gridSize;
	int depth;

public:
	
	ThreeDGridMap(int depth, double gridSize);
	void setDepth(int depth);
	int getDepth() const;
	void setGridSize(double gridSize);
	double getGridSize() const;
	void insertPointCloud(list<Point>* pc);
	void insertPoint(Point& p);
	bool getGrid(int x, int y, int z) const;
	bool loadMap(const string& fileName);
	bool saveMap(const string& fileName);

};

