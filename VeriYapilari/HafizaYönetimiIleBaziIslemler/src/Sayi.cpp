/**
* @file Sayi.cpp
* @description Tek yönlü bağlı liste ile işlemler
* @course 1. öğreim C grubu
* @assignment 1
* @date 06.11.2023
* @author ibrahim.alikilic@ogr.sakarya.edu.tr
*/
#include "Sayi.hpp"
#include "Basamak.hpp"
#include "SayilarListesi.hpp"
#include <iostream>
#include <string>
#include <sstream> // pointer ı string dönüştürüp son 3 karakteri almak istedim onun için bu lazımmış
using namespace std;
Sayi::Sayi()
{
    ilk = NULL;
    yeniSayBaslangicNoktasi = NULL;
    ilkKezMiYaziyor = true;
    elemanSayisi = 0;
    sayim = 0;
    yenilemeMiLazim = true;
    kacBasamakTerslendi = 0;
    ilkKezMiSayiOlusturuluyor = true;
    ilkKezMiYaziyorBasamak = true;
    ilkKezMiYaziyorAdres = true;
    ilkKezMiYaziyorDegerAyirma = true;
    kacAdresYazildi = 0;
    kacBasamakYazildiOrta = 0;
    kacBasamakYazildiUst = 0;
    kacDegerYazildi = 0;
    kacBasamakYazildiAlt = 0;
    kacTekKontrolEdildi = 0;
    kacTekYazildi = 0;
}

void Sayi::ekle(int sayi)
{
    Basamak *yeni = new Basamak(sayi);
    if (elemanSayisi == 0)
    {
        ilk = yeni;
        yeniSayBaslangicNoktasi = yeni;
        elemanSayisi++;
        return; // returnlediğimizden elseye gerek kalmadı
    }
    // şimdi ilk düğümü kaybetmemek için temp oluşturucaz
    Basamak *temp = yeniSayBaslangicNoktasi;
    // son elemana kadar gidicez
    while (temp->sonraki != NULL)
    {
        temp = temp->sonraki;
    }
    // şimdi son düğüme geldik ve 1 sonraki düğüm yok yani Null şu anda biz de yeniyi atamış olduk ilk düğümü de tuttuğumuzdan hepsine ulaşabiliyoz.
    temp->sonraki = yeni;
    elemanSayisi++;
}

// burada sayıyı oluştururum oluşturduğumu sayılar listesinin düğümüne eklerim yazdırma yaparken de her yazdırmada sayılar listesinden sonrakine geç derim.
int Sayi::SayiyiOlustur(int baslangicSayiUzunlugu)
{
    sayim = 0;
    if (elemanSayisi == 0)
    {
        cout << "Eleman yok" << endl;
        return 111;
    }
    Basamak *temp=NULL;
    if (ilkKezMiSayiOlusturuluyor)
    {
        temp = yeniSayBaslangicNoktasi;
        ilkKezMiSayiOlusturuluyor = false;
    }
    else
    {
        temp = yeniSayBaslangicNoktasi->sonraki;
    }
    while (temp != 0)
    {
        int SayiOlusuyor = CarpacagimDeger(baslangicSayiUzunlugu - 1); // uzunluk -1 tane 0 olmalı
        // cout<<"temp->basamak : "<<temp->basamak<<"sayiOlusuyor : "<<SayiOlusuyor<<endl; kontrol amaçlı oluşturulmuş bir satırdır
        sayim += temp->basamak * SayiOlusuyor;
        temp = temp->sonraki;
        baslangicSayiUzunlugu--; // bir sonraki basamak değeri için 1 azalttık
    }
    return sayim;
}
void Sayi::yeniSayimKonumu()
{
    Basamak *temp = yeniSayBaslangicNoktasi;
    while (temp->sonraki != NULL)
    {
        temp = temp->sonraki; // şu anda sayımın son basamağına gelmiş bulunmakyayım
    }
    // ekle dediğim zaman yeni basamağımı buraya ekliyor bu sebepten eğer ben buranın konumunu yeniSayBaslangicNoktasi atarsam yeni sayımın basamaklarının başlangıç noktasında olmuş olurum.
    // cout<<"temp : "<<temp<<" temp->basamak : "<<temp->basamak<<" temp->sonraki : "<<temp->sonraki<<endl;
    yeniSayBaslangicNoktasi = temp;
}

