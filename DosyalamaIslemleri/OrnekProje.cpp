#include <iostream>
#include<fstream>
#include<string>
#include<stdlib.h>
#include <stdio.h>
#include <ctype.h>
#include <array>
#include <iomanip>//boşluklar için
//Alttaki 3lü remove ve rename için diğer türlü problem oluşuyor
#include <tuple>
#include <ctime>//time() fonksiyonu için
#include <stdio.h>
using namespace std;

ofstream Depo;
fstream YemekCesit;
fstream Malzeme;


const int SabitArtisMiktari = 12;

int YemektenKazandıgım = 0;
int ekstraUrunSayac = 0;//içeride tanımlayınca çakışma oluyor .
int ekstraYemekAdi = 21;
int maliyetGenel = 0;
int KacYemekVarSayac = 0;
int TumUrunlerSabitiSayaci = 37;
int KacMalzemeKullanıldıSayac = 0;

void Bilgilendirme();
string BuGunlukDukkaniKapa();

class Urun {
private:
	int Kalori[54];

	int UretimGunu[54];
	int UretimAyi[54];
	int UretimYili[54];

	int TuketimGunu[54];
	int TuketimAyi[54];
	int TuketimYili[54];
public:
	void TarihAtama();
	void KaloriAtama();
	int yemekSayisi = 21;
	string yemekler[21] = { "Kuymak","Menemen","Sucuklu Yumurta","Patatesli Yumurta","Kavurmalı Yumurta","Patates Kızartması","Kumpir","Makarna" ,"Pirinç Pilav","Nohut","Fasulye" ,"Ispanak","Köfte Burger","Tavuk Burger" ,"Mercimek Çorbası","Doamtes Çorbası" ,"Yoğurt Çorbası","Brokoli Çorbası","Mantar Çorbası","Fırında Karnıbahar","Kuzu Tandır" };
	int miktar[54];//dizi elemanı sayısı = 37 .
	void MiktarAtama();
	string TumUrunler[54] = { "Mısır Unu","Yağ","Su","Peynir","Domates","Yumurta","Biber","Soğan","Sucuk","Patates","Kavurma","Makarna","Pirinç","Köfte"
	,"Hamburger Eekmeği","Tavuk","Salça","Nohut","Fasulye","Sarımsak","Ispanak","Mercimek","Havuç","Sarmısak","Un","Yoğurt","Nane","Brokoli","Süt","Mantar"
	,"Karnıbahar","Kıyma","Bİber","Krema","Kaşar","Kuzu","Yağlı Kağıt" };

	struct UrundeNeVar {
		string Kuymak[4] = { "Mısır Unu","Su","Peynir","Yağ" };
		string Menemen[5] = { "Domates","Yumurta","Biber","Soğan","Yağ" };
		string SucukluYumurta[3] = { "Sucuk",  "Yağ","Yumurta" };
		string PatatesliYumurta[3] = { "Patates","Yağ","Yumurta" };
		string KavurmaliYumurta[3] = { "Kavurma","Yağ","Yumurta" };
		string PatatesKızartması[2] = { "Patates","Yağ" };
		string Kumpir[2] = { "Patates","Yağ" };
		string Makarna[3] = { "Makarna","Yağ" ,"Su" };
		string PirinçPilav[3] = { "Pirinç","Yağ" ,"Su" };
		string KöfteBurger[3] = { "Köfte","Yağ" ,"Hamburger Ekmeği" };
		string TavukBurger[3] = { "Köfte","Yağ" ,"Hamburger Ekmeği" };
		string Nohut[4] = { "Soğan","Salça" ,"Nohut","Yağ" };
		string Fasulye[6] = { "Soğan","Salça" ,"Fasulye","Yağ","Domates","Sarımsak" };
		string Ispanak[5] = { "Ispanak","Salça" ,"Soğan","Yağ","Pirinç" };
		string MercimekCorbasi[6] = { "Mercimek","Patates" ,"Soğan","Yağ","Sarımsak","Havuç" };
		string DomateCorbasi[5] = { "Domates","Salça" ,"Un","Yağ","Su" };
		string YogurCorbasi[6] = { "Yoğurt","Pirinç" ,"Un","Yağ","Yumurta","Nane" };
		string BrokoliCorbasi[4] = { "Brokili","Süt" ,"Un","Yağ" };
		string MantarCorbasi[4] = { "Mantar","Süt" ,"Un","Yağ" };
		string FırındaKarnıbahar[7] = { "Karnıbahar","Soğan" ,"Kıyma","Yağ","Biber","Krema","Kaşar" };
		string KuzuTandır[4] = { "Kuzu","Sarımsak" ,"Yağlı Kağıt","Yağ" };


	};
	//Tekrardan başlayınca oluşturma .
	void DepoUrunYazma();
	void TumUrunleriYazdirma();
	void DepoUrunEkle();
	void YemekIslemYapacakMiyiz();

