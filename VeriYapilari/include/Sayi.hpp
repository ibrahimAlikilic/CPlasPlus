/**
* @file Sayi.hpp
* @description Tek yönlü bağlı liste ile işlemler
* @course 1. öğreim C grubu
* @assignment 1
* @date 06.11.2023
* @author ibrahim.alikilic@ogr.sakarya.edu.tr
*/
#ifndef SAYi_HPP
#define SAYi_HPP
#include "Basamak.hpp"
#include "SayilarListesi.hpp"
#include <iostream>
#include <string>
#include <sstream> // pointer ı string dönüştürüp son 3 karakteri almak istedim onun için bu lazımmış
using namespace std;
class Sayi
{
public:
    Sayi();

    void ekle(int sayi);

    // burada sayıyı oluştururum oluşturduğumu sayılar listesinin düğümüne eklerim yazdırma yaparken de her yazdırmada sayılar listesinden sonrakine geç derim.
    int SayiyiOlustur(int baslangicSayiUzunlugu);
    void yeniSayimKonumu();

    void UstuYazdir();
    void AdresDegerAyirma();
    void yazdirAdres();
    void yazdirBasamak();

    // buradan itibaren breakPoint ile kontrollü bir şekilde devam edeceğim

    // ilk başta oluştururken yazma kısmı için sadece okuma sırasında olacak şekilde oluşturulmuştur. bu sebepten dolayı ileriki kısmlara uymamaktadır.
    // şimdi basamakların yerleri değiştikten sonrası için yazdırma kısmını oluşturacağım
    // uyarlayabilirsem tamamını buna uyarlayacağım.
    void SonradanUstuYazdir(int sayiUzunlugu, int anaSayiUzunlugu);
    void SonradanAdresYaz(int sayiUzunlugu, int anaSayiUzunlugu);
    // hem üstten yaz hem alttan yaz ayrı ayrı yapıyorum çünkü diper türlü sayacım 2 kere saymış olur.
    void SonradanOrtaYazdir(int sayiUzunlugu,int anaSayiUzunlugu);
    void SonradanDegersYaz(int sayiUzunlugu, int anaSayiUzunlugu);
    void SonradanOrtaAlt(int sayiUzunlugu, int anaSayiUzunlugu);

    // Tekleri Başa al
    string TekleriBasaAl(int sayiUzunlugu);
    void TekleriYazdir(int sayiUzunlugu);

    /*
    void BasamaklariTersle(int sayiUzunlugu);
    void SonrdanAdresDegerAyirma();
    void SonrdanYazdirAdres(int sayiUzunlugu);
    void SonrdanyazdirBasamak();
    */
    int CarpacagimDeger(int basamakUzunlugu);
    void HerSeyiSifirla();
    ~Sayi();
private:
    Basamak *ilk;
    Basamak *yeniSayBaslangicNoktasi;
    bool ilkKezMiYaziyor; // BasamaklariTersle if için
    int elemanSayisi;
    int sayim;
    bool yenilemeMiLazim;
    int kacBasamakTerslendi;
    bool ilkKezMiSayiOlusturuluyor;
    bool ilkKezMiYaziyorBasamak;
    bool ilkKezMiYaziyorAdres;
    bool ilkKezMiYaziyorDegerAyirma;
    int kacAdresYazildi;
    int kacBasamakYazildi;
    int kacBasamakYazildiOrta;
    int kacBasamakYazildiUst;
    int kacDegerYazildi;
    int kacBasamakYazildiAlt;
    int kacTekKontrolEdildi;
    int kacTekYazildi;
};
#endif