void Sayi::UstuYazdir()
{
    // hiç eleman olmayabiliri , eleman sayisindan gidicem
    if (elemanSayisi == 0)
    {
        cout << "Eleman yok" << endl;
    }
    else
    {
        Basamak *temp = yeniSayBaslangicNoktasi; // sonraki olmalı çünkü şu anda  yeniSayBaslangicNoktasi önceki sayının son basamağında // ilk yazdırma hariç !
        if (ilkKezMiYaziyor)                     // ilk kez yazdırma kontrolü
        {
            ilkKezMiYaziyor = false;
        }
        else
        {
            temp = temp->sonraki; // sonraki olmalı çünkü şu anda  yeniSayBaslangicNoktasi önceki sayının son basamağında // ilk yazdırma hariç !
        }
        while (temp != 0)
        {
            cout << " ******* ";
            temp = temp->sonraki;
        }
    }
}
void Sayi::AdresDegerAyirma()
{
    // hiç eleman olmayabiliri , eleman sayisindan gidicem
    if (elemanSayisi == 0)
    {
        cout << "Eleman yok" << endl;
    }
    else
    {
        Basamak *temp = yeniSayBaslangicNoktasi; // sonraki olmalı çünkü şu anda  yeniSayBaslangicNoktasi önceki sayının son basamağında // ilk yazdırma hariç !
        if (ilkKezMiYaziyorDegerAyirma)          // ilk kez yazdırma kontrolü
        {
            ilkKezMiYaziyorDegerAyirma = false;
        }
        else
        {
            temp = temp->sonraki; // sonraki olmalı çünkü şu anda  yeniSayBaslangicNoktasi önceki sayının son basamağında // ilk yazdırma hariç !
        }
        while (temp != 0)
        {
            cout << " ******* ";
            temp = temp->sonraki;
        }
    }
}
void Sayi::yazdirAdres()
{
    // hiç eleman olmayabiliri , eleman sayisindan gidicem
    if (elemanSayisi == 0)
    {
        cout << "Eleman yok" << endl;
    }
    else
    {
        Basamak *temp=NULL;            // sonraki olmalı çünkü şu anda  yeniSayBaslangicNoktasi önceki sayının son basamağında // ilk yazdırma hariç !
        if (ilkKezMiYaziyorAdres) // ilk kez yazdırma kontrolü
        {
            temp = ilk;
            ilkKezMiYaziyorAdres = false;
        }
        else
        {
            temp = yeniSayBaslangicNoktasi->sonraki; // sonraki olmalı çünkü şu anda  yeniSayBaslangicNoktasi önceki sayının son basamağında // ilk yazdırma hariç !
        }
        while (temp != 0)
        {
            stringstream ss;
            ss << temp; // stringstream kullanarak adresi stringe dönüştürmek için bu gerekiyormuş
            // işlemi yaparken kafam karışmasın diye ve dönüp bakınca tekrar anlamak için 2 satırda yaptım tek satırda gerçekleşir mi denemedim ama neden olmasın .
            string basamakAdres = ss.str();
            string basamakAdresSonUcHaneIcin = basamakAdres.substr(basamakAdres.size() - 3);
            cout << " * " << basamakAdresSonUcHaneIcin << " * ";
            temp = temp->sonraki;
        }
    }
}
void Sayi::yazdirBasamak()
{
    // hiç eleman olmayabiliri , eleman sayisindan gidicem
    if (elemanSayisi == 0)
    {
        cout << "Eleman yok" << endl;
    }
    else
    {
        Basamak *temp=NULL;              // sonraki olmalı çünkü şu anda  yeniSayBaslangicNoktasi önceki sayının son basamağında // ilk yazdırma hariç !
        if (ilkKezMiYaziyorBasamak) // ilk kez yazdırma kontrolü
        {
            temp = ilk;
            ilkKezMiYaziyorBasamak = false;
        }
        else
        {
            temp = yeniSayBaslangicNoktasi->sonraki; // sonraki olmalı çünkü şu anda  yeniSayBaslangicNoktasi önceki sayının son basamağında // ilk yazdırma hariç !
        }
        while (temp != 0)
        {
            cout << " *  " << temp->basamak << "  * ";
            temp = temp->sonraki;
        }
    }
}

