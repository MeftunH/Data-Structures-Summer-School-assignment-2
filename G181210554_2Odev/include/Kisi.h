/*@file  :Kisi.h
* @description :Kisi sinifinin tanimlanmasi yapilan header dosyasi.
* @course  :1.Öğretim A Grubu
* @assignment : 2
* @date  :30.08.2020
* @author :Maftun Hashimli(maftun.hashimli@ogr.sakarya.edu.tr)*/
#ifndef KISI_HPP
#define KISI_HPP

#include <iostream>

using namespace std;
class Kisi
{
public:
	string isim;
	int dogumTarihi;
	int kilo;
	int yas;

	Kisi(string _isim, int _dogumTarihi, int _kilo); //constructor
};

#endif
