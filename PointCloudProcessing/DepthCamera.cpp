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
	PointCloud PCC;
	double corNumber;
	int size;
	list <Point> p1;
	int counter = 0;

	dataFile.open(fileName, std::ifstream::in);
	if (!dataFile) {
		cout << "Could not open the file - " << fileName << endl;
	}
	else
	{
		dataFile >> size;
		//PC.setPointNumber(size);

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
				//PC.setPoint(P);
				counter++;
				p1.push_back(P);

			}
		}

		PC.setPoint(p1);
		PC.setPointNumber(counter);

		//dataFile.close();


		dataFile.close();

		return PC;



	}
}


PointCloud DepthCamera::captureFor() {

	ifstream dataFile;
	PointCloud PC;
	Point P;
	list <Point> p1;

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
		//PC.setPointNumber(size);

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
				//PC.setPoint(P);
				counter++;
				p1.push_back(P);


			}
		}
		PC.setPointNumber(counter);
		PC.setPoint(p1);



	}
	double array[9] = {
		  -0.7076050, 0.0065031, -0.7065783,
		   0.7066082, 0.0065134, -0.7075750,
		   0.0000008, -0.9999576, -0.0092041

	};
	double array2[9] = {
		  -0.6638364, -0.0068830, 0.7478462,
		  -0.7478778, 0.0061099, -0.6638082,
		  -0.0000002, -0.9999576, -0.0092036

	};
	double array3[9] = {
		 0.8762180, 0.0044351, -0.4818945,
		 0.4819149, -0.0080638, 0.8761809,
		 0.0000001, -0.9999577, -0.0092030

	};
	double array4[9] = {
		  0.3597052, -0.0085871, 0.9330265,
		 -0.9330660, -0.0033108, 0.3596900,
		  0.0000003, -0.9999576, -0.0092033

	};



	if (this->fileName == "cam.txt") {

		tr.setRotation(array);
		tr.setTrans(1.95704, 1.93000, 1.05707);
		tr.setTranslation();

	}
	else if (this->fileName == "cam1.txt")
	{
		tr.setRotation(array2);
		tr.setTrans(-1.91288, 1.94412, 1.05465);
		tr.setTranslation();
	}
	else if (this->fileName == "cam2.txt")
	{
		tr.setRotation(array3);
		tr.setTrans(1.96978, -1.94622, 1.05264);
		tr.setTranslation();
	}
	else if (this->fileName == "cam3.txt")
	{
		tr.setRotation(array4);
		tr.setTrans(-1.87445, -1.95027, 1.06432);
		tr.setTranslation();
	}
	p1 = PC.getPoint();

	//PC = tr.doTransform(PC);

	PC.setPointNumber(p1.size());

	//PCC = tr.doTransform(PC);

	dataFile.close();
	return tr.doTransform(PC);
}


