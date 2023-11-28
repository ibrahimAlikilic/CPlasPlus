#include <iostream>
#include <locale.h>// Diller ve karakter setleri kütüphanesi
#include <cmath>//kök alma felan.
#include <iomanip>//for setw
#include <ctime>// time() fonksiyonu için
#include <stdio.h>
#include <string>
using namespace std;

float ChackPoint(float KontrolNotu, int kacıncı, bool chack2 = false);
float OgrenciYiliciNotu(float kisa1, float kisa2, float odev1, float odev2, float proje, float vize);
float BasariNotu(float yilici, float final);
void Sartlar();
bool tarihKontrol(int dogumgun, int dogumayi, int dogumyili);
string islem(int islemnumarasi, string isim, string soyisim, string numara, float kisa1, float kisa2, float odev1, float odev2, float proje, float vize, float final, float yiliciNotu, float Ogrencibasarinotu, int gun, int ay, int yil, string harfNotu);
string BasariNotuHarf(float basarinotuHarfIcin);
string GoOn();

struct Tarih {
	int Gun[100];
	int Ay[100];
	int Yil[100];
};
struct Ogrenci
{
	string Adi[100];
	string Soyadi[100];
	string No[100]; //I used string becaus we school number's furst character is starting with letter

	float KisaSinav1[100];
	float KisaSinav2[100];
	float Odev1[100];
	float Odev2[100];
	float Proje[100];
	float Vize[100];
	float Final[100];
	Tarih tarih;
};

float karsilastirma = 0;
float ToplamNotOrtIcin = 0;
int KacinciyaDonuyor = 0;
int SistemKacKereCalısti=100;
int BirKereYaz = 1;
bool islemNumarasiKontrol = false;
bool TarihKontrol = true;