	string DepoEkstraMalzeme[154];

	//Tüm yemek çeşitlerimi hangi üründe ne vara atadım .
	string HangiUrundeNeVar[54][54];
	string YemekTutaci[54][54];
	void UrunAtama();
	int UrunFiyati[54];
	int HangiYemektenKacTaneSatildi[54];

	//void KucukHarfeCevirme();	/*Beceremedim evde dene araştır öğren yap.*/
	//Gün içerisinde istenen yemekler için .
	string MenuSunum();
	int Sparis();
	int UrunSilinecekMi(int KacinciIndexSifirOldu);
	void Rapor(int GenelMaliyet);
	void SatilanYemekMiktariAtama();

	void DosyalaraAtama();

};
int main()
{
	// Sonuç ekranında Türkçe karakterleri kullanabilmek için
	setlocale(LC_ALL, "Turkish");
	Bilgilendirme();

	int YemekCesidiIcinSayac;
	int UrunFiyatiAtamaIcinSayac = 0;
	int istek;
	bool YemekGirmeyeTamamDevam;
	bool YemekIstemeyeDevam;
	string SparisAlmayaDevamMı;
	string YemekGimrHarfKontrol;
	string NeDurumdayiz;// yemek bitti mi diye kontrol.

	//yeni oluşum.


	Urun urun;
	urun.UrunAtama();//var olan her şey atanmış oldu .
	urun.DepoUrunEkle();
	urun.DepoUrunYazma();

	//Yemek çeşitleri dosyasına hepsini yazdırma kısmına geldik .

	urun.YemekIslemYapacakMiyiz();

	urun.DosyalaraAtama();
	
	//Artık spariş kısmındayız :
	urun.MiktarAtama();
	urun.SatilanYemekMiktariAtama();
	do {
		system("cls");
		NeDurumdayiz = urun.MenuSunum();
		if (NeDurumdayiz == "Yemek bitti") {
			//alttaki ikili rapordan önce .
			urun.TarihAtama();
			urun.KaloriAtama();
			urun.Rapor(maliyetGenel);
			YemekIstemeyeDevam = false;
		}
		else {
			maliyetGenel += urun.Sparis();
			SparisAlmayaDevamMı = BuGunlukDukkaniKapa();
			if (SparisAlmayaDevamMı == "d" || SparisAlmayaDevamMı == "D") {
				YemekIstemeyeDevam = true;
			}
			else {
				//alttaki ikili rapordan önce .
				urun.TarihAtama();
				urun.KaloriAtama();
				urun.Rapor(maliyetGenel);
				YemekIstemeyeDevam = false;
			}
		}


	} while (YemekIstemeyeDevam);


}

