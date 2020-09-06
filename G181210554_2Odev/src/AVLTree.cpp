/*@file  :AVLTree.cpp
* @description :Agac sinifi icin gereken metod govdelerini bulundurur
* @course  :1.Öğretim A Grubu
* @assignment : 2
* @date  :30.08.2020
* @author :Maftun Hashimli(maftun.hashimli@ogr.sakarya.edu.tr)*/
#include "AVLTree.h"
Dugum* AVLTree::SolCocukIleDegistir(Dugum* alt_Dugum)
{
	Dugum* tmp = alt_Dugum->sol;
	alt_Dugum->sol = tmp->sag;
	tmp->sag = alt_Dugum;

	// Yükseklikleri Güncelle 
	alt_Dugum->yukseklik = Yukseklik(alt_Dugum);
	tmp->yukseklik = max(Yukseklik(tmp->sol), alt_Dugum->yukseklik) + 1;

	return tmp;
}
Dugum* AVLTree::SagCocukIleDegistir(Dugum* alt_Dugum)
{
	Dugum* tmp = alt_Dugum->sag;
	alt_Dugum->sag = tmp->sol;
	tmp->sol = alt_Dugum;

	// Yükseklikleri Güncelle 
	alt_Dugum->yukseklik = Yukseklik(alt_Dugum);
	tmp->yukseklik = max(Yukseklik(tmp->sag), alt_Dugum->yukseklik) + 1;

	return tmp;
}
void AVLTree::DerinlikEsitle(Dugum* alt_Dugum) //Alcalma Yukselme islemleri bittikden sonra dugumun derinligini esitliyoruz
{
	if (alt_Dugum != NULL) {
		int yeniDerinlik = DerinlikBul(root, alt_Dugum);
		alt_Dugum->oncekiDerinlik = yeniDerinlik;
		DerinlikEsitle(alt_Dugum->sol);//SOL
		DerinlikEsitle(alt_Dugum->sag);//SAĞ
	}
}
void AVLTree::DerinlikKontrol(Dugum* alt_Dugum)
{
	if (alt_Dugum != NULL) {
		if (ilkEkleme == false) {
			if (alt_Dugum->oncekiDerinlik != -1) {
				int yeniDerinlik = DerinlikBul(root, alt_Dugum);
				//Dugumun onceki leveli yenisinden buyukse yukselmistir
				if (alt_Dugum->oncekiDerinlik > yeniDerinlik) {
					//yigita Y atilacaktir.Pushluyoruz
					alt_Dugum->yigit->Push(89);
				}
				//Dugumun onceki leveli yenisinden kucukse alcalmistir
				else if (alt_Dugum->oncekiDerinlik < yeniDerinlik) {
					//yigita A atilacaktir
					alt_Dugum->yigit->Push(65);
				}
				else {
					//Degismemisse D atilacaktir
					alt_Dugum->yigit->Push(68);
				}
			}
		}
		else {
			ilkEkleme = false;
		}
		//Derinligi her eklemede kontrol edecek
		DerinlikKontrol(alt_Dugum->sol);//SOL
		DerinlikKontrol(alt_Dugum->sag);//SAĞ
	}
}
int AVLTree::Yukseklik(Dugum* alt_Dugum)
{
	if (alt_Dugum == NULL)
		return -1; // Ortada dugum yoksa yukseklik anlamsizdir. Kodun çalismasi adina -1 verilmektedir.
	return 1 + max(Yukseklik(alt_Dugum->sol), Yukseklik(alt_Dugum->sag));
}
int AVLTree::DerinlikBul(Dugum* root, Dugum* ptr, int level)
{
	if (root == NULL)
		return -1;
	if (root == ptr) 
		return level;
	if (root->sol == NULL && root->sag == NULL)
		return -1;
	int levelLeft = DerinlikBul(root->sol, ptr, level + 1); //solunun leveli
	int levelRight = DerinlikBul(root->sag, ptr, level + 1);//saginin leveli
	if (levelLeft == -1)
		return levelRight;
	else
		return levelLeft;
}
bool AVLTree::DugumSil(Dugum*& alt_Dugum)
{
	Dugum* silinecekDugum = alt_Dugum;
	if (alt_Dugum->sag == NULL)//sağ çocuğu yoksa
		alt_Dugum = alt_Dugum->sol;//sol çocuğu yerine geçsin
	else if (alt_Dugum->sol == NULL)//sol çocuğu yoksa
		alt_Dugum = alt_Dugum->sag;//sağ çocuğu yerine geçsin
	else {//iki çocuğu da varsa solun en sağı yerine geçsin
		silinecekDugum = alt_Dugum->sol;
		Dugum* ebeveynDugum = alt_Dugum;
		while (silinecekDugum->sag != NULL) {
			ebeveynDugum = silinecekDugum;
			silinecekDugum = silinecekDugum->sag;
		}
		alt_Dugum->veri = silinecekDugum->veri;
		if (ebeveynDugum == alt_Dugum)
			alt_Dugum->sol = silinecekDugum->sol;
		else
			ebeveynDugum->sag = silinecekDugum->sol;
	}
	delete silinecekDugum;
	return true;
}
Dugum* AVLTree::AraVeEkle(Dugum* alt_Dugum, Kisi* kisi)
{
	   if (alt_Dugum == NULL) {//eğer kök boşsa yeni kök olarak ekler
		   alt_Dugum = new Dugum(kisi);
		   alt_Dugum->oncekiDerinlik = -1;
	   }
	   else if (kisi->yas <= alt_Dugum->kisi->yas) {//küçükse sola ekler
		   alt_Dugum->sol = AraVeEkle(alt_Dugum->sol, kisi);//sol alt çocuk yerine yeni bir ağaç oluşturur

		   if (Yukseklik(alt_Dugum->sol) - Yukseklik(alt_Dugum->sag) == 2) {//yükseklik farkı birden büyükse dengeler
			   // Sol Sol Durumu 
			   if (kisi->yas <= alt_Dugum->sol->kisi->yas) {
				   alt_Dugum = SolCocukIleDegistir(alt_Dugum);//tek dönüş
			   }
			   else { //Sol Sağ Durumu
				   alt_Dugum->sol = SagCocukIleDegistir(alt_Dugum->sol); //çift dönüş
				   alt_Dugum = SolCocukIleDegistir(alt_Dugum);
			   }
		   }
	   }
	   else if (kisi->yas > alt_Dugum->kisi->yas) {//büyükse sağa ekler, sağ durumu
		   alt_Dugum->sag = AraVeEkle(alt_Dugum->sag, kisi);

		   if (Yukseklik(alt_Dugum->sag) - Yukseklik(alt_Dugum->sol) == 2) {
			   if (kisi->yas > alt_Dugum->sag->kisi->yas) {
				   // Sağ Sağ Durumu
				   alt_Dugum = SagCocukIleDegistir(alt_Dugum);//Tek dönüş
			   }
			   else {// Sağ Sol Durumu 
				   alt_Dugum->sag = SolCocukIleDegistir(alt_Dugum->sag);//çift dönüş
				   alt_Dugum = SagCocukIleDegistir(alt_Dugum);
			   }
		   }
	   }
	   else; // bişey yapma

	   //Yüksekliği güncelle
	   alt_Dugum->yukseklik = Yukseklik(alt_Dugum);
	   return alt_Dugum;
}
void AVLTree::PostOrder(Dugum* alt_Dugum)
{
	if (alt_Dugum != NULL) {
		PostOrder(alt_Dugum->sol);//SOL
		PostOrder(alt_Dugum->sag);//SAĞ
		cout << alt_Dugum->kisi->isim << "," << alt_Dugum->kisi->dogumTarihi << "," << alt_Dugum->kisi->kilo << " Yigit: ";
		while (!alt_Dugum->yigit->IsEmpty()) {
			cout << (char)alt_Dugum->yigit->Pop() << " "; //yigittan Pop'la cekiyoruz
		}
		cout << endl;
	}
}
AVLTree::AVLTree()
{
	   root = NULL;
	   ilkEkleme = true;
}
bool AVLTree::Bosmu()
{
	return root == NULL;
}
void AVLTree::Ekle(Kisi* _kisi)
{
	root = AraVeEkle(root, _kisi);
	//eklendikten sonra levelini kontrol ediyor
	DerinlikKontrol();
	DerinlikEsitle();

}
void AVLTree::PostOrder()
{
	PostOrder(root);
}
void AVLTree::DerinlikEsitle()
{
	DerinlikEsitle(root);
}
void AVLTree::DerinlikKontrol()
{
	DerinlikKontrol(root);
}
int AVLTree::Yukseklik()
{
	return Yukseklik(root);//agacin yuksekligini bulmak icin koku gondeririz
}
void AVLTree::Temizle()
{
	while (!Bosmu()) DugumSil(root);
}
AVLTree::~AVLTree()
{
	   Temizle();
}

