/**
* @file PointCloudRecorder.h
* @Author Mukrime Sagiroglu ---->mkrimesagrglu@gmail.com
* @date Aralik 2021
* @brief nokta bulutlarini dosyaya kaydetme islemi
*/
#pragma once
#include "PointCloud.h"
#include <string>
using namespace std;
class PointCloudRecorder
{
#pragma once
private:

	string File;
public:
	
	PointCloudRecorder();
	void setFile(string& );
	string getFile()const;
	bool Save(const PointCloud& pc)const;
};

