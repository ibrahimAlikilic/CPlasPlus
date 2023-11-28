/**
* @file main.cpp
* @description Tek yönlü bağlı liste ile işlemler
* @course 1. öğreim C grubu
* @assignment 1
* @date 06.11.2023
* @author ibrahim.alikilic@ogr.sakarya.edu.tr
*/
#include "Basamak.hpp"
#include "Sayi.hpp"
#include "Dugum.hpp"
#include "SayilarListesi.hpp"
#include <iostream>
#include <fstream>
#include <string>
#include <cmath>   // üs alma için
#include <cstdlib> // system fonksiyonu için gerekli başlık
using namespace std;
int BolecegimDeger(int basamakUzunlugu);
void acilis();
void Islemler();
void TekleriBasaAl();
void BasamaklariTersle();
void EnBuyuguSil();
// bunları fonksiyonlarda kullandığımdan heryerden erişilebilir yaptım
Sayi *sayiBasamak = new Sayi();
SayilarListesi *sayiListe = new SayilarListesi();
int kacinciyaTersleniyor = 0;
int silinenElemanSayim = 0;
int toplamElemanSayim = 0;
int main()
{
    acilis();

    return 0;
}
void acilis()
{
    system("cls");
    std::ifstream dosya("Sayilar.txt");
    if (!dosya)
    {
        std::cerr << "Dosya açılamadı!" << std::endl;
    }
    int sayi;

    while (dosya >> sayi)
    {
        toplamElemanSayim += 1;
        // Sıra:
        // ekle
        // sayı oluştur
        // yazdır
        // yeni sayının basamağının konumu
        string sayiS = to_string(sayi);          // sayıyı string çevirdim
        int ilkBasamakUzunlugu = sayiS.length(); // uzunluğunu buldum
        if (sayi == 0)
        {
            sayiBasamak->ekle(0);
            int ilkBasamakUzunlugu = 1;
            int sayim = sayiBasamak->SayiyiOlustur(1);
            sayiListe->Ekle(sayim);
        }
        else
        {
            // cout << "sayi " << sayi << endl;
            int basamakUzunlugu = sayiS.length(); // uzunluğunu buldum
            int deger = basamakUzunlugu - 1;
            int boleceginDeger = BolecegimDeger(deger); // 10 üssü uzunluk -1 deyip ilk basamağı almış oldum
            int basamak = sayi / boleceginDeger;        // ilk basamağı almış oldum
            sayiBasamak->ekle(basamak);
            sayi = sayi - (basamak * boleceginDeger);
            int i = 1; // sayının içerisinde 0 var mı kontrolü yapmak için ve ilk basamağı eklediğimden 1den başlatıyorum
            while (sayi > 0 || ilkBasamakUzunlugu != i)
            {
                // diyorum ki eğer sayının basamağının olması gerekenden az basamaklıysa araadan 0 gştmiştir
                string sayiS = to_string(sayi);       // sayıyı string çevirdim
                int basamakUzunlugu = sayiS.length(); // uzunluğunu buldum
                if (basamakUzunlugu != ilkBasamakUzunlugu - i)
                {
                    sayiBasamak->ekle(0);
                    i++;
                }
                else
                {
                    int deger = basamakUzunlugu - 1;
                    int boleceginDeger = BolecegimDeger(deger); // 10 üssü uzunluk -1 deyip ilk basamağı almış oldum
                    int basamak = sayi / boleceginDeger;        // ilk basamağı almış oldum
                    sayiBasamak->ekle(basamak);
                    sayi = sayi - (basamak * boleceginDeger);
                    i++;
                }
            }
            int sayim = sayiBasamak->SayiyiOlustur(ilkBasamakUzunlugu); // oluşmuş olan sayıyı aldım
            sayiListe->Ekle(sayim);                                     // sayilar listesinin düğümüne atıyorum
        }
        // dizayn kısmına geldik
        // üst kısım
        sayiListe->UstYaz();
        sayiBasamak->UstuYazdir();
        cout << endl;
        // adresler
        sayiListe->SayilarListesiAdresYaz();
        sayiBasamak->yazdirAdres();
        cout << endl;
        // adres değer arası
        sayiListe->AdresDegerAyirma();
        sayiBasamak->AdresDegerAyirma();
        cout << endl;
        // değerler
        sayiListe->SayilarListesiDegerYaz();
        sayiBasamak->yazdirBasamak();
        cout << endl;
        sayiBasamak->yeniSayimKonumu();
        sayiListe->UstYaz();
        sayiBasamak->SonradanOrtaAlt(ilkBasamakUzunlugu, ilkBasamakUzunlugu);
        cout << endl;
        cout << endl;
    }
    Islemler();
}
void Islemler()
{
    cout << "1. Tek basamakalri basa al" << endl;
    cout << "2. Basamaklari tersle" << endl;
    cout << "3. En buyuk cikar" << endl;
    cout << "4. cikis" << endl;
    string islem;
    cin >> islem;
    if (islem == "1")
    {
        TekleriBasaAl();
    }
    else if (islem == "2")
    {
        BasamaklariTersle();
    }
    else if (islem == "3")
    {
        EnBuyuguSil();
    }
    else if (islem == "4")
    {
        return;
    }
    else
    {
        cout << "Hatali değer girisi ! 1,2,3,4 değerlerinden birini tuşlamaniz lazim" << endl;
        Islemler();
    }
    Islemler();
}