void Bilgilendirme() {
	cout << "************* Ön Bilgilendirme *************" << endl;
	cout << "Her malzemeden toplamda 12şer tane vardır." << endl;
	cout << "İlk önce depoda ve yemek ceşitlerinde yapmak istediğiniz değişiklikleri yaparsınız ." << endl;
	cout << "Ardından spariş almaya başlarsınız ve her yemek ürettiğinizde o yemeğin malzemeleri azalır ." << endl;
	cout << "Yemek malzemesi bittiği zaman size o malzemeden almak istiyor musunuz diye sorulu ." << endl;
	cout << "Eğer cevabınız evetse 12 tane o malzemeden eklenir ve maliyet 12TL olarak eklenir" << endl;
	cout << "Satılmış olan yeke için her kullanılmış olan malzeme maliyet olarak gösterilir ve müşteriye o fiyat sunulur ." << endl;
	cout << "Yemeklerin kalori miktarları fiyatlarla aynı şekilde hesaplanır ama müşteriye sunulmaz raporda gösterilir ." << endl;
	cout << "************* Bligilendirme Kısmı Bitmiştir *************" << endl;
}

void Urun::UrunAtama() {
	UrundeNeVar Unv;
	for (int i = 0; i < 21; i++) {
		for (int a = 1; a < 8; a++) {
			YemekTutaci[i][i] = yemekler[i];
			if (i == 0) {
				HangiUrundeNeVar[i][a] = Unv.Kuymak[a - 1];
				if (a == 4) { break; }
			}
			if (i == 1) {
				HangiUrundeNeVar[i][a] = Unv.Menemen[a - 1];
				if (a == 5) { break; }
			}
			if (i == 2) {
				HangiUrundeNeVar[i][a] = Unv.SucukluYumurta[a - 1];
				if (a == 3) { break; }
			}
			if (i == 3) {
				HangiUrundeNeVar[i][a] = Unv.PatatesliYumurta[a - 1];
				if (a == 3) { break; }
			}
			if (i == 4) {
				HangiUrundeNeVar[i][a] = Unv.KavurmaliYumurta[a - 1];
				if (a == 3) { break; }
			}
			if (i == 5) {
				HangiUrundeNeVar[i][a] = Unv.PatatesKızartması[a - 1];
				if (a == 2) { break; }
			}
			if (i == 6) {
				HangiUrundeNeVar[i][a] = Unv.Kumpir[a - 1];
				if (a == 2) { break; }
			}
			if (i == 7) {
				HangiUrundeNeVar[i][a] = Unv.Makarna[a - 1];
				if (a == 3) { break; }
			}
			if (i == 8) {
				HangiUrundeNeVar[i][a] = Unv.PirinçPilav[a - 1];
				if (a == 3) { break; }
			}
			if (i == 9) {
				HangiUrundeNeVar[i][a] = Unv.KöfteBurger[a - 1];
				if (a == 3) { break; }
			}
			if (i == 10) {
				HangiUrundeNeVar[i][a] = Unv.TavukBurger[a - 1];
				if (a == 3) { break; }
			}
			if (i == 11) {
				HangiUrundeNeVar[i][a] = Unv.Nohut[a - 1];
				if (a == 4) { break; }
			}
			if (i == 12) {
				HangiUrundeNeVar[i][a] = Unv.Fasulye[a - 1];
				if (a == 6) { break; }
			}
			if (i == 13) {
				HangiUrundeNeVar[i][a] = Unv.Ispanak[a - 1];
				if (a == 5) { break; }
			}
			if (i == 14) {
				HangiUrundeNeVar[i][a] = Unv.MercimekCorbasi[a - 1];
				if (a == 6) { break; }
			}
			if (i == 15) {
				HangiUrundeNeVar[i][a] = Unv.DomateCorbasi[a - 1];
				if (a == 5) { break; }
			}
			if (i == 16) {
				HangiUrundeNeVar[i][a] = Unv.YogurCorbasi[a - 1];
				if (a == 6) { break; }
			}
			if (i == 17) {
				HangiUrundeNeVar[i][a] = Unv.BrokoliCorbasi[a - 1];
				if (a == 4) { break; }
			}
			if (i == 18) {
				HangiUrundeNeVar[i][a] = Unv.MantarCorbasi[a - 1];
				if (a == 4) { break; }
			}
			if (i == 19) {
				HangiUrundeNeVar[i][a] = Unv.FırındaKarnıbahar[a - 1];
				if (a == 7) { break; }
			}
			if (i == 20) {
				HangiUrundeNeVar[i][a] = Unv.KuzuTandır[a - 1];
				if (a == 4) { break; }
			}
		}
	}

}
void Urun::DepoUrunYazma() {
	Depo.open("Depo.txt");
	if (Depo.is_open()) {
		Depo << "Var olan tüm malzemelerimiz :" << endl;
		for (int i = 0; i < 154; i++) {
			/*for (int a = 1; a < 54; a++) {
				if (HangiUrundeNeVar[i][a] == "") {
					continue;
				}
				else {
					Depo << HangiUrundeNeVar[i][a] << endl;
				}
			}*/
			if (TumUrunler[i] != "")
				Depo << TumUrunler[i] << endl;
		}
		for (int z = 0; z < 154; z++) {
			if (DepoEkstraMalzeme[z] != "") {
				Depo << DepoEkstraMalzeme[z] << endl;
			}
		}
	}
	Depo.close();
}
void Urun::TumUrunleriYazdirma() {
	for (int i = 0; i < 154; i++) {
		if (TumUrunler[i] != "")
			cout << i + 1 << ". " << TumUrunler[i] << endl;
	}
}

