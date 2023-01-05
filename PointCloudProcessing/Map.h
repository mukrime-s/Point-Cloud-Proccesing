#pragma once
#include <iostream>
#include "Point.h"
#include "PointCloud.h"
#include <vector>
using namespace std;
class Map
{
private:
    vector<PointCloud> pointClouds;
    vector<Point> points;
public:
    Map();
    ~Map();
    void getPointClouds(vector<PointCloud> pointClouds);
    void setPointClouds(vector<PointCloud> pointClouds);
    virtual void insertPointCloud(PointCloud& pc);
    virtual void insertPoint(Point& p);
    bool loadMap(string fileName);
    bool saveMap(string fileName);
};

