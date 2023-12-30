/**
* AVLagaci.cpp
* @description Veri.txt den sayıları okuyup avl ağacı ve yigit lar oluşturup kurala silme işlemleri yapıyor
* @course Dersi aldığınız eğitim türü : 1/C
* @assignment Kaçıncı ödev olduğu : 2
* Kodu oluşturduğunuz Tarih : 11.12.2023
* Gruptakilerin yazar adları ve mail adresleri : İbrahim ALİKILIÇ / ibrahim.alikilic@ogr.sakarya.edu.tr
*/
#include "AVLagaci.hpp"
#include "Dugum.hpp"
#include "Yigin.hpp"
#include <iostream>
using namespace std;
Yigin *yigin = new Yigin(); // bunlara ilk başta bir adres gerektiğinden burada oluşturuyorum null atamak istemiyorum
Yigin *tempYigin = new Yigin();
Yigin *harfYigin = new Yigin();
bool ilkEsitlemeMi = true;
int kacinciYiginHarfSayac = 1;
AVLagaci::AVLagaci()
{
	kok = 0;
	agacSonraki = NULL;
	AVLToplamDugumDeger = 0;
}
int AVLagaci::Yukseklik(Dugum *aktifDugum)
{
	if (aktifDugum)
	{
		return 1 + max(Yukseklik(aktifDugum->sol), Yukseklik(aktifDugum->sag)); // buradaki mantık sağ ve soldan aşşağıya gidiyor bana lazım olan en uzun olan +1 açıklayamıyorum çiz anlarsın
	}
	return -1; // yoksa -1 lazım açıklayamadım çizmek lazım
}
bool AVLagaci::varmi(int aranan, Dugum *aktif)
{
	if (aktif->veri == aranan) // varsa dirk true
	{
		return true;
	}
	else if (aranan < aktif->veri) // bunun anlamı küçükse yani soldan kontrole devam
	{
		if (aktif->sol) // solda düğüm var mı kontrol
		{
			return varmi(aranan, aktif->sol); // soldan aramaya devam
		}
		return false; // solda düğüm yoksa aranan eleman yoktur demektir
	}
	else
	{ // eşitlik bakıldı , solunda mı diye bakıldı bir tek sağında olabilme ihtimali kaldı o yüzden direk else
		if (aktif->sag)
		{										// sağda düğüm var mı bilmem lazım
			return (varmi(aranan, aktif->sag)); // sağdan aramaya devam
		}
		return false; // eğer sağda düğüm yoksa eleman bulunmamaktadır demek
	}
}
int AVLagaci::enBuyuk(Dugum *aktif)
{
	// büyük değer her zaman sağa yazılır bu sebepten ilk önce sağı var mı diye bakıcaz eğer sağı varsa özyineleme ile en sağa gideceğiz
	if (aktif->sag)
	{
		return enBuyuk(aktif->sag);
	}
	return aktif->veri; // yani en büyüğü buldum demek
}
Dugum *AVLagaci::solaDondur(Dugum *buyukEbeveyin)
{
	Dugum *sagCocuk = buyukEbeveyin->sag; // yerini değiştireceğimiz düğümden sonrakini atmaış olduk
	buyukEbeveyin->sag = sagCocuk->sol;	  // şimdi şöyle ki biz büyük ebeveyini sağ çocuğun soluna alıcaz eğer orada çocuk varsa onu büyük ebeveyinin sağı yapmamız lazım yoksa 0 atanır zaten
	sagCocuk->sol = buyukEbeveyin;		  // büyük ebeveyini sağ çocuğun soluna aldık
	return sagCocuk;					  // bu dönüş sayesinde buyukEbeveyin üstündeki düğüm artık sağ çocuğa bağlanıyor
}
Dugum *AVLagaci::sagaDondur(Dugum *buyukEbeveyin) // soladöndürün tersi
{
	Dugum *solCocuk = buyukEbeveyin->sol;
	buyukEbeveyin->sol = solCocuk->sag;
	solCocuk->sag = buyukEbeveyin;
	return solCocuk;
}
Dugum *AVLagaci::ekle(int veri, Dugum *aktifDugum)
{
	if (aktifDugum == 0)
	{ // 0 demek bulunduğum yerde düğüm yok demek
		return aktifDugum = new Dugum(veri);
	}
	if (veri < aktifDugum->veri)
	{ // verim aktif düğümümden küçük olduğundan sola gitmem lazım
		// burada özyineleme ile direk soldaki düğümü çağırıyorum var mı kontrolüne geerek yok öçünkü fer fonksiyoruna girdiğimde bakıp yoksa ekle diyoruz zaten
		//( ilk başta var mı kontrolü yapmayı düşündüm sonra bu sebepten vaz geçtim tekrar bakınca da hatırlamak için belirteyim dedim)
		aktifDugum->sol = ekle(veri, aktifDugum->sol);
		// şimdi sola ekleme yaptık ve buraya geri döndü artık kontrol etmemiz lazım avl ağacının düzeni bozuldu mu
		// bu kontrolü yükseklik yardımıyla yapacağız
		// sola eklediğimiz için sol taraf 1 en fazla 1 fazla olabilir şeklinde kontorolümüzü yapıyoruz
		if (Yukseklik(aktifDugum->sol) - Yukseklik(aktifDugum->sag) > 1)
		{
			if (veri < aktifDugum->sol->veri)
			{
				// sol sol bazukluğu mu yoksa sol sağ bozukluğu mu var diye kontrol ediyorum
				aktifDugum = sagaDondur(aktifDugum); // eşitlik eskisi ile olan bağı kopartıp yeni bağı kurmuş olalım diye
			}
			else
			{
				// önce sola döndürüp sol sol haline getirip sonra sağ döndürme yapmam lazım
				aktifDugum->sol = solaDondur(aktifDugum->sol);
				aktifDugum = sagaDondur(aktifDugum);
			}
		}
	}
	// şimdi de verim ektif düğümümden büyük o sebepten sağa gitmem gereken durum
	else if (aktifDugum->veri < veri)
	{ // if in tam tersi
		aktifDugum->sag = ekle(veri, aktifDugum->sag);
		if (Yukseklik(aktifDugum->sag) - Yukseklik(aktifDugum->sol) > 1)
		{
			if (veri > aktifDugum->sag->veri)
			{
				// sol sol bazukluğu mu yoksa sol sağ bozukluğu mu var diye kontrol ediyorum
				aktifDugum = solaDondur(aktifDugum); // eşitlik eskisi ile olan bağı kopartıp yeni bağı kurmuş olalım diye
			}

			else
			{
				aktifDugum->sag = sagaDondur(aktifDugum->sag);
				aktifDugum = solaDondur(aktifDugum);
			}
		}
	}
	return aktifDugum; // hiçbirine girmediğinden zaten var oluyor bu da var olanı döndürüyor .
}
void AVLagaci::postOrder(Dugum *aktif)
{
	if (aktif)
	{
		postOrder(aktif->sol);
		postOrder(aktif->sag);
		cout << aktif->veri << " ";
	}
}
void AVLagaci::yiginEkle(Dugum *aktif)
{
	if (aktif)
	{
		yiginEkle(aktif->sol);
		yiginEkle(aktif->sag);

		if (aktif->sag == NULL && aktif->sol == NULL)
		{
			tempYigin->ekle(aktif->veri); // Düğümün verisini yığına ekliyoruz
		}
		else
		{
			AVLToplamDugumDeger += aktif->veri; // bu şekilde var olan avl ağacımdaki değerlerin hepsini toplamış oluyorum
		}
	}
}