void Urun::DepoUrunEkle() {

	string Napcak;
	cout << "Depoya var olan malzemeler haricinde ürün eklemek istiyorsanız E" << endl;
	cout << "Depodan malzeme silmek istiyorsanız S" << endl;
	cout << "Var olan bir malzemenin yerine başka bir malzeme yazmak istiyorsanız B" << endl;
	cout << "Tuşuna basınız . " << endl;
	cout << "Depoda herhangi bir işlem yapmayacaksanız kalvyeden belirtilmiş olan tuşlar haricinde başka bir duşa basınız ." << endl;
	cout << "Karaınız :"; cin >> Napcak; cout << endl;
	if (Napcak == "e" || Napcak == "E") {
		//DepoEkstraMalzeme ekleme yaparak devam edeceksin .

		bool ekstraUrunKontrol;
		string ekstraUrunDevam;
		do
		{
			system("cls");
			TumUrunleriYazdirma();
			cout << "Malzemenin adını giriniz : "; cin >> DepoEkstraMalzeme[ekstraUrunSayac]; cout << endl;
			ekstraUrunSayac++;
			cout << "Malzeme girmeye devam edecekseniz D tuşuna basınız . "; cout << endl;
			cout << "Malzeme girmeye devam etmeyecekseniz başka herhangi bir tuşa basınız ."; cout << endl;
			cout << "Devam mı : "; cin >> ekstraUrunDevam;
			if (ekstraUrunDevam == "d" || ekstraUrunDevam == "D") {
				ekstraUrunKontrol = true;
			}
			else {
				ekstraUrunKontrol = false;
				DepoUrunEkle();
			}
		} while (ekstraUrunKontrol);
	}
	else if (Napcak == "s" || Napcak == "S") {
		int HangisiSilinecek;
		string SilmeyeDevaMi;
		bool SilmeKontrol;
		do
		{
			system("cls");
			TumUrunleriYazdirma();
			cout << "Kaçıncı ürünü sileceksinzi ? : "; cin >> HangisiSilinecek;
			for (int i = 0; i < 21; i++) {
				for (int a = 1; a < 8; a++) {
					if (HangiUrundeNeVar[i][a] == TumUrunler[HangisiSilinecek - 1]) {
						miktar[HangisiSilinecek - 1] = 0;
					}
				}
			}
			TumUrunler[HangisiSilinecek - 1] = TumUrunler[HangisiSilinecek];
			cout << endl;
			cout << "Malzeme silmeye devam edecekseniz D tuşuna basınız . "; cout << endl;
			cout << "Malzeme silmeye devam etmeyecekseniz başka herhangi bir tuşa basınız ."; cout << endl;
			cout << "Devam mı : "; cin >> SilmeyeDevaMi;
			if (SilmeyeDevaMi == "d" || SilmeyeDevaMi == "D")
				SilmeKontrol = true;
			else {
				SilmeKontrol = false;
				DepoUrunEkle();
			}
		} while (SilmeKontrol);
	}
	else if (Napcak == "b" || Napcak == "B") {
		bool DegisimKontrol;
		string DegisimeDevamMi;
		do
		{
			system("cls");
			TumUrunleriYazdirma();
			int DegisecekOlaninNumarasi;
			string YeniAd;
			cout << "Değiştirmek istediğiniz malzemenin numarasını giriniz :"; cin >> DegisecekOlaninNumarasi; cout << endl;
			cout << "Yeni malzeme adını giriniz : "; cin >> YeniAd;
			TumUrunler[DegisecekOlaninNumarasi - 1] = YeniAd; cout << endl;

			cout << "Malzeme değiştirmeye devam edecekseniz D tuşuna basınız . "; cout << endl;
			cout << "Malzeme değiştirmeye devam etmeyecekseniz başka herhangi bir tuşa basınız ."; cout << endl;
			cout << "Devam mı :"; cin >> DegisimeDevamMi;
			if (DegisimeDevamMi == "d" || DegisimeDevamMi == "D")
				DegisimKontrol = true;
			else {
				DegisimKontrol = false;
				DepoUrunEkle();
			}
		} while (DegisimKontrol);


	}

}