void TekleriBasaAl()
{
    sayiListe->DegerleriSifirlama(); // bu sayede ilk adresimde yerleştirmeye başlayacağım
    sayiBasamak->HerSeyiSifirla();   // bu sayede basamakları tekrar tekrar gezebileceğim
    system("cls");
    std::ifstream dosya("Sayilar.txt");
    if (!dosya)
    {
        std::cerr << "Dosya açılamadı!" << std::endl;
    }
    int sayi;
    while (dosya >> sayi)
    {
        string sayiS = to_string(sayi);       // sayıyı string çevirdim
        int basamakUzunlugu = sayiS.length(); // uzunluğunu buldum
        string sayim = sayiBasamak->TekleriBasaAl(basamakUzunlugu);
        int sayi = stoi(sayim);
        sayiListe->SonradanEkle(sayi);
        // üst kısım
        sayiListe->UstYaz();
        sayiBasamak->SonradanUstuYazdir(basamakUzunlugu, basamakUzunlugu); // bu tamam gibi duruyor bundan devam
        cout << endl;
        // adresler
        sayiListe->SayilarListesiAdresYaz();
        sayiBasamak->SonradanAdresYaz(basamakUzunlugu, basamakUzunlugu);
        cout << endl;
        // adres değer arası
        sayiListe->AdresDegerAyirma();
        sayiBasamak->SonradanOrtaYazdir(basamakUzunlugu, basamakUzunlugu);
        cout << endl;
        // değerler
        sayiListe->SayilarListesiDegerYaz();
        sayiBasamak->TekleriYazdir(basamakUzunlugu);
        cout << endl;
        // alttan ayırma
        sayiListe->UstYaz();
        sayiBasamak->SonradanOrtaAlt(basamakUzunlugu, basamakUzunlugu);
        cout << endl;
        cout << endl;
    }
}

