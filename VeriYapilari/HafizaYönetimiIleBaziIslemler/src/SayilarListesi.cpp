/**
* @file SayilarListesi.cpp
* @description Tek yönlü bağlı liste ile işlemler
* @course 1. öğreim C grubu
* @assignment 1
* @date 06.11.2023
* @author ibrahim.alikilic@ogr.sakarya.edu.tr
*/
#include "SayilarListesi.hpp"
#include <iostream>
#include "Dugum.hpp"
#include <iomanip> // stringstream için
#include <sstream> // pointer ı string dönüştürüp son 3 karakteri almak istedim onun için bu lazımmış
using namespace std;
SayilarListesi::SayilarListesi()
{
    ilk = NULL;
    elemanSayisi = 0;
    basamakAdres = "";
}
void SayilarListesi::Ekle(int sayi)
{
    Dugum *yeniDugum = new Dugum(sayi); // Dugum class ından nesnemi oluşturdum
    if (elemanSayisi == 0 & ilk == NULL)
    {
        ilk = yeniDugum;
        elemanSayisi++;
        return;
    }
    else if (elemanSayisi == 0)
    {
        ilk->sayi = yeniDugum->sayi;
        elemanSayisi++;
        return;
    }
    Dugum *temp = ilk; // başlangıç adresimi kaybetmiyorum
    while (temp->sonrakiDugum != 0)
    {
        temp = temp->sonrakiDugum; // son düğüme kadar gittim
    }
    temp->sonrakiDugum = yeniDugum;
    // cout << "yeniDugum : " << yeniDugum << " yeniDugum->sayi : " << yeniDugum->sayi << endl; kontrol amaçlı oluşturulmuş bir satırdır
    // cout<< "temp : " << temp << " temp->sayi" << temp->sayi << endl; kontrol amaçlı oluşturulmuş bir satırdır
    elemanSayisi++;
}

void SayilarListesi::UstYaz()
{
    Dugum *temp = ilk;
    for (int i = 0; i < elemanSayisi - 1; i++)
    {                              // eleman sayısından 1 eksik olmalı temp e ilki atadık hayalini kur hatırlarsın
        temp = temp->sonrakiDugum; // yazdırmak istediğim düğüme geldim demektir.
    }                              // adresini alacağımız düğüme geldik
    // adres uzunluğunu öğreniyoruz
    std::stringstream ss;
    ss << temp;
    basamakAdres = ss.str();
    int adresUzunlugu = basamakAdres.size();
    for (int i = 0; i < adresUzunlugu; i++)
    {
        cout << "#"; // burada adres uzunluğu kadar yaptık
    }
    cout << "## "; // 2 tane de baştan ve sondan için
}
void SayilarListesi::SayilarListesiAdresYaz()
{
    if (elemanSayisi == 0)
    {
        cout << "Herhangi bir deger yok !" << endl;
        return;
    }
    Dugum *temp = ilk;
    for (int i = 0; i < elemanSayisi - 1; i++)
    {                              // eleman sayısından 1 eksik olmalı temp e ilki atadık hayalini kur hatırlarsın
        temp = temp->sonrakiDugum; // yazdırmak istediğim düğüme geldim demektir.
    }
    cout << "#" << temp << "# ";
}
void SayilarListesi::AdresDegerAyirma()
{
    // UstYaz ile aynı mantık
    Dugum *temp = ilk;
    for (int i = 0; i < elemanSayisi - 1; i++)
    {                              // eleman sayısından 1 eksik olmalı temp e ilki atadık hayalini kur hatırlarsın
        temp = temp->sonrakiDugum; // yazdırmak istediğim düğüme geldim demektir.
    }                              // adresini alacağımız düğüme geldik
    // adres uzunluğunu öğreniyoruz
    stringstream ss;
    ss << temp;
    basamakAdres = ss.str();
    int adresUzunlugu = basamakAdres.size();
    // başa 1 tane #
    cout << "#";
    for (int i = 0; i < adresUzunlugu; i++)
    {
        cout << "-"; // burada adres uzunluğu kadar yaptık
    }
    cout << "# "; // sona 1 tane #
}
void SayilarListesi::SayilarListesiDegerYaz()
{
    if (elemanSayisi == 0)
    {
        cout << "Herhangi bir deger yok !" << endl;
        return;
    }
    Dugum *temp = ilk;
    for (int i = 0; i < elemanSayisi - 1; i++)
    {                              // eleman sayısından 1 eksik olmalı temp e ilki atadık hayalini kur hatırlarsın
        temp = temp->sonrakiDugum; // yazdırmak istediğim düğüme geldim demektir.
    }
    // adres uzunluğunu öğreniyoruz
    stringstream ss;
    ss << temp;
    basamakAdres = ss.str();
    int adresUzunlugu = basamakAdres.size();
    string sayiUzunlugu = to_string(temp->sayi);              // sayı uzunluğunu bulmak için ilk önce string çevirdim
    int soldanBosluk = adresUzunlugu - sayiUzunlugu.length(); // Adres uzunluğundan kalan kadar boşluk
    // yukarının cevabı kadar boşluk bırakıp sayıyı sağ tarafta olacak
    cout << left << "#";
    while (soldanBosluk > 0)
    {
        cout << " ";
        soldanBosluk--;
    }
    cout << temp->sayi << "# ";
}

