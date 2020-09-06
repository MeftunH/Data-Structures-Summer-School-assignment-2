/**@file  :Kisi.cpp
* @description :Kisi sinifi icin gereken metod govdelerini bulundurur.
* @course  :1.Öğretim A Grubu
* @assignment : 2
* @date  :30.08.2020
* @author :Maftun Hashimli(maftun.hashimli@ogr.sakarya.edu.tr)**/
#include "Kisi.h"
//isim dogrumtarihi ve kiloyu esitliyoruz
Kisi::Kisi(string _isim, int _dogumTarihi, int _kilo)
{
	this->isim = _isim;
	this->dogumTarihi = _dogumTarihi;
	this->kilo = _kilo;
	//yasin daha sonra sorun cikarmamasi icin burada 2020'den cikariyoruz dogum tarihini.
	this->yas = 2020 - this->dogumTarihi;
}