void Urun::YemekIslemYapacakMiyiz() {
	string Yapcam;
	string YemekAdi;
	string MalzemeAdiGir;
	int MalzemeAdi;
	int YemakKacMalzeme;
	int sıralamasayaci = 1;
	system("cls");
	for (int i = 0; i < 54; i++) {
		if (YemekTutaci[i][i] != "")
			cout << YemekTutaci[i][i] << endl;
	}
	cout << "Var olan yemeklerimiz haricinde yemek yapmak istiyor musunuz (E/?)" << endl;
	cout << "Var olan yemeği silmek istiyorsanız (S/?)" << endl;
	cout << "Var olan yemeği adını değiştirmek istiyorsanız (B/?)" << endl;
	cout << "Tuşuna basınız . " << endl;
	cout << "Herhangi bir işlem yapmayacaksanız kalvyeden belirtilmiş olan tuşlar haricinde başka bir duşa basınız ."; cin >> Yapcam; cout << endl;
	if (Yapcam == "e" || Yapcam == "E") {
		cout << "Lutfen yemeğin adını giriniz : "; cin >> YemekAdi; cout << endl;
		YemekTutaci[ekstraYemekAdi][ekstraYemekAdi] = YemekAdi;
		cout << "Yemek kaç malzemeyle yapılıyor ? : "; cin >> YemakKacMalzeme;
		for (int i = 1; i < YemakKacMalzeme + 1; i++) {
			for (int j = 0; j < 154; j++) {
				if (TumUrunler[j] != "")
					cout << sıralamasayaci << ". " << TumUrunler[j] << endl;
				sıralamasayaci++;
			}
			/*for (int z = 0; z < 154; z++) {
				if (DepoEkstraMalzeme[z] != "") {
					cout << sıralamasayaci << ". " << DepoEkstraMalzeme[z] << endl;
					sıralamasayaci++;
				}
			}*/
			cout << i << ". malzemenin numarasını giriniz , malzeme depoda yoksa 999'u tuşlayınız :"; cin >> MalzemeAdi;
			if (MalzemeAdi == 999) {
				cout << "Satın Alacak olduğunuz malzemenin adını giriniz :"; cin >> MalzemeAdiGir; cout << endl;
				HangiUrundeNeVar[ekstraYemekAdi][i] = MalzemeAdiGir;
				TumUrunler[TumUrunlerSabitiSayaci] = HangiUrundeNeVar[ekstraYemekAdi][i];
				maliyetGenel += SabitArtisMiktari;
				ekstraUrunSayac++;
				TumUrunlerSabitiSayaci++;
			}
			else {
				if (MalzemeAdi > 20) {
					HangiUrundeNeVar[ekstraYemekAdi][i] = DepoEkstraMalzeme[MalzemeAdi - 22];
					TumUrunler[TumUrunlerSabitiSayaci] = HangiUrundeNeVar[ekstraYemekAdi][i];
				}
				else {
					HangiUrundeNeVar[ekstraYemekAdi][i] = TumUrunler[MalzemeAdi - 1];
					TumUrunler[TumUrunlerSabitiSayaci] = HangiUrundeNeVar[ekstraYemekAdi][i];
				}
			}
		}
		ekstraYemekAdi++;
		YemekIslemYapacakMiyiz();
	}
	else if (Yapcam == "s" || Yapcam == "S") {
		int NeSiliyoz;
		for (int i = 0; i < 54; i++) {
			if (YemekTutaci[i][i] != "") {
				cout << i + 1 << ". " << YemekTutaci[i][i] << endl;;
			}
		}
		cout << "Silmek istediğiniz yemeğin mumarasını giriniz : "; cin >> NeSiliyoz; cout << endl;
		for (int a = 0; a < 54; a++) {
			if (NeSiliyoz < 54) {
				YemekTutaci[NeSiliyoz - 1][NeSiliyoz - 1] = YemekTutaci[NeSiliyoz][NeSiliyoz];
				HangiUrundeNeVar[NeSiliyoz - 1][a] = "";
				NeSiliyoz++;
			}
		}
		YemekIslemYapacakMiyiz();
	}
	else if (Yapcam == "b" || Yapcam == "B") {
		int NeyinAdiniDegistiricen;
		string YeniAd;
		for (int i = 0; i < 54; i++) {
			if (YemekTutaci[i][i] != "") {
				cout << i + 1 << ". " << YemekTutaci[i][i] << endl;;
			}
		}
		cout << "Adını değiştirmek istediğiniz yemeğin mumarasını giriniz : "; cin >> NeyinAdiniDegistiricen; cout << endl;
		cout << "Yeni adı giriniz : "; cin >> YeniAd; cout << endl;
		YemekTutaci[NeyinAdiniDegistiricen][NeyinAdiniDegistiricen] = YeniAd;
		YemekIslemYapacakMiyiz();
	}
}