void AVLagaci::AnaTepeOlusturma()
{
	tempYigin->anaTepe = tempYigin->tepe;
}
void AVLagaci::TepeSifirlama()
{
	Yigin *sifirlamaTemp = yigin;
	while (sifirlamaTemp != NULL)
	{
		sifirlamaTemp->tepe = sifirlamaTemp->anaTepe;
		sifirlamaTemp = sifirlamaTemp->sonraki;
	}
}

void AVLagaci::HarfOlustur()
{
	harfYigin = yigin;
	while (harfYigin->sonraki != NULL)
	{
		harfYigin = harfYigin->sonraki;
	}
	int ascii = AVLToplamDugumDeger % (90 - 65 + 1) + 65;
	harfYigin->tekamulHarf = ascii;
	harfYigin->kacinciYigin = kacinciYiginHarfSayac;
	kacinciYiginHarfSayac++;
	cout << harfYigin->tekamulHarf;
	AVLToplamDugumDeger = 0;
}
void AVLagaci::HarfleriYazdir()
{
	harfYigin = yigin;
	while (harfYigin != NULL)
	{
		cout << harfYigin->tekamulHarf;
		harfYigin = harfYigin->sonraki;
	}
}
void AVLagaci::SonYazma()
{
	harfYigin = yigin;
	system("cls");
	for (int i = 0; i < 30; i++)
	{
		cout << "=";
	}
	cout << endl;
	cout << "|\t\t\t     |" << endl;
	cout << "|\t\t\t     |" << endl;
	cout << "|\tSon Karakter: " << harfYigin->tekamulHarf << "      |" << endl;
	cout << "|\tAVL No      : " << harfYigin->kacinciYigin << "    |" << endl;
	cout << "|\t\t\t     |" << endl;
	cout << "|\t\t\t     |" << endl;
	for (int i = 0; i < 30; i++)
	{
		cout << "=";
	}
}

