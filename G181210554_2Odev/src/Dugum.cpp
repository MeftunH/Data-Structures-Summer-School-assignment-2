/*@file  :Dugum.cpp
* @description :Dugum sinifi icin gereken metod govdelerini bulundurur
* @course  :1.Öğretim A Grubu
* @assignment : 2
* @date  :30.08.2020
* @author :Maftun Hashimli(maftun.hashimli@ogr.sakarya.edu.tr)*/
#include "Dugum.h"
#include <iostream>

//constructor tanimlamasi
Dugum::Dugum(Kisi* _kisi)
{
	kisi = _kisi;
	sol = NULL;
	sag = NULL;
	yukseklik = 0;
	//yigit atamasi
	yigit = new Stack();
}
Dugum::~Dugum()
{
	delete this->yigit;
	delete this->kisi;
}