string Urun::MenuSunum() {
	int YemekVarmiSayac = 0;
	cout << "Menü : " << endl;
	for (int i = 0; i < 54; i++) {
		if (YemekTutaci[i][i] != "") {
			YemekVarmiSayac = 1;
		}
	}
	if (YemekVarmiSayac == 0) {

		cout << "Ürün almadığınızdan dolayı yapılabilecek yemek bulunmamaktadır .";
		return "Yemek bitti";
	}
	else {
		for (int z = 0; z < 54; z++) {
			if (YemekTutaci[z][z] != "")
				cout << z + 1 << ". " << YemekTutaci[z][z] << "; Fiyat :" << UrunFiyati[z] << endl;
		}
		/*ilkinde yapmışım nedenini hatırlamadım gereksiz kalırsa silerim.
		if (GununMenusu[i + 1] == "") {
			return "Daha bitmedi . ";
		}*/
		return "Daha Bitmedi";
	}
}

void Urun::TarihAtama() {
	srand(time(NULL));
	for (int i = 0; i < 37; i++) {
		UretimYili[i] = 2022;//Ürünlerin tamamı bu yıl üretilmiş kabul ettik .
		UretimAyi[i] = rand() % (12 - 1 + 1) + 1;
		if (UretimAyi[i] == 2) {// 200 yılı üretim olduğundan Şubatın 29 gün olma ihtimali yok
			UretimGunu[i] = rand() % (28 - 1 + 1) + 1;
		}
		else if (UretimAyi[i] == 1 || UretimAyi[i] == 3 || UretimAyi[i] == 5 || UretimAyi[i] == 7 || UretimAyi[i] == 8 || UretimAyi[i] == 10 || UretimAyi[i] == 12) {
			UretimGunu[i] = rand() % (31 - 1 + 1) + 1;
		}
		else {
			UretimGunu[i] = rand() % (30 - 1 + 1) + 1;
		}
	}
	for (int a = 0; a < 37; a++) {
		TuketimYili[a] = 2000 + (rand() % (24 - 23 + 1) + 23);//Son kullanım tarihini 2023 ya da 2024 yılında kabul ettim .
		TuketimAyi[a] = rand() % (12 - 1 + 1) + 1;
		if (TuketimYili[a] % 4 == 0) {// Şubat'ın 29 gün olma ihtimali yok
			if (TuketimAyi[a] == 2) {
				TuketimGunu[a] = rand() % (29 - 1 + 1) + 1;
			}
			else if (TuketimAyi[a] == 1 || TuketimAyi[a] == 3 || TuketimAyi[a] == 5 || TuketimAyi[a] == 7 || TuketimAyi[a] == 8 || TuketimAyi[a] == 10 || TuketimAyi[a] == 12) {
				TuketimGunu[a] = rand() % (31 - 1 + 1) + 1;
			}
			else {
				TuketimGunu[a] = rand() % (30 - 1 + 1) + 1;
			}
		}
		else {
			if (TuketimAyi[a] == 2) {
				TuketimGunu[a] = rand() % (28 - 1 + 1) + 1;
			}
			else if (TuketimAyi[a] == 1 || TuketimAyi[a] == 3 || TuketimAyi[a] == 5 || TuketimAyi[a] == 7 || TuketimAyi[a] == 8 || TuketimAyi[a] == 10 || TuketimAyi[a] == 12) {
				TuketimGunu[a] = rand() % (31 - 1 + 1) + 1;
			}
			else {
				TuketimGunu[a] = rand() % (30 - 1 + 1) + 1;
			}
		}
	}
}
void Urun::KaloriAtama() {
	for (int i = 0; i < 54; i++) {
		Kalori[i] = UrunFiyati[i];
	}
}
void Urun::MiktarAtama() {//Her üründen 50 tane var dedik .
	for (int i = 0; i < 37; i++) {
		miktar[i] = 1;
	}
}
void Urun::SatilanYemekMiktariAtama() {
	for (int i = 0; i < 54; i++) {
		HangiYemektenKacTaneSatildi[i] = 0;
	}
}
void Urun::Rapor(int GenelMaliyet) {
	cout << "Rapor:" << endl;
	cout << left << setw(20) << "Malzeme Adı" << setw(18) << "Üretim tarihi" << setw(21) << "Son Kullanım Tarihi" << setw(18) << "Kalan Adet Miktarı" << endl;
	for (int i = 0; i < 54; i++) {

		if (TumUrunler[i] != "") {
			cout << left << setw(20) << TumUrunler[i] << setw(3) << UretimGunu[i] << setw(3) << UretimAyi[i] << setw(12) << UretimYili[i] << setw(3) << TuketimGunu[i] << setw(3) << TuketimAyi[i] << setw(15) << TuketimYili[i] << setw(18) << miktar[i] << setw(20) << HangiYemektenKacTaneSatildi[i] << endl;
		}

	}
	cout << setw(77) << "*****************************************************************************" << endl;
	cout << left << setw(20) << "Yemek Adı" << setw(20) << "Satılma Miktarı" << endl;
	for (int i = 0; i < 54; i++) {
		if (YemekTutaci[i][i] != "") {
			cout << left << setw(20) << YemekTutaci[i][i] << setw(20) << HangiYemektenKacTaneSatildi[i] << endl;
		}

	}
	cout << "Bu günkü karımız :" << (YemektenKazandıgım - GenelMaliyet) << endl;
}

