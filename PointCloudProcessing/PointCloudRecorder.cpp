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
void PointCloudRecorder::setFile(string& File)
{
	this->File = File;
}
/**
* @brief getFile fonksiyonu dosya ismini döndürür.
*/
string PointCloudRecorder::getFile()const
{
	return File;
}
/**
* @brief nokta bulutunu  dosyaya kaydeden fonksiyon olusturuldu.
*/
bool PointCloudRecorder::Save(const PointCloud& pc)const
{
	bool success = false;
	ofstream outputFile(File);
	if (outputFile.is_open()) {
		for (int i = 0; i < pc.getPointNumber(); ++i) {
			outputFile << pc.getPointX(i) << "\t" << pc.getPointY(i) << "\t" << pc.getPointZ(i) << "\n";
		}
		success = true;
	}

	return success;
}
