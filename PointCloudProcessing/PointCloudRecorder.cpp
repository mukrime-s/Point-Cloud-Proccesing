/**
* @file PointCloudRecorder.cpp
* @Author Mukrime Sagiroglu ---->mkrimesagrglu@gmail.com
* @date Aralik 2022
* @brief nokta bulutlarini dosyaya kaydetme islemi
*/
#include "PointCloudRecorder.h"
#include <string>
#include <fstream>
#include <iostream>
using namespace std;
/**
* @brief Yapici fonsiyon olusturuldu.
*/
PointCloudRecorder::PointCloudRecorder()
{
}

/**
* @brief setFile fonksiyonu, PointCloudRecorder sýnýfýnýn fileName özelliðine bir dosya adý atamasý yapar. Bu fonksiyon, kullanýcýnýn belirttiði bir dosya adýný alýr ve fileName özelliðine atar.
*/
void PointCloudRecorder::setFile(string& fileName)
{
	this->fileName = fileName;
}
/**
* @brief getFile fonksiyonu dosya ismini döndürür.
*/
string PointCloudRecorder::getfileName()const
{
	return fileName;
}
/**
* @brief nokta bulutunu  dosyaya kaydeden fonksiyon olusturuldu.
*/
bool PointCloudRecorder::Save(PointCloud& pcl)const
{
	bool success = false;
	ofstream outputFile(fileName);
	if (outputFile.is_open()) {
		for (int i = 0; i < pcl.getPointNumber(); ++i) {
			outputFile << pcl.getPointX(i) << "\t" << pcl.getPointY(i) << "\t" << pcl.getPointZ(i) << "\n";
		}
		success = true;
	}

	return success;
}