int Urun::Sparis() {
	int geciciIcinSayac = 1;
	int YemekcesiSayac = 1;
	int istek;
	int maliyet = 0;
	cout << "Lütfen menüde istediğiniz yemeğin numarasını tuşlayınız : "; cin >> istek; cout << endl;
	if (istek > KacYemekVarSayac) {
		cout << "Var olamayan yemek numarası istediniz !";
		Urun::Sparis();
	}
	else {
		int KazanacSayaci = 1;
		for (int i = 0; i < KacYemekVarSayac; i++) {
			if (istek == i + 1) {
				HangiYemektenKacTaneSatildi[i]++;
				for (int a = 1; a < 54; a++) {
					if (HangiUrundeNeVar[i][a] == "")
						break;
					else {
						for (int z = 0; z < 37; z++) {
							if (HangiUrundeNeVar[i][a] == TumUrunler[z]) {
								if (miktar[z] > 0 && KazanacSayaci == 1) {
									YemektenKazandıgım += UrunFiyati[i];
									KazanacSayaci--;
								}
								miktar[z]--;
								if (miktar[z] <= 0) {
									maliyet = Urun::UrunSilinecekMi(z);
									if (maliyet == 0) {//O malzemenin var olduğu tüm yemekleri silmem lazım .
										HangiUrundeNeVar[i][a] = "";
										YemekTutaci[i][i] = "";
										TumUrunler[z] = "";
										DosyalaraAtama();
									}
								}
							}
						}

					}
				}
			}
		}
	}
	return maliyet;
}
int Urun::UrunSilinecekMi(int KacinciIndexSifirOldu) {
	string AlacakMı;
	system("cls");
	cout << "!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!" << endl;
	cout << TumUrunler[KacinciIndexSifirOldu] << " malzemesi bitmiştir .";
	cout << TumUrunler[KacinciIndexSifirOldu] << " temin etmek istiyor musunuz ?" << endl;
	cout << "Eğer temin ederseniz 12 TL karşılığında 12 tane alacaksınız ." << endl;
	cout << "Alacak iseiniz e ya da E tuşuna basınıc " << endl;
	cout << "Almak istemiyorsanız başka herhangi bir tuşa basınız . " << endl;
	cout << "Almak istiyor musunz ? " << endl; cin >> AlacakMı;
	if (AlacakMı == "e" || AlacakMı == "E") {
		miktar[KacinciIndexSifirOldu] = 12;
		return SabitArtisMiktari;
	}
	else {
		return 0;
	}

}

