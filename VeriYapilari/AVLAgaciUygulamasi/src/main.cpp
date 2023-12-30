/**
* main.cpp
* @description Veri.txt den sayıları okuyup avl ağacı ve yigit lar oluşturup kurala silme işlemleri yapıyor
* @course Dersi aldığınız eğitim türü : 1/C
* @assignment Kaçıncı ödev olduğu : 2
* Kodu oluşturduğunuz Tarih : 11.12.2023
* Gruptakilerin yazar adları ve mail adresleri : İbrahim ALİKILIÇ / ibrahim.alikilic@ogr.sakarya.edu.tr
*/

#include "AVLagaci.hpp"
#include "Dugum.hpp"
#include "Yigin.hpp"
#include <fstream>
#include <sstream>
#include <string>
using namespace std;
AVLagaci *agac = nullptr;
void kucukAzaltma();
void buyukAzaltma();
bool silmeYapildiMi = false;
int main()
{

	std::ifstream dosya("Veri.txt"); // Dosyayı oku

	if (!dosya.is_open())
	{
		cerr << "Dosya açılamadı!" << std::endl;
		return 1;
	}


	AVLagaci *temp = nullptr;
	string satir;
	bool ilkMi = true;
	// burası ilk atama işlemi
	while (getline(dosya, satir))
	{
		AVLagaci *agac2 = new AVLagaci();
		istringstream satirStream(satir);
		int sayi;

		while (satirStream >> sayi)
		{
			agac2->kok = agac2->ekle(sayi, agac2->kok);
		}

		if (ilkMi)
		{
			agac = agac2;
			temp = agac;
			ilkMi = false;
		}
		else
		{
			temp->agacSonraki = agac2;
			temp = temp->agacSonraki;
		}
	}

	// yazdırma döngüsü ve yıgın oluşturma
	AVLagaci *temp2 = agac;
	bool sonMu = false;
	while (temp2 != nullptr)
	{
		temp2->yiginEkle(temp2->kok);
		if (temp2->agacSonraki == nullptr)
		{
			sonMu = true;
		}
		temp2->AnaTepeOlusturma();
		temp2->esitleme(sonMu); // bu alttaydı ilk başta ama düşününce sıkıntı olabilir çünkü null bir şeyden nasıl çağırabiliriz (olmaz)
		temp2->HarfOlustur();	// ilk yazma burada
		temp2 = temp2->agacSonraki;
	}
	dosya.close();

	AVLagaci *temp3 = agac;
	while (temp3->agacSonraki != NULL) // tek ağaç kalıncaya kadar demek
	{								   // yani tek düğüm kalmayana kadar
		silmeYapildiMi = false;		   // her seferinde burada false yapıyorum ki kucukAzaltma da true olursa tekrardan dönüşte false olabilsin.
		kucukAzaltma();
		temp3 = agac;
		if (temp3->agacSonraki && silmeYapildiMi == false)
		{
			buyukAzaltma();
			temp3 = agac;
		}
	}
	// üstü geçmiş olması demek artık sadece 1 tane kaldı demektir.
	agac->SonYazma();
	// hafıza temizliği
	agac->PointerSilici();
	agac->~AVLagaci();
	temp=0;
	temp2=0;
	temp3=0;
	agac=0;
	delete temp;
	delete temp2;
	delete temp3;
	delete agac;
	return 0;
}
// yigini hallettin galiba break point ile dene sonra aşşağıdan devam.// yorum satırına aldığın kısımda gelmen lazım yani eksiltmeyi yap sonra da kontrol
void kucukAzaltma()
{
	bool ilkGirdi = true;
	// buradan itibaren en büyük en küçük çıkarma işlemleri var onları hallettikten sonra ekranı temizleyip ( systeam(cls) hariç başka bir şey bul) yeniden üstteki döngüyle yazdıracağım
	AVLagaci *tempEbEk = agac;
	AVLagaci *tempEbEkOnceki = nullptr;		// bunu en son atama yapıp önceki değeri elimde tutmuş oluyprum
	AVLagaci *tempEbEkDen1Onceki = nullptr; // bu tutar üstteki hep 1 geriden döner
	AVLagaci *tempEbEkgidici = nullptr;		// bunu oluşturma sebebim durmadan döngü kullanıp zaman kaybetmek istememe
	AVLagaci *tempEbEkgidici2 = nullptr;	// son eleman siliniyorsa diye oluşturdum buna ihtiyacım oluyor sildirme kısmınd üzerine tıkla nerede kullandığını görünce anlarsın
	int enKucukDeger;
	int enKucukSiraSayac = 0; // 0dan başlatıyorum çünkü arttırma işlemini girşte yapıyorum
	int enKucukSira;
	int kacinciyadonuyor = 0;
	while (tempEbEk->agacSonraki != NULL) // sonuncuyu da gezebilmek için eşitlik karşılaştırması bu olmalı
	{
		enKucukSiraSayac++;
		int deger = tempEbEk->TepeGetir(enKucukSiraSayac);
		if (ilkGirdi)
		{ // bu sayede ilk olanı en küçük atamış oldum ve bu benim ilk
			enKucukDeger = deger;
			ilkGirdi = false;
			tempEbEkgidici = tempEbEk;
			enKucukSira = enKucukSiraSayac;
		}
		else
		{ // şimdi karşılaştırma yapacağız
			if (deger < enKucukDeger)
			{
				enKucukDeger = deger;
				tempEbEkgidici = tempEbEk;
				enKucukSira = enKucukSiraSayac;
				tempEbEkDen1Onceki = tempEbEkOnceki; // bu sabit olarak tuttuğumdan döngüyü tekrardan döndürmek zorunda kalmayacağım
			}
		}
		tempEbEkOnceki = tempEbEk; // bunun sayesinde önceki değerimi de tutmuş oluyorum
		if (tempEbEk->agacSonraki)
		{
			tempEbEkgidici2 = tempEbEk;
			tempEbEk = tempEbEk->agacSonraki;
		}
	}
	enKucukSiraSayac++;
	int deger = tempEbEk->TepeGetir(enKucukSiraSayac); // son değer için
	if (deger < enKucukDeger)
	{ // buna giriyorsa sonuncu demektir o yüzden tempEbEkDen1Onceki = tempEbEkOnceki; gerek yok
		enKucukDeger = deger;
		tempEbEkgidici = tempEbEk;
		enKucukSira = enKucukSiraSayac;
	}

	int silcezMi = tempEbEk->yiginAzalt(enKucukSira);

	// alttaki ksıım tepe değerini 1 azalttıktan sonra
	if (silcezMi == -1)
	{ // bunun anlamı gelmiş olduğum yigit bitti
		// ilk ağaç mı silindi kontrolü yapmam lazım
		silmeYapildiMi = true;
		if (tempEbEkgidici == agac)
		{
			// ilkini silmek demek agacı agac sonrakine ver demek
			agac = agac->agacSonraki;
		}
		// eğer ağaç silindiyse
		else if (tempEbEkgidici->agacSonraki == NULL)
		{
			tempEbEkgidici2->agacSonraki = NULL;
		}
		else
		{
			tempEbEkDen1Onceki->agacSonraki = tempEbEkgidici->agacSonraki; // bunun sayesinde aradaki ağacı çıkarmış oluyorum
		}
		agac->TepeSifirlama(); // bunun sayesinde tepe değerlerini sıfırlamış oluyorum zaten silme gerçekleşti sıkıntı yok
		system("cls");
		agac->HarfleriYazdir();
	}
}

