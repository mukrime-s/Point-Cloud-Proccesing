#include "DepthCamera.h"
#include<iostream>

using namespace std;

DepthCamera::DepthCamera()
{
	//Constructor fonksiyonu.
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