void BasamaklariTersle()
{
    sayiListe->DegerleriSifirlama(); // bu sayede ilk adresimde yerleştirmeye başlayacağım
    sayiBasamak->HerSeyiSifirla();   // bu sayede basamakları tekrar tekrar gezebileceğim
    kacinciyaTersleniyor++;

    if (kacinciyaTersleniyor % 2 != 0) // eğer ilk kez tersleniyorsa budur yok çift terslemeyse ilk halidir
    {
        system("cls");
        std::ifstream dosya("Sayilar.txt");
        if (!dosya)
        {
            std::cerr << "Dosya açılamadı!" << std::endl;
        }
        int sayi;
        while (dosya >> sayi)
        {
            // SayilarListeme eklemek için aynı ilk başta basamaklarına ayırdığım gibi burada da ayırma lazım o sebepten
            string sayim;
            int tempSayi = sayi;
            int sayimSon;
            if (sayi != 0)
            {
                while (tempSayi > 0)
                {
                    // burada direk sayımın sondan başa basamaklarını alıp string çevirip tersten birleştirerek sayımı oluşturuyorum
                    int basamak = tempSayi % 10;
                    sayim += to_string(basamak);
                    tempSayi /= 10;
                }
                sayimSon = stoi(sayim);
            }
            else
            {
                sayimSon = 0;
            }
            sayiListe->SonradanEkle(sayimSon);

            // ilk önce sayının basamak uzunluğunu buluyoruz
            string sayiS = to_string(sayi);       // sayıyı string çevirdim
            int basamakUzunlugu = sayiS.length(); // uzunluğunu buldum
            // üst kısım
            sayiListe->UstYaz();
            sayiBasamak->SonradanUstuYazdir(basamakUzunlugu, basamakUzunlugu); // bu tamam gibi duruyor bundan devam
            cout << endl;
            // adresler
            sayiListe->SayilarListesiAdresYaz();
            sayiBasamak->SonradanAdresYaz(basamakUzunlugu, basamakUzunlugu);
            cout << endl;
            // adres değer arası
            sayiListe->AdresDegerAyirma();
            sayiBasamak->SonradanOrtaYazdir(basamakUzunlugu, basamakUzunlugu);
            cout << endl;
            // değerler
            sayiListe->SayilarListesiDegerYaz();
            sayiBasamak->SonradanDegersYaz(basamakUzunlugu, basamakUzunlugu);
            cout << endl;
            // alttan ayırma
            sayiListe->UstYaz();
            sayiBasamak->SonradanOrtaAlt(basamakUzunlugu, basamakUzunlugu);
            cout << endl;
            cout << endl;
            sayim = "";
        }
    }
    else
    { // ekleme işlemini sonradan ekle ile gerçekleştirdim çünkü o eleman sayısı ile oluşturulduğundan hepsini gerçekleştirebilmeye uygun durumda .
        system("cls");
        sayiListe->DegerleriSifirlama(); // bu sayede ilk adresimde yerleştirmeye başlayacağım
        sayiBasamak->HerSeyiSifirla();   // bu sayede basamakları tekrar tekrar gezebileceğim
        std::ifstream dosya("Sayilar.txt");
        if (!dosya)
        {
            std::cerr << "Dosya açılamadı!" << std::endl;
        }
        int sayi;

        while (dosya >> sayi)
        {
            // Sıra:
            // ekle
            // sayı oluştur
            // yazdır
            // yeni sayının basamağının konumu
            string sayiS = to_string(sayi);          // sayıyı string çevirdim
            int ilkBasamakUzunlugu = sayiS.length(); // uzunluğunu buldum
            if (sayi == 0)
            {
                sayiBasamak->ekle(0);
                int ilkBasamakUzunlugu = 1;
                int sayim = sayiBasamak->SayiyiOlustur(1);
                sayiListe->SonradanEkle(sayim);
            }
            else
            {
                // cout << "sayi " << sayi << endl;

                int basamakUzunlugu = sayiS.length(); // uzunluğunu buldum
                int deger = basamakUzunlugu - 1;
                int boleceginDeger = BolecegimDeger(deger); // 10 üssü uzunluk -1 deyip ilk basamağı almış oldum
                int basamak = sayi / boleceginDeger;        // ilk basamağı almış oldum
                sayiBasamak->ekle(basamak);
                sayi = sayi - (basamak * boleceginDeger);
                int i = 1; // sayının içerisinde 0 var mı kontrolü yapmak için ve ilk basamağı eklediğimden 1den başlatıyorum
                while (sayi > 0 || ilkBasamakUzunlugu != i)
                {
                    // diyorum ki eğer sayının basamağının olması gerekenden az basamaklıysa araadan 0 gştmiştir
                    string sayiS = to_string(sayi);       // sayıyı string çevirdim
                    int basamakUzunlugu = sayiS.length(); // uzunluğunu buldum
                    if (basamakUzunlugu != ilkBasamakUzunlugu - i)
                    {
                        sayiBasamak->ekle(0);
                        i++;
                    }
                    else
                    {
                        int deger = basamakUzunlugu - 1;
                        int boleceginDeger = BolecegimDeger(deger); // 10 üssü uzunluk -1 deyip ilk basamağı almış oldum
                        int basamak = sayi / boleceginDeger;        // ilk basamağı almış oldum
                        sayiBasamak->ekle(basamak);
                        sayi = sayi - (basamak * boleceginDeger);
                        i++;
                    }
                }
                int sayim = sayiBasamak->SayiyiOlustur(ilkBasamakUzunlugu); // oluşmuş olan sayıyı aldım
                sayiListe->SonradanEkle(sayim);                             // sayilar listesinin düğümüne atıyorum
            }
            // dizayn kısmına geldik
            // üst kısım
            sayiListe->UstYaz();
            sayiBasamak->UstuYazdir();
            cout << endl;
            // adresler
            sayiListe->SayilarListesiAdresYaz();
            sayiBasamak->yazdirAdres();
            cout << endl;
            // adres değer arası
            sayiListe->AdresDegerAyirma();
            sayiBasamak->AdresDegerAyirma();
            cout << endl;
            // değerler
            sayiListe->SayilarListesiDegerYaz();
            sayiBasamak->yazdirBasamak();
            cout << endl;
            sayiBasamak->yeniSayimKonumu();
            sayiListe->UstYaz();
            sayiBasamak->SonradanOrtaAlt(ilkBasamakUzunlugu, ilkBasamakUzunlugu);
            cout << endl;
            cout << endl;
            // buraya Sayi.hpp içerisinde sayiEkle oluşturup yazacağını koy
        }
    }
}

