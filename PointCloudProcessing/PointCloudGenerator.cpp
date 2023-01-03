#include "PointCloudGenerator.h"
#include"Transform.h"

//PointCloudGenerator için yapýcý(constructor) fonskiyonu
PointCloudGenerator::PointCloudGenerator()
{

}
//Setleme iþlem yapar parametre olarak transform nesnesinþi alýr bu classdaki transforma kopyalar
void PointCloudGenerator::setTransform(Transform tr) {

	transform = tr;
}
// bu fonksiyon transform nesnesini döndürür
Transform PointCloudGenerator::getTransform() {

	return transform;

}
