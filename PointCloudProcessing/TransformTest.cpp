#include "Transform.h"
#include <iostream>
#include <math.h>



int main() {
	
	Transform t1;
	
	Point p1;
	
	p1.setX(0);
	p1.setY(1);
	p1.setZ(0);
	cout << "Eski nokta (" << p1.getX() << "," << p1.getY() << "," << p1.getZ() << ")" << endl<<"Donusumden sonraki nokta "<<endl;

	t1.setAngles(180, 90, 0);// x y z
	t1.setTrans(1.5, 1, 1.5);// x y z
	t1.setRotation();        // dönüþüm matrisi ayarlanýr
	t1.setTranslation();     // translation matrisi ayarlanýr.

	t1.doTransform(p1);      // dönüþüm yapýlýr.
	
	
	cout << "Yeni nokta (" << t1.doTransform(p1).getX() << "," << t1.doTransform(p1).getY() <<"," << t1.doTransform(p1).getZ() <<")" << endl;
	
	
	
	
	
	
	return 0; 


}