// buradan itibaren breakPoint ile kontrollü bir şekilde devam edeceğim

// ilk başta oluştururken yazma kısmı için sadece okuma sırasında olacak şekilde oluşturulmuştur. bu sebepten dolayı ileriki kısmlara uymamaktadır.
// şimdi basamakların yerleri değiştikten sonrası için yazdırma kısmını oluşturacağım
// uyarlayabilirsem tamamını buna uyarlayacağım.
void Sayi::SonradanUstuYazdir(int sayiUzunlugu, int anaSayiUzunlugu)
{
    int tempAnaSayiUzunlugu = anaSayiUzunlugu;
    int gidecegimAdres = kacBasamakYazildiUst;
    Basamak *temp = ilk;
    while (gidecegimAdres > 0) // bu sayede sayımın adresine varmış oldum.
    {
        temp = temp->sonraki;
        gidecegimAdres--;
    }
    for (int i = 1; i < sayiUzunlugu; i++)
    { // burada istediğim sayımın son basamağına gelmiş oldum
        temp = temp->sonraki;
    }
    // üstten ayırıyorum
    cout << " ******* ";

    sayiUzunlugu -= 1; // sayı uzunluğumu 1 azaltarak ilk basamağa kadar geri dönüyorum
    if (sayiUzunlugu == 0)
    {
        kacBasamakYazildiUst += anaSayiUzunlugu;
        return;
    }
    else
    {
        SonradanUstuYazdir(sayiUzunlugu, tempAnaSayiUzunlugu);
    } // özyineleme ile tüm basamakları yazdırmış oluyorum
}
void Sayi::SonradanAdresYaz(int sayiUzunlugu, int anaSayiUzunlugu)
{
    int tempAnaSayiUzunlugu = anaSayiUzunlugu;
    int gidecegimAdres = kacAdresYazildi;
    Basamak *temp = ilk;
    while (gidecegimAdres > 0) // bu sayede sayımın adresine varmış oldum.
    {
        temp = temp->sonraki;
        gidecegimAdres--;
    }
    for (int i = 1; i < sayiUzunlugu; i++)
    { // burada istediğim sayımın son basamağına gelmiş oldum
        temp = temp->sonraki;
    }
    // adresi yazıyorum
    stringstream ss;
    ss << temp; // stringstream kullanarak adresi stringe dönüştürmek için bu gerekiyormuş
    // işlemi yaparken kafam karışmasın diye ve dönüp bakınca tekrar anlamak için 2 satırda yaptım tek satırda gerçekleşir mi denemedim ama neden olmasın .
    string basamakAdres = ss.str();
    string basamakAdresSonUcHaneIcin = basamakAdres.substr(basamakAdres.size() - 3);
    cout << " * " << basamakAdresSonUcHaneIcin << " * ";
    sayiUzunlugu -= 1; // sayı uzunluğumu 1 azaltarak ilk basamağa kadar geri dönüyorum
    if (sayiUzunlugu == 0)
    {
        kacAdresYazildi += anaSayiUzunlugu;
        return;
    }
    else
    {
        SonradanAdresYaz(sayiUzunlugu, tempAnaSayiUzunlugu);
    } // özyineleme ile tüm basamakları yazdırmış oluyorum
}
void Sayi::SonradanOrtaYazdir(int sayiUzunlugu, int anaSayiUzunlugu)
{
    int tempAnaSayiUzunlugu = anaSayiUzunlugu;
    int gidecegimAdres = kacBasamakYazildiOrta;
    Basamak *temp = ilk;
    while (gidecegimAdres > 0) // bu sayede sayımın adresine varmış oldum.
    {
        temp = temp->sonraki;
        gidecegimAdres--;
    }
    for (int i = 1; i < sayiUzunlugu; i++)
    { // burada istediğim sayımın son basamağına gelmiş oldum
        temp = temp->sonraki;
    }
    // alttan ayırıyorum
    cout << " ******* ";
    sayiUzunlugu -= 1; // sayı uzunluğumu 1 azaltarak ilk basamağa kadar geri dönüyorum
    if (sayiUzunlugu == 0)
    {
        kacBasamakYazildiOrta += anaSayiUzunlugu;
        return;
    }
    else
    {
        SonradanOrtaYazdir(sayiUzunlugu, tempAnaSayiUzunlugu);
    } // özyineleme ile tüm basamakları yazdırmış oluyorum
}
void Sayi::SonradanDegersYaz(int sayiUzunlugu, int anaSayiUzunlugu)
{
    int tempAnaSayiUzunlugu = anaSayiUzunlugu;
    int gidecegimAdres = kacDegerYazildi;
    Basamak *temp = ilk;
    while (gidecegimAdres > 0) // bu sayede sayımın adresine varmış oldum.
    {
        temp = temp->sonraki;
        gidecegimAdres--;
    }
    for (int i = 1; i < sayiUzunlugu; i++)
    { // burada istediğim sayımın son basamağına gelmiş oldum
        temp = temp->sonraki;
    }
    // basamağı yazıyorum
    cout << " *  " << temp->basamak << "  * ";
    sayiUzunlugu -= 1; // sayı uzunluğumu 1 azaltarak ilk basamağa kadar geri dönüyorum
    if (sayiUzunlugu == 0)
    {
        kacDegerYazildi += anaSayiUzunlugu;
        return;
    }
    else
    {
        SonradanDegersYaz(sayiUzunlugu, tempAnaSayiUzunlugu);
    } // özyineleme ile tüm basamakları yazdırmış oluyorum
}
void Sayi::SonradanOrtaAlt(int sayiUzunlugu, int anaSayiUzunlugu)
{
    int tempAnaSayiUzunlugu = anaSayiUzunlugu;
    int gidecegimAdres = kacBasamakYazildiAlt;
    Basamak *temp = ilk;
    while (gidecegimAdres > 0) // bu sayede sayımın adresine varmış oldum.
    {
        temp = temp->sonraki;
        gidecegimAdres--;
    }
    for (int i = 1; i < sayiUzunlugu; i++)
    { // burada istediğim sayımın son basamağına gelmiş oldum
        temp = temp->sonraki;
    }
    // alttan ayırıyorum
    cout << " ******* ";
    sayiUzunlugu -= 1; // sayı uzunluğumu 1 azaltarak ilk basamağa kadar geri dönüyorum
    if (sayiUzunlugu == 0)
    {
        kacBasamakYazildiAlt += anaSayiUzunlugu;
        return;
    }
    else
    {
        SonradanOrtaAlt(sayiUzunlugu, tempAnaSayiUzunlugu);
    } // özyineleme ile tüm basamakları yazdırmış oluyorum
}

