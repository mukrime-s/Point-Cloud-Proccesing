#include "DepthCamera.h"

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
	int counter = 0;
	double corNumber;

	dataFile.open(fileName, std::ifstream::in);
	if (!dataFile) {
		cout << "Could not open the file - " << fileName << endl;
	}
	else
	{
		while (!dataFile.eof())
		{
			dataFile >> corNumber;

			if (floor(corNumber) != ceil(corNumber)) {

				P.setX(corNumber);
			}
			
			dataFile >> corNumber;
			if (floor(corNumber) != ceil(corNumber)) {

				P.setY(corNumber);
			}
			
			dataFile >> corNumber;
			if (floor(corNumber) != ceil(corNumber)) {

				P.setZ(corNumber);
			}
			PC.setPoint(counter,P);
			counter++;
		}
		return PC;
	}

}