void Urun::DosyalaraAtama() {
	int YazarkenBirKereYaz = 0;
	YemekCesit.open("Yemek Çeşitleri.txt",ios::out);
	if (YemekCesit.is_open()) {
		for (int i = 0; i < 54; i++) {
			if (YemekTutaci[i][i] != "")
				YemekCesit << YemekTutaci[i][i] << endl;
		}
		YemekCesit.close();
	}
	Malzeme.open("Malzeme.txt", ios::out);
	if (Malzeme.is_open()) {
		for (int i = 0; i < 54; i++) {
			for (int a = 1; a < 54; a++) {
				if (YemekTutaci[i][i] != "") {
					if (YazarkenBirKereYaz == 0) {
						Malzeme << YemekTutaci[i][i] << " için kullanılan malzemeler : " << endl;
						YazarkenBirKereYaz++;
						KacYemekVarSayac++;
					}
					if (HangiUrundeNeVar[i][a] != "") {
						Malzeme << HangiUrundeNeVar[i][a] << endl;
						KacMalzemeKullanıldıSayac++;
					}
				}
			}
			UrunFiyati[i] = KacMalzemeKullanıldıSayac;
			YazarkenBirKereYaz = 0;
			KacMalzemeKullanıldıSayac = 0;
		}
		Malzeme.close();
	}
}

string BuGunlukDukkaniKapa() {
	cout << "Spariş almaya devam edecek misiniz ? " << endl << "Devam edecekseniz lütfen D ya da d tuşuna basınız" << endl << "Devam etmeyecekseniz gün sonu raporunu görmek için klavyeden başka herhanig bir tuşa basınız :";
	string cevap;
	cin >> cevap;
	return cevap;

}