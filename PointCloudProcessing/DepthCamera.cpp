#include "DepthCamera.h"
#include<iostream>

using namespace std;

DepthCamera::DepthCamera()
{
	
}

//bu fonksiyon fileName deðiskenine atama yapmamizi saglar.
void DepthCamera::setfileName(string fileName)
{
	this->fileName = fileName;
}

string DepthCamera::getfileName() const
{
	return this->fileName;
}

PointCloud DepthCamera::capture()
{
	ifstream dataFile;
	Point P;
	PointCloud PC;
	double corNumber;
	int size;

	dataFile.open(fileName, std::ifstream::in);
	if (!dataFile) {
		cout << "Could not open the file - " << fileName << endl;
	}
	else
	{
		dataFile >> size;
		PC.setPointNumber(size);
		while (!dataFile.eof())
		{
			dataFile >> corNumber;

			if (corNumber != (int)corNumber) {

				P.setX(corNumber);

			}

			dataFile >> corNumber;
			if (corNumber != (int)corNumber) {

				P.setY(corNumber);

			}

			dataFile >> corNumber;
			if (corNumber != (int)corNumber) {

				P.setZ(corNumber);

			}
			if (corNumber != (int)corNumber) {
				PC.setPoint(counter, P);
				counter++;
				/*PC.setPointNumber(counter + 1);*/
			}
		}

		return PC;
		dataFile.close();
	}
}


PointCloud DepthCamera::captureFor() {

	ifstream dataFile;
	Point P;
	PointCloud PC;
	Transform tr;

	double corNumber;
	int size;


	dataFile.open(fileName, std::ifstream::in);
	if (!dataFile)
	{
		cout << "Could not open the file - " << fileName << endl;
	}
	else
	{
		dataFile >> size;
		PC.setPointNumber(size);
		while (!dataFile.eof())
		{
			dataFile >> corNumber;

			if (corNumber != (int)corNumber) {

				P.setX(corNumber);

			}

			dataFile >> corNumber;
			if (corNumber != (int)corNumber) {

				P.setY(corNumber);

			}

			dataFile >> corNumber;
			if (corNumber != (int)corNumber) {

				P.setZ(corNumber);

			}
			if (corNumber != (int)corNumber) {
				PC.setPoint(counter, P);
				counter++;
				/*PC.setPointNumber(counter + 1);*/
			}
		}

	}

	if (this->fileName == "cam.txt") {
		tr.setAngles();
		tr.setTrans();
		tr.setRotation(tr.getAngles());
		tr.setTranslation();


	}
	else if (this->fileName == "cam1.txt")
	{
		tr.setAngles();
		tr.setTrans();
		tr.setRotation(tr.getAngles());
		tr.setTranslation();
	}
	else if (this->fileName == "cam2.txt")
	{
		tr.setAngles();
		tr.setTrans();
		tr.setRotation(tr.getAngles());
		tr.setTranslation();
	}
	else if (this->fileName == "cam3.txt")
	{
		tr.setAngles();
		tr.setTrans();
		tr.setRotation(tr.getAngles());
		tr.setTranslation();
	}


	PC = tr.doTransform(PC);





}


