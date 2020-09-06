/*@file  :AVLTree.h
* @description :Agac sinifinin tanimlanmasi yapilan header dosyasi.
* @course  :1.Öğretim A Grubu
* @assignment : 2
* @date  :30.08.2020
* @author :Maftun Hashimli(maftun.hashimli@ogr.sakarya.edu.tr)*/

#ifndef AVLTREE_HPP
#define AVLTREE_HPP

#include <algorithm>
#include <iostream>
#include "Dugum.h"
#include "Kisi.h"

using namespace std;

class AVLTree {
private:
	Dugum* root;
	bool ilkEkleme;
	Dugum* SolCocukIleDegistir(Dugum* alt_Dugum);//sağa dönüş
	Dugum* SagCocukIleDegistir(Dugum* alt_Dugum);//sola dönüş
	void DerinlikEsitle(Dugum* alt_Dugum); //Alcalma Yukselme islemleri bittikden sonra dugumun derinligini esitliyoruz
	void DerinlikKontrol(Dugum* alt_Dugum); //Dugumun seviyesi oncekiyle esit degilse islemleri
	int Yukseklik(Dugum* alt_Dugum);
	int DerinlikBul(Dugum* root, Dugum* ptr, int level = 0);//Dugumun seviyesini bulmak icin
	bool DugumSil(Dugum*& alt_Dugum);
	Dugum* AraVeEkle(Dugum* alt_Dugum, Kisi* kisi); //ekleme
	void PostOrder(Dugum* alt_Dugum); //postorder yazdirma

public:
	AVLTree();
	bool Bosmu();
	void Ekle(Kisi* _kisi); //Kisi ekleme
	void PostOrder();
	void DerinlikEsitle();
	void DerinlikKontrol();
	void Temizle();
	int Yukseklik();
	~AVLTree();
};

#endif