int main()
{
	setlocale(LC_ALL, "Turkish");
	srand(time(NULL));// For every work time create diferent value

	string info;
	string BittiMi;
	string SistemTamamDevamSoruyoz;
	string GunduzGece[2] = { "G","B" };
	string OgrenciBasariNotuHarf[100];
	string GoOnStudentInfo;
	bool chack = true;
	bool sistemTamamDevam = true;
	bool OgrAlMa;
	float yilicinotu[100];
	float nothesapla;
	float OgrenciBasariNotu[100];
	float AritmatikOrtFarkı = 0;
	float StandartSapma;
	int RandomOgrenciAdi;
	int RandomOgrenciSoyadi;
	int OgrenciNumarasiRandom;
	int enFazla = 230000000, enAz = 190000000;
	int islemNumarasi;
	int SinifOrt;
	int KacıncıGirdiIkinciBasamak;
	int KacıncıGirdiUcuncuBasamak;

	Ogrenci ogrenci;
	Ogrenci ogrenciRandom;

	string isim[30]{
		"Erkan", "Eren", "Yasin", "Melih", "Emir", "Sercan", "Yusuf", "Adem", "İdris", "Muhammed",
		"Mustafa", "İbrahim", "Ömer", "Yunus", "Yusuf", "Vahide", "Sudenaz", "Sevde", "Mukerrem", "İrem",
		"Nurdan", "Zuleyha", "Emra", "Nisa", "Beyza", "Hayriye", "Ümmiye", "Asiye", "Şevval", "Aylin"
	};
	string soyisim[30]{
		"ALİKILIÇ",	"KILIÇ",	"DEMİR",	"AKAYDIN",	"BİR",	"KIZILTAŞ",	"ESEN",	"ÖZCAN",	"DURMAZ",	"KOLAYLI",
		"TOPRAK",	"ŞEN",	"KALKAN",	"KORKMAZ",	"KAPLAN",	"ASLAN",	"KURAL",	"ÖZTÜRK",	"LEVENT",	"KOÇ",
		"UĞUR",	"BASTIK",	"KAYA",	"SUNAL",	"ÖZEN",	"ÇEVİK",	"DEDE",	"KARTAL",	"ERDEM",	"IŞIK"
	};

	cout << "Do you want to see student's information or will you get in the student information  ? " << endl;
	cout << "if will you get in student information key in 'g' or 'G' from keyboard." << endl;
	cout << "if you want to see student's information key in 's' or 'S' from keyboard." << endl;
	cin >> info;
	while (chack) {//for control get in rong or true character.

		if (info == "s" || info == "S")//for get in volue out.
		{
			SistemKacKereCalısti = 0;
			do
			{
				for (int i = 0; i < 100; i++) {//for get in 100 student information
					cout << left << i + 1 << ". student's name : "; cin >> ogrenci.Adi[i]; cout << endl;
					cout << left << i + 1 << ". student's surname : "; cin >> ogrenci.Soyadi[i]; cout << endl;
					TarihKontrol = true;
					while (TarihKontrol)
					{
						cout << left << i + 1 << ". student's day of birth : "; cin >> ogrenci.tarih.Gun[i]; cout << endl;
						cout << left << i + 1 << ". student's month of birth : "; cin >> ogrenci.tarih.Ay[i]; cout << endl;
						cout << left << i + 1 << ". student's year of birth : "; cin >> ogrenci.tarih.Yil[i]; cout << endl;
						tarihKontrol(ogrenci.tarih.Gun[i], ogrenci.tarih.Ay[i], ogrenci.tarih.Yil[i]);
					}

					cout << left << i + 1 << ". student's number : "; cin >> ogrenci.No[i]; cout << endl;

					cout << left << i + 1 << ". student's 1. quiz grade : "; cin >> ogrenci.KisaSinav1[i]; cout << endl;
					ogrenci.KisaSinav1[i] = ChackPoint(ogrenci.KisaSinav1[i], i, false);


					cout << left << i + 1 << ". student's 2. quiz grade : "; cin >> ogrenci.KisaSinav2[i]; cout << endl;
					ogrenci.KisaSinav2[i] = ChackPoint(ogrenci.KisaSinav2[i], i, false);

					cout << left << i + 1 << ". student's 1. assignment grade : "; cin >> ogrenci.Odev1[i]; cout << endl;
					ogrenci.Odev1[i] = ChackPoint(ogrenci.Odev1[i], i, false);

					cout << left << i + 1 << ". student's 2. assignment grade : "; cin >> ogrenci.Odev2[i]; cout << endl;
					ogrenci.Odev2[i] = ChackPoint(ogrenci.Odev2[i], i, false);

					cout << left << i + 1 << ". student's project grade : "; cin >> ogrenci.Proje[i]; cout << endl;
					ogrenci.Proje[i] = ChackPoint(ogrenci.Proje[i], i, false);

					cout << left << i + 1 << ". student's Midterm exam grade : "; cin >> ogrenci.Vize[i]; cout << endl;
					ogrenci.Vize[i] = ChackPoint(ogrenci.Vize[i], i, false);

					cout << left << i + 1 << ". student's final exam grade : "; cin >> ogrenci.Final[i]; cout << endl;
					ogrenci.Final[i] = ChackPoint(ogrenci.Final[i], i, false);


					yilicinotu[i] = OgrenciYiliciNotu(ogrenci.KisaSinav1[i], ogrenci.KisaSinav2[i], ogrenci.Odev1[i], ogrenci.Odev2[i], ogrenci.Proje[i], ogrenci.Vize[i]);
					OgrenciBasariNotu[i] = BasariNotu(yilicinotu[i], ogrenci.Final[i]);
					OgrenciBasariNotuHarf[i] = BasariNotuHarf(OgrenciBasariNotu[i]);
					SistemKacKereCalısti++;
					cout << "Do you want to go on get in student ? ";
					cout << "If you want to go on press G or g " << endl;
					cout << "If you don't wnat to go on please key in any button from keyboard . ";
					cout << "Do you want to go on : "; cin >> GoOnStudentInfo;
					if (GoOnStudentInfo == "g"|| GoOnStudentInfo=="G") {
						OgrAlMa = true;
					}
					else
					{
						OgrAlMa = false;
						break;
					}
					cout << "*************" << endl;
				}

			} while (OgrAlMa);
			
			while (sistemTamamDevam) {
				Sartlar();
				cin >> islemNumarasi; cout << endl;

				for (int j = 0; j < SistemKacKereCalısti; j++) {//for all informations go to the function.
					KacinciyaDonuyor++;
					BittiMi = islem(islemNumarasi, ogrenci.Adi[j], ogrenci.Soyadi[j], ogrenci.No[j], ogrenci.KisaSinav1[j], ogrenci.KisaSinav2[j], ogrenci.Odev1[j], ogrenci.Odev2[j], ogrenci.Proje[j], ogrenci.Vize[j], ogrenci.Final[j], yilicinotu[j], OgrenciBasariNotu[j], ogrenci.tarih.Gun[j], ogrenci.tarih.Ay[j], ogrenci.tarih.Yil[j], OgrenciBasariNotuHarf[j]);
					if (BittiMi == "bitti")
					{
						break;
					}
					while (islemNumarasiKontrol) {
						cin >> islemNumarasi; cout << endl;
						BittiMi = islem(islemNumarasi, ogrenci.Adi[j], ogrenci.Soyadi[j], ogrenci.No[j], ogrenci.KisaSinav1[j], ogrenci.KisaSinav2[j], ogrenci.Odev1[j], ogrenci.Odev2[j], ogrenci.Proje[j], ogrenci.Vize[j], ogrenci.Final[j], yilicinotu[j], OgrenciBasariNotu[j], ogrenci.tarih.Gun[j], ogrenci.tarih.Ay[j], ogrenci.tarih.Yil[j], OgrenciBasariNotuHarf[j]);
						if (BittiMi == "bitti")
						{
							system("pause");
							return 0;
						}
					}
				}
				if (islemNumarasi == 2) {
					cout << "Highest average : " << karsilastirma << endl;
				}
				if (islemNumarasi == 3) {
					cout << "lowest average : " << karsilastirma << endl;
				}
				if (islemNumarasi == 4) {
					SinifOrt = ToplamNotOrtIcin / SistemKacKereCalısti;
					cout << "Average of the class : " << SinifOrt << endl;
					ToplamNotOrtIcin = 0;
					SinifOrt = 0;
				}
				if (islemNumarasi == 5) {
					SinifOrt = ToplamNotOrtIcin / SistemKacKereCalısti;
					for (int t = 0; t < SistemKacKereCalısti; t++) {
						AritmatikOrtFarkı = AritmatikOrtFarkı + ((OgrenciBasariNotu[t] - (float)SinifOrt) * (OgrenciBasariNotu[t] - SinifOrt));
					}
					StandartSapma = sqrt(AritmatikOrtFarkı / SistemKacKereCalısti);
					cout << "Standard deviation of students : " << StandartSapma << endl;
					ToplamNotOrtIcin = 0;
					SinifOrt = 0;
					StandartSapma = 0;
					AritmatikOrtFarkı = 0;
				}
				SistemTamamDevamSoruyoz = GoOn();
				if (SistemTamamDevamSoruyoz == "G" || SistemTamamDevamSoruyoz == "g") { if (BirKereYaz == 0) { BirKereYaz++; } system("cls"); }
				else { sistemTamamDevam = false; }
			}
			chack = false;
		}
		else if (info == "g" || info == "G")//for create random information .
		{

			for (int z = 0; z < 100; z++) {//for take all of the studens information.


				ogrenciRandom.Adi[z] = isim[rand() % (29 - 0 + 1) + 0];
				ogrenciRandom.Soyadi[z] = soyisim[rand() % (29 - 0 + 1) + 0];

				ogrenciRandom.tarih.Yil[z] = rand() % (2006 - 1970 + 1) + 1970;
				ogrenciRandom.tarih.Ay[z] = rand() % (12 - 1 + 1) + 1;

				if (ogrenciRandom.tarih.Yil[z] % 4 == 0) {
					if (ogrenciRandom.tarih.Ay[z] == 2) {
						ogrenciRandom.tarih.Gun[z] = rand() % (29 - 1 + 1) + 1;
					}
					else if (ogrenciRandom.tarih.Ay[z] == 1 || ogrenciRandom.tarih.Ay[z] == 3 || ogrenciRandom.tarih.Ay[z] == 5 || ogrenciRandom.tarih.Ay[z] == 7 || ogrenciRandom.tarih.Ay[z] == 8 || ogrenciRandom.tarih.Ay[z] == 10 || ogrenciRandom.tarih.Ay[z] == 12) {
						ogrenciRandom.tarih.Gun[z] = rand() % (31 - 1 + 1) + 1;
					}
					else {
						ogrenciRandom.tarih.Gun[z] = rand() % (30 - 1 + 1) + 1;
					}
				}
				else {
					if (ogrenciRandom.tarih.Ay[z] == 2) {
						ogrenciRandom.tarih.Gun[z] = rand() % (28 - 1 + 1) + 1;
					}
					else if (ogrenciRandom.tarih.Ay[z] == 1 || ogrenciRandom.tarih.Ay[z] == 3 || ogrenciRandom.tarih.Ay[z] == 5 || ogrenciRandom.tarih.Ay[z] == 7 || ogrenciRandom.tarih.Ay[z] == 8 || ogrenciRandom.tarih.Ay[z] == 10 || ogrenciRandom.tarih.Ay[z] == 12) {
						ogrenciRandom.tarih.Gun[z] = rand() % (31 - 1 + 1) + 1;
					}
					else {
						ogrenciRandom.tarih.Gun[z] = rand() % (30 - 1 + 1) + 1;
					}
				}

				OgrenciNumarasiRandom = rand() % (23 - 19 + 1) + 19;
				KacıncıGirdiIkinciBasamak = rand() % ((9 - 0 + 1) + 0);
				KacıncıGirdiUcuncuBasamak = rand() % ((9 - 0 + 1) + 0);
				string NumaraStringDondur = to_string(OgrenciNumarasiRandom);
				string kacıncıGirdiIkinciBasamak = to_string(KacıncıGirdiIkinciBasamak);
				string kacıncıGirdiUcuncuBasamak = to_string(KacıncıGirdiUcuncuBasamak);
				if (z == 0) {
					ogrenciRandom.No[z] = GunduzGece[rand() % 2] + NumaraStringDondur + "1210100";
				}
				else {

					ogrenciRandom.No[z] = GunduzGece[rand() % 2] + NumaraStringDondur + "12100" + kacıncıGirdiIkinciBasamak + kacıncıGirdiUcuncuBasamak;
				}

				if (z < 10) {

					ogrenciRandom.KisaSinav1[z] = rand() % 41;
					ogrenciRandom.KisaSinav2[z] = rand() % 41;
					ogrenciRandom.Odev1[z] = rand() % 41;
					ogrenciRandom.Odev2[z] = rand() % 41;
					ogrenciRandom.Proje[z] = rand() % 41;
					ogrenciRandom.Vize[z] = rand() % 41;
					ogrenciRandom.Final[z] = rand() % 41;
				}
				else if (z < 60) {

					ogrenciRandom.KisaSinav1[z] = rand() % (70 - 40 + 1) + 40;
					ogrenciRandom.KisaSinav2[z] = rand() % (70 - 40 + 1) + 40;
					ogrenciRandom.Odev1[z] = rand() % (70 - 40 + 1) + 40;
					ogrenciRandom.Odev2[z] = rand() % (70 - 40 + 1) + 40;
					ogrenciRandom.Proje[z] = rand() % (70 - 40 + 1) + 40;
					ogrenciRandom.Vize[z] = rand() % (70 - 40 + 1) + 40;
					ogrenciRandom.Final[z] = rand() % (70 - 40 + 1) + 40;
				}
				else if (z < 75) {

					ogrenciRandom.KisaSinav1[z] = rand() % (80 - 70 + 1) + 70;
					ogrenciRandom.KisaSinav2[z] = rand() % (80 - 70 + 1) + 70;
					ogrenciRandom.Odev1[z] = rand() % (80 - 70 + 1) + 70;
					ogrenciRandom.Odev2[z] = rand() % (80 - 70 + 1) + 70;
					ogrenciRandom.Proje[z] = rand() % (80 - 70 + 1) + 70;
					ogrenciRandom.Vize[z] = rand() % (80 - 70 + 1) + 70;
					ogrenciRandom.Final[z] = rand() % (80 - 70 + 1) + 70;
				}
				else {
					ogrenciRandom.KisaSinav1[z] = rand() % (100 - 80 + 1) + 80;
					ogrenciRandom.KisaSinav2[z] = rand() % (100 - 80 + 1) + 80;
					ogrenciRandom.Odev1[z] = rand() % (100 - 80 + 1) + 80;
					ogrenciRandom.Odev2[z] = rand() % (100 - 80 + 1) + 80;
					ogrenciRandom.Proje[z] = rand() % (100 - 80 + 1) + 80;
					ogrenciRandom.Vize[z] = rand() % (100 - 80 + 1) + 80;
					ogrenciRandom.Final[z] = rand() % (100 - 80 + 1) + 80;
				}








				yilicinotu[z] = OgrenciYiliciNotu(ogrenciRandom.KisaSinav1[z], ogrenciRandom.KisaSinav2[z], ogrenciRandom.Odev1[z], ogrenciRandom.Odev2[z], ogrenciRandom.Proje[z], ogrenciRandom.Vize[z]);
				OgrenciBasariNotu[z] = BasariNotu(yilicinotu[z], ogrenciRandom.Final[z]);
				OgrenciBasariNotuHarf[z] = BasariNotuHarf(OgrenciBasariNotu[z]);


			}

			while (sistemTamamDevam)
			{
				Sartlar();
				cin >> islemNumarasi; cout << endl;

				for (int j = 0; j < 100; j++) {
					KacinciyaDonuyor++;
					BittiMi = islem(islemNumarasi, ogrenciRandom.Adi[j], ogrenciRandom.Soyadi[j], ogrenciRandom.No[j], ogrenciRandom.KisaSinav1[j], ogrenciRandom.KisaSinav2[j], ogrenciRandom.Odev1[j], ogrenciRandom.Odev2[j], ogrenciRandom.Proje[j], ogrenciRandom.Vize[j], ogrenciRandom.Final[j], yilicinotu[j], OgrenciBasariNotu[j], ogrenciRandom.tarih.Gun[j], ogrenciRandom.tarih.Ay[j], ogrenciRandom.tarih.Yil[j], OgrenciBasariNotuHarf[j]);
					if (BittiMi == "bitti")
					{
						break;
					}
					while (islemNumarasiKontrol) {
						cin >> islemNumarasi; cout << endl;
						BittiMi = islem(islemNumarasi, ogrenciRandom.Adi[j], ogrenciRandom.Soyadi[j], ogrenciRandom.No[j], ogrenciRandom.KisaSinav1[j], ogrenciRandom.KisaSinav2[j], ogrenciRandom.Odev1[j], ogrenciRandom.Odev2[j], ogrenciRandom.Proje[j], ogrenciRandom.Vize[j], ogrenciRandom.Final[j], yilicinotu[j], OgrenciBasariNotu[j], ogrenciRandom.tarih.Gun[j], ogrenciRandom.tarih.Ay[j], ogrenciRandom.tarih.Yil[j], OgrenciBasariNotuHarf[j]);
						if (BittiMi == "bitti")
						{
							system("pause");
							return 0;
						}
					}
				}
				if (islemNumarasi == 2) {
					cout << "Highest average : " << karsilastirma << endl;
				}
				if (islemNumarasi == 3) {
					cout << "Lowest average: " << karsilastirma << endl;
				}
				if (islemNumarasi == 4) {
					SinifOrt = ToplamNotOrtIcin / 100;
					cout << "Average of the class : " << SinifOrt << endl;
					ToplamNotOrtIcin = 0;
					SinifOrt = 0;
				}
				if (islemNumarasi == 5) {
					SinifOrt = ToplamNotOrtIcin / 100;
					for (int t = 0; t < 100; t++) {
						AritmatikOrtFarkı = AritmatikOrtFarkı + ((OgrenciBasariNotu[t] - (float)SinifOrt) * (OgrenciBasariNotu[t] - SinifOrt));
					}
					StandartSapma = sqrt(AritmatikOrtFarkı / 100);
					cout << "Standard deviation of students : " << StandartSapma << endl;
					ToplamNotOrtIcin = 0;
					SinifOrt = 0;
					StandartSapma = 0;
					AritmatikOrtFarkı = 0;
				}
				SistemTamamDevamSoruyoz = GoOn();
				if (SistemTamamDevamSoruyoz == "G" || SistemTamamDevamSoruyoz == "g") { if (BirKereYaz == 0) { BirKereYaz++; } system("cls"); }
				else { sistemTamamDevam = false; }
			}

			chack = false;
		}
		else
		{
			cout << "You get in wrong character!" << endl;
			cout << "Please answer the question again and key in one from keyboard  g or G or s or s key" << endl;
			cout << "if will you get in student information key in 'g' or 'G' from keyboard." << endl;
			cout << "if you want to see student's information key in 's' or 'S' from keyboard." << endl;
			cin >> info;
		}
	}
	system("pause");
	return 0;

}
float ChackPoint(float KontrolNotu, int kacıncı, bool chack2)//In here we are controling point
{
	if (KontrolNotu > 100 || KontrolNotu < 0)
		chack2 = true;
	while (chack2) {
		if (KontrolNotu > 100 || KontrolNotu < 0)
		{

			cout << "You get in rong grade please get in grade again and it should be maximum 100 , minimum 0" << endl;
			cout << left << kacıncı + 1 << ". student's grade : "; cin >> KontrolNotu; cout << endl;
		}
		else
			chack2 = false;
	}
	return KontrolNotu;

}
float OgrenciYiliciNotu(float kisa1, float kisa2, float odev1, float odev2, float proje, float vize)
{
	float nothesapla;
	nothesapla = (((vize * 50) / 100) + ((kisa1 * 7) / 100) + ((kisa2 * 7) / 100) + ((odev1 * 10) / 100) + ((odev2 * 10) / 100) + ((proje * 16) / 100));
	return nothesapla;
}
float BasariNotu(float yilici, float final)
{
	float Basarinotu;
	Basarinotu = ((yilici * 55) / 100) + ((final * 45) / 100);
	return Basarinotu;
}
void Sartlar()
{
	cout << " Menu " << endl;
	cout << " 1 : 20 Student" << endl;
	cout << " 2 : Top Grade Student" << endl;
	cout << " 3 : Lowest Grade Student" << endl;
	cout << " 4 : Class Average" << endl;
	cout << " 5 : Class Standard Deviation" << endl;
	cout << " 6 : Students With a Passing Grade Between 0 and 50" << endl;
	cout << " 7 : Students With a Passing Grade Between 50 and 75" << endl;
	cout << " 8 : Students With a Passing Grade Between 75 and 100" << endl;
	cout << "Please key in the number of the transaction you want to see : ";
}
string islem(int islemnumarasi, string isim, string soyisim, string numara, float kisa1, float kisa2, float odev1, float odev2, float proje, float vize, float final, float yiliciNotu, float Ogrencibasarinotu, int gun, int ay, int yil, string harfNotu) {
	string DevamTamam;


	if (islemnumarasi == 1)
	{
		if (BirKereYaz == 1)
		{
			cout << left << setw(17) << "Name" << setw(17) << "Surname"<< setw(7) << "Birth" << setw(8) << "Birth" << setw(7) << "Birth"<< setw(11) << "Number" << setw(9) << "1. Guiz" << setw(9) << "2. Quiz" << setw(15) << "1. Assignment" << setw(15) << "2. Assignment" << setw(9) << "Project" << setw(14) << "Midterm Exam" << setw(12) << "Final Exam" << setw(7) << "Year"  << setw(9) << "Passing" << setw(9) << "Passing"  << endl;
			cout << left << setw(17) << ""	   << setw(17) << ""	   << setw(7) << "Day"   << setw(8) << "Month" << setw(7) << "Year" << setw(11) << ""		<< setw(9) << "Grade"   << setw(9) << "Grade"	<< setw(15) << "Grade"		   << setw(15) << "Grade"		  << setw(9) << "Grade"	  << setw(14) << "Grade"		<< setw(12) << "Grade"		<< setw(7) << "Grade" << setw(9) << "Grade"	  << setw(9) << "With"	   << endl;

			BirKereYaz--;
		}
		cout << left << setw(17) << isim << setw(17) << soyisim << setw(7) << gun << setw(8) << ay << setw(7) << yil << setw(11) << numara << setw(9) << kisa1 << setw(9) << kisa2 << setw(15) << odev1 << setw(15) << odev2 << setw(9) << proje << setw(14) << vize << setw(12) << final << setw(7) << yiliciNotu << setw(9) << Ogrencibasarinotu << setw(9) << harfNotu  << endl;
		if (KacinciyaDonuyor == 100)
		{
			cout << "You saw the all student , thank you :)" << endl;

		}
		else if (KacinciyaDonuyor % 20 == 0) {
			cout << "Will you go on ?" << endl << "If will you go on please key in G or g from keyboard" << endl << "If won't you go on please key in any button from keyboard ." << endl << "Key in :"; cin >> DevamTamam;

			if (DevamTamam == "G" || DevamTamam == "g") {
				BirKereYaz++;
				system("cls");
			}
			else
			{
				return "bitti";
			}
		}
		islemNumarasiKontrol = false;

	}
	else if (islemnumarasi == 2)
	{
		if (Ogrencibasarinotu > karsilastirma)
			karsilastirma = Ogrencibasarinotu;
		islemNumarasiKontrol = false;

	}
	else if (islemnumarasi == 3) {
		if (Ogrencibasarinotu < karsilastirma)
			karsilastirma = Ogrencibasarinotu;
		islemNumarasiKontrol = false;

	}
	else if (islemnumarasi == 4)
	{
		ToplamNotOrtIcin = ToplamNotOrtIcin + Ogrencibasarinotu;
		islemNumarasiKontrol = false;

	}
	else if (islemnumarasi == 5)
	{
		ToplamNotOrtIcin = ToplamNotOrtIcin + Ogrencibasarinotu;
		islemNumarasiKontrol = false;

	}
	else if (islemnumarasi == 6) {
		if (Ogrencibasarinotu <= 50) {
			if (BirKereYaz == 1)
			{
				cout << left << setw(17) << "Name" << setw(17) << "Surname" << setw(7) << "Birth" << setw(8) << "Birth" << setw(7) << "Birth" << setw(11) << "Number" << setw(9) << "1. Guiz" << setw(9) << "2. Quiz" << setw(15) << "1. Assignment" << setw(15) << "2. Assignment" << setw(9) << "Project" << setw(14) << "Midterm Exam" << setw(12) << "Final Exam" << setw(7) << "Year" << setw(9) << "Passing" << setw(9) << "Passing" << endl;
				cout << left << setw(17) << "" << setw(17) << "" << setw(7) << "Day" << setw(8) << "Month" << setw(7) << "Year" << setw(11) << "" << setw(9) << "Grade" << setw(9) << "Grade" << setw(15) << "Grade" << setw(15) << "Grade" << setw(9) << "Grade" << setw(14) << "Grade" << setw(12) << "Grade" << setw(7) << "Grade" << setw(9) << "Grade" << setw(9) << "With" << endl;

				BirKereYaz--;
			}

			cout << left << setw(17) << isim << setw(17) << soyisim << setw(7) << gun << setw(8) << ay << setw(7) << yil << setw(11) << numara << setw(9) << kisa1 << setw(9) << kisa2 << setw(15) << odev1 << setw(15) << odev2 << setw(9) << proje << setw(14) << vize << setw(12) << final << setw(7) << yiliciNotu << setw(9) << Ogrencibasarinotu << setw(9) << harfNotu << endl;
		}

		islemNumarasiKontrol = false;

	}
	else if (islemnumarasi == 7) {
		if (Ogrencibasarinotu > 50 && Ogrencibasarinotu <= 75) {
			if (BirKereYaz == 1)
			{
				cout << left << setw(17) << "Name" << setw(17) << "Surname" << setw(7) << "Birth" << setw(8) << "Birth" << setw(7) << "Birth" << setw(11) << "Number" << setw(9) << "1. Guiz" << setw(9) << "2. Quiz" << setw(15) << "1. Assignment" << setw(15) << "2. Assignment" << setw(9) << "Project" << setw(14) << "Midterm Exam" << setw(12) << "Final Exam" << setw(7) << "Year" << setw(9) << "Passing" << setw(9) << "Passing" << endl;
				cout << left << setw(17) << "" << setw(17) << "" << setw(7) << "Day" << setw(8) << "Month" << setw(7) << "Year" << setw(11) << "" << setw(9) << "Grade" << setw(9) << "Grade" << setw(15) << "Grade" << setw(15) << "Grade" << setw(9) << "Grade" << setw(14) << "Grade" << setw(12) << "Grade" << setw(7) << "Grade" << setw(9) << "Grade" << setw(9) << "With" << endl;

				BirKereYaz--;
			}

			cout << left << setw(17) << isim << setw(17) << soyisim << setw(7) << gun << setw(8) << ay << setw(7) << yil << setw(11) << numara << setw(9) << kisa1 << setw(9) << kisa2 << setw(15) << odev1 << setw(15) << odev2 << setw(9) << proje << setw(14) << vize << setw(12) << final << setw(7) << yiliciNotu << setw(9) << Ogrencibasarinotu << setw(9) << harfNotu << endl;
		}
		islemNumarasiKontrol = false;

	}
	else if (islemnumarasi == 8) {
		if (Ogrencibasarinotu > 75 && Ogrencibasarinotu <= 100) {
			if (BirKereYaz == 1)
			{
				cout << left << setw(17) << "Name" << setw(17) << "Surname" << setw(7) << "Birth" << setw(8) << "Birth" << setw(7) << "Birth" << setw(11) << "Number" << setw(9) << "1. Guiz" << setw(9) << "2. Quiz" << setw(15) << "1. Assignment" << setw(15) << "2. Assignment" << setw(9) << "Project" << setw(14) << "Midterm Exam" << setw(12) << "Final Exam" << setw(7) << "Year" << setw(9) << "Passing" << setw(9) << "Passing" << endl;
				cout << left << setw(17) << "" << setw(17) << "" << setw(7) << "Day" << setw(8) << "Month" << setw(7) << "Year" << setw(11) << "" << setw(9) << "Grade" << setw(9) << "Grade" << setw(15) << "Grade" << setw(15) << "Grade" << setw(9) << "Grade" << setw(14) << "Grade" << setw(12) << "Grade" << setw(7) << "Grade" << setw(9) << "Grade" << setw(9) << "With" << endl;

				BirKereYaz--;
			}

			cout << left << setw(17) << isim << setw(17) << soyisim << setw(7) << gun << setw(8) << ay << setw(7) << yil << setw(11) << numara << setw(9) << kisa1 << setw(9) << kisa2 << setw(15) << odev1 << setw(15) << odev2 << setw(9) << proje << setw(14) << vize << setw(12) << final << setw(7) << yiliciNotu << setw(9) << Ogrencibasarinotu << setw(9) << harfNotu << endl;
		}
		islemNumarasiKontrol = false;

	}
	else {
		cout << "You get in rong number please enter the number of the transaction you want to apply :";
		islemNumarasiKontrol = true;
	}

	return "Artık bitti";
}
bool tarihKontrol(int dogumgun, int dogumayi, int dogumyili) {
	if (dogumyili % 4 == 0 && dogumayi == 2 && dogumgun > 29) {
		cout << "You get in wrong date please get in again." << endl;
	}
	else if (dogumyili % 4 != 0 && dogumayi == 2 && dogumgun > 28) {
		cout << "You get in wrong date please get in again." << endl;
	}
	else if (dogumayi > 12 || dogumayi < 1 || dogumgun>31 || dogumgun < 1) {
		cout << "You get in wrong date please get in again." << endl;
	}
	else if (dogumayi == 1 || dogumayi == 3 || dogumayi == 5 || dogumayi == 7 || dogumayi == 8 || dogumayi == 10 || dogumayi == 12) {
		if (dogumgun > 31 || dogumgun < 1) {
			cout << "You get in wrong date please get in again." << endl;
		}
		else {
			return TarihKontrol = false;
		}
	}
	else if (dogumayi == 2 || dogumayi == 4 || dogumayi == 6 || dogumayi == 9 || dogumayi == 11) {
		if (dogumgun > 30 || dogumgun < 1) {
			cout << "You get in wrong date please get in again." << endl;
		}
		else {
			return TarihKontrol = false;
		}
	}
}
string BasariNotuHarf(float basarinotuHarfIcin) {
	if (basarinotuHarfIcin <= 100 && basarinotuHarfIcin >= 90) {
		return "AA";
	}
	else if (basarinotuHarfIcin <= 89 && basarinotuHarfIcin >= 80) {
		return "BA";
	}
	else if (basarinotuHarfIcin <= 79 && basarinotuHarfIcin >= 70) {
		return "BB";
	}
	else if (basarinotuHarfIcin <= 69 && basarinotuHarfIcin >= 65) {
		return "CB";
	}
	else if (basarinotuHarfIcin <= 64 && basarinotuHarfIcin >= 60) {
		return "CC";
	}
	else if (basarinotuHarfIcin <= 59 && basarinotuHarfIcin >= 50) {
		return "DD";
	}
	else if (basarinotuHarfIcin <= 49 && basarinotuHarfIcin >= 30) {
		return "FD";
	}
	else {
		return "FF";
	}
}
string GoOn() {
	string GoOnMu;
	cout << "do you wnat to see list again ? " << endl;
	cout << "If you want to see again press G or g " << endl;
	cout << "If you don't wnat to see please key in any button from keyboard . ";
	cout << "Do you want to see : ";
	cin >> GoOnMu;
	cout << endl;
	return GoOnMu;
}




