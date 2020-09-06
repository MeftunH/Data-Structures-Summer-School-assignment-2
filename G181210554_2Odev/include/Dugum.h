/*@file  :Dugum.h
* @description :Dugum sinifinin tanimlanmasi yapilan header dosyasi.
* @course  :1.Öğretim A Grubu
* @assignment : 2
* @date  :30.08.2020
* @author :Maftun Hashimli(maftun.hashimli@ogr.sakarya.edu.tr)*/


#ifndef DUGUM_H
#define DUGUM_H
//kutuphaneler
#include <iostream>
#include "Stack.h"
#include "Kisi.h"
using namespace std;

class Dugum
{
public:
	int veri;
	Dugum* sol;
	Dugum* sag;
	int yukseklik;
	int oncekiDerinlik;
	Stack* yigit;
	Kisi* kisi;
	Dugum(Kisi* _kisi); //Dugum constructoru
	~Dugum();
};

#endif