void buyukAzaltma()
{
	bool ilkGirdi = true;
	// buradan itibaren en büyük en küçük çıkarma işlemleri var onları hallettikten sonra ekranı temizleyip ( systeam(cls) hariç başka bir şey bul) yeniden üstteki döngüyle yazdıracağım
	AVLagaci *tempEbEk = agac;
	AVLagaci *tempEbEkOnceki = nullptr;		// bunu en son atama yapıp önceki değeri elimde tutmuş oluyprum
	AVLagaci *tempEbEkDen1Onceki = nullptr; // bu tutar üstteki hep 1 geriden döner
	AVLagaci *tempEbEkgidici = nullptr;		// bunu oluşturma sebebim durmadan döngü kullanıp zaman kaybetmek istememe
	AVLagaci *tempEbEkgidici2 = nullptr;	// son eleman siliniyorsa diye oluşturdum buna ihtiyacım oluyor sildirme kısmınd üzerine tıkla nerede kullandığını görünce anlarsın
	int enBuyukDeger;
	int enBuyukSiraSayac = 0; // 0dan başlatıyorum çünkü arttırma işlemini girşte yapıyorum
	int enBuyukSira;
	int kacinciyadonuyor = 0;
	while (tempEbEk->agacSonraki != NULL) // sonuncuyu da gezebilmek için eşitlik karşılaştırması bu olmalı
	{
		enBuyukSiraSayac++;
		int deger = tempEbEk->TepeGetir(enBuyukSiraSayac);
		if (ilkGirdi)
		{ // bu sayede ilk olanı en küçük atamış oldum ve bu benim ilk
			enBuyukDeger = deger;
			ilkGirdi = false;
			tempEbEkgidici = tempEbEk;
			enBuyukSira = enBuyukSiraSayac;
		}
		else
		{ // şimdi karşılaştırma yapacağız
			if (deger > enBuyukDeger)
			{
				enBuyukDeger = deger;
				tempEbEkgidici = tempEbEk;
				enBuyukSira = enBuyukSiraSayac;
				tempEbEkDen1Onceki = tempEbEkOnceki; // bu sabit olarak tuttuğumdan döngüyü tekrardan döndürmek zorunda kalmayacağım
			}
		}
		tempEbEkOnceki = tempEbEk; // bunun sayesinde önceki değerimi de tutmuş oluyorum
		if (tempEbEk->agacSonraki)
		{
			tempEbEkgidici2 = tempEbEk;
			tempEbEk = tempEbEk->agacSonraki;
		}
	}

	enBuyukSiraSayac++;
	int deger = tempEbEk->TepeGetir(enBuyukSiraSayac); // son değer için
	if (deger > enBuyukDeger)
	{ // buna giriyorsa sonuncu demektir o yüzden tempEbEkDen1Onceki = tempEbEkOnceki; gerek yok
		enBuyukDeger = deger;
		tempEbEkgidici = tempEbEk;
		enBuyukSira = enBuyukSiraSayac;
	}

	int silcezMi = tempEbEk->yiginAzalt(enBuyukSira);

	// alttaki ksıım tepe değerini 1 azalttıktan sonra
	if (silcezMi == -1)
	{ // bunun anlamı gelmiş olduğum yigit bitti
		// ilk ağaç mı silindi kontrolü yapmam lazım
		if (tempEbEkgidici == agac)
		{
			// ilkini silmek demek agacı agac sonrakine ver demek
			agac = agac->agacSonraki;
		}
		// eğer ağaç silindiyse
		else if (tempEbEkgidici->agacSonraki == NULL)
		{
			tempEbEkgidici2->agacSonraki = NULL;
		}
		else
		{
			tempEbEkDen1Onceki->agacSonraki = tempEbEkgidici->agacSonraki; // bunun sayesinde aradaki ağacı çıkarmış oluyorum
		}
		agac->TepeSifirlama(); // bunun sayesinde tepe değerlerini sıfırlamış oluyorum zaten silme gerçekleşti sıkıntı yok
		system("cls");
		agac->HarfleriYazdir();
	}
}

// küçük sildi büyük çıkarma ve silme döngüsünün sonu kaldı
// ayrıca azaltma sonrası son eleman 2 kere yazıyor ona da bak
/*
if (tempEbEk->agacSonraki) {
			tempEbEk = tempEbEk->agacSonraki;
		}
burada sorun olabilir takip et
		*/