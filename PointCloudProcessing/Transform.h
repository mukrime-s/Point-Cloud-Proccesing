#pragma once
#include "PointCloud.h"

using namespace std;

class Transform
{
private:
    
    double angles[3];
    double trans[3];
    double transMatrix[4][4];
    double rotationMatrix[3][3];
public:
 
        Transform();
    void setAngles(double, double, double);
    void setTrans(double, double, double);

    double* getAngles();
    double* getTrans();

    void setRotation();
    void setTranslation();

    Point doTransform(Point p);
    PointCloud doTransform(PointCloud pc);
};