// elenam tersleme
// bunun sayesinde ilk adresimden itibaren ekleyebiliyorum.
void SayilarListesi::SonradanEkle(int sayi)
{
    int kacinciElemanaGidicem = elemanSayisi;
    Dugum *yeniDugum = new Dugum(sayi); // Dugum class ından nesnemi oluşturdum
    if (elemanSayisi == 0)
    {
        ilk->sayi = yeniDugum->sayi;
        elemanSayisi++;
        return;
    }
    Dugum *temp = ilk; // başlangıç adresimi kaybetmiyorum
    while (kacinciElemanaGidicem > 1)
    {
        temp = temp->sonrakiDugum; // son düğüme kadar gittim
        kacinciElemanaGidicem--;
    }
    temp->sonrakiDugum->sayi = yeniDugum->sayi;
    elemanSayisi++;
}

int SayilarListesi::EnBuyuguBulma()
{
    Dugum *temp = ilk;
    Dugum *eb = temp;
    while (temp->sonrakiDugum != NULL)
    {
        if (temp->sayi > eb->sayi)
        {
            eb = temp;
        }
        temp = temp->sonrakiDugum;
    }
    // son düğümü kontrol etmemiş olduğumdan ötürü
    if (temp->sayi > eb->sayi)
    {
        eb = temp;
    }
    return eb->sayi; // en büyük değeri döndürdüm.
}
void SayilarListesi::YenidenSirala(int eb)
{
    Dugum *temp = ilk;
    if(temp->sayi==eb){//yani ilk değerim en büyükse
        Dugum* silinecek=ilk;
        ilk=ilk->sonrakiDugum;
        // delete silinecek; anlamadığım bir şekilde çöpümü silince hata alıyorum ?
    }
    while (temp->sonrakiDugum != NULL)
    {
        if (temp->sonrakiDugum->sayi == eb)
        {
            Dugum *silinecek = temp->sonrakiDugum;
            temp->sonrakiDugum = temp->sonrakiDugum->sonrakiDugum;
            delete silinecek;
        }
        else
        {
            temp = temp->sonrakiDugum;
        }
    }
}

void SayilarListesi::ElemanSayisiArttir(){
    elemanSayisi++;
}

void SayilarListesi::DegerleriSifirlama()
{
    elemanSayisi = 0;
}

SayilarListesi::~SayilarListesi()
{
    Dugum *temp = ilk;
    while (temp == NULL)
    {
        Dugum *silinecek = temp;
        temp = temp->sonrakiDugum;
        delete silinecek;
    }
    delete ilk;
}