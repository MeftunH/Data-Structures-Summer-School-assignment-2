/*@file  :Test.cpp
* @description :Test programı için gereken kodları bulundurur.Dosyadan okuma,cop temizleme,nesnelerin olusturulmasi
* @course  :1.Öğretim A Grubu
* @assignment : 2
* @date  :30.08.2020
* @author :Maftun Hashimli(maftun.hashimli@ogr.sakarya.edu.tr)*/

//kutuphaneler
#include <iostream>
#include <fstream>
#include<string>
#include <sstream>
#include "AVLTree.h"
#include "Kisi.h"
using namespace std;

int main() {
	AVLTree* agac = new AVLTree();
	ifstream file("./doc/Kisiler.txt");
	string textline;
	string isim;
		string dyili;
		string kilo;
		//file'i sonuna kadar okuyorum
	while (getline(file, textline))
	{
		//isim dyili ve kiloyu aliyorum ve atamlarini yapiyorum
		stringstream linestream(textline);
		getline(linestream, isim, '#');
		getline(linestream, dyili, '#');
		getline(linestream, kilo, '#');
		linestream >> dyili >> kilo;
		//agaca ekliyorum
		agac->Ekle(new Kisi(isim,atoi(dyili.c_str()),atoi(kilo.c_str())));
	}
	//dosyayi kapatiyorum
	file.close();	
	//islemler bittikden sonra agaci postorder dolasiyorum
	agac->PostOrder();
	//Copleri temizliyorum	
	delete agac;
	system("pause");
	return 0;
}
