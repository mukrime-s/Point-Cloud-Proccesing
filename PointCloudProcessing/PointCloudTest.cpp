/**
* @file PointCloudTest.cpp
* @Author Mukrime Sagiroglu ---->mkrimesagrglu@gmail.com
* @date Aralýk 2021
* @brief Point cloud test sýnýfý oluþturuldu.
*/
#include <iostream>
#include "PointCloud.h"
#include "Point.h"
using namespace std;

void testPointCloud() {
	
	Point pp(0, 0, 0);
	PointCloud pc1;
	bool testFailed = false;
	

	//if (pc1.getPointNumber() != 1) {
	//	testFailed = true;
	//}
	//if (pc1.getPointX(0) != 0) {
	//	testFailed = true;
	//}
	//if (pc1.getPointY(0) != 0) {
	//	testFailed = true;
	//}
	//if (pc1.getPointZ(0) != 0) {
	//	testFailed = true;
	//}

	//if (testFailed) {
	//	cout << "Error! check default constructor function" << endl;
	//	return;
	//}

	PointCloud pc2(3);


	/**
	* @brief Added set pointx,pointy and pointz test.
	*/
	double beklenenDeger1[] = { 1, 2, 3 };
	;

	pc2.setPointX(0, beklenenDeger1[0]);
	pc2.setPointY(0, beklenenDeger1[1]);
	pc2.setPointZ(0, beklenenDeger1[2]);

	for (int i = 0; i < 3; i++) {
		double gercekDeger1;
		if (i == 0) {
			gercekDeger1 = pc2.getPointX(0);
		}
		else if (i == 1) {
			gercekDeger1 = pc2.getPointY(0);
		}
		else {
			gercekDeger1 = pc2.getPointZ(0);
		}
		if (gercekDeger1 != beklenenDeger1[i]) {
			cout << "Error! check  setPoint function" << (char)('X' + i) << endl;
			return;
		}
	}


	/**
	* @brief Added setPoint number test.
	*/
	pc2.setPointNumber(5);
	if (pc2.getPointNumber() != 5) {
		cout << "Error!check setPointNumber function" << endl;
		return;
	}

	/**
	* @brief Added setPoint test.
	*/
	Point p1(4, 5, 6);
	pc2.setPoint(1, p1);

	double beklenenDeger2[] = { 4, 5, 6 };

	for (int i = 0; i < 3; i++) {
		double gercekDeger2;
		if (i == 0) {
			gercekDeger2 = pc2.getPointX(1);
		}
		else if (i == 1) {
			gercekDeger2 = pc2.getPointY(1);
		}
		else {
			gercekDeger2 = pc2.getPointZ(1);
		}
		if (gercekDeger2 != beklenenDeger2[i]) {
			cout << "Error!check setPoint function" << endl;
			return;
		}
	}
	/**
	* @brief This part for test the getPoint() function of the PointCloud object is working correctly.
	*/
	Point p2 = pc2.getPoint(1);

	double beklenenDeger3[] = { 4, 5, 6 };

	for (int i = 0; i < 3; i++) {
		double gercekDeger3;
		if (i == 0) {
			gercekDeger3 = p2.getX();
		}
		else if (i == 1) {
			gercekDeger3 = p2.getY();
		}
		else {
			gercekDeger3 = p2.getZ();
		}
		if (gercekDeger3 != beklenenDeger3[i]) {
			cout << "Error!check getPoint function" << endl;
			return;
		}
	}

	/**
	* @brief This part for test check operator+ .
	*/
	PointCloud pc3(2); //nokta sayýsý 2  olursa
	pc3.setPointX(0, 7);
	pc3.setPointY(0, 8);
	pc3.setPointZ(0, 9);
	PointCloud pc4(3);//nokta sayýsý 3 olursa
	pc4.setPointX(0, 10);
	pc4.setPointY(0, 11);
	pc4.setPointZ(0, 12);
	PointCloud pc5 = pc3 + pc4;

	double beklenenDeger4[][3] = {
		{7, 8, 9},
		{10, 11, 12}
	};

	for (int i = 0; i < 2; i++) {
		for (int j = 0; j < 3; j++) {
			double gercekDeger4;
			if (j == 0) {
				gercekDeger4 = pc5.getPointX(i);
			}
			else if (j == 1) {
				gercekDeger4 = pc5.getPointY(i);
			}
			else {
				gercekDeger4 = pc5.getPointZ(i);
			}
			if (gercekDeger4 != beklenenDeger4[i][j]) {
				cout << "Error!check operator+ function" << endl;
				return;
			}
		}
	}

	if (pc5.getPointNumber() != 5) { //toplam nokta sayisinin 5 'e esit olmasý gerekir
		cout << "Error!check operator+ function the total number of points is not equal to 5" << endl;
		return;
	}


	/**
	* @brief  This part for test operator+ .
	*/
	PointCloud pc6(2);
	pc6.setPointX(0, 1);
	pc6.setPointY(0, 2);
	pc6.setPointZ(0, 3);
	PointCloud pc7 = pc6;
	//PointCloud pc7;
	pc7.setPointNumber(pc6.getPointNumber());
	pc7.setPointX(0, pc6.getPointX(0));
	pc7.setPointY(0, pc6.getPointY(0));
	pc7.setPointZ(0, pc6.getPointZ(0));

	if (pc7.getPointNumber() != 2 || pc7.getPointX(0) != 1 || pc7.getPointY(0) != 2 || pc7.getPointZ(0) != 3) {
		cout << "Error!Check operator= function" << endl;
		return;
	}

	/**
	* @brief  This part for test deleteMovePoint function .
	*/
	PointCloud pc8(3); //Test için bu bölüm, pc8 nesnesinin içindeki 1. noktayý silen ve kalan noktalarý bir satýr yukarý taþýyan deleteMovePoint() iþlevi çalýþýr.
	pc8.setPointX(0, 1);
	pc8.setPointY(0, 2);
	pc8.setPointZ(0, 3);
	pc8.setPointX(1, 4);
	pc8.setPointY(1, 5);
	pc8.setPointZ(1, 6);
	pc8.setPointX(2, 7);
	pc8.setPointY(2, 8);
	pc8.setPointZ(2, 9);
	pc8.deleteMovePoint(1);
	if (pc8.getPointNumber() != 2 || pc8.getPointX(0) != 1 || pc8.getPointY(0) != 2 || pc8.getPointZ(0) != 3 || pc8.getPointX(1) != 7
		|| pc8.getPointY(1) != 8 || pc8.getPointZ(1) != 9) {
		cout << "Error! Check deleteMovePoint function" << endl;
		return;
	}

	cout << "Tests completed successfully!" << endl;
}



int main(){
	
	testPointCloud();

	
	/**
	* @brief Added default constructor test.
	*/
	
	return 0;
}

