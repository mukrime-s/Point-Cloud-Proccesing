#pragma once
#include "PointCloud.h"
#include<Eigen/Dense>
#include <list>
using namespace std;

class Transform
{
private:
    Eigen::Vector3d angles;
    Eigen::Vector3d trans;
    Eigen::Matrix4d transMatrix;
public:

    Transform();
    ~Transform();
    void setAngles(double, double, double);
    void setTrans(double, double, double);

    double* getAngles();
    double* getTrans();

    void setRotation(double[]);
    void setRotation(Eigen::Vector3d);
    void setTranslation();
    void setTranslation(Eigen::Vector3d);

    list<Point> doTransform(list<Point> p);
    PointCloud doTransform(PointCloud pc);
};