int AVLagaci::TepeGetir(int kacinciYigin)
{ // 1den başlıyoruz
	tempYigin = yigin;
	for (int i = 1; i < kacinciYigin; i++)
	{ // yigin sıram 1 den başladığından i de 1
		tempYigin = tempYigin->sonraki;
	}
	int gelen = tempYigin->getir();
	return gelen; // -1 mi kontrolüne gerek yok -1 gelirse onu da main de  karşılaştıracağız
}

int AVLagaci::yiginAzalt(int kacinciYigin)
{
	tempYigin = yigin;
	Yigin *BaglamakIcinTempYigin = tempYigin;
	for (int i = 1; i < kacinciYigin; i++)
	{ // yigin sıram 1 den başladığından i de 1
		if (i + 1 == kacinciYigin)
		{
			BaglamakIcinTempYigin = tempYigin; // bunun sayesinde bağlayabilicem
		}
		if (tempYigin->sonraki)
		{ // bu mantıklı ama silmem gerekebilir hiçbir yerde ilk başta tempYigin null olmamalı diye hatırladığımdan böyle yaptım
			tempYigin = tempYigin->sonraki;
		}
	}
	int tepeDegeri = tempYigin->cikar(); // yukarıda istediğim yığına gelip çıkarmış oldum
	if (tepeDegeri == -1)
	{ // yani yığın silinmeliyse
		if (tempYigin == yigin)
		{ // eğer ilk yığın siliniyorsa
			yigin = yigin->sonraki;
			tempYigin = yigin;
		}
		else if (tempYigin->sonraki)
		{ // silinecek eleman son eleman değil demek
			BaglamakIcinTempYigin->sonraki = tempYigin->sonraki;
		}
		else
		{
			BaglamakIcinTempYigin->sonraki = NULL; // son eleman silinirse sondan 1 önceki elemanın sonraki NULL olur.
		}
		// tempYigin benim silmek istediğim istediğim düğüm bunun önceki BaglamakIcinTempYigin eğer bunun sonrakini tempYigin->sonraki dersem onu silmiş olurum.
		return -1;
	}
}
// bu yığınları oluştururken eşitleme.
void AVLagaci::esitleme(bool sonMu)
{
	if (ilkEsitlemeMi)
	{
		ilkEsitlemeMi = false;
		yigin = tempYigin;
	}
	else
	{
		Yigin *temp2 = yigin;
		while (temp2->sonraki != NULL)
		{
			temp2 = temp2->sonraki;
		}
		temp2->sonraki = tempYigin; // Son elemanı tempYigin'e bağla
	}
	if (sonMu)
	{
		tempYigin = yigin;
		return; // bu benim en son eşitlemem artık kontrollerimi yigindan başlatarak yapıyorum demek ve bunun asıl sebebi getirde direk tempYigin->sonraki diyebilmek
	}
	tempYigin = new Yigin(); // her seferinde yeni adres göster diyorum
}
void AVLagaci::PointerSilici()
{
	yigin->~Yigin();
	harfYigin = 0;
	tempYigin = 0;
	yigin = 0;
	delete harfYigin;
	delete tempYigin;
	delete yigin;
}
AVLagaci::~AVLagaci(){
	kok = 0;
	agacSonraki = NULL;
	delete kok;
	delete agacSonraki;
}
// method içlerinde oluşturduğum düğümleri silmedim çünkü onlar zaten metod bitince hafızadan otomatik silinir.