// Tekleri başa al
string Sayi::TekleriBasaAl(int sayiUzunlugu)
{
    // tempimin ilk sayımdan 1 öncekine kadar gelmesi lazım
    Basamak *temp = ilk;
    Basamak *tek = NULL;
    Basamak *cift = NULL;
    Basamak *ciftOnce = NULL;
    Basamak *ciftSonra = NULL;
    int kacIleriGidicem = kacTekKontrolEdildi;
    // eğer ilk çiftse onu tek ile değiştirmem lazım
    if (ilk->basamak % 2 == 0)
    {
        cift = ilk;
        Basamak *geciciTemp = temp;
        for (int i = 1; i < sayiUzunlugu; i++)
        {
            if (geciciTemp->sonraki->basamak % 2 != 0)
            { // teki bulduğumda
                tek = geciciTemp->sonraki;
                geciciTemp->sonraki = cift;
                cift->sonraki = tek->sonraki;
                tek->sonraki = ilk;
                ilk = tek;
                i = sayiUzunlugu;
            }
            geciciTemp = geciciTemp->sonraki;
        }
        temp = ilk;
    }
    while (kacIleriGidicem > 1) // 1 dedim çünkü 1 geride olmam lazım
    {
        temp = temp->sonraki;
        kacIleriGidicem--;
    }
    Basamak *geciciTemp2 = temp;
    for (int i = 1; i < sayiUzunlugu; i++)
    {
        if (geciciTemp2->sonraki->basamak % 2 == 0)
        {
            ciftOnce=geciciTemp2; // bunu sondaki değer için kullanıcam
            ciftSonra=geciciTemp2->sonraki->sonraki;
            cift = geciciTemp2->sonraki;
            Basamak *geciciTemp = cift;
            for (int j = i; j < sayiUzunlugu - 1; j++)
            {
                if (geciciTemp->sonraki->basamak % 2 != 0)
                { // yani tekse
                    tek = geciciTemp->sonraki;
                    geciciTemp2->sonraki = tek;
                    geciciTemp->sonraki = cift;
                    Basamak *geciciTekSonraki = tek->sonraki;
                    tek->sonraki = cift->sonraki;
                    cift->sonraki = geciciTekSonraki;
                    j = sayiUzunlugu - 1;
                    i = 1;
                    geciciTemp2 = temp->sonraki;
                }
                geciciTemp = geciciTemp->sonraki;
            }
        }
        else
        {
            geciciTemp2 = geciciTemp2->sonraki;
        }
    }
    temp=temp->sonraki; // şimdi düzenlediğim sayımın ilk basamağındayım
    string sayim="";
    for(int i=1;i<sayiUzunlugu;i++){
        sayim+=to_string(temp->basamak);
        temp=temp->sonraki;
    }
    kacTekKontrolEdildi += sayiUzunlugu;
    return sayim; // sayılarListesine ekleyeceğim değerim
}
void Sayi::TekleriYazdir(int sayiUzunlugu)
{
    int gidecegimAdres = kacTekYazildi;
    Basamak *temp = ilk;
    while (gidecegimAdres > 0) // bu sayede sayımın adresine varmış oldum.
    {
        temp = temp->sonraki;
        gidecegimAdres--;
    }
    for (int i = 0; i < sayiUzunlugu; i++)
    {
        cout << " *  " << temp->basamak << "  * ";
        temp = temp->sonraki;
    }
    kacTekYazildi += sayiUzunlugu;
}

int Sayi::CarpacagimDeger(int basamakUzunlugu)
{
    int deger = 1;
    for (int i = basamakUzunlugu; i > 0; i--)
    {
        deger *= 10;
    }
    return deger;
}
void Sayi::HerSeyiSifirla()
{ // ilk hariç
    yeniSayBaslangicNoktasi = NULL;
    ilkKezMiYaziyor = true;
    elemanSayisi = 0;
    sayim = 0;
    yenilemeMiLazim = true;
    kacBasamakTerslendi = 0;
    ilkKezMiSayiOlusturuluyor = true;
    ilkKezMiYaziyorBasamak = true;
    ilkKezMiYaziyorAdres = true;
    ilkKezMiYaziyorDegerAyirma = true;
    kacAdresYazildi = 0;
    kacBasamakYazildiOrta = 0;
    kacBasamakYazildiUst = 0;
    kacDegerYazildi = 0;
    kacBasamakYazildiAlt = 0;
    kacTekKontrolEdildi = 0;
    kacTekYazildi = 0;
}

Sayi::~Sayi()
{
    Basamak *temp = ilk;
    while (temp == NULL)
    {
        Basamak *silinecek = temp;
        temp = temp->sonraki;
        delete silinecek;
    }
    delete ilk;
}