void EnBuyuguSil()
{
    sayiListe->DegerleriSifirlama(); // bu sayede ilk adresimde yerleştirmeye başlayacağım
    sayiBasamak->HerSeyiSifirla();   // bu sayede basamakları tekrar tekrar gezebileceğim
    system("cls");
    std::ifstream dosya("Sayilar.txt");
    if (!dosya)
    {
        std::cerr << "Dosya açılamadı!" << std::endl;
    }
    // hemen en büyüğü bulrum
    if (silinenElemanSayim + 1 == toplamElemanSayim)
    {
        return;
    }
    int eb = sayiListe->EnBuyuguBulma();
    sayiListe->YenidenSirala(eb); // sıralamamı yapar eleman sayımı 1 azaltırım ve başlangıç halini -1 e getirmiş olurum
    silinenElemanSayim += 1;
    int sayi;
    int kacKereGezdim = 0;
    while (dosya >> sayi)
    {
        sayiListe->ElemanSayisiArttir();
        if (kacKereGezdim + silinenElemanSayim == toplamElemanSayim)
        {
            return;
        } // bu sayede out of range olmasını engelliyorum
        // üst kısım
        sayiListe->UstYaz();
        // sayiBasamak->SonradanUstuYazdir(basamakUzunlugu, basamakUzunlugu); // bu tamam gibi duruyor bundan devam
        cout << endl;
        // adresler
        sayiListe->SayilarListesiAdresYaz();
        // sayiBasamak->SonradanAdresYaz(basamakUzunlugu, basamakUzunlugu);
        cout << endl;
        // adres değer arası
        sayiListe->AdresDegerAyirma();
        // sayiBasamak->SonradanOrtaYazdir(basamakUzunlugu, basamakUzunlugu);
        cout << endl;
        // değerler
        sayiListe->SayilarListesiDegerYaz();
        // sayiBasamak->SonradanDegersYaz(basamakUzunlugu, basamakUzunlugu);
        cout << endl;
        // alttan ayırma
        sayiListe->UstYaz();
        // sayiBasamak->SonradanOrtaAlt(basamakUzunlugu, basamakUzunlugu);
        cout << endl;
        cout << endl;
        kacKereGezdim += 1;
    }
}

int BolecegimDeger(int basamakUzunlugu)
{
    int deger = 1;
    for (int i = basamakUzunlugu; i > 0; i--)
    {
        deger *= 10;
    }
    return deger;
}